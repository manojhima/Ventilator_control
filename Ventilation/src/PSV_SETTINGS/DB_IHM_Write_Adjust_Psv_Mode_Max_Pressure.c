/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Psv_Mode_Max_Pressure.c     	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new value		*/
/*%C        of the Max Pressure in the Psv mode        	     						*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTSET4.18
Max Pres
Unit: cmH2O, mbar, hPa
Min Value: 8
Max Value: 55
List of Values: N.A.
Step: 1
Default Value: Psupport + 3
Links: P SUPPORT <= MaxPres <= P SUPPORT +20
MaxPres + PEEP <= 55 in relative pressure
Auto-adjustement: N.A.
Comments: Not displayed if Vt target is set to OFF
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

UWORD16 DB_IHM_Write_Adjust_Psv_Mode_Max_Pressure(UWORD16 *Value)
{

/*%C Target Vt saturation (max) */
   	if (*Value > (UWORD32)cDB_PSV_TEST_ADJUST_DB[ADJUST_MAX_PRESSURE_U16].maxi)
	{
      *Value =  cDB_PSV_TEST_ADJUST_DB[ADJUST_MAX_PRESSURE_U16].maxi;
	}
/*%C Value recording */
   DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_MAX_PRESSURE_U16],
								   *Value);

/*%C This function always return TRUE */
	return(TRUE);
}
