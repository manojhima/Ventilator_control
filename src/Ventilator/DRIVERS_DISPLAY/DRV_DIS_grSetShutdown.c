/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : DRV_DIS_grSetShutdown.c */
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
#include "DRV_DIS_grSetShutdown.h"						 
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void DRV_DIS_grSetShutdown ( UBYTE etat )
{
	DRV_DIS_grWriteDisplay(grESC);
	DRV_DIS_grWriteDisplay('V');
	DRV_DIS_grWriteDisplay(etat);
}