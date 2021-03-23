/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Vol_Mode_High_Vte.c		          		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the High Vte setting in the Vol mode  									*/
/*                                                            				  		*/
/*%C HIGH VTE [min:80, max:3000, step:10, default:OFF=700]   						*/
/*%C HIGH VTE is include in its own limits(otherwise, value is saturated)	   */
/*%C HIGH VTE > VOL CONTROL + 10                                              */
/*%C If the conditions on High Vte is not respected, the value is saturated 	*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTAL46
HIGH VTE
Detection Conditions: when VTE > HIGH VTE
Validation Delay: 3 consecutive cycles
Cancel Conditions: auto
Priority: Medium priority
Audio Pause: yes
Alarm Pause: No
Modes: VOL A/C; PRES A/C; PSV; VOL SIMV; PRES SIMV
Actions: Events HIGH VTE + END OF HIGHVTE
Resetconditions: ventilation change; Ventilation std-by
Replaceventifpersistmessage: No
Circuit: valve

SFSYSTSET2.13
HIGH VTE
Unit: ml
Min Value: 80
Max Value: 3000
List of Values: N.A.
Step: 10
Default Value: 1000
Links: HIGH VTE + 10 >= VOL CONTROL
Auto-adjustement: N.A.
Comments: OFF is available by the UP KEY
output value = 3000

SFSYSTSET3.13
HIGH VTE
Unit: ml
Min Value: 80
Max Value: 3000
List of Values: N.A.
Step: 10
Default Value: 1000
Links: LOW VTE <= HIGH VTE - 20
High Vte >= Vt target +10
Auto-adjustement: N.A.
Comments: OFF is available upside
display only if exhalation valve is detected
OFF (=3000) output value = 3000

SFSYSTSET4.16
HIGH VTE
Unit: ml
Min Value: 80
Max Value: 3000
List of Values: N.A.
Step: 10
Default Value: 1000

SFSYSTSET5.21
HIGH VTE
Unit: ml
Min Value: 80
Max Value: 3000
List of Values: N.A.
Step: 10
Default Value: 1000
Links: HIGH VTE >= VOL CONTROL + 10
Auto-adjustement: N.A.
Comments: OFF is available by the UP KEY

SFSYSTSET6.18
HIGH VTE
Unit: ml
Min Value: 80
Max Value: 3000
List of Values: N.A.
Step: 10
Default Value: 1000
Links: LOW VTE <= HIGH VTE - 20
Auto-adjustement: N.A.
Comments: OFF is available by the UP KEY

SFSYSTEV2.23
High VTE
The software shall record this event when a new HIGH VTE is set

SFSYSTEV3.78
HIGH VTE
The software shall record this event when a HIGH VTE alarm is detected


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
#include "../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode_High_Vte.h"
 
/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Adjust_Vol_Mode_High_Vte(UWORD16 *Value,
															  UWORD16 Id)
{
/*%C Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Id value recovery from adjust base in vol mode */
   UWORD16 Adjust_Vol_Control	= EEP_DB_VOL_Adjust[ADJUST_VOL_CONTROL_U16];

/*%C Up and down limit test											*/
   if (*Value < cDB_VOL_TEST_ADJUST_DB[Id].mini)
   {
		Function_Result = TRUE;
   }
/*%C Up and down limit test											*/
   else if (*Value > cDB_VOL_TEST_ADJUST_DB[Id].maxi)
   {
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_VOL_Adjust[HIGH_VTE_NO_SELECT_U16],
										TRUE);
		Function_Result = TRUE;
   }
   else if (*Value < Adjust_Vol_Control + cVolControlHighVteHysteresis)
   {
/*%C  Vol Control activation */
		DB_ControlWrite(LIMIT_VOL_CONTROL_U16,
							 TRUE);
		Function_Result = TRUE;
   }
/*%C If "no select flag" activated => "no select flag" cancelled */
	else if (EEP_DB_VOL_Adjust[HIGH_VTE_NO_SELECT_U16] == TRUE)
	{
/*%C Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_VOL_Adjust[HIGH_VTE_NO_SELECT_U16],
										FALSE);
/*%C  Vol Control limit flag desactivation */
		DB_ControlWrite(LIMIT_VOL_CONTROL_U16,
							 FALSE);
		Function_Result = TRUE;
	}
/*%C  Value in range  */
   else
   {
/*%C  Vol Control limit flag desactivation */
		DB_ControlWrite(LIMIT_VOL_CONTROL_U16,
							 FALSE);
		Function_Result = FALSE;
   }
   return(Function_Result);
}
