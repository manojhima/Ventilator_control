/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : DIS_EraseZone.c */
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
#include "DIS_EraseZone.h"
			 
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void DIS_EraseZone( UBYTE startline
						, UWORD16 startcolumn
						, UBYTE endline
						, UWORD16 endcolumn
						, UBYTE printon
						, UBYTE page )
{
	DRV_DIS_grSetPage ( page-1 ) ;

	DRV_DIS_grSetColor ( printon ) ;

	DRV_DIS_grFullRect ( startcolumn, startline, endcolumn, endline ) ;
}
