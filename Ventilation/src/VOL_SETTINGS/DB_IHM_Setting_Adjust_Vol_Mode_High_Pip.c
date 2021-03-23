/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Vol_Mode_High_Pip.c  		        		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the High Pip setting in the Vol mode									*/
/*                                                            				  		*/
/*%C HIGH PIP [min:150, max:600, step:10, default:400] 								*/
/*%C HIGH PIP is include in its own limits(otherwise, value is saturated)   	*/
/*%C LOW PIP <= HIGH PIP - 80                      									*/
/*%C HIGH PIP >= PEEP + 100                          									*/
/*%C If the conditions on High Pip or Peep are not respected, a limit flag is	*/
/*%C set for IHM indication and the value is saturated       				  		*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTSET2.8
HIGH PIP
Unit: cmH2O, mbar, hPa
Min Value: 12
Max Value: 90
List of Values: N.A.
Step: 1
Default Value: 40
Links: LOW PIP <= HIGH PIP – 8
PEEP + 10 <= HIGH PIP
Auto-adjustement: N.A.
Comments: No comment

SFSYSTSET5.14
HIGH PIP
Unit: cmH2O, mbar, hPa
Min Value: 12
Max Value: 90
List of Values: N.A.
Step: 1
Default Value: 40
Links: in relative pressure:
P SUPPORT + PEEP <= HIGH PIP - 2
in absolute pressure:
P SUPPORT <= HIGH PIP - 2
in both:
LOW PIP <= HIGH PIP - 8
Auto-adjustement: N.A.
Comments: No comment

SFSYSTEV2.22
High PIP
the software shall record this event when a new High PIP is set

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
#include "../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode_High_Pip.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Adjust_Vol_Mode_High_Pip(UWORD16 *Value,
																UWORD16 Id)
{
/*%C Function result declaration */
   UWORD16 Function_Result = FALSE;

/* Id values recuperation from adjust base in vol mode */
   UWORD16 Adjust_Low_Pip  = EEP_DB_VOL_Adjust[ADJUST_LOW_PIP_U16];
   UWORD16 Adjust_Peep     = EEP_DB_VOL_Adjust[ADJUST_PEEP_U16];

/*%C Limit tests */
   if ( (*Value < cDB_VOL_TEST_ADJUST_DB[Id].mini)
     || (*Value > cDB_VOL_TEST_ADJUST_DB[Id].maxi) )
   {
		Function_Result = TRUE;
   }			
/*%C Dependence test between Low Pip and High pip */
	else if (*Value < Adjust_Low_Pip + cLowPipHighPipHysteresis)
	{
/*%C  => Low Pip flag for IHM indication */
		DB_ControlWrite(LIMIT_LOW_PIP_U16,
							 TRUE);
/*%C  Peep flag limit detection */
		if (*Value < Adjust_Peep + cPeepHighPipHysteresis)
		{
/*%C  	=> Peep flag for IHM indication */
			DB_ControlWrite(LIMIT_PEEP_U16,
							 	TRUE);
		}
		Function_Result = TRUE;
	}
/*%C Dependence test between High Pip and Peep */
	else if (*Value < Adjust_Peep + cPeepHighPipHysteresis)
	{
/*%C  => Peep flag for IHM indication */
		DB_ControlWrite(LIMIT_PEEP_U16,
							 TRUE);
		Function_Result = TRUE;
	}
   else
   {
/*%C  Value in range => Low pip and Peep flag desactivation */
		DB_ControlWrite(LIMIT_LOW_PIP_U16,
							 FALSE);
		DB_ControlWrite(LIMIT_PEEP_U16,
							 FALSE);
      Function_Result = FALSE;
   }
  
	return(Function_Result);
}
