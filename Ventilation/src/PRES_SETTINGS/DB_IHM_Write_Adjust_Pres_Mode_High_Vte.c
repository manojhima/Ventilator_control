/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Pres_Mode_High_Vte.c  		        		   */
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new limits		*/
/*%C        of the linked settings function of High Vte conditions     	  		*/
/*                                                            				  		*/
/*%C If High Vte < Low Vte + 20 => Low Vte = High Vte - 20	   				   */
/*                                                            				  		*/
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
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/
UWORD16 DB_IHM_Write_Adjust_Pres_Mode_High_Vte(UWORD16 *Value)
{

/* Id values recuperation from adjust base in Pres mode */
   UWORD16 Adjust_Low_Vte = EEP_DB_PRES_Adjust[ADJUST_LOW_VTE_U16];
   UWORD16 Low_Vte_No_Select	= EEP_DB_PRES_Adjust[LOW_VTE_NO_SELECT_U16];

	DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_HIGH_VTE_U16],
									*Value);

/*%C Low Vte writing */
   if ( (*Value < Adjust_Low_Vte + cLowVteHighVteHysteresis)
	  && (Low_Vte_No_Select == TRUE) )
   {
	   DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_LOW_VTE_U16],
									   *Value - cLowVteHighVteHysteresis);
   }

/* In this function the result is always TRUE */
	return(TRUE);
}



 
