/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Psv_Mode_Ti_Min.c           	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new value   	*/
/*%C        of the Ti min setting in the Psv mode	        							*/
/*                                                            				  		*/
/*%C In automatic mode the Ti Min value is value: adjust rise time + 300ms    */
/*%C In the other cases the Ti Min value is given by the value parameter      */
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTSET4.8
TI MIN
Unit: s
Min Value: 0.1
Max Value: 2.8
List of Values: N.A.
Step: 0
Default Value: Auto = 0.7 output value = 0.7
Links: TI MIN <= (60*1/2)/BACK UP R
TI MIN <= TI MAX
Auto-adjustement: N.A.
Comments: Auto is available by the DOWN KEY
Step is 0.1
Auto = Rise time +300 ms

SFSYSTSET5.8
TI MIN
Unit: s
Min Value: N.A.
Max Value: N.A.
List of Values: N.A.
Step: 0
Default Value: Auto = Rise time + 300ms
Links: N.A.
Auto-adjustement: N.A.
Comments: No comment

SFSYSTSET6.8
TI MIN
Unit: s
Min Value: N.A.
Max Value: N.A.
List of Values: N.A.
Step: 0
Default Value: Auto = Rise time + 300ms
Links: N.A.
Auto-adjustement: N.A.
Comments: No comment

SFSYSTEV2.8
Ti min
the software shall record this event when a new Ti min is set

SFSYSTCOMDP14.2.43
Ti mini setting
Offset (byte): 086
087
Format: 16 bits
Data: ti min
Range: 100 to 2800
AA AA = not used
Unit: ms

SFSYSTCOMDP93.3.19
Ti mini setting
Offset (byte): 88
Format: 8 bits
Data: Ti mini
Range: 1 to 28
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

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/


UWORD16 DB_IHM_Write_Adjust_Psv_Mode_Ti_Min(UWORD16 *Value)
{

/* Id values recuperation from adjust base in psv mode */
   UWORD16 Adjust_Rise_Time   = EEP_DB_PSV_Adjust[RISE_TIME_U16];
   UWORD16 Ti_Min_Auto_Select = EEP_DB_PSV_Adjust[TI_MIN_AUTO_SELECT_U16];
   UWORD16 Adjust_Ti_Max = EEP_DB_PSV_Adjust[ADJUST_TI_MAX_U16];

/*%C Automatic mode test */
   if (Ti_Min_Auto_Select == TRUE)
   {
/*%C  Ti Min writing (fixed to Adjust Rise Time + 300 ms) */
      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_TI_MIN_U16],
									   Adjust_Rise_Time + cDeltaRiseTime);			
   }
/*%C The Ti min is written to the setting value : */
	else
	{
      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_TI_MIN_U16],
								      *Value);						          
   }

/*%C Ti Min/Max dependance */
   if (*Value > Adjust_Ti_Max)
   {
      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_TI_MAX_U16],
								      *Value);
   }

/*%C This function always returns TRUE */
   return(TRUE);
}
