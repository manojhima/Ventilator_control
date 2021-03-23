/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: DB_IHM_Write_Access.c			    			                  		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function manages the writing		*/
/*%C        operation in the different bases function of DbType parameter		*/
/*                                                            				  		*/
/******************************************************************************/
/*%I Input Parameter :				Id                                    		  	*/
/*%I                    			DbType                                		  	*/
/*%I                    			DataOperation                         		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
1) SFSYSTUSB1.6.23
The software shall read the settings in database and write them in the settings file according to
SFSYSTCOMFILE1

2) SFSYSTUSB1.4.24
The software shall read the settings in database and write them in the settings file according to
SFSYSTCOMFILE

note: SFSYSTCOMFILE1
SETTINGS FILE FORMAT
Settings data shall be recorded in a "SPR_Settings.spr" file.
Settings file shall have the following format :
Serial Number (12 bytes).
Date and Hour (5 bytes).
Setting data packet (108 bytes) (Refers to SFSYSTCOMDP14).
CCITT CRC (2 bytes) (CRC computed on all data excepted the 2 last bytes).
*/


/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/

#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_AlarmStatus.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/DATABASE/DB_Event.h"
#include "../../inc/DATABASE_SETTINGS/DB_IHM_Write_Info_Access.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
#include "../../inc/DATABASE/DB_AlarmStatus.h"
#include "../../inc/DATABASE/DB_KeyboardEvent.h"
#include "../../inc/DATABASE/DB_PowerSupply.h"

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

UWORD16 DB_IHM_Write_Info_Access(UWORD16 *Value,
									 UWORD16 Id,
									 e_TYPE_OF_DB_TARGET DbType)
{
/* Function result declaration */
   UWORD16 Function_Result = FALSE;

   switch (DbType)
   {
/*%C	Alarm base info writing*/
		case ALARMS:
		{
			DB_AlarmInfoWrite(Id, (UBYTE)*Value);
			Function_Result = TRUE;
		}
			break;
		default:
		{
			Function_Result = DB_IHM_Write_Access(Value, Id, DbType);
		}
			break;		
	}
	
	return(Function_Result);
}



