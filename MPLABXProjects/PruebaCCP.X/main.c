#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)



#define _XTAL_FREQ 4000000

#include <xc.h>
#include <stdio.h>

#include "lcd.h"

unsigned int valor_pasos;
unsigned int frecuencia;
unsigned int in;
float periodo;
char buffer[20];

void main()
{
    TRISBbits.TRISB3 = 1;
    //ADCON1bits.PCFG = 0x0F;         // Coloca todos los pines como digitales
    INTCONbits.GIE = 1;             // Habilita las interrupciones globales
    INTCONbits.PEIE = 1;            // Habilita las interrupciones de perifericos
    PIE1bits.CCP1IE = 1;            // Habilita la interrupcion del CCP1
    PIR1bits.CCP1IF = 0;            // Flag 0
    T1CON = 0b00000000;                   // Configura el timer 1
    TMR1L = 0x00;
    TMR1H = 0x00;
    CCP1CON = 0x05;                 // Configura el CCP1 en modo captura
    T1CONbits.TMR1ON = 1;           // Habilita el timer 1
    Lcd_Init();                     // Inicializa la pantalla LCD
    
    
    while(1)
    {
        if(in == 1){
            periodo = valor_pasos * 0.000001;
            frecuencia = 1 / periodo;
            in = 0;
        }
        //buffer = "Hola";
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        //sprintf(buffer, "T: %f", periodo);
        sprintf(buffer, "P: %u", valor_pasos);
        Lcd_Write_String(buffer);
        Lcd_Set_Cursor(2,1);
        sprintf(buffer, "F: %u", frecuencia);
        Lcd_Write_String(buffer);
        __delay_ms(100);
    }
}

void __interrupt() INT_CCP1()       // Interrupcion del CCP1
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
}