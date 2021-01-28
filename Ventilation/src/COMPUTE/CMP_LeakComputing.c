/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : CMP_LeakComputing.c      		                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C   This function computes leak value during inspiration     			  */
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter : NONE                                                   */
/*%IO Input/Output : NONE                                                     */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                           */
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/DATABASE/DB_Current.h"
#include "../../inc/DATABASE/DB_Compute.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/VENTILATION/Ventilation_Datas.h"
#include "../../inc/COMPUTE/CMP_LeakComputing.h"
#include "../../inc/VENTILATION/Ventilation_Compute_data.h"
#include "math.h"
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void CMP_LeakComputing(void)
{							  

	SWORD16 Measure_Patient_Pressure = DB_ComputeRead(MEASURE_PATIENT_PRESSURE_S16);
	UWORD16 ValveDetected = DB_ControlRead(VALVE_DETECTED_U16);

	// Calcul de leak
	if (ValveDetected == FALSE)
	{
		// Calcul du d�bit de fuite
		VEN_LeakVtiCorrection =  ((sqrt(VEN_LeakFlowFactorAverage * (double)Measure_Patient_Pressure))/10);

	}
	else
	{
		VEN_LeakVteCorrection =  ((sqrt(VEN_LeakFlowFactorAverage * (double)Measure_Patient_Pressure))/10);

	}
}
