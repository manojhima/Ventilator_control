/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Pres_Mode_Low_Vte.c  		        		   */
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new limits		*/
/*%C        of the linked settings function of Low Vte conditions     	  		*/
/*                                                            				  		*/
/*%C If Low Vte > High Vte - 20 => High Vte = Low Vte + 20	   				   */
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
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/
UWORD16 DB_IHM_Write_Adjust_Pres_Mode_Low_Vte(UWORD16 *Value)
{

/* Id values recuperation from adjust base in Pres mode */
   UWORD16 Adjust_High_Vte = EEP_DB_PRES_Adjust[ADJUST_HIGH_VTE_U16];

	DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_LOW_VTE_U16],
									*Value);

/*%C High Vte writing */
   if (*Value > Adjust_High_Vte - cLowVteHighVteHysteresis)
   {
	   DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_HIGH_VTE_U16],
									   *Value + cLowVteHighVteHysteresis);
   }

/* In this function the result is always TRUE */
	return(TRUE);
}


 
