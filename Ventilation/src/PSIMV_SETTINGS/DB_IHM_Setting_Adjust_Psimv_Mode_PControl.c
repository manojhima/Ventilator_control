/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Psimv_Mode_PControl.c   	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the P Control setting in the Psimv mode     							*/
/*                                                            				  		*/
/*%C P Control [min:50, max:600, step:10, default:150]          					*/
/*%C P Control is include in its own limits(otherwise, value is saturated)    */
/*%C P Control + PEEP <= 600                       							      */
/*                                                            				  		*/
/*%C If the conditions on PEEP is not respected, a limit flag is	set for     */
/*%C IHM indication and the value is saturated                                */
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
#include "../../inc/DATABASE/DB_Config.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
//#include "DB_IHM_Setting_Adjust_Psimv_Mode_PControl.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"

/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Adjust_Psimv_Mode_PControl(UWORD16 *Value,
																   UWORD16 Id)
{

/* Function result declaration */
   UWORD16 Function_Result = FALSE;
 /* Peep/Pi gap declaration   */
	UWORD16 Delta_Peep_Pi = 20;
/* Id values recuperation from adjust base in psimv mode */
   UWORD16 Adjust_Peep = EEP_DB_PSIMV_Adjust[ADJUST_PEEP_U16];
/* read of the pressure convention */
	UWORD16 Pressure_Support_Relative = DB_ConfigRead(PRESSURE_SUPPORT_RELATIVE_U16);
 
	if(Pressure_Support_Relative == FALSE)
	{
		Delta_Peep_Pi = 50;
	}
	else
	{
		Delta_Peep_Pi = 20;
	}
/*%C Limit tests */
   if (*Value < cDB_PSIMV_TEST_ADJUST_DB[Id].mini)
   {			
/*%C  Value limited to its min */
      *Value = cDB_PSIMV_TEST_ADJUST_DB[Id].mini;
		Function_Result = FALSE;
	}
   else if (*Value > cDB_PSIMV_TEST_ADJUST_DB[Id].maxi)		
	{
/*%C  Value limited to its max */
      *Value = cDB_PSIMV_TEST_ADJUST_DB[Id].maxi;
		Function_Result = FALSE;
	}
/*%C Dependence test between P Control  and PEEP */
   else if ((*Value + Adjust_Peep > cMaxPressure )
   		&& (Pressure_Support_Relative == TRUE))
   {
/*%C  Value out of range,        */
      *Value = (cMaxPressure - Adjust_Peep);
/*%C  => Peep flag for IHM indication */
		DB_ControlWrite(LIMIT_PEEP_U16,
							 TRUE);
		Function_Result = FALSE;
	}
	/*%C Dependence test between P Control and PEEP */
   else if ((*Value < Adjust_Peep + Delta_Peep_Pi)
      	&& (Pressure_Support_Relative == FALSE))
   {
/*%C  Value out of range,        */
/*%C  => value saturation        */
      *Value = Adjust_Peep + Delta_Peep_Pi;
/*%C  => Peep flag for IHM indication */
		DB_ControlWrite(LIMIT_PEEP_U16,
							 TRUE);
		Function_Result = FALSE;
	}
   else
   {
/*%C  Setting authorized, Peep flag desactivation */
		DB_ControlWrite(LIMIT_PEEP_U16,
							 FALSE);
      Function_Result = FALSE;
   }

	return(Function_Result);
}