/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Cpap_Mode_High_Vti.c		          		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the High Vti setting in the Cpap mode  	   						*/
/*                                                            				  		*/
/*%C HIGH VTI [min:80, max:3000, step:10, default:2000] 	    						*/
/*%C HIGH VTI is include in its own limits(otherwise, value is saturated)	   */
/*%C HIGH VTI >= LOW VTI + 20 ml       									            */
/*%C If the conditions on Low Vti is not respected, a limit flag is	set for  */
/*%C IHM indication and the value is saturated                                */
/*%C If the Low Vti is set to No, the low Vti is refreshed with the high Vti  */
/*%C conditions                                                               */
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

SFSYSTSET31
CPAP settings
*/

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
#include "DB_IHM_Setting_Adjust_Cpap_Mode_High_Vti.h"

/* locate database code to specific section */
#include "../GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Adjust_Cpap_Mode_High_Vti(UWORD16 *Value,
															   UWORD16 Id)
{

/*%C Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Id values recuperation from adjust base in psv mode */
   UWORD16 Adjust_Low_Vti = EEP_DB_CPAP_Adjust[ADJUST_LOW_VTI_U16];
   UWORD16 Low_Vti_No_Select = EEP_DB_CPAP_Adjust[LOW_VTI_NO_SELECT_U16];
   
/*%C Limit tests */
/*%C Down limit test */
/*%C Up limit test */
   if (*Value < cDB_CPAP_TEST_ADJUST_DB[Id].mini)
   {
		Function_Result = TRUE;
   }
/*%C Up limit test */
   else if (*Value > cDB_CPAP_TEST_ADJUST_DB[Id].maxi)
   {
/*%C  High Vti flag writing by DB_WriteDataInEepAndRam function call 	*/
      DB_WriteDataInEepAndRam(&EEP_DB_CPAP_Adjust[HIGH_VTI_NO_SELECT_U16],
										TRUE);
		Function_Result = TRUE;
   }
   else if ( (*Value < Adjust_Low_Vti + cLowVtiHighVtiHysteresis)
	       && (Low_Vti_No_Select == FALSE) ) 
   {
/*%C  If the low Vti value is not set, low Vti = high Vti - 20 */
/*%C     => Low vti flag for IHM indication */
	       DB_ControlWrite(LIMIT_LOW_VTI_U16,
	      			   TRUE);
	       Function_Result = TRUE;
   }
/*%C If "no select flag" activated => "no select flag" cancelled */
	else if (EEP_DB_CPAP_Adjust[HIGH_VTI_NO_SELECT_U16] == TRUE)
	{
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_CPAP_Adjust[HIGH_VTI_NO_SELECT_U16],
										FALSE);
/*%C  Low vti flag desactivation */
		DB_ControlWrite(LIMIT_LOW_VTI_U16,
							 FALSE);
		Function_Result = TRUE;
	}
   else
   {
/*%C  Setting authorized */
/*%C  Low vti flag desactivation */
		DB_ControlWrite(LIMIT_LOW_VTI_U16,
							 FALSE);

      Function_Result = FALSE;
   }

	return(Function_Result);
}