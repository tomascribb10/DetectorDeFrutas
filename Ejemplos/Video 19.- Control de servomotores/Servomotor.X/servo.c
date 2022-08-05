/* #include "servo.h"
*
* Creada por: Ing. Abiezer Hernandez O.
* Fecha de creacion: 10/01/2021
* Electronica y Circuitos
*
*/

#include "servo.h"

unsigned int cont_sr = 0;
unsigned char data_s[8];

void Servo_Init(void)
{
    #ifdef SERVO_1_PIN
    SERVO_1_DIR = 0;
    SERVO_1_PIN = 0;
    #endif

    #ifdef SERVO_2_PIN
    SERVO_2_DIR = 0;
    SERVO_2_PIN = 0;
    #endif

    #ifdef SERVO_3_PIN
    SERVO_3_DIR = 0;
    SERVO_3_PIN = 0;
    #endif

    #ifdef SERVO_4_PIN
    SERVO_4_DIR = 0;
    SERVO_4_PIN = 0;
    #endif

    #ifdef SERVO_5_PIN
    SERVO_5_DIR = 0;
    SERVO_5_PIN = 0;
    #endif

    #ifdef SERVO_6_PIN
    SERVO_6_DIR = 0;
    SERVO_6_PIN = 0;
    #endif

    #ifdef SERVO_7_PIN
    SERVO_7_DIR = 0;
    SERVO_7_PIN = 0;
    #endif

    #ifdef SERVO_8_PIN
    SERVO_8_DIR = 0;
    SERVO_8_PIN = 0;
    #endif
    
    INTCONbits.GIE = 1;
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
    T0CON = 0x50;
    T0CONbits.TMR0ON = 1;
    TMR0 = 50;
}

#ifdef SERVO_1_PIN
void Servo_1_Write(unsigned char ang)
{
    data_s[0] = (ang-0)*(v_max-v_min)/(180-0)+v_min;
}
#endif

#ifdef SERVO_2_PIN
void Servo_2_Write(unsigned char ang)
{
    data_s[1] = (ang-0)*(v_max-v_min)/(180-0)+v_min;
}
#endif

#ifdef SERVO_3_PIN
void Servo_3_Write(unsigned char ang)
{
    data_s[2] = (ang-0)*(v_max-v_min)/(180-0)+v_min;
}
#endif

#ifdef SERVO_4_PIN
void Servo_4_Write(unsigned char ang)
{
    data_s[3] = (ang-0)*(v_max-v_min)/(180-0)+v_min;
}
#endif

#ifdef SERVO_5_PIN
void Servo_5_Write(unsigned char ang)
{
    data_s[4] = (ang-0)*(v_max-v_min)/(180-0)+v_min;
}
#endif

#ifdef SERVO_6_PIN
void Servo_6_Write(unsigned char ang)
{
    data_s[5] = (ang-0)*(v_max-v_min)/(180-0)+v_min;
}
#endif

#ifdef SERVO_7_PIN
void Servo_7_Write(unsigned char ang)
{
    data_s[6] = (ang-0)*(v_max-v_min)/(180-0)+v_min;
}
#endif

#ifdef SERVO_8_PIN
void Servo_8_Write(unsigned char ang)
{
    data_s[7] = (ang-0)*(v_max-v_min)/(180-0)+v_min;
}
#endif

#ifdef SERVO_HARDWARE
void __interrupt() TMR0_ISR(void)
{
    if(INTCONbits.TMR0IF == 1)
    {
        cont_sr = cont_sr + 1;
        if(cont_sr > 490){
            cont_sr = 0;
        }
        #ifdef SERVO_1_PIN
        if(cont_sr < data_s[0]){SERVO_1_PIN = 1;} else{SERVO_1_PIN = 0;}
        #endif

        #ifdef SERVO_2_PIN
        if(cont_sr < data_s[1]){SERVO_2_PIN = 1;} else{SERVO_2_PIN = 0;}
        #endif

        #ifdef SERVO_3_PIN
        if(cont_sr < data_s[2]){SERVO_3_PIN = 1;} else{SERVO_3_PIN = 0;}
        #endif

        #ifdef SERVO_4_PIN
        if(cont_sr < data_s[3]){SERVO_4_PIN = 1;} else{SERVO_4_PIN = 0;}
        #endif

        #ifdef SERVO_5_PIN
        if(cont_sr < data_s[4]){SERVO_5_PIN = 1;} else{SERVO_5_PIN = 0;}
        #endif

        #ifdef SERVO_6_PIN
        if(cont_sr < data_s[5]){SERVO_6_PIN = 1;} else{SERVO_6_PIN = 0;}
        #endif

        #ifdef SERVO_7_PIN
        if(cont_sr < data_s[6]){SERVO_7_PIN = 1;} else{SERVO_7_PIN = 0;}
        #endif

        #ifdef SERVO_8_PIN
        if(cont_sr < data_s[7]){SERVO_8_PIN = 1;} else{SERVO_8_PIN = 0;}
        #endif
        
        TMR0 = 50;
        INTCONbits.TMR0IF = 0;
    }
}
#endif