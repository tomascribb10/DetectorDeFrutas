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

#define _XTAL_FREQ  4000000     // System clock frequency

#define MAX_LENGTH_UART 16      // Max lenght of a string send or received with UART

void init() {
    // Oscillator config
    //OSCCONbits.SCS = 0b00;      // Oscillator mode defined by FOSC<2:0>
    //OSCCONbits.IRCF = 0b111;    // Internal RC freq to 8 MHz
    //OSCCONbits.IOFS = 1;        // Int freq is stable
    
    //ANSEL = 0x00;               // Set all I/O to digital I/O
    
    CMCONbits.CM0 = 1;
    CMCONbits.CM1 = 1;
    CMCONbits.CM2 = 1;
    
    // Ports config
    TRISBbits.TRISB1 = 0;
    TRISA = 0x00;
    PORTA = 0;
    
    UARTInit(9600, 1);
}

void main(void) {
    char* readBuf[MAX_LENGTH_UART];
    char* tmpBuf[8];
    int nRead = 0;
    char letra;
    init();
    PORTAbits.RA0 = 1;
    PORTAbits.RA1 = 1;
    PORTAbits.RA2 = 1;
    PORTA = 0b00000111;
    while (1) {
        
        // Send prompt
        UARTSendString("> \0", MAX_LENGTH_UART);
        // Read response
        nRead = UARTReadString(readBuf, MAX_LENGTH_UART);
        // Send number of bytes received
        itoa(tmpBuf, nRead, 10);
        UARTSendString("\n\rReceived \0", MAX_LENGTH_UART);
        UARTSendString(tmpBuf, MAX_LENGTH_UART);
        UARTSendString(" bytes: \0", MAX_LENGTH_UART);
        // Send echo of response.
        UARTSendString(readBuf, nRead);
        UARTSendString("\n\r\0", MAX_LENGTH_UART);
        
        //if (readBuf[0] == 'a' ){
        //    UARTSendString("\n\rPrendiendo Led \0", MAX_LENGTH_UART);
        //    PORTAbits.RA0 = 1;
        //}
        //if (readBuf[0] == 'b' ){
        //    UARTSendString("\n\rApagando Led \0", MAX_LENGTH_UART);
        //    PORTAbits.RA0 = 0;
        //}
        letra = readBuf[0];
                
        switch (letra){
            case 'a': 
                UARTSendString("\n\rPrendiendo Led \0", MAX_LENGTH_UART);
                PORTAbits.RA0 = 1;
                break;
            case 'b':
                UARTSendString("\n\rApagando Led \0", MAX_LENGTH_UART);
                PORTAbits.RA0 = 0;                
                break;
            case 'c':    
                UARTSendString("\n\rPrendiendo Led \0", MAX_LENGTH_UART);
                PORTAbits.RA1 = 1;
                break;
            case 'd':
                UARTSendString("\n\rApagando Led \0", MAX_LENGTH_UART);
                PORTAbits.RA1 = 0;
                break;
            case 'e':    
                UARTSendString("\n\rPrendiendo Led \0", MAX_LENGTH_UART);
                PORTAbits.RA2 = 1;  
                break;      
            case 'f':
                UARTSendString("\n\rApagando Led \0", MAX_LENGTH_UART);
                PORTAbits.RA2 = 0;
                break;             
        } 
    }
    
    return;
}