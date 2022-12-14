#include <xc.h>

    // Flash Program Memory Code Protection bit (Code protection off)

#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
     // Internal External Switchover bit (Internal External Switchover mode disabled)

#define _XTAL_FREQ  4000000 

void main()
{
    int cont;
    cont=0;
    
    //LOS REGISTROS TRIS SIRVEN SOLAMENTE PARA CONFIGURAR ENTRADAS Y SALIDAS
    TRISAbits.TRISA0=0;     
    TRISAbits.TRISA1=0;  
    TRISAbits.TRISA2=0;
 
    TRISBbits.TRISB5=0;     
    TRISBbits.TRISB6=0;  
    TRISBbits.TRISB7=0;    
    
    
    #define sal1 PORTAbits.RA0
    #define sal2 PORTAbits.RA1
    #define sal3 PORTAbits.RA2

    
    #define sal4 PORTBbits.RB5
    #define sal5 PORTBbits.RB6
    #define sal6 PORTBbits.RB7

    
    PSA=0;
    T0CS=0;
    PS0=0;
    PS1=0;
    PS2=0;
    T0IF=0;
    TMR0=0;
    
    

    
    //NUMEROS
    
    
//    sal1=0; //NUMERO 0
//    sal2=1;
//    sal2=0;
//    sal1=1;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
    
//    sal1=0; // NUMERO 1
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal1=1;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal1=0;
//    sal2=1;
//    sal2=0;
    
    
//    sal1=1;  // NUMERO 2
//    sal2=1;
//    sal2=0;
//    sal1=0;
//    sal2=1;
//    sal2=0;
//    sal1=1;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal1=0;
//    sal2=1;
//    sal2=0;
//    sal1=1;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
    
    
//    sal1=1;  //NUMERO 3
//    sal2=1;
//    sal2=0;
//    sal1=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal1=1;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
    
//    sal1=1;  //NUMERO 4
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal1=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal1=1;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal1=0;
//    sal2=1;
//    sal2=0;
    
    
//    sal1=1;  //NUMERO 5
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal1=0;
//    sal2=1;
//    sal2=0;
//    sal1=1;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal1=0;
//    sal2=1;
//    sal2=0;
//    sal1=1;
//    sal2=1;
//    sal2=0;
    
    
//    sal1=1;  //NUMERO 6
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal1=0;
//    sal2=1;
//    sal2=0;
//    sal1=1;
//    sal2=1;
//    sal2=0;
    
    
//    sal1=0;  //NUMERO 7
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal1=1;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
    
    
//    sal1=1;  //NUMERO 8
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
    
    
//    sal1=1;  //NUMERO 9
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal1=0;
//    sal2=1;
//    sal2=0;
//    sal1=1;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;
//    sal2=1;
//    sal2=0;

    


     
    CMCON=7;
    
while(1)
{
    
    if(cont==40 || cont==81 || cont==122)
    {
            sal4=0; 
            sal5=0;
            sal6=0;        
    }    

    
    //CONTADOR TOIF 
    
    if(T0IF==1)   
        
        {
            T0IF=0;
            cont=cont+1;
        }
    
    if(cont==123)
        
        {
        cont=0;
        }
    
    
    
    //PRIMER DIGITO
    
    if (cont>=0 && cont<40)
        
       {

            
            sal3=0;

            sal1=0; // NUMERO 1
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;
            sal1=1;
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;
            sal1=0;
            sal2=1;
            sal2=0;

            sal3=1;
            
            sal4=1; //VER PRIMER DIGITO
            sal5=0;
            sal6=0;


        }



    
    
    //SEGUNDO DIGITO
    
    if (cont>=41 && cont<81)
        
        {


            sal3=0;

            sal1=0; //NUMERO 0
            sal2=1;
            sal2=0;
            sal1=1;
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;

            sal3=1;
            
            sal4=0; //VER SEGUNDO DIGITO
            sal5=1;
            sal6=0;
        }
    
    
    //TERCER DIGITO
    
    if (cont>=82 && cont<122)
        
        {


            sal3=0;

            sal1=0; //NUMERO 0
            sal2=1;
            sal2=0;
            sal1=1;
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;
            sal2=1;
            sal2=0;

            sal3=1;
            
            sal4=0; //VER TERCER DIGITO
            sal5=0;
            sal6=1;            
        }    
    
}
   

}
