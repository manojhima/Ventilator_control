/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : DIS_Symbol.c */
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
#include "DIS_Symbol.h"
			 
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void DIS_Symbol( UBYTE symbol, UBYTE line
					, UWORD16 column
					, UBYTE page )
{
#if 0
	// For�age de NON inversion vid�o
	DRV_DIS_grNegative(0) ;

	DRV_DIS_grSetPage ( page-1 ) ;
	
	DRV_DIS_grPutStamp ( symbol, column, line ) ;
#endif
}
