/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Config_Adjust_High_Spo2.c   	     				*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*
SFSYSTCOMDP93.2.47
High SPO2 alarm.
Offset (byte): 61
Format: 8 bits
Data: SpO2 maxi setting
Range: 90 to 100
Unit: %
*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the High Spo2 setting in the Config base      						*/
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
#include "../../inc/GENERAL/define.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Compute.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
//#include "DB_IHM_Setting_Config_Adjust_High_Spo2.h"

/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Config_Adjust_High_Spo2(UWORD16 *Value,
															 UWORD16 Id)
{

/* Function result declaration */
   UWORD16 Function_Result = FALSE;
   UWORD16 MeasureSpo2 = DB_ComputeRead(MEASURE_SPO2_U16);

/*%C Limit tests */
/*%C Down Limit test */
   if ( (*Value < cDB_TEST_CONFIG_DB[Id].mini)
	  || (*Value > cDB_TEST_CONFIG_DB[Id].maxi) )
	{
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_Config[SPO2_HIGH_SELECT],
										FALSE);
		Function_Result = TRUE;
	}
/*%C Up Limit test */
   else if (*Value < MeasureSpo2 - cDELTA_HIGH_SPO2)
   {
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_Config[SPO2_HIGH_SELECT],
										FALSE);
		DB_ControlWrite(LIMIT_SPO2, TRUE);
		Function_Result = TRUE;
   }
/*%C If "no select flag" activated => "no select flag" cancelled */
	else if (EEP_DB_Config[SPO2_HIGH_SELECT] == FALSE)
	{
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_Config[SPO2_HIGH_SELECT],
										TRUE);
		DB_ControlWrite(LIMIT_SPO2, FALSE);
		Function_Result = TRUE;
	}
   else
   {
/*%C  Setting authorized */
      Function_Result = FALSE;
   }

	return(Function_Result);
}