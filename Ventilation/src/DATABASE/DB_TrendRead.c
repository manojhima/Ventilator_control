/******************************************************************************/
/*														  					  */
/* Project Number	: 	RB0505     			     		                      */
/*																			  */
/*----------------------------------------------------------------------------*/
/*                                                                 			  */
/* Filename	: DB_TrendRead.c 			   				                  	  */
/*                                                           				  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 		Functional description : 	this function reads the values in the */
/*%C        trend base														  */
/*                                                            				  */
/******************************************************************************/
/*%I 	Input Parameter : 			Id			      	                      */
/*%IO 	Input/Output Parameter : 	None 	        			              */
/*%O 	Output Parameter : 			EEP_DB_TREND[Id]            			  */
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          */
/******************************************************************************/
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
//#include "../DRIVERS/DRV_VarEeprom.h"

/******************************************************************************/
/*                     EXTERNAL FUNCTION DECLARATION                          */
/******************************************************************************/
UWORD16  EEP_DB_TREND[];


UWORD16 DB_TrendRead(e_DB_Trend Id)
{
/*%C Returns the trend array element value function of Id                   */
	return (EEP_DB_TREND[Id]);	
}
