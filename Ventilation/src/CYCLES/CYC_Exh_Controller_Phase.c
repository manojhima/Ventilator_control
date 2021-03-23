/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : CYC_Exh_Controller_Phase.c */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C          Generation of the type of control Phase and the type of 		   */
/*            control.                                     							*/
/******************************************************************************/
/*%I Input Parameter :  NONE                                            		*/
/*%IO Input/Output :    NONE	                                              	*/
/*%O Output Parameter : NONE       															*/
/******************************************************************************/
/*
SFSYST6.13
If a sigh is set to YES, at each CPT SIGH cycles, the software must control the EXPIRATORY
FLOW SETPOINT to the adjusted PEEP until the patient INSPIRATORY TRIGGER if an INSP
SENS is adjusted or until the end of the VT SIGH x TE.
*/

/******************************************************************************/
/*                                INCLUDE FILES		                           */
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/DATABASE/DB_Compute.h"
#include "../../inc/DATABASE/DB_Current.h"
#include "../../inc/VENTILATION/Ventilation_Datas.h"
#include "../../inc/VENTILATION/Ventilation_Constants.h"
#include "../../inc/VENTILATION/Ventilation_Cycles_Datas.h"
#include "../../inc/CYCLES/CYC_Exh_Controller_Phase.h"
						 
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void CYC_Exh_Controller_Phase(void)
{

	UWORD16 VenTeCount = TIM_ReadCounterValue(VEN_TE_COUNT);
	SWORD16 MeasurePatientPressure 
											= DB_ComputeRead(MEASURE_PATIENT_PRESSURE_S16);
	UWORD16 AdjustPeep = DB_CurrentRead (ADJUST_PEEP_U16);


/*%C At the first step of scheduler, the software must go into "EXHALATION */
/*%C FALL" state. */
/*%C So it is necessary to test the previous state :"VEN_INSP_RISE" or */
/*%C "VEN_INSP_PLAT"*/
	if ( (CYC_PreviousControllerPhase == VEN_INSP_RISE)
	  || (CYC_PreviousControllerPhase == VEN_INSP_PLAT))
	{
	   VEN_Controller_Phase = VEN_EXH_FALL;
	}

/*%C         In the case of Pe set point is different from 0mBar:		      */
/*%C While the value of the Te Counter (counter of the exhalation phase) is*/
/*%C lower than a time out for the falling phase, and the patient pressure is*/
/*%C upper than 102% of Pe set point + an offset(1mBar), and the Pe set point*/
/*%C is upper than 0, and the previous state is different from "VEN_EXH_PLAT",*/
/*%C then the new phase of controller is "VEN_EXH_FALL". */
	else if ( (VenTeCount < cEXH_FALL_TIMEOUT) 
	       && (MeasurePatientPressure > 
	       									(((AdjustPeep * 102U) / 100U) + cDELTA_PE))
	       && (AdjustPeep > 0)
	       && (CYC_PreviousControllerPhase != VEN_EXH_PLAT) )
	{
	   VEN_Controller_Phase = VEN_EXH_FALL;
	}

/*%C         In the case of Pe set point is equal to 0mBar:		            */
/*%C While the value of the Te Counter (counter of the exhalation phase) is*/
/*%C lower than a time out for the falling phase, and the patient pressure is*/
/*%C upper than Pe set point + an offset(0.5mBar), and the Pe set point is */
/*%C equal to 0mBar, and the previous state is different from "VEN_EXH_PLAT", */
/*%C then the new phase of controller is "VEN_EXH_FALL". */
	else if ( (VenTeCount < cEXH_FALL_TIMEOUT)
		   && (MeasurePatientPressure > (AdjustPeep + 5U))
		   && (AdjustPeep == 0)
		   && (CYC_PreviousControllerPhase != VEN_EXH_PLAT) )
	{
	   VEN_Controller_Phase = VEN_EXH_FALL;
	}

/*%C In the other case, the new phase of controller is "VEN_EXH_PLAT".*/
	else
	{
	  	VEN_Controller_Phase = VEN_EXH_PLAT;
	}

/*%C Previous onctroller phase refresh */
	CYC_PreviousControllerPhase = VEN_Controller_Phase;
}
