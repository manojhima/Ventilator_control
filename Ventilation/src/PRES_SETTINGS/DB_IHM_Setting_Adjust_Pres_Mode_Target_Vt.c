/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Pres_Mode_Target_Vt.c     	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*
SFSYSTEV2.27
Vt target
the software shall record this event when a new Vt target is set

SFSYSTCOMDP14.2.26
Vt Target setting
Offset (byte): 052
053
Format: 16 bits
Data: target vt
Range: 50 to 2000
AA AA = not used
Unit: ml

SFSYSTCOMDP93.3.11
Vt Target setting
Offset (byte): 75
76
Format: 2*8 bits
Data: Vt Target
Range: 0 to 2000
Unit: ml

SFSYSTCOMDP93.4.11
Vt Target setting
Offset (byte): 75
76
Format: 2*8 bits
Data: Vt Target
Range: 0 to 2000
Unit: ml
*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the Target VT setting in the Psv mode	     							*/
/******************************************************************************/
/*%C TARGET VT [min:50, max:2000, step:10, default:1000]         					*/
/*%C TARGET VT is include in its own limits(otherwise, value is saturated)    */
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

UWORD16 DB_IHM_Setting_Adjust_Pres_Mode_Target_Vt(UWORD16 *Value,
																  UWORD16 Id)
{

/* Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Limit tests */
/*%C Down Limit test */
   if (*Value < cDB_PRES_TEST_ADJUST_DB[Id].mini)
	{
/*%C  Value limited to its min */
      *Value = cDB_PRES_TEST_ADJUST_DB[Id].mini;
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[TARGET_VT_SELECT_U16],
										FALSE);
		Function_Result = FALSE;
	}
/*%C Up Limit test */
   else if (*Value > cDB_PRES_TEST_ADJUST_DB[Id].maxi)
   {
/*%C  Value limited to its max */
      *Value = cDB_PRES_TEST_ADJUST_DB[Id].maxi;
      Function_Result = FALSE;
   }
/*%C If "no select flag" activated => "no select flag" cancelled */
	else if (EEP_DB_PRES_Adjust[TARGET_VT_SELECT_U16] == FALSE)
	{
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[TARGET_VT_SELECT_U16],
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
