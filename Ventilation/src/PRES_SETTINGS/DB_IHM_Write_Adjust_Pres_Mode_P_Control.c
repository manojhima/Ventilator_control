/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Pres_Mode_P_Control.c     	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new value		*/
/*%C        of the P Control in the Pres mode      	  	     						*/
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
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Write_Adjust_Pres_Mode_P_Control(UWORD16 *Value)
{

	UWORD16 Adjust_Max_Pressure = EEP_DB_PRES_Adjust[ADJUST_MAX_PRESSURE_U16];

   DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_P_CONTROL_U16],
								   *Value);
								   
	if (Adjust_Max_Pressure < *Value)
	{
	   DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_MAX_PRESSURE_U16],
									   *Value);
	}
	else if (Adjust_Max_Pressure > *Value + cPControlPiMaxHysteresis)
	{
	   DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_MAX_PRESSURE_U16],
									   *Value + cPControlPiMaxHysteresis);
	}								   						

/*%C This function always return TRUE */
	return(TRUE);
}
