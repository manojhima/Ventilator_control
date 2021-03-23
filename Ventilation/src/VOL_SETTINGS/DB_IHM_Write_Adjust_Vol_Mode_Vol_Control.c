/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Write_Adjust_Vol_Mode_Vol_Control.c 	  	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function writes the new limits		*/
/*%C        of the linked settings, function of vol control conditions:   		*/
/*                                                            				  		*/
/*%C If VOL CONTROL - 10 < LOW VTE  =>  LOW VTE  = VOL CONTROL - 10				*/
/*%C If VOL CONTROL + 10 > HIGH VTE =>  HIGH VTE = VOL CONTROL	+ 10				*/
/*%C If VOL CONTROL * SIGH VT COEF > 2000ml  											*/
/*%C											=>  SIGH VT COEF = VOL CONTROL / 2000		*/
/******************************************************************************/
/*%I 	Input Parameter :				*Value                                		  	*/
/*%IO Input/Output Parameter : 	None  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTSET2
VOL CONTROL settings

SFSYSTSET5.1
VOL CONTROL
Unit: ml
Min Value: 50
Max Value: 2000
List of Values: N.A.
Step: 10
Default Value: 500
Links: 3 lpm <= (VOL CONTROL*60) / (TI CONTROL*1000) <= 100 lpm
LOW VTE <= VOL CONTROL - 10
VOL CONTROL <= HIGH VTE - 10
Auto-adjustement: LOW VTE
HIGH VTE
Comments: No comment

SFSYSTEV2.10
Vol Control
the software shall record this event when a new Vol Control is set

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
#include "../../inc/VOL_SETTINGS/DB_IHM_Write_Adjust_Vol_Mode_Vol_Control.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/
UWORD16 DB_IHM_Write_Adjust_Vol_Mode_Vol_Control(UWORD16 *Value)
{
/* Id values recuperation from adjust base in vol mode */
   UWORD16 Adjust_Low_Vte   = EEP_DB_VOL_Adjust[ADJUST_LOW_VTE_U16];
   UWORD16 Adjust_High_Vte  = EEP_DB_VOL_Adjust[ADJUST_HIGH_VTE_U16];
   UWORD16 Adjust_Sigh_Vt_Coef = EEP_DB_VOL_Adjust[ADJUST_SIGH_VT_COEF_U16];


/*%C Vol Control writing */
   DB_WriteDataInEepAndRam(&EEP_DB_VOL_Adjust[ADJUST_VOL_CONTROL_U16],
									*Value);						
		  
/*%C Dependence test between vol control and low vte */
	if (*Value < Adjust_Low_Vte + cVolControlLowVteHysteresis)
	{
/*%C  ADJUST_LOW_VTE affectation */
		DB_WriteDataInEepAndRam(&EEP_DB_VOL_Adjust[ADJUST_LOW_VTE_U16]
										, *Value - cVolControlLowVteHysteresis);
	}
/*%C Dependence test between vol control and high vte */
	if (*Value > Adjust_High_Vte - cVolControlHighVteHysteresis)
	{
/*%C  ADJUST_LOW_VTE affectation */
		DB_WriteDataInEepAndRam(&EEP_DB_VOL_Adjust[ADJUST_HIGH_VTE_U16] 
										, *Value + cVolControlHighVteHysteresis);
	}

/*%C Dependence test between vol control and Vt sigh coef */
	if ((*Value * Adjust_Sigh_Vt_Coef) / 10 >
									 cDB_VOL_TEST_ADJUST_DB[ADJUST_VOL_CONTROL_U16].maxi)
	{
/*%C  ADJUST_SIGH_VT_COEF affectation */
		DB_WriteDataInEepAndRam(&EEP_DB_VOL_Adjust[ADJUST_SIGH_VT_COEF_U16] 
			,((cDB_VOL_TEST_ADJUST_DB[ADJUST_VOL_CONTROL_U16].maxi * 10) / *Value));
	}

/*%C In this function the result is always TRUE */
   return(TRUE);
}
