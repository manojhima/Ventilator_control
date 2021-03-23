/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Psv_Mode_Ti_Max.c        	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the Ti max setting in the Psv mode	        							*/
/*                                                            				  		*/
/*%C Ti max [min:800, max:3000, step:100, default:3000]          					*/
/*%C Apnea Time is include in its own limits(otherwise, value is saturated)   */
/*%C TI_MIN <= TI_MAX                                                         */
/*%C The automatic mode is reached by the up key, a flag is set in this case  */
/*%C and the value is saturated                                               */
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYST7.5
TI MAX = min [TI MAX setting, 30 /R]
If TIMAX is set to auto, the TIMAX must not exceed 3 s.
This applies only in PSV cycles of PSV mode and SIMV modes

SFSYSTSET4.9
TI MAX
Unit: s
Min Value: 0.8
Max Value: 3
List of Values: N.A.
Step: 0
Default Value: Auto = 3s output value = 3s
Links: TI MIN <= TI MAX
Auto-adjustement: N.A.
Comments: Auto is available by the UP KEY
Step is 0.1
Auto = Min [ 3s;(60*1/2)/R]

SFSYSTSET5.9
TI MAX
Unit: s
Min Value: N.A.
Max Value: N.A.
List of Values: N.A.
Step: 0
Default Value: Auto = Min [ 3s;(60*1/2)/R]
Links: N.A.
Auto-adjustement: N.A.
Comments: No comment

SFSYSTSET6.9
TI MAX
Unit: s
Min Value: N.A.
Max Value: N.A.
List of Values: N.A.
Step: 0
Default Value: Auto = Min [ 3s;(60*1/2)/R]
Links: N.A.
Auto-adjustement: N.A.
Comments: No comment

SFSYSTEV2.9
Ti max
the software shall record this event when a new Ti max is set

SFSYSTCOMDP14.2.45
Ti maxi setting
Offset (byte): 090
091
Format: 16 bits
Data: ti max
Range: 800 to 3000
AA AA = not used
Unit: ms

SFSYSTCOMDP93.3.20
Ti maxi setting
Offset (byte): 89
Format: 8 bits
Data: Ti maxi
Range: 8 to 30
Unit: 10-1 s
*/

/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
//#include "DB_IHM_Setting_Adjust_Psv_Mode_Ti_Max.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Adjust_Psv_Mode_Ti_Max(UWORD16 *Value,
                                              UWORD16 Id)
{
/* Function result declaration */
   UWORD16 Function_Result = FALSE;

/* Id values recuperation from adjust base in psv mode */
   UWORD16 Adjust_Ti_Min   = EEP_DB_PSV_Adjust[ADJUST_TI_MIN_U16];
   UWORD16 Ti_Min_Auto_Select   = EEP_DB_PSV_Adjust[TI_MIN_AUTO_SELECT_U16];

/*%C Limit tests */
/*%C Down limit test */
   if (*Value < cDB_PSV_TEST_ADJUST_DB[Id].mini)
   {
/*%C  Value limited to its min */
      *Value = cDB_PSV_TEST_ADJUST_DB[Id].mini;
		Function_Result = FALSE;
   }
/*%C Up limit test */
   else if (*Value > cDB_PSV_TEST_ADJUST_DB[Id].maxi)
   {
/*%C  Value limited to its max */
      *Value = cDB_PSV_TEST_ADJUST_DB[Id].maxi;
/*%C  Auto ti min flag writing by DB_WriteDataInEepAndRam function call 	*/
      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[TI_MAX_AUTO_SELECT_U16],
										TRUE);
		Function_Result = FALSE;
   }
/*%C Dependence test between Ti min and Ti max */
	else if (*Value < Adjust_Ti_Min)
	{
      if (Ti_Min_Auto_Select == FALSE)
      {
/*%C     Value out of range,        */
/*%C     => value saturation        */
         *Value = Adjust_Ti_Min;
/*%C     => Ti max flag for IHM indication */
		   DB_ControlWrite(LIMIT_TI_MIN_U16,
							   TRUE);
      }
		Function_Result = FALSE;
	}
/*%C If "Auto ti min flag" activated => "Auto ti min flag" cancelled */
	else if (EEP_DB_PSV_Adjust[TI_MAX_AUTO_SELECT_U16] == TRUE)
	{
/*%C Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[TI_MAX_AUTO_SELECT_U16],
										FALSE);
		Function_Result = TRUE;
	}
   else
   {
/*%C  Setting authorized, Ti min flag desactivation */
		DB_ControlWrite(LIMIT_TI_MIN_U16,
							 FALSE);
      Function_Result = FALSE;
   }

	return(Function_Result);
}
