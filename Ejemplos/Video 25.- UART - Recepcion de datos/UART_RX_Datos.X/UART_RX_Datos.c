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

#include "uart.h"                       // Libreria del modulo USART

char dato_rx;                           // Almacena el dato recibido por el puerto serial

void main()
{
    ADCON1bits.PCFG = 0x0F;             // Coloca todos los pines como digitales
    Uart_Init(9600);                    // Inicializa la comunicacion serial a 9600 baudios
    
    while(1)
    {
        if(Uart_Available() > 0)        // Verifica si ha recibido datos por el puerto serial
        {
            dato_rx = Uart_Read();      // Lee el dato recibido y lo almacena
            
            Uart_Send_String("Dato recibido: ");
            Uart_Send_Char(dato_rx);
            Uart_Send_String("\r\n");
        }
    }
}