/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Psv_Mode_Target_Vt.c	     	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new value		*/
/*%C        of the Target VT in the Psv mode        	     							*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTEV2.27
Vt target
the software shall record this event when a new Vt target is set

SFSYSTCOMDP14.2.26
Vt Target setting
Offset (byte): 052
053
Format: 16 bits
Data: target vt
Range: 50 to 2000
AA AA = not used
Unit: ml

SFSYSTCOMDP93.3.11
Vt Target setting
Offset (byte): 75
76
Format: 2*8 bits
Data: Vt Target
Range: 0 to 2000
Unit: ml

SFSYSTCOMDP93.4.11
Vt Target setting
Offset (byte): 75
76
Format: 2*8 bits
Data: Vt Target
Range: 0 to 2000
Unit: ml
*/

/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Write_Adjust_Psv_Mode_Target_Vt(UWORD16 *Value)
{
/* Id values recuperation from adjust base in psv mode */

   	UWORD16 Target_Vt_Select = EEP_DB_PSV_Adjust[TARGET_VT_SELECT_U16];
   	UWORD16 Adjust_Low_Vte = EEP_DB_PSV_Adjust[ADJUST_LOW_VTE_U16];
   	UWORD16 Adjust_Low_Vti = EEP_DB_PSV_Adjust[ADJUST_LOW_VTI_U16];
   	UWORD16 Adjust_High_Vti = EEP_DB_PSV_Adjust[ADJUST_HIGH_VTI_U16];
   	UWORD16 Adjust_High_Vte = EEP_DB_PSV_Adjust[ADJUST_HIGH_VTE_U16];
   	UWORD16 Target_Vt_Default_Value
   						= cDB_PSV_TEST_ADJUST_DB[ADJUST_TARGET_VT_U16].defvalue;

/*%C Target Vt saturation (max) */
   if (*Value > cDB_PSV_TEST_ADJUST_DB[ADJUST_TARGET_VT_U16].maxi)
	{
      *Value = cDB_PSV_TEST_ADJUST_DB[ADJUST_TARGET_VT_U16].maxi;
	}

/*%C If target Vt selected,  */
   if (Target_Vt_Select == FALSE)
	{
/*%C  Target Vt set to default value */
      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_TARGET_VT_U16],
								      Target_Vt_Default_Value);						
	}
/*%C  Target Vt set to the request value */
	else
	{
      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_TARGET_VT_U16],
								      *Value);
/*%C Target Vt / Low Vte dependance */
		if (Adjust_Low_Vte >= *Value)
		{
	      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_LOW_VTE_U16],
									      *Value - 10);
		}                                
	
/*%C Target Vt / Low Vti dependance */
		if (Adjust_Low_Vti >= *Value)
		{
	      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_LOW_VTI_U16],
									      *Value - 10);
		}                                
	
/*%C Target Vt / High Vti dependance */
		if (Adjust_High_Vti <= *Value)
		{
	      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_HIGH_VTI_U16],
									      *Value + 10);
		}                                
	
/*%C Target Vt / High Vte dependance */
		if (Adjust_High_Vte <= *Value)
		{
	      DB_WriteDataInEepAndRam(&EEP_DB_PSV_Adjust[ADJUST_HIGH_VTE_U16],
									      *Value + 10);
		} 
	}
   
                                

/*%C This function always return TRUE */
	return(TRUE);
}
