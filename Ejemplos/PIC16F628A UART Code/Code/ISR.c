#include "Includes.h"



void interrupt ISR(void)
{
	if(RCIF)  // If UART Rx Interrupt
	{
		if(OERR) // If over run error, then reset the receiver
		{
			CREN = 0;
			CREN = 1;
		}

		SendByteSerially(RCREG);	// Echo back received char
	}
}