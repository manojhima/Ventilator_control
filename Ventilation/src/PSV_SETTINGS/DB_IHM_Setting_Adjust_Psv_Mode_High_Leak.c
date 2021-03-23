/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Psv_Mode_High_Leak.c	          			*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the High leak setting in the Psv mode  	   						*/
/*                                                            				  		*/
/*%C HIGH LEAK [min:0 = OFF, max:200, step:5, default:0]      						*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTSET3.18
High leak
Unit: lpm
Min Value: 5
Max Value: 150
List of Values: N.A.
Step: 5
Default Value: OFF (=200) output value = 200
Links: N.A.
Auto-adjustement: N.A.
Comments: available only if no valve is detected
OFF is available upside
OFF = 200 output value = 200

SFSYSTSET4.19
High leak
Unit: lpm
Min Value: 5
Max Value: 150
List of Values: N.A.
Step: 5
Default Value: OFF (=200) output value = 200
Links: N.A.
Auto-adjustement: N.A.
Comments: available only if no valve is detected
OFF is available upside
OFF = 200 output value = 200

SFSYSTEV2.30
HIGH LEAK
the software shall record this event when a new high leak is set

*/

/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/DATABASE/DB_Current.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Adjust_Psv_Mode_High_Leak(UWORD16 *Value,
															   UWORD16 Id)
{

/*%C Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Limit tests */
/*%C Down limit test */
/*%C Up limit test */
   if  (*Value < cDB_PSV_TEST_ADJUST_DB[Id].mini)
   {
		Function_Result = TRUE;
   }
   else if (*Value > cDB_PSV_TEST_ADJUST_DB[Id].maxi)
   {
/*%C  High leak flag writing by DB_WriteDataInEepAndRam function call 	*/
       DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[HIGH_LEAK_SELECT_U16],
										FALSE);
		Function_Result = TRUE;
   }
/*%C If "no select flag" activated => "no select flag" cancelled */
	else if (EEP_DB_PSV_Adjust[HIGH_LEAK_SELECT_U16] == FALSE)
	{
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[HIGH_LEAK_SELECT_U16],
										TRUE);
		Function_Result = TRUE;
	}
   else
   {
/*%C  Setting authorized */
      Function_Result = FALSE;
   }
	return(Function_Result);
}