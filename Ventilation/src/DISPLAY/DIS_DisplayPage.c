/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : DIS_DisplayPage.c */
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
//#include "../DRIVERS_DISPLAY/Driver_Display_Data.h"
#include "DIS_DisplayPage.h"
			 
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
#define PAGE1				1
#define PAGE2				2

void DIS_DisplayPage( UBYTE page, UBYTE mode )
{
#if 0
	if (page == PAGE1)
		{
		DRV_DIS_grControlPage ( 0, 1 ) ;
		DRV_DIS_grControlPage ( 0, 2 ) ;
		DRV_DIS_grControlPage ( mode, page-1 ) ;
		}
	else if (page == PAGE2)
		{
		DRV_DIS_grControlPage ( 0, 0 ) ;
		DRV_DIS_grControlPage ( 0, 2 ) ;
		DRV_DIS_grControlPage ( mode, page-1 ) ;
		}
	else
		{
		DRV_DIS_grControlPage ( 0, 0 ) ;
		DRV_DIS_grControlPage ( 0, 1 ) ;
		DRV_DIS_grControlPage ( mode, page-1 ) ;
		}
#endif
}
