/* #include "uart.h"
*
* Creada por: Ing. Abiezer Hernandez O.
* Fecha de creacion: 22/11/2019
* Electronica y Circuitos
*
*/

#include <xc.h>
#define _XTAL_FREQ 48000000

void Uart_Init(unsigned long baud);
short Uart_Available(void);
void Uart_Send_Char(char txData);
void Uart_Send_String(char *info);
char Uart_Read(void);
void Uart_Read_String(char* Buf, unsigned int s_buf);
void Uart_Read_Substring(char* cp, char* vc, int inc, int fn);
void Uart_Read_StringUntil(char stop_c, char* buf, unsigned int st_size);