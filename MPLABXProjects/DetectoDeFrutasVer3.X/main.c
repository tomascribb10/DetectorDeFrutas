/*
 * File:   main.c
 * Author: tomas
 *
 * Created on 14 de julio de 2022, 10:48
 */


/*
 * File:   main.c
 * Author: Alex Saucet
 *
 * Created on August 6, 2017, 10:19 AM
 */

// CONFIG1
 
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// CONFIG2
//#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
//#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode disabled)

#include <xc.h>
#include <stdint.h>
#include <stdlib.h>

#include "UART.h"
#include "servo.h"

#define _XTAL_FREQ  4000000     // System clock frequency

#define MAX_LENGTH_UART 16      // Max lenght of a string send or received with UART


unsigned int valor_pasos;
unsigned int frecuencia = 1500;
unsigned int in;
float periodo;
unsigned int cont_sr = 0;
unsigned char data_s[8];


void init() {
    //Configuracion modulo CCP
    CCP1CON = 0b00000101; //captura flanco ascendente
    T1CON = 0b00000000; //Configuracion time1 para CCP
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.CCP1IE = 1;
    PIR1bits.CCP1IF = 0;
    TMR1L = 0x00;
    TMR1H = 0x00;
    T1CONbits.TMR1ON = 1; //Prendemos el timer luego de configurar todo
    
    
    //Apagamos los comparadores de los puertos RA3 y RA4
    CMCONbits.CM0 = 1;
    CMCONbits.CM1 = 1;
    CMCONbits.CM2 = 1;
    
    // Ports config Por defecto inician como Entradas (1)
    //TRISA = 0x00;
    //PORTA = 0;
    TRISAbits.TRISA0 = 1;
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA2 = 1;
    TRISAbits.TRISA3 = 1;
    
    TRISBbits.TRISB3 = 1;
    TRISBbits.TRISB4 = 0;
    TRISBbits.TRISB5 = 0;
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB7 = 0;
    PORTB = 0;
    
    UARTInit(9600, 1);
}

void main(void) { 
    char* readBuf[MAX_LENGTH_UART];
    char* tmpBuf[8];
    int nRead = 0;
    char letra;
    init();
    //PORTBbits.RB3 = 1;
    PORTBbits.RB4 = 1;
    PORTBbits.RB5 = 1;
    PORTBbits.RB6 = 1;
    PORTBbits.RB7 = 1;
    __delay_ms(1000);
    //PORTBbits.RB3 = 0;
    PORTBbits.RB4 = 0;
    PORTBbits.RB5 = 0;
    PORTBbits.RB6 = 0;
    PORTBbits.RB7 = 0;
    //UARTSendString("TOM> \0", MAX_LENGTH_UART);
    int detect_on = 0;
    Servo_Init();   
    int contador = 0;
    //Prendemos el motor
    PORTBbits.RB7 = 1;
    while (1) {
        //Prendemos el motor mientras no corte la barrera IR
        //if(PORTAbits.RA3 == 1 && detect_on == 0 ){
        //    PORTBbits.RB6 = 0; //detenemos motor
            //UARTSendChar("x");
        //    UARTSendString("x\0", MAX_LENGTH_UART); //iniciamos deteccion
        //    detect_on = 1;
        //}
        ////////
        
        //PORTBbits.RB4 = 0;
        if(in == 1){
            periodo = valor_pasos * 0.000001;
            frecuencia = 1 / periodo;
            in = 0;
        }
        
        if (frecuencia > 1300  ){
            PORTBbits.RB7 = 0; //detenemos motor
            //UARTSendChar("x");
            UARTSendString("x\0", MAX_LENGTH_UART); //iniciamos deteccion
            detect_on = 1;
        }else{
            PORTBbits.RB7 = 1;
        }
        
        
        
        
        
        if(PORTAbits.RA0 == 1){
            PORTBbits.RB7 = 0;
        }
        if(PORTAbits.RA1 == 1){
            PORTBbits.RB4 = 0;
        }
        if(PORTAbits.RA2 == 1){
            PORTBbits.RB5 = 0;
        }
        
        if(UARTDataReady() > 0){       // Verifica si ha recibido datos por el puerto serial
            // Send prompt
            //UARTSendString("TOM> \0", MAX_LENGTH_UART);
            // Read response
            //nRead = UARTReadString(readBuf, MAX_LENGTH_UART);
            // Send number of bytes received
            //itoa(tmpBuf, nRead, 10);
            //UARTSendString("\n\rReceived \0", MAX_LENGTH_UART);
            //UARTSendString(tmpBuf, MAX_LENGTH_UART);
            //UARTSendString(" bytes: \0", MAX_LENGTH_UART);
            // Send echo of response.
            //UARTSendString(readBuf, nRead);
            //UARTSendString("\n\r\0", MAX_LENGTH_UART);
            //letra = readBuf[0];
            
            letra = UARTReadChar();
            
            switch (letra){
                case 'a': 
                    //UARTSendString("\n\rPrendiendo Led \0", MAX_LENGTH_UART);
                    PORTBbits.RB7 = 1;
                    //Servo_8_Write(0);
                    UARTSendString("y\0", MAX_LENGTH_UART);
                    PORTBbits.RB6 = 1; //Arrancamos motor
                    detect_on = 0;
                    break;
                case 'b':
                    //UARTSendString("\n\rApagando Led \0", MAX_LENGTH_UART);
                    PORTBbits.RB7 = 0;                
                    break;
                case 'c':    
                    //UARTSendString("\n\rPrendiendo Led \0", MAX_LENGTH_UART);
                    PORTBbits.RB4 = 1;
                    //Servo_8_Write(90);
                    UARTSendString("y\0", MAX_LENGTH_UART);
                    PORTBbits.RB6 = 1; //Arrancamos motor
                    detect_on = 0;
                    break;
                case 'd':
                    //UARTSendString("\n\rApagando Led \0", MAX_LENGTH_UART);
                    PORTBbits.RB4 = 0;
                    break;
                case 'e':    
                    //UARTSendString("\n\rPrendiendo Led \0", MAX_LENGTH_UART);
                    PORTBbits.RB5 = 1; 
                    //Servo_8_Write(180);
                    UARTSendString("y\0", MAX_LENGTH_UART);
                    PORTBbits.RB6 = 1; //Arrancamos motor
                    detect_on = 0;
                    break;      
                case 'f':
                    //UARTSendString("\n\rApagando Led \0", MAX_LENGTH_UART);
                    PORTBbits.RB5 = 0;
                    break;             
            }
        }
        
    }
    
    return;
}


