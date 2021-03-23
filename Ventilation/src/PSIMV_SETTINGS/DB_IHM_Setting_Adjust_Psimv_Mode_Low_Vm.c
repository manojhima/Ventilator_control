/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Psimv_Mode_Low_Vm.c 		          		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the Low_Vm setting in the Psimv mode									*/
/*                                                            				  		*/
/*%C LOW VM [min:5, max:500, step:5, default:OFF=40]      							*/
/*%C LOW VM is include in its own limits(otherwise, value is saturated)   	   */
/*%C LOW VM <= HIGH VM - 10 dlpm         									            */
/*%C If the conditions on High Vm is not respected, a limit flag is	set for  */
/*%C IHM indication and the value is saturated                                */
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
//#include "DB_IHM_Setting_Adjust_Psimv_Mode_Low_Vm.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"

/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Adjust_Psimv_Mode_Low_Vm(UWORD16 *Value,
															   UWORD16 Id)
{

/*%C Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Id values recuperation from adjust base in psimv mode */
   UWORD16 Adjust_High_Vm = EEP_DB_PSIMV_Adjust[ADJUST_HIGH_VM_U16];

/*%C Limit tests */
   if (*Value < cDB_PSIMV_TEST_ADJUST_DB[Id].mini)
	{
/*%C  Low Vm No select flag writing  	*/
		DB_WriteDataInEepAndRam(&EEP_DB_PSIMV_Adjust[LOW_VM_NO_SELECT_U16],
										TRUE);
		Function_Result = TRUE;
	}
   else if (*Value > cDB_PSIMV_TEST_ADJUST_DB[Id].maxi)
	{
		Function_Result = TRUE;
	}
/*%C Dependence test between high and low Vm */
   else if (*Value >= Adjust_High_Vm - cLowVmHighVmHysteresis)
   {
	   if (EEP_DB_PSIMV_Adjust[HIGH_VM_NO_SELECT_U16] == FALSE)
      {
/*%C     Value out of range,        */
         *Value = (Adjust_High_Vm - cLowVmHighVmHysteresis);
/*%C     => Low vm flag for IHM indication */
		   DB_ControlWrite(LIMIT_HIGH_VM_U16,
							   TRUE);
      }
	   Function_Result = FALSE;
   }
/*%C If "no select flag" activated => "no select flag" cancelled */
	else if (EEP_DB_PSIMV_Adjust[LOW_VM_NO_SELECT_U16] == TRUE)
	{
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
		DB_WriteDataInEepAndRam(&EEP_DB_PSIMV_Adjust[LOW_VM_NO_SELECT_U16],
										FALSE);
/*%C  High vm flag desactivation */
		DB_ControlWrite(LIMIT_HIGH_VM_U16,
							 FALSE);
		Function_Result = TRUE;
	}
   else
   {
/*%C  Setting authorized */
/*%C  High vm flag desactivation */
		DB_ControlWrite(LIMIT_HIGH_VM_U16,
							 FALSE);

      Function_Result = FALSE;
   }

	return(Function_Result);
}