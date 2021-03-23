/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Vsimv_Mode_Peep.c         	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the Peep setting in the Vsimv mode    	     							*/
/*                                                            				  		*/
/*%C Peep [min:0, max:200, step:10, default:0]                   					*/
/*%C Peep is include in its own limits(otherwise, value is saturated)         */
/*%C P Support + PEEP <= 600                        							      */
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
#include "../../inc/VSIMV_SETTINGS/DB_IHM_Setting_Adjust_Vsimv_Mode_Peep.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
																							  
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Adjust_Vsimv_Mode_Peep(UWORD16 *Value,
														    UWORD16 Id)
{

/* Function result declaration */
   UWORD16 Function_Result = FALSE;
/* Peep/Pi gap declaration   */
	UWORD16 Delta_Peep_Pi = 50;
/* Id values recuperation from adjust base in vsimv mode */
   UWORD16 Adjust_P_Support = EEP_DB_VSIMV_Adjust[ADJUST_P_SUPPORT_U16];

	/* read of the pressure convention */
	UWORD16 Pressure_Support_Relative = DB_ConfigRead(PRESSURE_SUPPORT_RELATIVE_U16);
 
/*%C Up and down limit test 								                  */
/*   *Value non sign�, il passe donc de 0 au max de son type         */
/*   => fix� � la valeur min de la PEEP                              */
   if ( (*Value <= cDB_VSIMV_TEST_ADJUST_DB[Id].mini)
     || (*Value > cDB_VSIMV_TEST_ADJUST_DB[Id].maxi +
                  cDB_VSIMV_TEST_ADJUST_DB[Id].step) )
   {
/*%C  Value limited to its min */
      *Value = cDB_VSIMV_TEST_ADJUST_DB[Id].mini;
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[PEEP_NO_SELECT_U16],
										TRUE);
      Function_Result = FALSE;
   }
   else if (*Value > cDB_VSIMV_TEST_ADJUST_DB[Id].maxi) 			
	{
      Function_Result = TRUE;
	}
/*%C Dependence test between P Support  and PEEP */
   else if ((Adjust_P_Support + *Value > cMaxPressure )
   		&& (Pressure_Support_Relative == TRUE))
   {
/*%C  => P Support for IHM indication */
		DB_ControlWrite(LIMIT_P_SUPPORT_U16,
							 TRUE);
		Function_Result = TRUE;
	}
/*%C Dependence test between P Support and PEEP */
   else if ((*Value > Adjust_P_Support - Delta_Peep_Pi)
   		&& (Pressure_Support_Relative == FALSE))
   {
/*%C  Value out of range,        */
/*%C  => value saturation        */
      *Value = Adjust_P_Support - Delta_Peep_Pi;
/*%C  => Peep flag for IHM indication */
		DB_ControlWrite(LIMIT_P_SUPPORT_U16,
							 TRUE);
		Function_Result = FALSE;
	}
/*%C If "no select flag" activated => "no select flag" cancelled */
	else if (EEP_DB_VSIMV_Adjust[PEEP_NO_SELECT_U16] == TRUE)
	{
/*%C Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[PEEP_NO_SELECT_U16],
										FALSE);
		Function_Result = FALSE;
	}
   else
   {
/*%C  Setting authorized, P Support flag desactivation */
		DB_ControlWrite(LIMIT_P_SUPPORT_U16,
							 FALSE);
      Function_Result = FALSE;
   }

	return(Function_Result);
}
