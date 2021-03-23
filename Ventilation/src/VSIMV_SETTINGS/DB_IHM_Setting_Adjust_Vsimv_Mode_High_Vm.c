/******************************************************************************/
/*																										*/
  /* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Vsimv_Mode_High_Vm.c		          		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the High_Vm setting in the Vsimv mode									*/
/*                                                            				  		*/
/*%C HIGH VM [min:20, max:990, step:5, default:OFF=90]  								*/
/*%C HIGH VM is include in its own limits(otherwise, value is saturated)		*/
/*%C (10 * VOL CONTROL x SIMV BACKUP R) /1000 + 5 < HIGH VM   						*/
/*%C If the conditions Vol Control or Simv Backup R are not        				*/
/*%C respected, a limit flag is	set for IHM indication and the value is      */
/*%C saturated                                                                */
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
#include "../../inc/VSIMV_SETTINGS/DB_IHM_Setting_Adjust_Vsimv_Mode_High_Vm.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"

/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Adjust_Vsimv_Mode_High_Vm(UWORD16 *Value,
															    UWORD16 Id)
{
/*%C Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Id values recuperation from adjust base in Vsimv mode */
   UWORD16 Adjust_Low_Vm = EEP_DB_VSIMV_Adjust[ADJUST_LOW_VM_U16];

/*%C Id values recuperation from adjust base in vol mode */
   UWORD32 Adjust_Control_R    =
                       (UWORD32) EEP_DB_VSIMV_Adjust[ADJUST_CONTROL_R_U16];
   UWORD32 Adjust_Vol_Control  =
                       (UWORD32) EEP_DB_VSIMV_Adjust[ADJUST_VOL_CONTROL_U16];
	
/*%C Datas declaration for the compute	 */
   UWORD32 Volume_Per_Minute = 0;
	
	if(Adjust_Control_R <= cSIMV_BACKUP_R_MIN)
	{
		Adjust_Control_R = cSIMV_BACKUP_R_MIN; 	
	}


/* Volume_Per_Minute en lpm avec 10: VM en dl; 1000: VOL_CONTROL en ml */
   Volume_Per_Minute = (100 * Adjust_Vol_Control * Adjust_Control_R) / 1000u;
/* Volume_Per_Minute rounded to the upper 50 ml if it is not an integer value*/
   if((Volume_Per_Minute % 50) != 0)
   {
       Volume_Per_Minute = Volume_Per_Minute 
   					     - (Volume_Per_Minute % 50); 
       Volume_Per_Minute = Volume_Per_Minute 					  
					     + 50;
   }
   Volume_Per_Minute = Volume_Per_Minute / 10;

/*%C Limit tests */
   if (*Value < cDB_VSIMV_TEST_ADJUST_DB[Id].mini)
   {
		Function_Result = TRUE;
   }
   else if (*Value > cDB_VSIMV_TEST_ADJUST_DB[Id].maxi)
   {
/*%C  High Vm No select flag writing  	*/
		DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[HIGH_VM_NO_SELECT_U16],
										TRUE);
		Function_Result = TRUE;
   }
   else if (*Value <= (UWORD16)Volume_Per_Minute + cHighVmVolumePerMinuteHysteresis)
   {
/*%C  => Vol Control and Control R flag for IHM indication */
		DB_ControlWrite(LIMIT_VOL_CONTROL_U16,
							 TRUE);
		DB_ControlWrite(LIMIT_CONTROL_R_U16,
							 TRUE);
      Function_Result = TRUE;
   }
/*%C Dependence test between high and low Vm */
   else if (*Value < Adjust_Low_Vm + cLowVmHighVmHysteresis)
   {
	   if (EEP_DB_VSIMV_Adjust[LOW_VM_NO_SELECT_U16] == FALSE)
      {
/*%C     Value out of range,        */
/*%C     => value robustness        */
         *Value = (Adjust_Low_Vm + cLowVmHighVmHysteresis);
/*%C     => Low vm flag for IHM indication */
		   DB_ControlWrite(LIMIT_LOW_VM_U16,
							   TRUE);
      }
	   Function_Result = FALSE;
   }
/*%C If "no select flag" activated => "no select flag" cancelled */
	else if (EEP_DB_VSIMV_Adjust[HIGH_VM_NO_SELECT_U16] == TRUE)
	{
		DB_WriteDataInEepAndRam(&EEP_DB_VSIMV_Adjust[HIGH_VM_NO_SELECT_U16],
										FALSE);
/*%C  Vol Control and Control R flag desactivation */
		DB_ControlWrite(LIMIT_CONTROL_R_U16,
							 FALSE);
		DB_ControlWrite(LIMIT_VOL_CONTROL_U16,
							 FALSE);
/*%C  Low vm flag for IHM indication */
	   DB_ControlWrite(LIMIT_LOW_VM_U16,
							 FALSE);
		Function_Result = TRUE;
	}
   else
   {
/*%C  Setting authorized */
/*%C  Low vm flag for IHM indication */
	   DB_ControlWrite(LIMIT_LOW_VM_U16,
							 FALSE);
/*%C  Vol Control and Control R flag desactivation */
		DB_ControlWrite(LIMIT_CONTROL_R_U16,
							 FALSE);
		DB_ControlWrite(LIMIT_VOL_CONTROL_U16,
							 FALSE);

      Function_Result = FALSE;
   }

   return(Function_Result);
}
