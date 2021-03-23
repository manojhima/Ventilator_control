/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : SET_InspFlowOffsetDefault.c                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/



/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C           Inspiratory Flow Offset Default		                     		*/
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter : NONE                                                   */
/*%IO Input/Output : NONE                                                     */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/
/*
SFSYSTEV3.3
Insp Flow calibration
the software shall record this event when the VALIDATION KEY is SHORT PRESS on the Insp
Flow calibration field
*/

/******************************************************************************/
/*                                INCLUDE FILES	                              */
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/DATABASE/DB_Event.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/DATABASE/DB_AlarmStatus.h"
#include "../../inc/SECURITY/Security_Datas.h"
#include "../../inc/SET_UP/SET_InspFlowOffsetDefault.h"

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
void SET_InspFlowOffsetDefault(void)
{
/* Technical alarm inspiration flow recovery from base */
UWORD16 TechAlarmInspFlowOffset = 
						DB_AlarmStatusRead(TECH_ALARM_INSP_FLOW_OFFSET_DEFAULT_U16);
						 
/*%C Detection of Anomaly Default Offset internal Pressure :*/
/*%C The value DETECTED is written if the calibration has failed					*/

/*%C When the TRUE state is read, the alarm is set to the FALSE state			*/
	if(TechAlarmInspFlowOffset >= ALARM_TRUE)
	{
		DB_AlarmStatusWrite(TECH_ALARM_INSP_FLOW_OFFSET_DEFAULT_U16,
		                    ALARM_FALSE);
	}
/*%C When the DETECTED state is read, an event is sent and the alarm is set to*/
/*%C the TRUE state*/
	if (TechAlarmInspFlowOffset == ALARM_DETECTED) 
	{
	   DB_EventMngt(EVENT_ALT_INSP_FLOW_OFFSET);
      DB_AlarmStatusWrite(TECH_ALARM_INSP_FLOW_OFFSET_DEFAULT_U16,
                          ALARM_TRUE);
	}
}
