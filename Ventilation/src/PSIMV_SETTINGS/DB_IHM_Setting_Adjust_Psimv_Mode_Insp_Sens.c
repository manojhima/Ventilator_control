/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Psimv_Mode_Insp_Sens.c 	  	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function manages the new Insp 		*/
/*%C        Sens setting                                                  		*/
/*                                                            				  		*/
/*%C INSP SENS [min:OFF=1, max:5, step:1, default:2]      							*/
/*%C INSP SENS is include in its own limits(otherwise, value is saturated)		*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				*Value                                		  	*/
/*%IO Input/Output Parameter : 	None  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTSET2.6
INSP SENS
Unit: N.A.
Min Value: 0P
Max Value: 5
List of Values: N.A.
Step: 1
Default Value: 2
Links: N.A.
Auto-adjustement: N.A.
Comments: OFF available under the minimum value OFF. output value = 0
loop setting.
HIGH R = OFF if INSP SENS = OFF

SFSYSTSET3.6
INSP SENS
Unit: N.A.
Min Value: 0P
Max Value: 5
List of Values: N.A.
Step: 1
Default Value: 2
Links: N.A.
Auto-adjustement: High Rate = OFF if Insp Sens = OFF
Comments: OFF is available only under minimum value OFF. output value =0.
HIGH R = OFF if INSP SENS = OFF
loop setting

SFSYSTSET4.6
INSP SENS
Unit: N.A.
Min Value: 0P
Max Value: 5
List of Values: N.A.
Step: 1
Default Value: 2
Links: N.A.
Auto-adjustement: N.A.
Comments: loop setting.

SFSYSTSET5.7
INSP SENS
Unit: N.A.
Min Value: 0P
Max Value: 5
List of Values: N.A.
Step: 1
Default Value: 2
Links: N.A.
Auto-adjustement: N.A.
Comments: No comment

SFSYSTSET31.7
Insp Sens
Unit: N.A.
Min Value: N.A.
Max Value: N.A.
List of Values: N.A.
Step: 0
Default Value: 2
Links: N.A.
Auto-adjustement: N.A.
Comments: No comment

SFSYSTEV2.6
Insp Sens
the software shall record this event when a new Insp Sens is set

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

UWORD16 DB_IHM_Setting_Adjust_Psimv_Mode_Insp_Sens(UWORD16 *Value,
																   UWORD16 Id)
{
/* Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Limit tests */
   if ((*Value < cDB_PSIMV_TEST_ADJUST_DB[Id].mini)||
      (*Value == (UWORD16) (cDB_PSIMV_TEST_ADJUST_DB[Id].mini - cDB_PSIMV_TEST_ADJUST_DB[Id].step)))   
   {			
/*%C  Value limited to its min */
      *Value = cDB_PSIMV_TEST_ADJUST_DB[Id].maxi;
		Function_Result = FALSE;
	}
   else if (*Value > cDB_PSIMV_TEST_ADJUST_DB[Id].maxi)		
	{
/*%C  Value limited to its max  */
      *Value = cDB_PSIMV_TEST_ADJUST_DB[Id].mini;
		Function_Result = FALSE;
	}
/*%C Setting in range 	*/
   else
   {
		Function_Result = FALSE;
   }

   return(Function_Result);
}
