/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Cpap_Mode_Low_Vti.c		          		   */
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
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

SFSYSTSET31
CPAP settings
*/

/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the            	*/
/*%C        Low Vti setting in the Psv mode    	      								*/
/*                                                            				  		*/
/*%C if LOW VTI > HIGH VTI - 20 => HIGH VTI = LOW VTI + 20	 						*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/


/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../DRIVERS/DRV_VarEeprom.h"
#include "../DATABASE/DB_Current.h"
#include "../DATABASE/DB_Control.h"
#include "../DATABASE/DB_Rtc.h"
#include "../DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

/* locate database code to specific section */
#include "../GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Write_Adjust_Cpap_Mode_Low_Vti(UWORD16 *Value)
{
/*%C Id values recuperation from adjust base in psv mode */
   UWORD16 Adjust_High_Vti = EEP_DB_CPAP_Adjust[ADJUST_HIGH_VTI_U16];
   UWORD16 High_Vti_No_Select = EEP_DB_CPAP_Adjust[HIGH_VTI_NO_SELECT_U16];

/*%C Low Vti Writing */
   DB_WriteDataInEepAndRam(&EEP_DB_CPAP_Adjust[ADJUST_LOW_VTI_U16],
 								   *Value);

   if (High_Vti_No_Select == TRUE)
   {
/*%C  High/Low Vti dependance */
      if (*Value > Adjust_High_Vti - cLowVtiHighVtiHysteresis)
      {
/*%C     High Vti writing by DB_WriteDataInEepAndRam function call 	*/
         DB_WriteDataInEepAndRam(&EEP_DB_CPAP_Adjust[ADJUST_HIGH_VTI_U16],
										   *Value + cLowVtiHighVtiHysteresis);
      }
   }
   return(TRUE);
}



 
