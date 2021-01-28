/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: DB_ComputeRead.c 			   				                  		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function reads the values in the	*/
/*%C         compute base																		*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter : 			Id			        			                  	*/
/*%IO Input/Output Parameter :  None                                  		  	*/
/*%O 	Output Parameter : 			DB_Compute[Id]               				  		*/
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"

#include "../../inc/DATABASE/DB_Compute.h"
/******************************************************************************/
/*                     EXTERNAL FUNCTION DECLARATION                         	*/
/******************************************************************************/
UWORD16 DB_ComputeRead(e_DB_COMPUTE Id)
{
/*%C Returns the compute array element value function of Id                  	*/
	return (DB_Compute[Id]);	
}
