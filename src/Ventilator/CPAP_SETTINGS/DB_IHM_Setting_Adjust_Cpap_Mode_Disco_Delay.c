/******************************************************************************/
/*																										*/
/* Project Number	: 	RBO5O5     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: DB_IHM_Setting_Adjust_Cpap_Mode_Disco_Delay.c  		          	*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the disconnection delay setting in the Vsimv mode  				*/
/*                                                            				  		*/
/*%C Delay [min:3000, max:30000, step:1000, default:16000]							*/
/*%C Delay is include in its own limits											  	   */
/*                                                            				  		*/
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
#include "../GENERAL/Structure.h"
#include "../DRIVERS/DRV_VarEeprom.h"
#include "../DATABASE/DB_Current.h"
#include "../DATABASE/DB_Control.h"
#include "../DATABASE/DB_Rtc.h"
#include "../DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

/* locate database code to specific section */
#include "../GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/
UWORD16 DB_IHM_Setting_Adjust_Cpap_Mode_Disco_Delay(UWORD16 *Value,
															 		 UWORD16 Id)
{

/*%C Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Limit tests */
/*%C Down limit test */
   if (*Value < cDB_CPAP_TEST_ADJUST_DB[Id].mini)
   {
   	  *Value = cDB_CPAP_TEST_ADJUST_DB[Id].mini;
/*%C  High R flag writing by DB_WriteDataInEepAndRam function call 	*/
//      DB_WriteDataInEepAndRam(&EEP_DB_CPAP_Adjust[DISCONNECTION_DELAY_AUTO_U16],
//										TRUE);
	  Function_Result = FALSE;
   }
   else if (*Value > cDB_CPAP_TEST_ADJUST_DB[Id].maxi)
   {
		*Value = cDB_CPAP_TEST_ADJUST_DB[Id].maxi;
		Function_Result = FALSE;
   }
/*%C If "no select flag" activated => "no select flag" cancelled */
//	else if (EEP_DB_CPAP_Adjust[DISCONNECTION_DELAY_AUTO_U16] == TRUE)
//
//	{
//        DB_WriteDataInEepAndRam(&EEP_DB_CPAP_Adjust[DISCONNECTION_DELAY_AUTO_U16],
//                                                        FALSE);
//        Function_Result = TRUE;
//
//	}
	else
	{
	}
	return(Function_Result);
}
