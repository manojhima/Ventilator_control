/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : SEC_NoBattery.c                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C                   Management of No battery alarm                         */
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter : NONE                                                   */
/*%IO Input/Output : NONE                                                     */
/*%O Output Parameter : Alarm_Error                                           */
/******************************************************************************/
/*
SFSYSTAL18
NO BATTERY
Detection Conditions: BATTERY PRESENCE flag = No
Validation Delay: Immediate
Cancel Conditions: Auto
or CHECK SUPPLY alarm on
Priority: Medium priority
Audio Pause: yes
Alarm Pause: No
Modes: All
Actions: Events NO BATTERY + END OF NO BATTERY + display neutral symbol on BATTERY
LEVEL HOURMETER displayed
Resetconditions: N/A
Replaceventifpersistmessage: No
Circuit: all

SFSYSTEV3.29
NO BATTERY
the software shall record this event when the NO BATTERY alarm is detected

SFSYSTEV3.30
END OF NO BATTERY
the software shall record this event when the NO BATTERY alarm is cancelled
*/
/******************************************************************************/
/*                                INCLUDE FILES                               */
/******************************************************************************/
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../DATABASE/DB_AlarmStatus.h"
#include "../DATABASE/DB_Event.h"
#include "../DATABASE/DB_PowerSupply.h"
#include "SEC_NoBattery.h"
#include "../SECURITY/Security_Datas.h"

/* locate security code to specific section */  
#include "../SECURITY/locate_security_code.h" 

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
e_ALARM_ERROR SEC_NoBattery(void)
{
/*%C Alarm no battery state recovery from base                                */
    e_DB_ALARMS_STATE AlarmNoBattery = DB_AlarmStatusRead(ALARM_NO_BATTERY_U16);
/*%C Alarm check supply state recovery from base                              */
    e_DB_ALARMS_STATE AlarmCheckSupply = 
                                    DB_AlarmStatusRead(ALARM_CHECK_SUPPLY_U16);
/*%C Battery presence state recovery from base                                */
    UWORD16 NoPresenceBat = DB_PowerSupplyRead(NO_PRESENCE_BAT_U16);
/*%C Alarm error declaration                                                  */
     e_ALARM_ERROR Alarm_Error = NO_ERR_AL;

/*%C Check ALARM_NO_BATTERY_U16 state                                         */
    switch(AlarmNoBattery)
    {
/******************************************************************************/
/*%C                                  "FALSE" State                           */
/******************************************************************************/
    case ALARM_FALSE :
/*%C    if NO_PRESENCE_BAT_U16 = TRUE and ALARM_CHECK_SUPPLY_U16 = ALARM_FALSE*/ 
/*%C    then                                                                  */
        if ( (NoPresenceBat == TRUE)
          && (AlarmCheckSupply == ALARM_FALSE) )
        {
/*%C        ALARM_NO_BATTERY_U16 =  ALARM_TRUE                                */
            DB_AlarmStatusWrite(ALARM_NO_BATTERY_U16, ALARM_TRUE);
/*%C        Associated event is stored                                        */
            DB_EventMngt(EVENT_AL_NO_BATTERY);
/*%C        Priority register updating for buzzer and leds command            */
            SEC_Medium_Priority_1 = SEC_Medium_Priority_1 | 0x0800;
        }
/*%C    End if                                                                */
/*%C    Alarm_Error = NO_ERR_AL                                               */
        Alarm_Error = NO_ERR_AL;
        break;
/******************************************************************************/
/*%C                                  "DETECTED" State                        */
/******************************************************************************/
    case ALARM_DETECTED :
/*%C    Alarm_Error = ERR_AL_NO_BATTERY                                       */
        Alarm_Error = ERR_AL_NO_BATTERY;
        break;
/******************************************************************************/
/*%C                                  "TRUE" State                            */
/******************************************************************************/
    case ALARM_TRUE :
/*%C    The following state ,"ALARM_DISPLAYED", is written by HMI module.     */
/*%C    So there is no action to do.                                          */
/*%C    Alarm_Error = NO_ERR_AL                                               */
        Alarm_Error = NO_ERR_AL;
        break;
/******************************************************************************/
/*%C                                  "DISPLAYED" State                       */
/******************************************************************************/
    case ALARM_DISPLAYED    :
/*%C    if NO_PRESENCE_BAT_U16 = FALSE or ALARM_CHECK_SUPPLY_U16 >= ALARM_TRUE*/
/*%C    then                                                                  */ 
        if ( (NoPresenceBat == FALSE)
          || (AlarmCheckSupply >= ALARM_TRUE) )
        {
/*%C        ALARM_NO_BATTERY_U16 = ALARM_FALSE                                */
            DB_AlarmStatusWrite(ALARM_NO_BATTERY_U16, ALARM_FALSE);
/*%C        Associated event is stored                                        */
            DB_EventMngt(EVENT_AL_END_OF_NO_BATTERY);
/*%C        Priority register updating for buzzer and leds command            */
            SEC_Medium_Priority_1 = SEC_Medium_Priority_1 & 0xF7FF;
        }
/*%C    End if                                                                */
/*%C    Alarm_Error = NO_ERR_AL                                               */
        Alarm_Error = NO_ERR_AL;
        break;
/******************************************************************************/
/*%C                                  "CANCELED" State                        */
/******************************************************************************/
    case ALARM_CANCELED :
/*%C    Alarm_Error = ERR_AL_NO_BATTERY                                       */
        Alarm_Error = ERR_AL_NO_BATTERY;
        break;
/******************************************************************************/
/*%C                                  DEFAULT                                 */
/******************************************************************************/
    default:
/*%C    Alarm_Error = ERR_AL_NO_BATTERY                                       */
        Alarm_Error = ERR_AL_NO_BATTERY;
        break;
    }
/*%C End of check alarm state                                                 */
    return(Alarm_Error);
}
