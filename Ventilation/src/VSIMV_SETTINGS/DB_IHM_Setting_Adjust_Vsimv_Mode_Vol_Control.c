/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Vsimv_Mode_Vol_Control.c  	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the Vol_Control setting in the Vsimv mode								*/
/*                                                            				  		*/
/*%C VOL CONTROL [min:50, max:2000, step:10, default:500]         				*/
/*%C VOL CONTROL is include in its own limits(otherwise, value is saturated)  */
/*%C 3 lpm <= (VOL CONTROL * 60) / TI CONTROL <= 100 lpm    							*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
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
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
#include "../../inc/VSIMV_SETTINGS/DB_IHM_Setting_Adjust_Vsimv_Mode_Vol_Control.h"

/* locate database code to specific section */
#include "../../inc/GENERAL/locate_database_code.h"


/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/
UWORD16 DB_IHM_Setting_Adjust_Vsimv_Mode_Vol_Control(UWORD16 *Value, 
                                                     UWORD16 Id)
{


    /* Function result declaration */
    UWORD16 Function_Result = FALSE;

    /* Datas declaration for the compute	 */
    UWORD32 Volume_Inspired_Per_Minute = 0;

    /* Id values recuperation from adjust base in vsimv mode */
    UWORD32 Adjust_Ti_Control = 
        (UWORD32)EEP_DB_VSIMV_Adjust[ADJUST_TI_CONTROL_U16];

    /* Computed values*/
    Volume_Inspired_Per_Minute = ((UWORD32)(*Value) * 60u) / Adjust_Ti_Control ;

    /*%C Limit tests */
    if ( (*Value < cDB_VSIMV_TEST_ADJUST_DB[Id].mini)
         || (*Value > cDB_VSIMV_TEST_ADJUST_DB[Id].maxi)  )
    {
        Function_Result = TRUE;
    }
    /*%C Dependence test between Vol Control and Ti Control */
    else if ( (Volume_Inspired_Per_Minute < cPeakFlowMin)
              || (Volume_Inspired_Per_Minute > cPeakFlowMax) )
    {
        /*%C  Value out of range => Vol Control flag for IHM indication */
        DB_ControlWrite(LIMIT_TI_CONTROL_U16,
                        TRUE);
        Function_Result = TRUE;
    }
    else
    {
        /*%C Setting authorized, Ti Control flag desactivated */
        DB_ControlWrite(LIMIT_TI_CONTROL_U16,
                        FALSE);
        Function_Result = FALSE;
    }
    return(Function_Result);
}
