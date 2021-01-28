/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Psv_Mode_Low_Vti.c		          		   */
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the            	*/
/*%C        Low Vti setting in the Psv mode    	      								*/
/*                                                            				  		*/
/*%C if LOW VTI > HIGH VTI - 20 => HIGH VTI = LOW VTI + 20	 						*/
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

UWORD16 DB_IHM_Write_Adjust_Psv_Mode_Low_Vti(UWORD16 *Value)
{
/*%C Id values recuperation from adjust base in psv mode */
   UWORD16 Adjust_High_Vti = EEP_DB_PSV_Adjust[ADJUST_HIGH_VTI_U16];
   UWORD16 High_Vti_No_Select = EEP_DB_PSV_Adjust[HIGH_VTI_NO_SELECT_U16];

/*%C Low Vti Writing */
   DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_LOW_VTI_U16],
 								   *Value);

   if (High_Vti_No_Select == TRUE)
   {
/*%C  High/Low Vti dependance */
      if (*Value > Adjust_High_Vti - cLowVtiHighVtiHysteresis)
      {
/*%C     High Vti writing by DB_WriteDataInEepAndRam function call 	*/
         DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_HIGH_VTI_U16],
										   *Value + cLowVtiHighVtiHysteresis);
      }
   }
   return(TRUE);
}



 
