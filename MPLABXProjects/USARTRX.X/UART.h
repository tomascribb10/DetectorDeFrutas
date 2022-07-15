/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

/* 
 * File:   UART.h
 * Author: Alex Saucet
 *
 * Created on August 6, 2017, 10:33 AM
 * 
 * Library for UART communication with a 8-bit PIC microcontroller. 
 * Change the values below for the clock frequency and the UART pins used.
 * 
 */

#ifndef UART_H
#define	UART_H

#include <xc.h>
#include <stdint.h>

/****** CHANGE VALUES BELOW ******/
// System clock frequency
#define _XTAL_FREQ  4000000

// Define the pins used
#define UART_TRIS_RX     TRISBbits.TRISB1
#define UART_TRIS_TX     TRISBbits.TRISB2

/**
 * Initialize the UART module with given baud rate and speed mode
 * @param baud_rate
 * @param BRGH speed mode (high speed or low speed)
 */
void UARTInit(const uint32_t baud_rate, const uint8_t BRGH);

/**
 * Send a character
 * @param c character to send
 */
void UARTSendChar(const char c);

/**
 * Send a string, until '\0' is read, up to max_length characters
 * @param str
 * @param max_length
 */
void UARTSendString(const char* str, const uint8_t max_length);

/**
 * Determines whether a new data is available to read
 * @return 
 */
uint8_t UARTDataReady();

/**
 * Read one character
 * @return  byte read
 */
char UARTReadChar();

/**
 * Read a string, until we read '\0', up to max_length characters.
 * @param buf   pre-allocated buffer
 * @param max_length
 * @return number of bytes read
 */
uint8_t UARTReadString(char *buf, uint8_t max_length);

#endif	/* UART_H */

