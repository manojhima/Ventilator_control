/*****************************************************************************/
/*                                                                            */
/* Project N°  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : MAIN_Version_Error_Mngt.c                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C       If it is a bad version, then the ventilation is not allowed, 		*/
/*%C		  and a message is displayed continously.         							*/
/******************************************************************************/
/*%I Input Parameter :  NONE                                                  */
/*%IO Input/Output :    NONE	                                                */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/
/******************************************************************************/
/*                                INCLUDE FILES		                           */
/******************************************************************************/
#ifndef _TASKING
#include "LH_ST10F276.h"
#include <intrins.h>
#else
#include "regf276e.h"
#endif
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../GENERAL/define.h"

#include "../GENERAL/io_declare.h"
#include "../DRIVERS_DISPLAY/Driver_Display_Data.h"
#include "../DATABASE/Db_Config.h"
#include "../DATABASE/DB_Control.h"
#include "../DATABASE/DB_Rtc.h"
#include "../DATABASE/DB_Current.h"
#include "../DATABASE/Db_AlarmStatus.h"
#include "../DATABASE/DB_Event.h"
#include "Security_Datas.h"
#include "../DATABASE/Db_AlarmStatus.h"
#include "MAIN_Version_Error_Mngt.h"
#include "../DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
#include "../DRIVERS/DRV_VarEeprom.h"
#include "../PUST/PUST.h"
			 
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void MAIN_Version_Error_Mngt(void)
{
/*%C If a bad version is detected, an alarm flag is set         			      */
   if ( (BadVersion == TRUE)
     && (EEP_DB_Config[VENTIL_REQ_U16] == FALSE) ) 
   {
/*%C 	Ventilation stop if reboot         			      */
      DB_ConfigWrite(VENTIL_REQ_U16,FALSE);

#ifndef _TASKING
/*%C 	Enter infinite loop         			      */
      PUST_Checks(TRUE, PUST_SOFT_VERSION_CHECK_REQ);
#endif	
	}
}