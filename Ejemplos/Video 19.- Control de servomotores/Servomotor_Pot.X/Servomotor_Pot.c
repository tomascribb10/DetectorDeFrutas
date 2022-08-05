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

#include "servo.h"                      // Libreria para control de servomotores
#include "adc.h"                        // Libreria para manejo del ADC
#include "map_function.h"               // Libreria para conversiones

void main()
{
    ADC_Init(AN0_ANALOG);               // Inicializa el ADC
    Servo_Init();                       // Inicializa la funcion de los servos
    
    while(1)
    {
        int valor_pot = ADC_Read(0);
        unsigned char angulo = map(valor_pot, 0, 1023, 0, 180);
        Servo_1_Write(angulo);
    }
}