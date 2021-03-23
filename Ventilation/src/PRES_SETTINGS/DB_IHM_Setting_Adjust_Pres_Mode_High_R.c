/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: DB_IHM_Setting_Adjust_Pres_Mode_High_R.c  			          		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*
1) SFSYSTSET31.6
High R
Unit: bpm
Min Value: 10
Max Value: 70
List of Values: N.A.
Step: 1
Default Value: OFF (=70) output value = 70
Links: N.A.
Auto-adjustement: N.A.
Comments: OFF is reached upside
OFF(=70) output value = 70

2) SFSYSTEV2.20
High R
the software shall record this event when a new High R is set
*/
/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the High_R setting in the Pres mode										*/
/*                                                            				  		*/
/*%C HIGH R [min:10, max:70, step:1, default:70 = OFF]								*/
/*%C HIGH R is include in its own limits (Otherwise, value is saturated)      */
/*%C CONTROL R <= HIGH R - 5	                       									*/
/*%C If the conditions on Control R is not respected a limit flag is set for, */
/*%C IHM indication and the value is saturated                                */
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/


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
//#include "DB_IHM_Setting_Adjust_Pres_Mode_High_R.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/
UWORD16 DB_IHM_Setting_Adjust_Pres_Mode_High_R(UWORD16 *Value,
															  UWORD16 Id)
{

/*%C Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Id values recuperation from adjust base in vol mode */
   UWORD16 Adjust_Control_R	=     EEP_DB_PRES_Adjust[ADJUST_CONTROL_R_U16];

/*%C If no Insp Sens selected, high R setting is forbidden */
   if (EEP_DB_PRES_Adjust[INSP_SENS_NO_SELECT_U16] == TRUE)
	{
      *Value = EEP_DB_PRES_Adjust[ADJUST_HIGH_R_U16];
/*%C  Limit flag for HMI indication */
		DB_ControlWrite(LIMIT_INSP_SENS_U16,
							 TRUE);
		Function_Result = FALSE;
   }
/*%C Up and down limit test											*/
/*%C Down limit test */
  else if (*Value < cDB_PRES_TEST_ADJUST_DB[Id].mini)
   {
/*%C  Value limited to its min */
      *Value = cDB_PRES_TEST_ADJUST_DB[Id].mini;

		Function_Result = FALSE;
   }
/*%C If value < Control R + 5 => "no select flag" activated 	*/
/*%C Limit tests */
   else if (*Value < Adjust_Control_R + cAlarmRHysteresis)
   {
/*%C  Value limited to its min */
      *Value = Adjust_Control_R + cAlarmRHysteresis;

/*%C  Limit flag for HMI indication */
		DB_ControlWrite(LIMIT_CONTROL_R_U16,
							 TRUE);

		Function_Result = FALSE;
   }
/*%C Up limit test */
   else if (*Value > cDB_PRES_TEST_ADJUST_DB[Id].maxi)
	{
/*%C  Value limited to its max */
	   *Value = cDB_PRES_TEST_ADJUST_DB[Id].maxi;   
/*%C  No select flag indication */
		DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[HIGH_R_NO_SELECT_U16],
										TRUE);
/*%C  Limit flag for HMI indication */
		DB_ControlWrite(LIMIT_INSP_SENS_U16,
							 FALSE);
		Function_Result = FALSE;
	}
	else if (EEP_DB_PRES_Adjust[HIGH_R_NO_SELECT_U16] == TRUE)
	{
		DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[HIGH_R_NO_SELECT_U16],
										FALSE);
		DB_ControlWrite(LIMIT_CONTROL_R_U16,
							 FALSE);
/*%C  Limit flag for HMI indication */
		DB_ControlWrite(LIMIT_INSP_SENS_U16,
							 FALSE);

		Function_Result = TRUE;
	}
/*%C Setting authorized */
	else
   {
/*%C  Limit flag for HMI indication */
		DB_ControlWrite(LIMIT_INSP_SENS_U16,
							 FALSE);
		Function_Result = FALSE;
   }

	return(Function_Result);
}
