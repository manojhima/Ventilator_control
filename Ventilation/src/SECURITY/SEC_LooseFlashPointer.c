			 /******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : SEC_LooseFlashPointer.c                                     	*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C           Alarme Loose Flash Pointer				     	           		  		*/
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter : NONE                                                   */
/*%IO Input/Output : NONE                                                     */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/
/*
FSYSTAL62
LOOSE FLASH POINTER FAULT (n°12)
Detection Conditions: The pointer address is not at a value consistent with the event logs size
Validation Delay: immediate
Cancel Conditions: NA
Priority: Visual
Audio Pause: no
Alarm Pause: No
Modes: All
Actions: Event LOOSE FLASH POINTER DEFAULT
Resetconditions: N/A
Replaceventifpersistmessage: No
Circuit: all

SFSYSTEV3.100
LOOSE FLASH POINTER
the software shall record this event when a LOOSE FLASH POINTER is detected
*/
/******************************************************************************/
/*                                INCLUDE FILES		                           */
/******************************************************************************/
#include "../GENERAL/typedef.h"
#include "../DATABASE/DB_Event.h"
#include "../GENERAL/enum.h"
#include "../DATABASE/DB_AlarmStatus.h"
#include "../SECURITY/Security_Datas.h"
#include "SEC_LooseFlashPointer.h"

/* locate security code to specific section */  
#include "../SECURITY/locate_security_code.h" 

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
void SEC_LooseFlashPointer(void)
{
	UWORD16 TechAlarmLooseFlashPointer = 
						DB_AlarmStatusRead(TECH_ALARM_LOOSE_FLASH_POINTER);
 
/*%C Detection of Anomaly Default Loose Flash Pointer :*/
/*%C The value DETECTED is written if the calibration has failed					*/

/*%C When the TRUE state is read, the alarm is set to the FALSE state			*/
	if(TechAlarmLooseFlashPointer >= ALARM_TRUE)
	{
		DB_AlarmStatusWrite(TECH_ALARM_LOOSE_FLASH_POINTER,
		                    ALARM_FALSE);
	}
/*%C When the DETECTED state is read, an event is sent and the alarm is set to*/
/*%C the TRUE state*/
	if (TechAlarmLooseFlashPointer == ALARM_DETECTED) 
   {
	   DB_EventMngt(EVENT_ALT_LOOSE_FLASH_POINTER);
      DB_AlarmStatusWrite(TECH_ALARM_LOOSE_FLASH_POINTER,
                          ALARM_TRUE);
	}
}