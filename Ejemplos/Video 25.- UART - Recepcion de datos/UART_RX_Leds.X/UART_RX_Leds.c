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
    TRISBbits.RB2 = 0;                  // Pin RB2 como salida
    TRISBbits.RB3 = 0;                  // Pin RB3 como salida
    LATBbits.LB2 = 0;
    LATBbits.LB3 = 0;
    Uart_Init(9600);                    // Inicializa la comunicacion serial a 9600 baudios
    
    while(1)
    {
        if(Uart_Available() > 0)        // Verifica si ha recibido datos por el puerto serial
        {
            dato_rx = Uart_Read();      // Lee el dato recibido y lo almacena
            
            switch(dato_rx)             // Comparacion del dato recibido
            {
                case 'a':
                    LATBbits.LB2 = 1;
                    Uart_Send_String("Led 1: Encendido\r\n");
                    break;
                    
                case 'b':
                    LATBbits.LB2 = 0;
                    Uart_Send_String("Led 1: Apagado\r\n");
                    break;
                    
                case 'c':
                    LATBbits.LB3 = 1;
                    Uart_Send_String("Led 2: Encendido\r\n");
                    break;
                    
                case 'd':
                    LATBbits.LB3 = 0;
                    Uart_Send_String("Led 2: Apagado\r\n");
                    break;
            }
        }
    }
}