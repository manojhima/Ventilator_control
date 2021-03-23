/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Pres_Mode_Max_Pressure.c     	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new value		*/
/*%C        of the Max Pressure in the Pres mode        	     						*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTCOMDP93.2.11
Pressure unit setting
Offset (byte): 12
Format: 8 bits
Data: P unit conv
Range: 0 = mbar , 1 = cmH2O , 2 = hPa
Unit: NA
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

UWORD16 DB_IHM_Write_Adjust_Pres_Mode_Max_Pressure(UWORD16 *Value)
{

/*%C Target Vt saturation (max) */
	if (*Value > (UWORD32)cDB_PRES_TEST_ADJUST_DB[ADJUST_MAX_PRESSURE_U16].maxi)
	{
      *Value = cDB_PRES_TEST_ADJUST_DB[ADJUST_MAX_PRESSURE_U16].maxi;
	}

        /*%C Value recording */
   DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_MAX_PRESSURE_U16],
								   *Value);

/*%C This function always return TRUE */
	return(TRUE);
}
