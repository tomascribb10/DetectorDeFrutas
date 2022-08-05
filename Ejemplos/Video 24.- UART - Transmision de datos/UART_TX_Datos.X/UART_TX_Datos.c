#pragma config PLLDIV = 2, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, BORV = 3, VREGEN = OFF
#pragma config WDT = OFF
#pragma config WDTPS = 32768
#pragma config CCP2MX = ON, PBADEN = OFF, LPT1OSC = OFF, MCLRE = ON
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF
#pragma config CPB = OFF, CPD = OFF
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF
#pragma config WRTC = OFF, WRTB = OFF, WRTD = OFF
#pragma config EBTR0 = OFF, EBTR1 = OFF, EBTR2 = OFF, EBTR3 = OFF
#pragma config EBTRB = OFF

#define _XTAL_FREQ 48000000
#include <xc.h>
#include <stdio.h>

#include "adc.h"                        // Libreria del ADC
#include "uart.h"                       // Libreria del modulo USART

char buffer[30];

void main()
{
    ADC_Init(AN0_AN1_ANALOG);           // Inicializa el ADC
    Uart_Init(9600);                    // Inicializa la comunicacion serial a 9600 baudios
    
    while(1)
    {
        int valor_ch0 = ADC_Read(0);
        int valor_ch1 = ADC_Read(1);
        
        /*sprintf(buffer, "ADC CH0: %u", valor_ch0);
        Uart_Send_String(buffer);
        Uart_Send_String(" , ");
        sprintf(buffer, "ADC CH1: %u", valor_ch1);
        Uart_Send_String(buffer);
        Uart_Send_String("\r\n");*/
        
        sprintf(buffer, "ADC CH0: %u , ADC CH1: %u\r\n", valor_ch0, valor_ch1);
        Uart_Send_String(buffer);
        __delay_ms(100);
    }
}