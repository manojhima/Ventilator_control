/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Vsimv_Mode_Low_Vti.c 	          		   */
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the            	*/
/*%C        Low Vti setting in the Vsimv mode  	      								*/
/*                                                            				  		*/
/*%C if LOW VTI > HIGH VTI - 20 => HIGH VTI = LOW VTI + 20	 						*/
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
#include "../../inc/DATABASE/DB_Current.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"

/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Write_Adjust_Vsimv_Mode_Low_Vti(UWORD16 *Value)
{
/*%C Id values recuperation from adjust base in vsimv mode */
   UWORD16 Adjust_High_Vti = EEP_DB_VSIMV_Adjust[ADJUST_HIGH_VTI_U16];
   UWORD16 High_Vti_No_Select = EEP_DB_VSIMV_Adjust[HIGH_VTI_NO_SELECT_U16];

/*%C Low Vti Writing */
   DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[ADJUST_LOW_VTI_U16],
 								   *Value);

   if (High_Vti_No_Select == TRUE)
   {
/*%C  High/Low Vti dependance */
      if (*Value > Adjust_High_Vti - cLowVtiHighVtiHysteresis)
      {

	     Adjust_High_Vti = (UWORD16)(*Value + cLowVtiHighVtiHysteresis);

/*%C     High Vti writing by DB_WriteDataInEepAndRam function call 	*/
         DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[ADJUST_HIGH_VTI_U16],
								Adjust_High_Vti);
      }
   }
   return(TRUE);
}





 
