/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: DB_RTCWrite.c 				   				                  		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the values in the	*/
/*%C         RTC base																			*/
/*                                                            				  		*/
/******************************************************************************/
/*%I Input Parameter : 				Id			      			                  	*/
/*%I						  				Value                                 		  	*/
/*%IO Input/Output Parameter : 	None 	        			                  		*/
/*%O Output Parameter : 			DB_Rtc[Id] 		              				  		*/
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
/******************************************************************************/
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../DRIVERS/DRV_VarEeprom.h"
#include "../DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
#define DECLARATION_RTC_BASE
#include "DB_Rtc.h"

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
void DB_RTCWrite(e_DB_RTC Id, UWORD16 Value)
{
	if(Id < end_of_db_rtc_table)
	{
//		if (Value > cDB_TEST_RTC_DB[Id+cOFFSET_RTC].maxi)
//		{
//			Value = cDB_TEST_RTC_DB[Id+cOFFSET_RTC].maxi;
//		}
//		else if (Value < cDB_TEST_RTC_DB[Id+cOFFSET_RTC].mini)
//		{
//			Value = cDB_TEST_RTC_DB[Id+cOFFSET_RTC].mini;
//		} // commented by manoj need to check where cOFFSET_RTC exists
		DB_Rtc[Id] = (UWORD16)Value;	
	}
}
