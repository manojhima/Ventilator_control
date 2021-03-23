/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : SET_ValvePressureOffsetDefault.c                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C           Valve pressure Offset Default			                     		*/
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter : NONE                                                   */
/*%IO Input/Output : NONE                                                     */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/
/*
SFSYSTEV3.156
CHECK VALVE PRESSURE
the software shall record this event when the CHECK VALVE PRESSURE alarm is detected
SFSYSTEV3.157
END OF CHECK VALVE PRESSURE
the software shall record this event when the CHECK VALVE PRESSURE alarm is cancelled
*/

/******************************************************************************/
/*                                INCLUDE FILES		                           */
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/DATABASE/DB_Event.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/DATABASE/DB_AlarmStatus.h"
#include "../../inc/SECURITY/Security_Datas.h"
#include "../../inc/SET_UP/SET_ValvePressureOffsetDefault.h"


/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
void SET_ValvePressureOffsetDefault(void)
{	 
/* Technical alarm valve pressure offset													*/
UWORD16 TechAlarmValvePressOffset = 
						DB_AlarmStatusRead(TECH_ALARM_VALVE_PRESS_OFFSET_DEFAULT_U16);
 
/*%C Detection of Anomaly Default Offset Pressure Valve  :*/
/*%C The values  DETECTED are written By SETUP	  */
/*%C erasing the alarm */
	if(DB_AlarmStatusRead(TECH_ALARM_VALVE_PRESS_OFFSET_DEFAULT_U16)
																					>= ALARM_TRUE)
	{
		DB_AlarmStatusWrite(TECH_ALARM_VALVE_PRESS_OFFSET_DEFAULT_U16,
								  ALARM_FALSE);
	}

	if (TechAlarmValvePressOffset == ALARM_DETECTED) 
	{
	   DB_EventMngt(EVENT_ALT_VALVE_PRESSURE_OFFSET);
      DB_AlarmStatusWrite(TECH_ALARM_VALVE_PRESS_OFFSET_DEFAULT_U16,
      						  ALARM_TRUE);
	}
}
