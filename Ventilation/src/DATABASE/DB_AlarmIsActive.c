/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: DB_AlarmStatusRead.c	 	   				                  		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*
SFSYSTEV1.10
Alarm Inhibition
the software shall record this event when the INHIBITION KEY is SHORT PRESS and an alarm
*/
/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/DATABASE/DB_AlarmStatus.h"
#include "../../inc/SECURITY/Security_Datas.h"
/******************************************************************************/
/*                     EXTERNAL FUNCTION DECLARATION                         	*/
/******************************************************************************/
e_BOOL DB_AlarmIsActive(e_DB_ALARM_LEVEL_PRIORITY prio)
{
    e_BOOL active = FALSE;

    switch (prio) {

        case HP :
        /* High */
        active = (SEC_High_Priority_1 || SEC_High_Priority_2 || SEC_High_Priority_3)?TRUE:FALSE;
        break;

        case MPR :
        /* Medium */
        active = (SEC_Medium_Priority_1 || SEC_Medium_Priority_2 || SEC_Medium_Priority_3)?TRUE:FALSE;
        break;

        case LP :
        /* Low */
        active = (SEC_Low_Priority)?TRUE:FALSE;
        break;

        default:
        break;
    }
    return active;
}

e_BOOL DB_AlarmIsOneActive(void)
{
    return (DB_AlarmIsActive(HP) || DB_AlarmIsActive(MPR) || DB_AlarmIsActive(LP));
}
