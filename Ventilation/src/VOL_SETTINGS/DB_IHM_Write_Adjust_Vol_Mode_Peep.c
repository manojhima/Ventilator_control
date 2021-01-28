/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Vol_Mode_Peep.c	 			         		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new limits		*/
/*%C        of the linked settings, function of peep conditions:					*/
/*                                                            				  		*/
/*%C If PEEP + 2 > LOW PIP => LOW PIP = PEEP + 2      								*/
/*%C If PEEP + 10 > HIGH PIP => HIGH PIP = PEEP + 10    								*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				*Value                                		  	*/
/*%IO Input/Output Parameter : 	None  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/


/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/
UWORD16 DB_IHM_Write_Adjust_Vol_Mode_Peep(UWORD16 *Value)
{
/* Id values recuperation from adjust base in vol mode */
   UWORD16 Adjust_Low_Pip		=     EEP_DB_VOL_Adjust[ADJUST_LOW_PIP_U16];
   UWORD16 Adjust_High_Pip		=     EEP_DB_VOL_Adjust[ADJUST_HIGH_PIP_U16];

/*%C Peep value writing */
   DB_WriteDataInEepAndRam(&EEP_DB_VOL_Adjust[ADJUST_PEEP_U16],
									*Value);

/*%C Dependence test between peep and low pip */
	if (*Value + cPeepLowPipHysteresis > Adjust_Low_Pip )
	{	
/*%C  ADJUST_LOW_PIP affectation */
      DB_WriteDataInEepAndRam(&EEP_DB_VOL_Adjust[ADJUST_LOW_PIP_U16],
									   (*Value + cPeepLowPipHysteresis));
   }

/*%C Dependence test between peep and high pip */
	if (*Value + cPeepHighPipHysteresis > Adjust_High_Pip)
	{	
/*%C  ADJUST_HIGH_PIP affectation */
      DB_WriteDataInEepAndRam(&EEP_DB_VOL_Adjust[ADJUST_HIGH_PIP_U16],
									   (*Value + cPeepHighPipHysteresis));
   }

/*%C In this function the result is always TRUE */
	return(TRUE);
}
