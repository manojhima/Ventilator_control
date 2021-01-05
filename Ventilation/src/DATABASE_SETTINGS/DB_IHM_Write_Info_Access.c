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



/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/

#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../DATABASE/DB_Control.h"
#include "../DATABASE/DB_AlarmStatus.h"
#include "../DATABASE/DB_Rtc.h"
//#include "../DRIVERS/DRV_VarEeprom.h"
#include "../DATABASE/DB_Event.h"
//#include "DB_IHM_Write_Info_Access.h"
#include "DB_IhmAccessParaDataBase.h"
#include "../DATABASE/DB_AlarmStatus.h"
#include "../DATABASE/DB_KeyboardEvent.h"
#include "../DATABASE/DB_PowerSupply.h"

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



