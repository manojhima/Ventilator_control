/******************************************************************************/
/*																										*/
/* N� du Projet	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Nom du Fichier	: DB_WriteDataInEepAndRam.c						          		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes datas in eeprom 	*/
/*%C        and Ram																				*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter : 			*data_address, value   */
/*%IO Input/Output Parameter : 	None 	        			                  		*/
/*%O 	Output Parameter : 			value			                 				  		*/
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/GENERAL/define.h"
//#include "../EEPROM/Eeprom_Data.h"
#include "../../inc/DATABASE/DB_WriteDataInEepAndRam.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/
//void DB_WriteDataInEepAndRam(UWORD16 xhuge *data_address,UWORD16 value)
void DB_WriteDataInEepAndRam(UWORD16 *data_address,UWORD16 value)
{
	// Ecriture dans la RAM
	*data_address = value;
	// Ecriture dans l'e2prom
	//EEP_FIFO_PushOneData(data_address,WRITE_EEP);
}
