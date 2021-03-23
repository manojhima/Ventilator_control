/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Pres_Mode_Peep.c	     	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new value		*/
/*%C        of the P Support in the Pres mode     	 	  	     						*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTSET2.5
PEEP
Unit: cmH2O, mbar, hPa
Min Value: 1
Max Value: 20
List of Values: N.A.
Step: 1
Default Value: 0FF (=0) output value = 1
Links: LOW PIP >= PEEP + 2
PEEP + 10 <= HIGH PIP
Auto-adjustement: HIGH PIP
LOW PIP
Comments: Possibility to set OFF (down side)
0FF (=0) output value = 1

SFSYSTSET3.5
PEEP
Unit: cmH2O, mbar, hPa
Min Value: OFF (=0) in valve ventilation or standby

SFSYSTSET4.2
PEEP
Unit: cmH2O, mbar, hPa
Min Value: OFF (=0) in valve ventilation or standby

SFSYSTSET5.5
PEEP
Unit: cmH2O, mbar, hPa
Min Value: 1
Max Value: 20
List of Values: N.A.
Step: 1
Default Value: OFF
Links: PEEP <= Psupport - 5 in absolute pressure
P SUPPORT + PEEP <= 55 in relative pressure
P SUPPORT + PEEP <= HIGH PIP - 2 in relative pressure
P SUPPORT + PEEP >= LOW PIP in relative pressure
LOW PIP >= PEEP + 2 in absolute pressure
Auto-adjustement: LOW PIP
HIGH PIP
Comments: Possibility to set OFF

SFSYSTSET6.5
PEEP
Unit: cmH2O, mbar, hPa
Min Value: 1
Max Value: 20
List of Values: N.A.
Step: 1
Default Value: OFF
Links: in absolute pressure:
PEEP <= P SUPPORT - 5
in relative pressure:
P CONTROL + PEEP <= 55
P SUPPORT + PEEP <= 55
Auto-adjustement: N.A.
Comments: Possibility to set OFF

SFSYSTMON8
PEEP
Min Val: 0
Max Val: 99
Rounded to: 1

SFSYSTEV2.2
PEEP
the software shall record this event when a new PEEP is set

SFSYSTCOMDP303.2.9
PeeP measure
Offset (byte): 10
11
Format: 2*8 bits
Data: PeeP
Range: 0 to 999 modulo 256
Unit: 10-1 mbar

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
//#include "DB_IHM_Write_Adjust_Pres_Mode_Peep.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/


UWORD16 DB_IHM_Write_Adjust_Pres_Mode_Peep(UWORD16 *Value)
{
/* Id values recuperation from adjust base in Pres mode */
	UWORD16 Adjust_Max_Pressure = EEP_DB_PRES_Adjust[ADJUST_MAX_PRESSURE_U16];
	UWORD16 Pressure_Support_Relative = DB_ConfigRead(PRESSURE_SUPPORT_RELATIVE_U16);
	UWORD16 Target_Vt_Select = EEP_DB_PRES_Adjust[TARGET_VT_SELECT_U16];
								   
/*%C In relative mode, and Vt target not selected, if the Peep becomes upper than */
/*%C 55mbar - Pmax, then Pmax takes Pcontrol value */
	if ((Adjust_Max_Pressure + *Value >= cDB_PRES_TEST_ADJUST_DB[ADJUST_MAX_PRESSURE_U16].maxi)
	&& (Pressure_Support_Relative == TRUE)
	&& (Target_Vt_Select == FALSE))
	{
	   DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_MAX_PRESSURE_U16],
									   EEP_DB_PRES_Adjust[ADJUST_P_CONTROL_U16]);
	   DB_CurrentWrite(ADJUST_MAX_PRESSURE_U16,EEP_DB_PRES_Adjust[ADJUST_P_CONTROL_U16]);	
	}
	
	DB_WriteDataInEepAndRam(&EEP_DB_PRES_Adjust[ADJUST_PEEP_U16],
										   *Value);				   						

/*%C This function always return TRUE */
	return(TRUE);
}
