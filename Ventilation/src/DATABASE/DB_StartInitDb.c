/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: DB_StartInitDb.c 			   				                  		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function makes the init process	*/
/*%C         version prg, chek ram and init variables									*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameters :  			None          			                  		*/
/*%IO Input/Output Parameters :  None          			                  		*/
/*%O 	Output Parameters :  		None         			                  		*/
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/

#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/DATABASE/DB_Config.h"
#include "../../inc/DATABASE/DB_Event.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Current.h"
	#define DECLARATION_ALARM_STATUS_BASE
#include "../../inc/DATABASE/DB_AlarmStatus.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE/DB_Usb.h"
#include "../../inc/DATABASE/DB_StartInitDb.h"
	#define DECLARATION_IHM_ACCESS_PARA_DATABASE
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
	#define DECLARATION_SECURITY_DATAS
#include "../../inc/SECURITY/Security_Datas.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/VENTILATION/Ventilation_Compute_data.h"

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
void DB_StartInitDb(void)
{
 	UBYTE Id;

/*%C Version test function call                     									*/
   DB_SoftwareVersionTest();

/*%C Load and check Eeprom into Ram function call			    						*/
   DB_LoadAndCheckEepromIntoRam();

/*%C Tables initialization function call            									*/
   DB_InitializeTables();

#ifndef _BORLAND
/*%C Active mode memorization initialization                     			      */
	MemoMode = EEP_DB_Config[ADJUST_MODE_U16];

/*%C Adjust base to current base copy function call              			      */
	DB_CopyMngt();

/*%C Good erase and complete initialization indication in order to know if    */
/*%C an init is needed to the next device start                			      */
   do
	{
//		DB_WriteDataInEepAndRam(&EEP_DB_Config[BAD_ERASE_U16],
//		                        ERASE_OK); // manoj
//		EEP_FIFO_PushOneData(&EEP_DB_Config[BAD_ERASE_U16],
//		                     READ_EEP); // manoj
	}
	while (EEP_DB_Config[BAD_ERASE_U16] != ERASE_OK);

	/*%C Initialisation of DB_Trend's compute variables*/
	for(Id = DB_TREND_VENTIL_HOUR ; Id < DB_TREND_IHM_VENTIL_HOUR ; Id++)
	{
		CMP_VentilReport_Array[Id] = DB_TrendRead(Id);
	}

	
/*%C End of base initialization                                               */
   DB_StartInitRequest = TRUE;
#endif

}
