/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Pres_Mode_Insp_Sens.c    	  	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new Insp 		*/
/*%C        Sens value depending on the High R value :                  		*/
/*                                                            				  		*/
/*%C Insp sens value writing.                                          			*/
/*%C If Insp Sens value = 0, Insp Sens and High R No Select are activated 		*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				*Value                                		  	*/
/*%IO Input/Output Parameter : 	None  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTSET2.6
INSP SENS
Unit: N.A.
Min Value: 0P
Max Value: 5
List of Values: N.A.
Step: 1
Default Value: 2
Links: N.A.
Auto-adjustement: N.A.
Comments: OFF available under the minimum value OFF. output value = 0
loop setting.
HIGH R = OFF if INSP SENS = OFF

SFSYSTSET3.6
INSP SENS
Unit: N.A.
Min Value: 0P
Max Value: 5
List of Values: N.A.
Step: 1
Default Value: 2
Links: N.A.
Auto-adjustement: High Rate = OFF if Insp Sens = OFF
Comments: OFF is available only under minimum value OFF. output value =0.
HIGH R = OFF if INSP SENS = OFF
loop setting

SFSYSTSET4.6
INSP SENS
Unit: N.A.
Min Value: 0P
Max Value: 5
List of Values: N.A.
Step: 1
Default Value: 2
Links: N.A.
Auto-adjustement: N.A.
Comments: loop setting.

SFSYSTSET5.7
INSP SENS
Unit: N.A.
Min Value: 0P
Max Value: 5
List of Values: N.A.
Step: 1
Default Value: 2
Links: N.A.
Auto-adjustement: N.A.
Comments: No comment

SFSYSTSET31.7
Insp Sens
Unit: N.A.
Min Value: N.A.
Max Value: N.A.
List of Values: N.A.
Step: 0
Default Value: 2
Links: N.A.
Auto-adjustement: N.A.
Comments: No comment

SFSYSTEV2.6
Insp Sens
the software shall record this event when a new Insp Sens is set

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
#include "../../inc/DATABASE/DB_Config.h"
//#include "DB_IHM_Write_Adjust_Pres_Mode_Insp_Sens.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/
UWORD16 DB_IHM_Write_Adjust_Pres_Mode_Insp_Sens(UWORD16 *Value)
{
/*%C Insp Sens no select flag recovery */
	UWORD16 Insp_Sens_No_Select = EEP_DB_PRES_Adjust[INSP_SENS_NO_SELECT_U16];

	UWORD16 CurrentMode = DB_ControlRead(CURRENT_MODE_U16);

	UWORD16 AdjustMode = DB_ConfigRead(ADJUST_MODE_U16);

/*%C Insp Sens value writing in current base for immediate application, */
/*%C except when the mode is changing) */

	if(CurrentMode == AdjustMode)
	{
		DB_CurrentWrite(ADJUST_INSP_SENS_U16,*Value);
	}

/*%C Insp Sens value writing */
   DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_INSP_SENS_U16],
									*Value);


 

/*%C If Insp Sens no select is TRUE, High R no select is activated */
   if (Insp_Sens_No_Select == TRUE)
	{ 
/*%C  No select flag indication */
      	DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[INSP_SENS_NO_SELECT_U16],
									   TRUE); 	  
     	DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[HIGH_R_NO_SELECT_U16],
									   TRUE);
     	DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_HIGH_R_U16],
									   cDB_PRES_TEST_ADJUST_DB[ADJUST_HIGH_R_U16].maxi);
	}
	else
	{
/*%C  No select flag indication */
      	DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[INSP_SENS_NO_SELECT_U16],
									   FALSE); 
	}

/*%C In this function the result is always TRUE */
   return(TRUE);
}
