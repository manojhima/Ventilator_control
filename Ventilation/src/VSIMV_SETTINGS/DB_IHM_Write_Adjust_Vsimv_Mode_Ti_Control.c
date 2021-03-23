/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Vsimv_Mode_Ti_Control.c     	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new value		*/
/*%C        of the Ti Control in the Vsimv mode      	     							*/
/*                                                            				  		*/
/*%C If apnea time < 2 * Ti Control => apnea time = 2 * Ti control                 */
/*%C rounded the second sup								             			*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTSET2.19
TI CONTROL
Unit: s
Min Value: 0.3
Max Value: 6.0
List of Values: N.A.
Step: 0.1
Default Value: 1.5
Links: 3 lpm <= (VOL CONTROL x 60) /(TI CONTROL*1000) <= 100 lpm in R RAMP
3 lpm <= 3*(VOL CONTROL x 60) / 2*(TI CONTROL*1000) <= 100 lpm in D RAMP and S RAMP
TI CONTROL <= (0.5*60 / CONTROL R)
Comments: I:E <= 1:1

SFSYSTSET3.21
TI CONTROL
Unit: s
Min Value: 0.3
Max Value: 6.0
List of Values: N.A.
Step: 0.1
Default Value: 1.5
Links: TI CONTROL <= (0.5*60 / CONTROL R)
Auto-adjustment: N.A.
Comments: I:E <= 1:1

SFSYSTSET5.2
TI CONTROL
Unit: s
Min Value: 0.3
Max Value: 2.4
List of Values: N.A.
Step: 0
Default Value: 1.5
Links: 3 lpm <= (VOL CONTROL*60) / (TI CONTROL*1000) <= 100 lpm
APNEA TIME >= 2 * TI CONTROL
if CONTROL R >= 8 :
TI CONTROL <= 0.33 * 60 / CONTROL R
if CONTROL R < 8 :
TI CONTROL <= 2.4
Auto-adjustement: APNEA TIME
Comments: Step is 0.1

SFSYSTSET6.2
TI CONTROL
Unit: s
Min Value: 0.3
Max Value: 2.4
List of Values: N.A.
Step: 0
Default Value: 1.5
Links: if CONTROL R >= 8 :
TI CONTROL <= 0.33 * 60 / CONTROL R
if CONTROL R < 8 :
TI CONTROL <= 2.4
APNEA TIME >= 2 * TI CONTROL
Auto-adjustement: APNEA TIME
Comments: Step is 0.1

SFSYSTEV2.11
Ti Control
the software shall record this event when a new Ti Control is set

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

UWORD16 DB_IHM_Write_Adjust_Vsimv_Mode_Ti_Control(UWORD16 *Value)
{

/* Apnea time declaration */
   UWORD16 Adjust_Apnea   = EEP_DB_VSIMV_Adjust[ADJUST_APNEA_U16];

/* Ti Control writing */
   DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[ADJUST_TI_CONTROL_U16],
						      *Value);						


/*%C Link with apnea time setting */
   if (Adjust_Apnea < *Value * 2)
   {
		if ( (*Value * 2) %1000 != 0)
		{
		 	DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[ADJUST_APNEA_U16],
									(((*Value * 2) /1000) + 1) * 1000 );
		}
		else
		{
		 	DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[ADJUST_APNEA_U16],
									*Value * 2);
		}
   }
/*%C This function always return TRUE */
	return(TRUE);
}
