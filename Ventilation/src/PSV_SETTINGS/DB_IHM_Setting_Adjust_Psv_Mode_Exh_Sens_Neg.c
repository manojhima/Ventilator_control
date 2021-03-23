/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Psv_Mode_Exh_Sens_Neg.c   	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the Exh Sens Neg setting in the Psv mode	  							*/
/*                                                            				  		*/
/*%C Exh Sens [min:10, max:90, step:5, default:15]             					*/
/*%C Exh Sens is include in its own limits(otherwise, value is saturated)     */
/*%C Automatic mode is reached by the up key                                  */
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTSET4.20
Exh Sens (negative)
Unit: %
Min Value: -5
Max Value: -95
List of Values: N.A.
Step: 5
Default Value: Auto = -75 output value = -75
Links: N.A.
Auto-adjustement: N.A.
Comments: Available if Esens in setup menu is set to Negative
Auto = -75 output value = -75
Auto is reached by down key
*/

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

UWORD16 DB_IHM_Setting_Adjust_Psv_Mode_Exh_Sens_Neg(UWORD16 *Value,
																	UWORD16 Id)
{

/* Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C  Down limit test 	*/
   if (*Value < cDB_PSV_TEST_ADJUST_DB[Id].mini)
   {
/*%C  Value limited to its min */
      *Value = cDB_PSV_TEST_ADJUST_DB[Id].mini;
/*%C  Auto exh sens flag writing by DB_WriteDataInEepAndRam function call 	*/
      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[AUTO_EXH_SENS_NEG_SELECT_U16],
										TRUE);
		Function_Result = FALSE;
   }			
/*%C Limit tests */
   else if (*Value > cDB_PSV_TEST_ADJUST_DB[Id].maxi)
   {
/*%C  Value limited to its max */
      *Value = cDB_PSV_TEST_ADJUST_DB[Id].maxi;
		Function_Result = FALSE;
   }
/*%C If "Auto exh sens flag" activated => "Auto exh sens flag" cancelled */
	else if (EEP_DB_PSV_Adjust[AUTO_EXH_SENS_NEG_SELECT_U16] == TRUE)
	{
/*%C Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[AUTO_EXH_SENS_NEG_SELECT_U16],
										FALSE);										
		Function_Result = TRUE;
	}
/*%C Setting authorized	 */
   else
   {
      Function_Result = FALSE;
   }

	return(Function_Result);
}
