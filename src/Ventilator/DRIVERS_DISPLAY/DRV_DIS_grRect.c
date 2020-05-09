/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : DRV_DIS_grRect.c */
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

#include "../GENERAL/typedef.h"
#include "Driver_Display_Data.h"
#include "DRV_DIS_grRect.h"						 
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void DRV_DIS_grRect ( UWORD16 posx1
						  , UBYTE posy1
						  , UWORD16 posx2
						  , UBYTE posy2  )
{
	DRV_DIS_grWriteDisplay(grESC);
	DRV_DIS_grWriteDisplay('R');
	DRV_DIS_grWriteDisplay( posx1>>8);
	DRV_DIS_grWriteDisplay( (UBYTE) posx1);
	DRV_DIS_grWriteDisplay( posy1);
	DRV_DIS_grWriteDisplay( posx2>>8);
	DRV_DIS_grWriteDisplay((UBYTE) posx2);
	DRV_DIS_grWriteDisplay( posy2);
}