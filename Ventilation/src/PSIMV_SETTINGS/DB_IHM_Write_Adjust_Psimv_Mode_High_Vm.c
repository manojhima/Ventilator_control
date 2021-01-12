/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Psimv_Mode_High_Vm.c 	          		   */
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the            	*/
/*%C        High_Vm setting in the Psv mode  	      								*/
/*                                                            				  		*/
/*%C if HIGH VM < LOW VM + 10 => LOW VM = HIGH VM - 10								*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/


/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../DRIVERS/DRV_VarEeprom.h"
#include "../DATABASE/DB_Current.h"
#include "../DATABASE/DB_Control.h"
#include "../DATABASE/DB_Rtc.h"
#include "../DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

/* locate database code to specific section */
#include "../GENERAL/locate_database_code.h"

/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Write_Adjust_Psimv_Mode_High_Vm(UWORD16 *Value)
{
/*%C Id values recuperation from adjust base in psv mode */
   UWORD16 Adjust_Low_Vm = EEP_DB_PSIMV_Adjust[ADJUST_LOW_VM_U16];


/*%C High Vm Writing */
   DB_WriteDataInEepAndRam(&EEP_DB_PSIMV_Adjust[ADJUST_HIGH_VM_U16],
 								   *Value);


/*%C  High/Low Vm dependance */
      if (*Value < Adjust_Low_Vm + cLowVmHighVmHysteresis)
      {
/*%C     Low Vm writing by DB_WriteDataInEepAndRam function call 	*/
         Adjust_Low_Vm = (UWORD16)(*Value - cLowVmHighVmHysteresis);

         DB_WriteDataInEepAndRam(&EEP_DB_PSIMV_Adjust[ADJUST_LOW_VM_U16],
								Adjust_Low_Vm);
      }

   return(TRUE);
}
 