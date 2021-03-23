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
/*
SFSYSTSET3.1
P CONTROL
Unit: cmH2O, mbar, hPa
Min Value: 5 in valve ventilation or 6 in leak ventilation or 2 in standby
Max Value: 55 in valve ventilation or in standby
30 in leak ventilation
List of Values: N.A.
Step: 1
Default Value: 15
Links: IIn valve ventilation :
PEEP <= Pcontrol - 5 in absolute pressure
Pcontrol+ PEEP <= 55 in relative pressure
In leak ventilation
PEEP <= Pcontrol - 2 in absolute pressure
Pcontrol+ PEEP <= 30 in relative pressure
in stand by:
PEEP <= Pcontrol - 2 in absolute pressure
Pcontrol+ PEEP <= 55 in relative pressure
both:
Pmax + PEEP <= 55 in relative pressure
Auto-adjustement: Max Pres
Comments: No comment

SFSYSTSET6.1
P CONTROL
Unit: cmH2O, mbar, hPa
Min Value: 5
Max Value: 55
List of Values: N.A.
Step: 1
Default Value: 15
Links: in absolute pressure:
PEEP <= P CONTROL - 5
in relative pressure:
P CONTROL + PEEP <= 55
Auto-adjustement: N.A.
Comments: No comment

SFSYSTEV2.13
P Control
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
