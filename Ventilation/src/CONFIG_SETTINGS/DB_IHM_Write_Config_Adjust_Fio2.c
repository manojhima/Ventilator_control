/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Config_Adjust_Fio2.c  	    	       				*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*
SFSYSTCOMDP93.2.39
FIO2 setting
Offset (byte): 62
Format: 8 bits
Data: FIO2
Range: 0 to 99
Unit: %

SFSYSTCOMDP93.2.40
FiO2 min setting
Offset (byte): 63
Format: 8 bits
Data: FiO2 mini
Range: 0 to 99
Unit: %

SFSYSTCOMDP93.2.41
FiO2 max setting
Offset (byte): 64
Format: 8 bits
Data: FiO2 maxi
Range: 0 to 99
Unit: %
*/
/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the 					*/
/*%C        Fio2 setting and its dependancies in the Config base 					*/
/*																										*/
/*%C FIO2 mini = Fio2 - 15 												 					*/
/*%C FIO2 maxi = Fio2 + 15 												 					*/
/*																										*/
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
#include "../../inc/GENERAL/define.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
//#include "../../inc/CONFIG_SETTINGS/DB_IHM_Write_Config_Adjust_Fio2.h"

/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Write_Config_Adjust_Fio2(UWORD16 *Value)
{

/* Function result declaration */
   UWORD16 Function_Result = FALSE;


/*%C Adjust Fio2 writing */
	DB_WriteDataInEepAndRam(&EEP_DB_Config[ADJUST_FIO2],
									*Value);
/*%C Adjust Low Fio2 writing */
	DB_WriteDataInEepAndRam(&EEP_DB_Config[ADJUST_LOW_FIO2],
									*Value - cDELTA_LOW_FIO2);

/*%C Adjust High Fio2 writing */
	DB_WriteDataInEepAndRam(&EEP_DB_Config[ADJUST_HIGH_FIO2],
									*Value + cDELTA_HIGH_FIO2);

   Function_Result = TRUE;

	return(Function_Result);
}
