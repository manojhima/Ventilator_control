/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*																			*/
/* Filename	: DB_VersionWrite.c 			   				                  		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the values in the	*/
/*%C         version base																		*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter : 			Id			      	        	                	*/
/*%IO 	Input/Output Parameter : 	None 	        			                  		*/
/*%O 	Output Parameter : 			EEP_DB_Version_Number[Id]    				  		*/
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/DATABASE/DB_VersionWrite.h"
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
void DB_VersionWrite(e_DB_VERSION Id, UWORD16 Value)
{
	if (Id < end_of_db_version_table)
	{
		EEP_DB_Version_Number[Id] = Value;		
      DB_WriteDataInEepAndRam(&EEP_DB_Version_Number[Id], Value);
	
	}


}