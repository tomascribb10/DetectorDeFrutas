/* #include "servo.h"
*
* Creada por: Ing. Abiezer Hernandez O.
* Fecha de creacion: 10/01/2021
* Electronica y Circuitos
*
*/

#include <xc.h>


#define v_min 1
#define v_max 4
#define SERVO_HARDWARE

//#define SERVO_1_PIN PORTBbits.RB0
//#define SERVO_1_DIR TRISBbits.TRISB0

//#define SERVO_2_PIN PORTBbits.RB1
//#define SERVO_2_DIR TRISBbits.TRISB1

//#define SERVO_3_PIN PORTBbits.RB2
//#define SERVO_3_DIR TRISBbits.TRISB2

//#define SERVO_4_PIN LATDbits.LD3
//#define SERVO_4_DIR TRISDbits.RD3

//#define SERVO_5_PIN LATDbits.LD4
//#define SERVO_5_DIR TRISDbits.RD4

//#define SERVO_6_PIN LATDbits.LD5
//#define SERVO_6_DIR TRISDbits.RD5

//#define SERVO_7_PIN LATDbits.LD6
//#define SERVO_7_DIR TRISDbits.RD6

#define SERVO_8_PIN PORTBbits.RB7
#define SERVO_8_DIR TRISBbits.TRISB7

void Servo_Init(void);

#ifdef SERVO_1_PIN
void Servo_1_Write(unsigned char ang);
#endif

#ifdef SERVO_2_PIN
void Servo_2_Write(unsigned char ang);
#endif

#ifdef SERVO_3_PIN
void Servo_3_Write(unsigned char ang);
#endif

#ifdef SERVO_4_PIN
void Servo_4_Write(unsigned char ang);
#endif

#ifdef SERVO_5_PIN
void Servo_5_Write(unsigned char ang);
#endif

#ifdef SERVO_6_PIN
void Servo_6_Write(unsigned char ang);
#endif

#ifdef SERVO_7_PIN
void Servo_7_Write(unsigned char ang);
#endif

#ifdef SERVO_8_PIN
void Servo_8_Write(unsigned char ang);
#endif