/* #include "adc.h"
*
* Creada por: Ing. Abiezer Hernandez O.
* Fecha de creacion: 16/02/2021
* Electronica y Circuitos
*
*/

#include "adc.h"

void ADC_Init(unsigned char p_ang)
{
    ADCON1 = p_ang;
    ADCON0 = 0x00;
    ADCON2 = 0x8F;
}

unsigned int ADC_Read(unsigned char ch)
{
    if(ch > 13){
        return 0;
    }else{
        ADCON0 = 0x00;
        ADCON0 = (ch << 2);
        ADCON0bits.ADON = 1;
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE == 1);
        return ADRES;
    }
}