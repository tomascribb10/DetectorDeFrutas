/*
 * File:   usarttx.c
 * Author: tomas
 *
 * Created on 13 de julio de 2022, 22:35
 */
// PIC16F628A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>

//#ifndef _XTAL_FREQ
#define _XTAL_FREQ   4000000  // Hz
//#endif


#include <stdio.h>
#include <stdlib.h>
//#include "confbits.h"
#include <xc.h>
#include "uart.h" //incluir la librería

int main(void){
    Init_UART(9600); //inicializar la librería uart a 9600 baudios
    while(1){
        Write_Text_UART("Hola mundo \r\n");
    }
}