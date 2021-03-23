/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Pres_Mode_Control_R.c 		        		   */
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new limits		*/
/*%C        of the linked settings function of control R conditions   	  		*/
/*                                                            				  		*/
/*%C If CONTROL R > HIGH R - 5 =>  HIGH R = CONTROL R + 5							*/
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
#include "../../inc/DATABASE/DB_Compute.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
//#include "DB_IHM_Setting_Adjust_Pres_Mode.h"
//#include "DB_IHM_Write_Adjust_Pres_Mode_Control_R.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"

/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/
UWORD16 DB_IHM_Write_Adjust_Pres_Mode_Control_R(UWORD16 *Value)
{

/* Id values recuperation from adjust base in Pres mode */
   UWORD16 Adjust_High_R = (UWORD16)EEP_DB_PRES_Adjust[ADJUST_HIGH_R_U16];
   UWORD16 High_R_No_Select	= EEP_DB_PRES_Adjust[HIGH_R_NO_SELECT_U16];
   	/* Id values recuperation from adjust base in Pres mode */
   UWORD16 Disconnection_Delay_Auto =
   								 EEP_DB_PRES_Adjust[DISCONNECTION_DELAY_AUTO_U16];

/*%C Control R writing */
	DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_CONTROL_R_U16],
									*Value);
															
/*%C Computed rate writing for I/E and I/T computing */
	DB_ComputeWrite(COMPUTED_RATE_U16,*Value);
			  
/*%C Dependence test between Control R and High R */
	if ( (*Value > Adjust_High_R - cAlarmRHysteresis)
     || (High_R_No_Select == TRUE) )
	{
/*%C  ADJUST_HIGH_R affectation */
		DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_HIGH_R_U16],
										*Value + cAlarmRHysteresis);						
	}


/*%C Dependence test between Control R and Disconnection delay when AUTO */
	if (Disconnection_Delay_Auto == TRUE)
	{
		DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_DISCONNECTION_DELAY_U16],
								   (180 / *Value) * 1000);
	}

/* In this function the result is always TRUE */
	return(TRUE);
}