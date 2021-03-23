/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Pres_Mode_Low_Vti.c  		        		   */
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new limits		*/
/*%C        of the linked settings function of Low Vte conditions     	  		*/
/*                                                            				  		*/
/*%C If Low Vti > High Vti - 20 => High Vti = Low Vti + 20	   				   */
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
1) SFSYSTAL5
LOW VTI
Detection Conditions: when VTI < LOW VTI
Validation Delay: 3 consecutive cycles
Cancel Conditions: Auto + DISCONNECTION alarm on
Priority: Medium priority
Audio Pause: yes
Alarm Pause: No
Modes: PRES A/C; PSV; PRES SIMV; CPAP
Actions: Events LOW VTI + END OF LOW VTI
Resetconditions: ventilation change; Ventilation std-by
Replaceventifpersistmessage: No
Circuit: all

2) SFSYSTSET3.7
LOW VTI
Unit: ml
Min Value: 30
Max Value: 2000
List of Values: N.A.
Step: 10
Default Value: 300
Links: LOW VTI <= HIGH VTI - 20
Low Vti <= Vt target - 10
Auto-adjustement: N.A.
Comments: OFF is available downside. OFF(=30) output value = 30

3) SFSYSTSET6.12
LOW VTI
Unit: ml
Min Value: 30
Max Value: 2000
List of Values: N.A.
Step: 10
Default Value: 300
Links: LOW VTI <= HIGH VTI - 20
Auto-adjustement: N.A.
Comments: OFF is available by the DOWN KEY

4) SFSYSTSET31.3
LOW VTI
Unit: ml
Min Value: 30
Max Value: 2000
List of Values: N.A.
Step: 10
Default Value: 300
Links: LOW VTI <= HIGH VTI - 20
Auto-adjustement: N.A.
Comments: OFF is reached downside
OFF (=30) output value = 30

5) SFSYSTEV2.15
Low VTI
the software shall record this event when a new Low VTI is set

6) SFSYSTEV3.13
LOW VTI
the software shall record this event when the LOW VTI alarm is detected.

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
UWORD16 DB_IHM_Write_Adjust_Pres_Mode_Low_Vti(UWORD16 *Value)
{

/* Id values recuperation from adjust base in Pres mode */
   UWORD16 Adjust_High_Vti = EEP_DB_PRES_Adjust[ADJUST_HIGH_VTI_U16];

	DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_LOW_VTI_U16],
									*Value);

/*%C High Vti writing */
   if (*Value > Adjust_High_Vti - cLowVtiHighVtiHysteresis)
   {
	   DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_HIGH_VTI_U16],
									   *Value + cLowVtiHighVtiHysteresis);
   }

/* In this function the result is always TRUE */
	return(TRUE);
}



 