void __interrupt() TMR0_ISR(void)
{
    
   
    if(PIR1bits.CCP1IF == 1)
    {
        valor_pasos = (CCPR1H << 8) + CCPR1L;
        TMR1H = 0x00;
        TMR1L = 0x00;
        //periodo = valor_pasos * 0.000001;
        //frecuencia = 1 / periodo;
        in = 1;
        PIR1bits.CCP1IF = 0;
    }
    
    if(INTCONbits.T0IF == 1)
    {
        cont_sr = cont_sr + 1;
        if(cont_sr > 41){
            cont_sr = 0;
        }
        #ifdef SERVO_1_PIN
        if(cont_sr < data_s[0]){SERVO_1_PIN = 1;} else{SERVO_1_PIN = 0;}
        #endif

        #ifdef SERVO_2_PIN
        if(cont_sr < data_s[1]){SERVO_2_PIN = 1;} else{SERVO_2_PIN = 0;}
        #endif

        #ifdef SERVO_3_PIN
        if(cont_sr < data_s[2]){SERVO_3_PIN = 1;} else{SERVO_3_PIN = 0;}
        #endif

        #ifdef SERVO_4_PIN
        if(cont_sr < data_s[3]){SERVO_4_PIN = 1;} else{SERVO_4_PIN = 0;}
        #endif

        #ifdef SERVO_5_PIN
        if(cont_sr < data_s[4]){SERVO_5_PIN = 1;} else{SERVO_5_PIN = 0;}
        #endif

        #ifdef SERVO_6_PIN
        if(cont_sr < data_s[5]){SERVO_6_PIN = 1;} else{SERVO_6_PIN = 0;}
        #endif

        #ifdef SERVO_7_PIN
        if(cont_sr < data_s[6]){SERVO_7_PIN = 1;} else{SERVO_7_PIN = 0;}
        #endif

        #ifdef SERVO_8_PIN
        if(cont_sr < data_s[7]){SERVO_8_PIN = 1;} else{SERVO_8_PIN = 0;}
        #endif
        
        TMR0 = 5;
        INTCONbits.T0IF = 0;
        INTCONbits.T0IE = 1;
    }
}