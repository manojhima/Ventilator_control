/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: DB_IHM_Setting_Adjust_Vol_Mode_Disco_Delay.c   		          	*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the disconnection delay setting in the Vol mode  					*/
/*                                                            				  		*/
/*%C Delay [min:3000, max:30000, step:1000, default:15000]							*/
/*%C Delay is include in its own limits											  	   */
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTSETUP3.9
Disconnection delay
The software must allow the user to set a disconnection delay.

SFSYSTEV2.33
DISCONNECTION DELAY
the software shall record this event when the DISCONNECTION DELAY is set

SFSYSTCOMDP93.2.48
Disconnection delay
Offset (byte): 58
Format: 8 bits
Data: Disconnection delay
Range: 5 to 62
Unit: s
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
UWORD16 DB_IHM_Setting_Adjust_Vol_Mode_Disco_Delay(UWORD16 *Value,
															 		 UWORD16 Id)
{

/*%C Function result declaration */
   UWORD16 Function_Result = FALSE;
   

/*%C Limit tests */
/*%C Down limit test */
   if (*Value < cDB_VOL_TEST_ADJUST_DB[Id].mini)
   {
   	  *Value = cDB_VOL_TEST_ADJUST_DB[Id].mini;
/*%C  High R flag writing by DB_WriteDataInEepAndRam function call 	*/
//      DB_WriteDataInEepAndRam(&EEP_DB_VOL_Adjust[DISCONNECTION_DELAY_AUTO_U16],
//										TRUE);
	  Function_Result = FALSE;
   }
   else if (*Value > cDB_VOL_TEST_ADJUST_DB[Id].maxi)
   {
		*Value = cDB_VOL_TEST_ADJUST_DB[Id].maxi;
		Function_Result = FALSE;
   }
/*%C If "no select flag" activated => "no select flag" cancelled */
//	else if (EEP_DB_VOL_Adjust[DISCONNECTION_DELAY_AUTO_U16] == TRUE)
//
//	{
//        DB_WriteDataInEepAndRam(&EEP_DB_VOL_Adjust[DISCONNECTION_DELAY_AUTO_U16],
//                                                        FALSE);
//        Function_Result = TRUE;
//
//	}
	else
	{
	}
	return(Function_Result);;
}