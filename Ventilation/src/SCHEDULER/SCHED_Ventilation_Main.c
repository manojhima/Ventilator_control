/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : SCHED_Ventilation_Main.c                                       */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*
SFSYSTSETUP3.3.1
when the VALIDATION KEY is SHORT PRESS on "Back to ventilation" field, the software must
display the VENTILATION MENU

SFSYSTSETUP3.3.2
the software must switch to the VENTILATION MENU if there is no key activation until 14
seconds or if a high priority alarm occurs or if the ventilation is launched (one press on ventilation
key)
*/

/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C                                              */
/******************************************************************************/
/*%I Input Parameter :  NONE                                                  */
/*%IO Input/Output :    NONE	                                                */
/*%O Output Parameter : NONE                                                  */
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
//#include "../GENERAL/io_declare.h"
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/MAIN/Main_Data.h"
#include "../../inc/SCHEDULER/SCHED_Ventilation_Main.h"

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void SCHED_Ventilation_Main(void)
{
   if (MAIN_TopTimer5ms == TRUE) 
   {
	  	SCHED_Ventilation_entry();
	  	MAIN_TopTimer5ms = FALSE;
   }
}
