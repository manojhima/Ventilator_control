/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : SEC_Fio2OffsetDefault.c                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C           Exhalatory Flow Offset Default		     	           		  		*/
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter : NONE                                                   */
/*%IO Input/Output : NONE                                                     */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/
/*
SFSYSTEV3.137
FiO2 OFFSET
the software shall record this event when the FiO2 OFFSET DEFAULT alarm is detected
*/
/******************************************************************************/
/*                                INCLUDE FILES		                           */
/******************************************************************************/
#include "../GENERAL/typedef.h"
#include "../DATABASE/DB_Event.h"
#include "../GENERAL/enum.h"
#include "../DATABASE/DB_AlarmStatus.h"
#include "../SECURITY/Security_Datas.h"
#include "SEC_Fio2OffsetDefault.h"

/* locate security code to specific section */  
#include "../SECURITY/locate_security_code.h" 

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
void SEC_Fio2OffsetDefault(void)
{
	UWORD16 Fio2OffsetDefault = DB_AlarmStatusRead(TECH_ALARM_FIO2_OFFSET_DEFAULT);
 
/*%C When the TRUE state is read, the alarm is set to the FALSE state			*/
	if(Fio2OffsetDefault >= ALARM_TRUE)
	{
		DB_AlarmStatusWrite(TECH_ALARM_FIO2_OFFSET_DEFAULT,
		                    ALARM_FALSE);
	}
/*%C When the DETECTED state is read, an event is sent and the alarm is set to*/
/*%C the TRUE state*/
	if (Fio2OffsetDefault == ALARM_DETECTED) 
	{
	   DB_EventMngt(EVENT_ALT_FIO2_OFFSET);
      DB_AlarmStatusWrite(TECH_ALARM_FIO2_OFFSET_DEFAULT,
                          ALARM_TRUE);
	}
}