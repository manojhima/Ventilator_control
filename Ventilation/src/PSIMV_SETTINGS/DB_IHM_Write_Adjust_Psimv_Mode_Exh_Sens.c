/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Psimv_Mode_Exh_Sens.c		    	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new value		*/
/*%C        of the exh sens in the Psimv mode    		    	     						*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/


/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Write_Adjust_Psimv_Mode_Exh_Sens(UWORD16 *Value)
{


/*%C Exh sens value writing  */
	DB_WriteDataInEepAndRam(&EEP_DB_PSIMV_Adjust[ADJUST_EXH_SENS_U16],
								   *Value);						

/*%C Exh sens negative value writing  */
/*%C The sign is only displayed  */
	DB_WriteDataInEepAndRam(&EEP_DB_PSIMV_Adjust[ADJUST_EXH_SENS_NEGATIVE_U16],
								   100 - *Value);						

	if (EEP_DB_PSIMV_Adjust[AUTO_EXH_SENS_SELECT_U16] == TRUE)
	{
      DB_WriteDataInEepAndRam(&EEP_DB_PSIMV_Adjust[AUTO_EXH_SENS_NEG_SELECT_U16],
										TRUE);
/*%C  Value takes default */
      *Value = cDB_PSIMV_TEST_ADJUST_DB[ADJUST_EXH_SENS_U16].defvalue;
/*%C Exh sens value writing  */
		DB_WriteDataInEepAndRam(&EEP_DB_PSIMV_Adjust[ADJUST_EXH_SENS_U16],
									   *Value);
/*%C Exh sens negative value writing  */
/*%C The sign is only displayed  */
		DB_WriteDataInEepAndRam(&EEP_DB_PSIMV_Adjust[ADJUST_EXH_SENS_NEGATIVE_U16],
								   	100 - *Value);
	}
	else
	{
      DB_WriteDataInEepAndRam(&EEP_DB_PSIMV_Adjust[AUTO_EXH_SENS_NEG_SELECT_U16],
										FALSE);
	}	
/*%C This function always return TRUE */
	return(TRUE);
}
