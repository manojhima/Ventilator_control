/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Vsimv_Mode_Low_Vte.c		          		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the Low_Vte setting in the Vsimv mode 									*/
/*                                                            				  		*/
/*%C LOW VTE [min:30, max:2000, step:10, default:OFF=300]  							*/
/*%C LOW VTE is include in its own limits(otherwise, value is saturated)	   */
/*%C LOW VTE <= VOL_CONTROL - 10	                                             */
/*%C If the conditions on Vol Control is not respected,                       */
/*%C a limit flag is set for IHM indication and the value is saturated        */
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTAL6
LOW VTE
Detection Conditions: when VTE < LOW VTE
Validation Delay: 3 consecutive cycles
Cancel Conditions: Auto + DISCONNECTION alarm on
Priority: Medium priority
Audio Pause: yes
Alarm Pause: No
Modes: VOL A/C; PRES A/C; PSV; VOL SIMV; PRES SIMV
Actions: Events LOW VTE + END OF LOW VTE
Resetconditions: ventilation change; Ventilation std-by
Replaceventifpersistmessage: No
Circuit: valve

SFSYSTSET2.9
LOW VTE
Unit: ml
Min Value: 30
Max Value: 1990
List of Values: N.A.
Step: 10
Default Value: 300
Links: LOW VTE <= VOL CONTROL - 10
Auto-adjustement: N.A.
Comments: OFF is available by the DOWN KEY.
OFF (=30), output value 30
exhalation spirometer calibration available after validation of this setting

SFSYSTSET3.9
LOW VTE
Unit: ml
Min Value: 30
Max Value: 1990
List of Values: N.A.
Step: 10
Default Value: 300
Links: LOW VTE <= HIGH VTE - 20
Low vte <= Vt target - 10
Auto-adjustement: N.A.
Comments: OFF is available downside
display only if exhalation valve is detected
OFF ( =30) output value = 30

SFSYSTSET4.12
LOW VTE
Unit: ml
Min Value: 30
Max Value: 1990
List of Values: N.A.
Step: 10
Default Value: 300
Links: LOW VTE <= HIGH VTE - 20
Low Vte <= Vt target - 10
Auto-adjustement: N.A.
Comments: OFF is available by the DOWN KEY
available only if a valve is detected
OFF (=30) output value =30

SFSYSTSET5.17
LOW VTE
Unit: ml
Min Value: 30
Max Value: 1990
List of Values: N.A.
Step: 10
Default Value: 300
Links: LOW VTE <= VOL CONTROL - 10
Auto-adjustement: N.A.
Comments: OFF is available by the DOWN KEY

SFSYSTSET6.14
LOW VTE
Unit: ml
Min Value: 30
Max Value: 1990
List of Values: N.A.
Step: 10
Default Value: 300
Links: LOW VTE <= HIGH VTE - 20
Auto-adjustement: N.A.
Comments: OFF is available by the DOWN KEY

SFSYSTEV2.17
Low VTE
the software shall record this event when a new Low VTE is set

SFSYSTEV3.15
LOW VTE
the software shall record this event when the LOW VTE alarm is detected

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
#include "../../inc/VSIMV_SETTINGS/DB_IHM_Setting_Adjust_Vsimv_Mode_Low_Vte.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Adjust_Vsimv_Mode_Low_Vte(UWORD16 *Value,
															    UWORD16 Id)
{
/*%C Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Id values recuperation from adjust base in Vsimv mode */
   UWORD16 Adjust_Vol_Control = EEP_DB_VSIMV_Adjust[ADJUST_VOL_CONTROL_U16];


/*%C Limit tests */
   if (*Value < cDB_VSIMV_TEST_ADJUST_DB[Id].mini)
   {
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[LOW_VTE_NO_SELECT_U16],
										TRUE);
      Function_Result = TRUE;
   }
   else if (*Value > cDB_VSIMV_TEST_ADJUST_DB[Id].maxi)
   {
      Function_Result = TRUE;
   }
   else if (*Value > Adjust_Vol_Control - cVolControlLowVteHysteresis)
	{
/*%C  => High vte flag for IHM indication */
		DB_ControlWrite(LIMIT_VOL_CONTROL_U16,
							 TRUE);
      Function_Result = TRUE;
	}
/*%C If "no select flag" activated => "no select flag" cancelled */
	else if (EEP_DB_VSIMV_Adjust[LOW_VTE_NO_SELECT_U16] == TRUE)
	{
		DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[LOW_VTE_NO_SELECT_U16],
										FALSE);										
/*%C  High vte and vol control flag desactivation */
		DB_ControlWrite(LIMIT_VOL_CONTROL_U16,
							 FALSE);
		Function_Result = TRUE;
	}
/*%C  Value in range  */
   else
   {
/*%C  High vte and vol control flag desactivation */
		DB_ControlWrite(LIMIT_VOL_CONTROL_U16,
							 FALSE);
		Function_Result = FALSE;
   }

   return(Function_Result);
}
