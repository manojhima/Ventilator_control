/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Pres_Mode_Rise_Time.c   	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the Rise Time setting in the Pres mode	     							*/
/*                                                            				  		*/
/*%C RISE TIME [min:1, max:4, step:1, default:2]                					*/
/*%C RISE TIME is include in its own limits(otherwise, value is saturated)    */
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYST17
RISE TIME
No text (title)

SFSYST17.1
RISE TIME 1 = 200 ms

SFSYST17.2
RISE TIME 2 = 400 ms

SFSYST17.3
RISE TIME 3 = 600 ms

SFSYST17.4
RISE TIME 4 = 800 ms

SFSYSTEV2.3
Rise Time
the software shall record this event when a new Rise Time is set

SFSYSTSET4.3
RISE TIME
Unit: N.A.
Min Value: 1
Max Value: 4
List of Values: N.A.
Step: 1
Default Value: 2
Links: N.A.
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

UWORD16 DB_IHM_Setting_Adjust_Pres_Mode_Rise_Time(UWORD16 *Value,
																  UWORD16 Id)
{

/* Function result declaration */
   UWORD16 Function_Result = FALSE;
 
/*%C Limit tests */
/*%C Up and down limit test											*/
   if (*Value < cDB_PRES_TEST_ADJUST_DB[Id].mini)
	{
/*%C  Value limited to its min */
	   *Value = cDB_PRES_TEST_ADJUST_DB[Id].maxi;
		Function_Result = FALSE;
	}
   else if (*Value > cDB_PRES_TEST_ADJUST_DB[Id].maxi)
	{
/*%C  Value limited to its max */
	   *Value = cDB_PRES_TEST_ADJUST_DB[Id].mini;   
		Function_Result = FALSE;
   }
   else
   {
/*%C  Setting authorized */
      Function_Result = FALSE;
   }

	return(Function_Result);
}
