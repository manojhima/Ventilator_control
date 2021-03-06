/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : INTERRUPT_STKUF_trap.c 	  													*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C             Stack underflow interrupt												*/
/******************************************************************************/
/*%I Input Parameter :  NONE                                            		*/
/*%IO Input/Output :    NONE	                                              	*/
/*%O Output Parameter : NONE       															*/
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          */
/******************************************************************************/
//#ifndef _TASKING
//#include "LH_ST10F276.h"
//#include <intrins.h>
//#else
//#include "regf276e.h"
//#endif
#include "../GENERAL/typedef.h"
#include "../GENERAL/io_declare.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../TIMERS/Timer_Data.h"
					 
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

//#ifndef _TASKING
//void INTERRUPT_STKUF_trap(void) interrupt 0x06
//#else
//interrupt (0x06)
 void INTERRUPT_STKUF_trap(void)
//#endif
{
   while (1) 
  	{ 
	ARRET_INVOLONTAIRE = 1;
  	_srvwdt_();
	WDOG =! WDOG;
   }              
}
