#include <16F628A.h> //Se define el Pic a utilizar
#fuses XT,NOWDT,NOPROTECT //Ordenes para el programador
#use delay (clock=4M) //Frecuencia del oscilador
#use standard_io(b) //Manejo del puerto B
/******************Se declaran los puertos a utilizar***************/
#define Led_B4 PIN_B4
/******************Programa**********************/
void main(){
//Configuración de Puertos//
   set_tris_b(0b00000000);  // Todos los pines como salidas.
//Inicialización de Periféricos//
   output_b(0b00000000);  // Inicializa los pines Apagados

   while(true){      // Ciclo infinito 
      output_high(Led_B4);  
      delay_ms(1000);
      output_low(Led_B4);
      delay_ms(1000);
}
}
