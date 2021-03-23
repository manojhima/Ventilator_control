/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Psimv_Mode_Low_Vm.c		          		   */
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the            	*/
/*%C        Low Vm setting in the Psimv mode    	      	  						*/
/*                                                            				  		*/
/*%C if LOW VM > HIGh VM - 10 => HIGH VM = LOW VM + 10								*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTCOMDP93.2.29
Vm measure
Offset (byte): 45
46
Format: 2*8 bits
Data: Vm
Range: 0 to 999
Unit: 10-1 l/min

SFSYSTCOMDP303.2.11
Vm measure
Offset (byte): 14
15
Format: 2*8 bits
Data: Vm
Range: 0 to 999
Unit: 10-1 l/min
*/

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

UWORD16 DB_IHM_Write_Adjust_Psimv_Mode_Low_Vm(UWORD16 *Value)
{
/*%C Id values recuperation from adjust base in psv mode */
   UWORD16 Adjust_High_Vm = EEP_DB_PSIMV_Adjust[ADJUST_HIGH_VM_U16];


/*%C Low Vm Writing */
   DB_WriteDataInEepAndRam(&EEP_DB_PSIMV_Adjust[ADJUST_LOW_VM_U16],
 								   *Value);


/*%C  High/Low Vm dependance */
      if (*Value > Adjust_High_Vm - cLowVmHighVmHysteresis)
      {
/*%C     High Vm writing by DB_WriteDataInEepAndRam function call 	*/
         Adjust_High_Vm = (UWORD16)(*Value + cLowVmHighVmHysteresis);

         DB_WriteDataInEepAndRam(&EEP_DB_PSIMV_Adjust[ADJUST_HIGH_VM_U16],
								Adjust_High_Vm);
      }

   return(TRUE);
}


 
