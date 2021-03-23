/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Psv_Mode_P_Support.c	     	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new value		*/
/*%C        of the P Support in the Psv mode     	 	  	     						*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTSET5.4
P SUPPORT
Unit: cmH2O, mbar, hPa
Min Value: 5
Max Value: 55
List of Values: N.A.
Step: 1
Default Value: 15
Links: PEEP <= Psupport - 5 in absolute pressure
P SUPPORT + PEEP <= 55 in relative pressure
P SUPPORT + PEEP >= LOW PIP in relative pressure
P SUPPORT + PEEP <= HIGH PIP - 2 in relative pressure
P SUPPORT >= LOW PIP in absolute pressure
P SUPPORT <= HIGH PIP - 2 in absolute pressure
Auto-adjustement: LOW PIP
HIGH PIP
Comments: No comment

SFSYSTSET6.4
P SUPPORT
Unit: cmH2O, mbar, hPa
Min Value: 5
Max Value: 55
List of Values: N.A.
Step: 1
Default Value: 15
Links: in absolute pressure:
PEEP <= P SUPPORTL - 5
in relative pressure:
P SUPPORT + PEEP <= 55
Auto-adjustement: N.A.
Comments: No comment

SFSYSTEV2.1
P Support
the software shall record this event when a new P Support is set


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

UWORD16 DB_IHM_Write_Adjust_Psv_Mode_P_Support(UWORD16 *Value)
{

	UWORD16 Adjust_Max_Pressure = EEP_DB_PSV_Adjust[ADJUST_MAX_PRESSURE_U16];

   DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_P_SUPPORT_U16],
								   *Value);
								   
	if (Adjust_Max_Pressure < *Value)
	{
	   DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_MAX_PRESSURE_U16],
									   *Value);
	}
	else if (Adjust_Max_Pressure > *Value + cPSupportPiMaxHysteresis)
	{
	   DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_MAX_PRESSURE_U16],
									   *Value + cPSupportPiMaxHysteresis);
	}								   						

/*%C This function always return TRUE */
	return(TRUE);
}
