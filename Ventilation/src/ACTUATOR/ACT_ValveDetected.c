/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : ACT_ValveDetected.c										   	  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C                  Detection of the valve						 	      */
/******************************************************************************/
/*%I Input Parameter :  NONE                                  				  */
/*%IO Input/Output :    NONE	                                              */
/*%O Output Parameter : NONE												  */
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          */
/******************************************************************************/

#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Compute.h"
#include "../../inc/ACTUATOR/ACT_ValveDetected.h"


/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
void ACT_ValveDetected(void)
{
SWORD16 MeasureValvePressure 
							= (SWORD16)DB_ComputeRead(MEASURE_VALVE_PRESSURE_S16);
e_BOOL ValveDetected = FALSE;

/*%C If timer reached delay, then 								  	  		  */
	if (TIM_ReadDecounterValue(VEN_VALVE_TIM) == 0)
	{
/*%C  Valve Detection :		  												  */
/*%C  if MEASURE_VALVE_PRESSURE_S16 < cVALVE_DETECT_LEVEL, then 			  */
		if (MeasureValvePressure < (SWORD16)cVALVE_DETECT_LEVEL) 
		{
/*%C	ValveDetected = FALSE												  */
			ValveDetected = FALSE;
		}
/*%C  else, ValveDetected = TRUE											  */
		else
		{
			ValveDetected = TRUE;
		}
/*%C	End if 																  */
/*%C  Storage of Valve detection state in data base	 						  */
/*%C  VALVE_DETECTED_U16 = ValveDetected									  */	
		DB_ControlWrite(VALVE_DETECTED_U16,ValveDetected);
/*%C VALVE_DETECT_IN_PROGRESS_U16 = FALSE									  */
		DB_ControlWrite(VALVE_DETECT_IN_PROGRESS_U16,FALSE);
	}
}
