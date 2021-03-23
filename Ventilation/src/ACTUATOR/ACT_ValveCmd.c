/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : ACT_ValveCmd.c																	*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C                       Valve management						     					*/
/*%C     															  								*/
/******************************************************************************/
/*%I Input Parameter :  Value                       									*/
/*%IO Input/Output :    NONE	                                                */
/*%O Output Parameter : NONE																	*/
/******************************************************************************/
/*
1) SFSYSTEV3.48
CHECK VALVE
the software shall record this event when the CHECK VALVE alarm is detected

2) SFSYSTEV3.118
CONNECT VALVE / CHANGE PRESS
the software shall record this event when the CONNECT VALVE / CHANGE PRESS alarm is
detected

3) SFSYSTEV3.119
END OF CONNECT VALVE / CHANGE PRESS
the software shall record this event when the CONNECT VALVE / CHANGE PRESS alarm is
canceled

4) SFSYSTEV3.120
DISCONNECT VALVE / CHANGE PI PE
the software shall record this event when the DISCONNECT VALVE / CHANGE PI PE alarm is
detected

5) SFSYSTEV3.121
END OF DISCONNECT VALVE / CHANGE PI PE
the software shall record this event when the DISCONNECT VALVE / CHANGE PI PE alarm is
canceled


/******************************************************************************/
/*                                INCLUDE FILES		                           */
/******************************************************************************/
//#ifndef _TASKING
//	#include "LH_ST10F276.h"
//	#include <intrins.h>
//#else
//	#ifdef _TESTRT
//		#include "IO_TestRT.h"
//	#else
//		#include "regf276e.h"
//	#endif
//#endif
//#include "../../inc/GENERAL/io_declare.h"
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Compute.h"
#include "../../inc/VENTILATION/Ventilation_Constants.h"
#include "../../inc/ACTUATOR/ACT_ValveCmd.h"


/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

#define sfr unsigned int
sfr VALVE_CMD_2 = 0xFE32; //bhavya


void ACT_ValveCmd(UWORD16 Value)
{
  	UWORD16 High_Pressure_Exhalation_Detected =
				 DB_ControlRead(HIGH_PRESSURE_EXHALATION_DETECTED_U16);

/*%C valve command monitoring in database */
	DB_ComputeWrite(VALVE_COMMAND_U16, Value*10);

/*%C The adaptation of the value depends on:  */
/*%C Battery supply value */
/*%C or main supply value */

/*%C Valve command saturation to 2672 */
	if (Value > cVALVE_CMD_OFF)
	{
		Value = cVALVE_CMD_OFF;
	}
	
	if (High_Pressure_Exhalation_Detected == TRUE)
	{
		Value = cVALVE_CMD_OFF;
	}

/*%C Valve command update */
	VALVE_CMD_2 = Value;

}
