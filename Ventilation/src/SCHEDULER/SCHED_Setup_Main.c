/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : SCHED_Setup_Main.c                                             */
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
/*
SFSYSTSETUP2
SET UP MENU
In the SETUP MENU the software must provide following fields :
- machine hours
- language
- date
- time
- intentional vent stop
- pressure unit
- alarm tone
- patient hours
- Restore Defaults
- maintenance
- next
*/

/******************************************************************************/
/*                                INCLUDE FILES		                          */
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/MAIN/Main_Data.h"
#include "../../inc/SCHEDULER/SCHED_Setup_Main.h"

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void SCHED_Setup_Main(void)
{

   if (MAIN_TopTimer5ms == TRUE) 
   {
   	SCHED_Setup_entry();
	  	MAIN_TopTimer5ms = FALSE;
   }

}
