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
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/define.h"
#include "../GENERAL/Structure.h"
#include "../DRIVERS/DRV_VarEeprom.h"
#include "../DATABASE/DB_Control.h"
#include "../DATABASE/DB_Rtc.h"
#include "../DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
//#include "DB_IHM_Write_Config_Adjust_Fio2.h"

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
