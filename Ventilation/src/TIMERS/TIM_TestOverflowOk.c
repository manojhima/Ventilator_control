/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : TIM_TestOverflowOk.c */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C                  																			*/
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
//#include "../GENERAL/io_declare.h"
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/TIMERS/Timer_Data.h"
			 
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

UWORD16 TIM_TestOverflowOk(e_TIM_TABLE_ID offset_table)
{
	if ( (TIM_TableOfCntAndDecnt[offset_table].value == 0) 
	  && (TIM_TableOfCntAndDecnt[offset_table].activate == TRUE) )
	{
		TIM_TableOfCntAndDecnt[offset_table].activate = FALSE;
  		return (TRUE);
	}
	else 
	{
		return (FALSE);
	}
}
