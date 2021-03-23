/******************************************************************************/
/*																										*/
/* Project Number	: 	RC1205     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Config_Adjust_Mode_S2.c 		  	     				*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*
1) SFSYSTHMI10.2
When VALIDATION KEY is SHORT PRESS on a selected new mode in stand by mode, the
software must display the new mode settings

2) SFSYSTHMI10.5
the software shall record the new mode settings and display the running mode settings if there is
no key action before 14 s

3) SFSYSTHMI10.6
the software must display and activate the new mode settings, if the Accept mode is set to Yes

4) SFSYSTHMI10.7
If a valve is detected, only Vol control, Pres Control, PSV, PSIMV and VSIMV modes are
available

5) SFSYSTHMI10.8
If no valve is detected, only CPAP, Pres Control and PSV modes are available

*/

/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of the adjust mode in the Config base     							*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/


/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/GENERAL/define.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
//#include "DB_IHM_Setting_Config_Adjust_Mode.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Config_Adjust_Mode_S2(UWORD16 *Value,
															 UWORD16 Increase)
{

/* Function result declaration */
   UWORD16 Function_Result = FALSE;
   UWORD16 ValveDetected = DB_ControlRead(VALVE_DETECTED_U16);
   UWORD16 VentilAuthorization = DB_ControlRead(VENTIL_AUTHORIZATION_U16);
	static e_MODE_TYPES PreviousValveMode = PRES;

/*%C 	during ventilation, only the CPAP, PRES and PSV modes are authorized	 */
	if ( (VentilAuthorization == TRUE)
	  && (ValveDetected == TRUE) )
	{
/*%C  Only PRES or PSVT for valve modes */
		if (PreviousValveMode == PRES)
		{
			*Value = PSVT;			
		}
		else
		{
			*Value = PRES;			
		}
/*%C  Previous valve mode update */
		PreviousValveMode = *Value;
	 }
/*%C else, leak modes management for PRES, PSVT and CPAP modes or */
/*%C ventilation OFF	 */
	else
	{
/*%C  increase sequence for leak modes: PRES --> PSVT --> CPAP --> PRES... */
      if (Increase == TRUE)
      {
			if (*Value >= CPAP)
			{
			       *Value = PRES;
			}
			else if ((*Value == VSIMV) || (*Value == PSIMV))
			{
			       *Value = CPAP;
			}
      }
/*%C  decrease sequence for leak modes: CPAP --> PSVT --> PRES --> CPAP...*/
      else
      {
			if (*Value == VOL)
			{
			       *Value = CPAP;
			}
			else if ((*Value == VSIMV) || (*Value == PSIMV))
			{
				   *Value = PSVT;
			}
      }
	}
   Function_Result = FALSE;


	return(Function_Result);
}
