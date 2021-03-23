/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Vol_Mode_Sigh_Cpt.c 		         		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the sigh cpt setting in the Vol mode	 								*/
/*  					                                            				  		*/
/*%C SIGH CPT [min:50, max:250, step:50, default:50]       							*/
/*%C SIGH CPT is include in its own limits(otherwise, value is saturated)		*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTSET2.18
Cpt Sigh
Unit: N.A.
Min Value: 50
Max Value: 250
List of Values: N.A.
Step: 50
Default Value: 50
Links: N.A.
Auto-adjustement: N.A.
Comments: available only if Sigh is set to Yes

SFSYSTCOMDP14.2.51
Cpt Sigh setting
Offset (byte): 102
103
Format: 16 bits
Data: sigh cpt
Range: 50 to 250
AA AA = not used
Unit: NA

SFSYSTCOMDP93.5.24
Cpt Sigh setting
Offset (byte): 91
Format: 8 bits
Data: Cpt Sigh
Range: 50 to 250 0 = not used
Unit: NA
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

UWORD16 DB_IHM_Setting_Adjust_Vol_Mode_Sigh_Cpt(UWORD16 *Value,
															  UWORD16 Id)
{
/*%C Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Limit tests */
   if ( (*Value < cDB_VOL_TEST_ADJUST_DB[Id].mini)
	  || (*Value > cDB_VOL_TEST_ADJUST_DB[Id].maxi)	)
   {
		Function_Result = TRUE;
   }
   else
   {
/*%C 	Setting authorized  */
		Function_Result = FALSE;
   }
	return(Function_Result);
}
