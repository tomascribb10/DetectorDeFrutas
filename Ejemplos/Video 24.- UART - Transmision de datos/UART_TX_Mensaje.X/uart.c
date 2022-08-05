/* #include "uart.h"
*
* Creada por: Ing. Abiezer Hernandez O.
* Fecha de creacion: 22/11/2019
* Electronica y Circuitos
*
*/

#include "uart.h"

void Uart_Init(unsigned long baud)                  // Inicialzia el modulo USART
{
    TRISCbits.RC6 = 0;                              // Pin TX como salida
    TRISCbits.RC7 = 1;                              // Pin RX como entrada
    TXSTA = 0x24;                                   // Configuracion del registro TXSTA
    RCSTA = 0x90;                                   // Configuracion del registro RCSTA
    BAUDCON = 0x00;                                 // Limpia el registro de baudios
    BAUDCONbits.BRG16 = 1;                          // Baudios a 16 bits
    unsigned int vx = (_XTAL_FREQ/(baud*4))-1;
    SPBRG = vx & 0x00FF;                            // Carga los baudios de la parte baja
    SPBRGH = vx >> 8;                               // Carga los baudios de la parte alta
}

short Uart_Available(void)                          // Funcion de verificacion si ha recibido datos
{
    return PIR1bits.RCIF ? 1 : 0;
}

void Uart_Send_Char(char txData)         			// Funcion para transmitir caracteres
{
    while(TXSTAbits.TRMT == 0);
    TXREG = txData;
}

void Uart_Send_String(char *info)          			// Funcion para transmitir una cadena de caracteres
{
    while(*info)
    {
        Uart_Send_Char(*info++);
    }
}

char Uart_Read(void)                        		// Funcion para recibir caracteres
{
    while(PIR1bits.RCIF == 0);
    if(RCSTAbits.OERR == 1)
    {
        RCSTAbits.CREN = 0;
        RCSTAbits.CREN = 1;
    }
    PIR1bits.RCIF = 0;
    return RCREG;
}
                                                    // Funcion para recibir cadenas de caracteres
void Uart_Read_String(char* Buf, unsigned int s_buf)
{
    unsigned int cont_buf = 0;
    char c;
    do
    {
        c = Uart_Read();
        Buf[cont_buf++] = c;
        if(cont_buf >= s_buf) break;
    }while(c != '\n');
    Buf[cont_buf-2] = '\0';
    cont_buf = 0;
}
                                                    // Funcion para descomponer cadenas de caracteres
void Uart_Read_Substring(char* cp, char* vc, int inc, int fn)
{
    int pt = 0;
    for(int lt=inc; lt<=fn; lt++)
    {
        vc[pt] = cp[lt];
        pt++;
    }
    vc[pt] = '\0';
    pt = 0;
}
                                                    // Funcion para descomponer cadenas de caracteres, bit stop
void Uart_Read_StringUntil(char stop_c, char* buf, unsigned int st_size)
{
    unsigned int rx_cont = 0;
    while(*(buf-1) != stop_c)
    {
        rx_cont++;
        *buf++ = Uart_Read();
        if(rx_cont >= st_size) break;
    }
    *--buf = 0;
}