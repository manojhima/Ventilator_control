/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Vsimv_Mode_Control_R.c 		        		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C Functionnal description : this function controls the limits of the   		*/
/*%C CONTROL R setting in the Vsimv mode:									            */
/*%C                                                                         	*/
/*%C CONTROL R [min:1, max:40, step:1, default:13]   									*/
/*%C if CONTROL R >= 8 => Ti control <= 0.33 * 60 / Control R				*/
/*%C if CONTROL R < 8 => Ti control <= 2.4 s								*/
/*%C CONTROL R is include in its own limits(otherwise, value is saturated)   	*/
/*%C If CONTROL R is out of range, a no select flag is activated and the value*/
/*%C is saturated                                                             */
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTEV2.12
Control R
the software shall record this event when a new Control R is set

SFSYSTSET2.2
CONTROL R
Unit: bpm
Min Value: 1
Max Value: 60
List of Values: N.A.
Step: 1
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
#include "../../inc/VSIMV_SETTINGS/DB_IHM_Setting_Adjust_Vsimv_Mode_Control_R.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"

/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/
UWORD16 DB_IHM_Setting_Adjust_Vsimv_Mode_Control_R(UWORD16 *Value,
																   UWORD16 Id)
{

/*%C Function result declaration */
   UWORD16 Function_Result = FALSE;
/*%C Ti control initialized to 2400ms */
   UWORD16 Ti_Control_Control_R_Limit = cITMaxSimvLimit;

/*%C Database reading parameters */
   UWORD16 Adjust_Ti_Control = EEP_DB_VSIMV_Adjust[ADJUST_TI_CONTROL_U16];

/*%C if control R > 8bpm, Ti control limit switches from 2400ms to  (0.33*60*1000 / Control R) 	*/	
	if (*Value >= cSimvControlR)
	{
		Ti_Control_Control_R_Limit = cITMaxSimvSec / *Value;	
	}

/*%C Limit tests */
   if (*Value < cDB_VSIMV_TEST_ADJUST_DB[Id].mini)
	{
      Function_Result = TRUE;
	}
/*%C Limit tests */
   else if (*Value > cDB_VSIMV_TEST_ADJUST_DB[Id].maxi)
	{
      Function_Result = TRUE;
	}
/*%C Dependence test between Simv Backup R and Ti Control */
	else if (Adjust_Ti_Control > Ti_Control_Control_R_Limit)
	{
/*%C  => Control R flag for IHM indication */
		DB_ControlWrite(LIMIT_TI_CONTROL_U16,
							 TRUE);
		Function_Result = TRUE;
	}
   else
   {
/*%C  => Control R flag desactivation */
		DB_ControlWrite(LIMIT_TI_CONTROL_U16,
							 FALSE);
/*%C  Value in range  */
		Function_Result = FALSE;

		DB_ComputeWrite(COMPUTED_RATE_U16,*Value);
		DB_ComputeBreathTimingRatios();
   }

	return(Function_Result);
}
