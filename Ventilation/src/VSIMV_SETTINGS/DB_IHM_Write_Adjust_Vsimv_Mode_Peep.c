/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Vsimv_Mode_Peep.c  			         		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new limits		*/
/*%C        of the linked settings, function of peep conditions:					*/
/*                                                            				  		*/
/*%C If PEEP + P SUPPORT < LOW PIP => LOW PIP = P SUPPORT + PEEP           	*/
/*%C If PEEP + P SUPPORT > HIGH PIP -2 => HIGH PIP = P SUPPORT + PEEP + 2     */
/*%C If PEEP > LOW PIP -2 => LOW PIP = PEEP + 2                               */
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				*Value                                		  	*/
/*%IO Input/Output Parameter : 	None  	        			                  	*/
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
#include "../../inc/VSIMV_SETTINGS/DB_IHM_Setting_Adjust_Vsimv_Mode_Peep.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"

/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/
UWORD16 DB_IHM_Write_Adjust_Vsimv_Mode_Peep(UWORD16 *Value)
{
/* Id values recuperation from adjust base in vol mode */
	UWORD16 Adjust_Low_Pip		=     EEP_DB_VSIMV_Adjust[ADJUST_LOW_PIP_U16];
	UWORD16 Adjust_High_Pip		=     EEP_DB_VSIMV_Adjust[ADJUST_HIGH_PIP_U16];
	UWORD16 Adjust_P_Support	=     EEP_DB_VSIMV_Adjust[ADJUST_P_SUPPORT_U16];
/* read of the pressure convention */
	UWORD16 Pressure_Support_Relative = DB_ConfigRead(PRESSURE_SUPPORT_RELATIVE_U16);

/*%C Peep value writing */
	DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[ADJUST_PEEP_U16],
									*Value);


/*%C Dependence test between peep and low pip */
	if (*Value + cPeepLowPipHysteresis > Adjust_Low_Pip )
	{	
/*%C  ADJUST_LOW_PIP affectation */
      DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[ADJUST_LOW_PIP_U16],
									   (*Value + cPeepLowPipHysteresis));
   }

/*%C Dependence test between peep and high pip */
	if ((*Value + Adjust_P_Support < Adjust_Low_Pip )
	&& (Pressure_Support_Relative == TRUE))
	{
/*%C  ADJUST_LOW_PIP affectation */

      	 Adjust_Low_Pip = (UWORD16)(*Value + Adjust_P_Support);

     	 DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[ADJUST_LOW_PIP_U16],
									Adjust_Low_Pip);
  	 }

/*%C Dependence test between peep and high pip */
	if ((*Value + Adjust_P_Support > Adjust_High_Pip - cPiHighPipHysteresis )
	&& (Pressure_Support_Relative == TRUE))
	{
/*%C  ADJUST_LOW_PIP affectation */

      	Adjust_High_Pip = (UWORD16)(*Value + Adjust_P_Support + cPiHighPipHysteresis);

     	 DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[ADJUST_HIGH_PIP_U16],
									Adjust_High_Pip);
  	 }


/*%C In this function the result is always TRUE */
	return(TRUE);
}
