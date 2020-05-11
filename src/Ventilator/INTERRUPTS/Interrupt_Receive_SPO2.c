/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : INTERRUPT_Receive_SPO2.c                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C                                                                          */
/******************************************************************************/
/*%I Input Parameter :  NONE                                                  */
/*%IO Input/Output :    NONE                                                  */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          */
/******************************************************************************/
//#ifndef _TASKING
//	#include "LH_ST10F276.h"
//	#include <intrins.h>
//#else
// 		#include "regf276e.h"
//#endif
#include "../GENERAL/io_stubs.h"
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../SYSTEM/System_Datas.h"



//#ifndef _TASKING
//void INTERRUPT_Receive_SPO2(void) interrupt 0x40
//#else
//interrupt 0x40
void INTERRUPT_Receive_SPO2(void) 
//#endif
{ 
	UWORD16  ReceivedData;
 	static e_FrameUART1  IdxFrameUART1 = 0;

 	ReceivedData = XS1RBUF;
	
	//masquage de la partie haute du buffer de reception
	ReceivedData &= 0x00FF;
	//Raz du flags ASC1 receive interrupt request
	XIR0SEL &= 0xFF7F;
	//D�tection et synchronisation sur d�but de trame (valeur > 127 bit7 toujours = 1)
	if (ReceivedData > 127)
		{
		IdxFrameUART1 = DATA_FRAME0;
		}
 	DataFrameUART1[IdxFrameUART1++] = (UBYTE) ReceivedData;
	IdxFrameUART1 %= SIZE_FRAME_UART1;
}

