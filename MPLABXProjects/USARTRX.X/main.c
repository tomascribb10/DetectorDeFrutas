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

void init() {
    // Oscillator config
    //OSCCONbits.SCS = 0b00;      // Oscillator mode defined by FOSC<2:0>
    //OSCCONbits.IRCF = 0b111;    // Internal RC freq to 8 MHz
    //OSCCONbits.IOFS = 1;        // Int freq is stable
    
    //ANSEL = 0x00;               // Set all I/O to digital I/O
    
    
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
    
    TRISBbits.TRISB3 = 0;
    TRISBbits.TRISB4 = 0;
    TRISBbits.TRISB5 = 0;
    TRISBbits.TRISB6 = 0;
    PORTB = 0;
    
    UARTInit(9600, 1);
}

void main(void) {
    char* readBuf[MAX_LENGTH_UART];
    char* tmpBuf[8];
    int nRead = 0;
    char letra;
    init();
    PORTBbits.RB3 = 1;
    PORTBbits.RB4 = 1;
    PORTBbits.RB5 = 1;
    PORTBbits.RB6 = 1;
    __delay_ms(1000);
    PORTBbits.RB3 = 0;
    PORTBbits.RB4 = 0;
    PORTBbits.RB5 = 0;
    PORTBbits.RB6 = 0;
    //UARTSendString("TOM> \0", MAX_LENGTH_UART);
    int detect_on = 0;
    Servo_Init();   
    int contador = 0;
    //Prendemos el motor
    PORTBbits.RB6 = 1;
    while (1) {
        //Prendemos el motor mientras no corte la barrera IR
        if(PORTAbits.RA3 == 1 && detect_on == 0 ){
            PORTBbits.RB6 = 0; //detenemos motor
            //UARTSendChar("x");
            UARTSendString("x\0", MAX_LENGTH_UART); //iniciamos deteccion
            detect_on = 1;
        }
        
        ////////
        /*
        if (PORTAbits.RA3 == 1){
            if (contador < 1000){
                contador++;
            }            
        }else{
            if (contador > 0){
                contador--;
            }
        }
        if (contador > 1 && detect_on == 0){
            PORTBbits.RB6 = 1;
        }else{
            PORTBbits.RB6 = 0;
            UARTSendString("x\0", MAX_LENGTH_UART); //iniciamos deteccion
            detect_on = 1;
        }
        */
        ///////
        
        if(PORTAbits.RA0 == 1){
            PORTBbits.RB3 = 0;
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
                    PORTBbits.RB3 = 1;
                    Servo_8_Write(0);
                    UARTSendString("y\0", MAX_LENGTH_UART);
                    PORTBbits.RB6 = 1; //Arrancamos motor
                    detect_on = 0;
                    break;
                case 'b':
                    //UARTSendString("\n\rApagando Led \0", MAX_LENGTH_UART);
                    PORTBbits.RB3 = 0;                
                    break;
                case 'c':    
                    //UARTSendString("\n\rPrendiendo Led \0", MAX_LENGTH_UART);
                    PORTBbits.RB4 = 1;
                    Servo_8_Write(90);
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
                    Servo_8_Write(180);
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