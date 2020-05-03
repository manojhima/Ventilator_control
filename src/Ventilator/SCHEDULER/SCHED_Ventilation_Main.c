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
#ifndef _TASKING
#include "LH_ST10F276.h"
#include <intrins.h>
#else
#include "regf276e.h"
#endif	
#include "../GENERAL/io_declare.h"
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../MAIN/Main_Data.h"
#include "../SCHEDULER/SCHED_Ventilation_Main.h"

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
