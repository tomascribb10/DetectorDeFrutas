/* #include "adc.h"
*
* Creada por: Ing. Abiezer Hernandez O.
* Fecha de creacion: 16/02/2021
* Electronica y Circuitos
*
*/

#include <xc.h>
#define _XTAL_FREQ 48000000

#define AN0_ANALOG          0x0E
#define AN0_AN1_ANALOG      0x0D
#define AN0_TO_AN2_ANALOG   0x0C
#define AN0_TO_AN3_ANALOG   0x0B
#define AN0_TO_AN4_ANALOG   0x0A
#define AN0_TO_AN5_ANALOG   0x09
#define AN0_TO_AN6_ANALOG   0x08
#define AN0_TO_AN7_ANALOG   0x07
#define AN0_TO_AN8_ANALOG   0x06
#define AN0_TO_AN9_ANALOG   0x05
#define AN0_TO_AN10_ANALOG  0x04
#define AN0_TO_AN11_ANALOG  0x03
#define ALL_ANALOG          0x00

void ADC_Init(unsigned char p_ang);
unsigned int ADC_Read(unsigned char ch);