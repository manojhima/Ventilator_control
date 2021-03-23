/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Psv_Mode_High_Vte.c		          		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the High Vte setting in the Psv mode 									*/
/*                                                            				  		*/
/*%C HIGH VTE [min:80, max:3000, step:10, default:OFF=2000]   						*/
/*%C HIGH VTE is include in its own limits(otherwise, value is saturated)	   */
/*%C HIGH VTE > LOW VTE + 20                                                  */
/*%C HIGH VTE > TARGET VT + 10      	                                       */
/*%C If the conditions on High Vte or targer Vt are not respected,				*/
/*%C the values are saturated 																*/
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
//#include "DB_IHM_Setting_Adjust_Psv_Mode_High_Vte.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Adjust_Psv_Mode_High_Vte(UWORD16 *Value,
															    UWORD16 Id)
{
/*%C Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Id value recovery from adjust base in pres mode */
   UWORD16 Adjust_Low_Vte	= EEP_DB_PSV_Adjust[ADJUST_LOW_VTE_U16];
   UWORD16 Low_Vte_No_Select	= EEP_DB_PSV_Adjust[LOW_VTE_NO_SELECT_U16];
/*%C Id value recovery from adjust base in pres mode */
   UWORD16 Adjust_Target_Vt	= EEP_DB_PSV_Adjust[ADJUST_TARGET_VT_U16];
   UWORD16 Target_Vt_Select = EEP_DB_PSV_Adjust[TARGET_VT_SELECT_U16];

/*%C Down limit test */
   if (*Value < cDB_PSV_TEST_ADJUST_DB[Id].mini)
   {
		Function_Result = TRUE;
   }
   else if (*Value > cDB_PSV_TEST_ADJUST_DB[Id].maxi)  
   {
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[HIGH_VTE_NO_SELECT_U16],
										TRUE);
		Function_Result = TRUE;
   }
/*%C Down limit test */
   else if ( (*Value < Adjust_Low_Vte + cLowVteHighVteHysteresis)
			 && (Low_Vte_No_Select == FALSE) )
   {
/*%C     => Low vte flag for IHM indication */
	   DB_ControlWrite(LIMIT_LOW_VTE_U16,
	      		   TRUE);
	   Function_Result = TRUE;
   }
/*%C Down limit test */
   else if ( (*Value < Adjust_Target_Vt + cHighVteTargetVtHysteresis)
          && (Target_Vt_Select == TRUE) )
   {
/*%C  High Vte flag writing by DB_WriteDataInEepAndRam function call 	*/
      /*DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_TARGET_VT_U16],
									   Adjust_Target_Vt - cHighVteTargetVtHysteresis);	  */
/*%C  => Target Vt flag for IHM indication */
	   DB_ControlWrite(LIMIT_TARGET_VT_U16,
						   TRUE);
	   Function_Result = TRUE;
   }
/*%C If "no select flag" activated => "no select flag" cancelled */
	else if (EEP_DB_PSV_Adjust[HIGH_VTE_NO_SELECT_U16] == TRUE)
	{
/*%C Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[HIGH_VTE_NO_SELECT_U16],
										FALSE);
/*%C  Low vte flag limit desactivation */
		DB_ControlWrite(LIMIT_LOW_VTE_U16,
							 FALSE);
/*%C  Target Vt flag desactivation */
	   DB_ControlWrite(LIMIT_TARGET_VT_U16,
						   FALSE);
		Function_Result = TRUE;
	}
/*%C  Value in range  */
   else
   {
/*%C  Low vte flag limit desactivation */
		DB_ControlWrite(LIMIT_LOW_VTE_U16,
							 FALSE);
/*%C  Target Vt flag desactivation */
	   DB_ControlWrite(LIMIT_TARGET_VT_U16,
						   FALSE);
		Function_Result = FALSE;
   }
   return(Function_Result);
}
