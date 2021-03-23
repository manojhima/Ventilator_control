/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Pres_Mode_High_Vti.c  		        		   */
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new limits		*/
/*%C        of the linked settings function of High Vte conditions     	  		*/
/*                                                            				  		*/
/*%C If High Vti < Low Vti + 20 => Low Vti = High Vti - 20	   				   */
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTAL4
HIGH VTI
Detection Conditions: when VTI > HIGH VTI
Validation Delay: 3 consecutive cycles
Cancel Conditions: Auto + DISCONNECTION alarm on
Priority: High priority
Audio Pause: yes
Alarm Pause: No
Modes: PRES A/C; PSV; PRES SIMV; CPAP
Actions: Events HIGH VTI + END OF VTI
Resetconditions: ventilation change; Ventilation std-by
Replaceventifpersistmessage: No
Circuit: all

SFSYSTSET3.8
HIGH VTI
Unit: ml
Min Value: 80
Max Value: 3000
List of Values: N.A.
Step: 10
Default Value: 2000
Links: HIGH VTI >= LOW VTI + 20
High Vti >= Vt target + 10
Auto-adjustement: N.A.
Comments: OFF is available upside
OFF = 3000 output value = 3000

SFSYSTSET4.11
HIGH VTI
Unit: ml
Min Value: 80
Max Value: 3000
List of Values: N.A.
Step: 10
Default Value: 2000
Links: HIGH VTI >= LOW VTI + 20
High Vti >= Vt target + 10
Auto-adjustement: N.A.
Comments: OFF is available by the UP KEY
OFF (=3000) output value = 3000

SFSYSTSET6.13
HIGH VTI
Unit: ml
Min Value: 80
Max Value: 3000
List of Values: N.A.
Step: 10
Default Value: 2000
Links: HIGH VTI >= LOW VTI + 20
Auto-adjustement: N.A.
Comments: OFF is available by the UP KEY

SFSYSTSET31.4
HIGH VTI
Unit: ml
Min Value: 80
Max Value: 3000
List of Values: N.A.
Step: 10
Default Value: 2000
Links: LOW VTI <= HIGH VTI - 20
Auto-adjustement: N.A.
Comments: OFF is reached upside
OFF (=3000) output value = 3000

SFSYSTEV2.16
High VTI
the software shall record this event when a new High VTI is set
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
UWORD16 DB_IHM_Write_Adjust_Pres_Mode_High_Vti(UWORD16 *Value)
{

/* Id values recuperation from adjust base in Pres mode */
   UWORD16 Adjust_Low_Vti = EEP_DB_PRES_Adjust[ADJUST_LOW_VTI_U16];
   UWORD16 Low_Vti_No_Select = EEP_DB_PRES_Adjust[LOW_VTI_NO_SELECT_U16];

	DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_HIGH_VTI_U16],
									*Value);

/*%C Low Vti writing */
   if ( (*Value < Adjust_Low_Vti + cLowVtiHighVtiHysteresis)
	  && (Low_Vti_No_Select == TRUE) )
   {
	   DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_LOW_VTI_U16],
									   *Value - cLowVtiHighVtiHysteresis);
   }

/* In this function the result is always TRUE */
	return(TRUE);
}




 
