/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Psv_Mode_High_Vte.c		          		   */
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the            	*/
/*%C        High_Vte setting in the Psv mode  	      								*/
/*                                                            				  		*/
/*%C if HIGH VTE < LOW VTE + 20 => LOW VTE = HIGH VTE - 20  						*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/


/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/DATABASE/DB_Current.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Write_Adjust_Psv_Mode_High_Vte(UWORD16 *Value)
{
/*%C Id values recuperation from adjust base in psv mode */
   UWORD16 Adjust_Low_Vte = EEP_DB_PSV_Adjust[ADJUST_LOW_VTE_U16];
   UWORD16 Low_Vte_No_Select = EEP_DB_PSV_Adjust[LOW_VTE_NO_SELECT_U16];

/*%C High Vte Writing */
   DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_HIGH_VTE_U16],
 								   *Value);

   if (Low_Vte_No_Select == TRUE)
   {
/*%C  High/Low Vte dependance */
      if (*Value < Adjust_Low_Vte + cLowVteHighVteHysteresis)
      {
/*%C     Low Vte writing by DB_WriteDataInEepAndRam function call 	*/
         DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_LOW_VTE_U16],
										   *Value - cLowVteHighVteHysteresis);
      }
   }
   return(TRUE);
}
 
