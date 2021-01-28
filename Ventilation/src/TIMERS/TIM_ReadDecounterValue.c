/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : TIM_ReadDecounterValue.c */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C                  */
/******************************************************************************/
/*%I Input Parameter :  NONE                                            */
/*%IO Input/Output :    NONE	                                              */
/*%O Output Parameter : NONE       */
/******************************************************************************/
/******************************************************************************/
/*                                INCLUDE FILES		                          */
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/TIMERS/Timer_Data.h"
			 
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

UWORD16 TIM_ReadDecounterValue(e_TIM_TABLE_ID offset_table)
{
	return (TIM_TableOfCntAndDecnt[offset_table].value);
}
