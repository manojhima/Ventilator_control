/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Psv_Mode_Ti_Max.c           	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new value		*/
/*%C        of the Ti max setting in the Psv mode	        							*/
/*                                                            				  		*/
/*%C In automatic mode the Ti Max is the min between 3s and 30 / Measure R    */
/*%C In normal mode the Ti Max takes the setting value                        */
/*%C If the Ti min no select flag is set and Ti max < Ti min                  */
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYST7.5
TI MAX = min [TI MAX setting, 30 /R]
If TIMAX is set to auto, the TIMAX must not exceed 3 s.
This applies only in PSV cycles of PSV mode and SIMV modes

SFSYSTSET4.9
TI MAX
Unit: s
Min Value: 0.8
Max Value: 3
List of Values: N.A.
Step: 0
Default Value: Auto = 3s output value = 3s
Links: TI MIN <= TI MAX
Auto-adjustement: N.A.
Comments: Auto is available by the UP KEY
Step is 0.1
Auto = Min [ 3s;(60*1/2)/R]

SFSYSTSET5.9
TI MAX
Unit: s
Min Value: N.A.
Max Value: N.A.
List of Values: N.A.
Step: 0
Default Value: Auto = Min [ 3s;(60*1/2)/R]
Links: N.A.
Auto-adjustement: N.A.
Comments: No comment

SFSYSTSET6.9
TI MAX
Unit: s
Min Value: N.A.
Max Value: N.A.
List of Values: N.A.
Step: 0
Default Value: Auto = Min [ 3s;(60*1/2)/R]
Links: N.A.
Auto-adjustement: N.A.
Comments: No comment

SFSYSTEV2.9
Ti max
the software shall record this event when a new Ti max is set

SFSYSTCOMDP14.2.45
Ti maxi setting
Offset (byte): 090
091
Format: 16 bits
Data: ti max
Range: 800 to 3000
AA AA = not used
Unit: ms

SFSYSTCOMDP93.3.20
Ti maxi setting
Offset (byte): 89
Format: 8 bits
Data: Ti maxi
Range: 8 to 30
Unit: 10-1 s
*/


/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/DATABASE/DB_Current.h"
#include "../../inc/DATABASE/DB_Config.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
//#include "DB_IHM_Write_Adjust_Psv_Mode_Ti_Max.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Write_Adjust_Psv_Mode_Ti_Max(UWORD16 *Value)
{

/* Id values recovery from adjust base in psv mode */
   UWORD16 Ti_Max_Auto_Select = EEP_DB_PSV_Adjust[TI_MAX_AUTO_SELECT_U16];
   UWORD16 Adjust_Ti_Min = EEP_DB_PSV_Adjust[ADJUST_TI_MIN_U16];
   UWORD16 Adjust_BackUp_R = EEP_DB_PSV_Adjust[ADJUST_BACKUP_R_U16];

/* Min Ti Max declaration (3000ms)*/
   UWORD16 Ti_Max_Min = cTiMaxmax;

/* Test between 3s and 30 / BackUp_R */
    if (Ti_Max_Min > 30000 / Adjust_BackUp_R)
	{
	   Ti_Max_Min = (30000 / Adjust_BackUp_R);
	}
/* else, keeps its declaration value */

/*%C Automatic mode test */
   if (Ti_Max_Auto_Select == TRUE)
   {
/*%C  Ti Max writing (fixed to min(3s, 30/Measure_R)) */
      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_TI_MAX_U16],
									   Ti_Max_Min);			
   }
/*%C The Ti Max is written to the setting value : */
	else
	{
      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_TI_MAX_U16],
								      *Value);
   }

/*%C Ti Min/Max dependance */
   if (*Value < Adjust_Ti_Min)
   {
      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_TI_MIN_U16],
								      *Value);
   }
/*%C This function always return TRUE */
	return(TRUE);
}
