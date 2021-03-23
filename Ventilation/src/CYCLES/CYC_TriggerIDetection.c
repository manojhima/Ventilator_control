/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : CYC_TriggerIDetection.c                                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functional description :                            */
/*%C                Detection of the Inspiration trigger                 		*/
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter :  NONE                                            		*/
/*%IO Input/Output :    NONE	                                              	*/
/*%O Output Parameter : UWORD16  TriggerIDetected      								*/
/******************************************************************************/
/*
SFSYST15
INSPIRATORY TRIGGER

SFSYST15.1
The software must detect the INSPIRATORY TRIGGER when the (current QI + 2 x previous
QI)/3 is varying more than INSP SENS in 20 ms during the exhalation phase after MIN EXH
DELAY

SFSYST10.6
The software must deliver a VIM two seconds after the ventilation has started (starting at the end
of the turbine test) if no inspiratory trigger is detected during this period.

SFSYST10.7
The software must deliver a PIM if an inspiratory trigger is detected during two seconds after the
ventilation has started (starting at the end of the turbine test). The SIMV period (60/rate) then
starts from the beginning of this PIM.

SFSYST10.8
The software must deliver a PS breath if an inspiratory trigger is detected before a period of
INSP TIME from the end of the SIMV period

/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/DATABASE/DB_Compute.h"
#include "../../inc/DATABASE/DB_Current.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/TIMERS/Timer_Data.h"
#include "../../inc/VENTILATION/Ventilation_Cycles_Datas.h"
#include "../../inc/CYCLES/CYC_TriggerIDetection.h"

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/


UWORD16 CYC_TriggerIDetection(void)
{
	UWORD16 VenTeCounter = TIM_ReadCounterValue(VEN_TE_COUNT);
   SWORD16 MeasureQinsp = (SWORD16)DB_ComputeRead(MEASURE_QINSP_S16);
	SWORD16 CurrentQinsp = 0;
	UWORD16 AdjustInspSens = DB_CurrentRead(ADJUST_INSP_SENS_U16);
	UWORD16 AdjustPeep = DB_CurrentRead(ADJUST_PEEP_U16);
   	UWORD16 Vti = DB_ComputeRead(COMPUTED_VTI_U16);
   SWORD16 TriggerIValue = 0; 
	SWORD32 TriggTime = 0;
  	SWORD16 Qinsp_filter = 0;
  	SWORD16 DeltaFlow_filter = 0;
	UWORD16 TriggerIDetected = FALSE;
    SWORD16 MaxAdjustTriggerI = 4;
   static SWORD16 PreviousFlow2_filter = 0;
   static SWORD16 PreviousFlow1_filter = 0;
	static UWORD16 DeltaCompute = 0;

    /*%C Qinsp filter correspond to the equation below : */
    /*%SC Qinsp_filter = (MeausreQinsp + 2 *PreviousFlow1_Filter)/3 */
    /*%C But PreviousFlow1_Filter = PreviousFlow2_Filter	*/
    /*%C So, */
    /*%C Qinsp_filter = (MeasureQinsp + PreviousFlow1_filter + */
    /*%C PreviousFlow2_filter) / 3 */
	Qinsp_filter = (MeasureQinsp + PreviousFlow1_filter + PreviousFlow2_filter) / 3;


	CurrentQinsp =	MeasureQinsp;
    /*%C Compute of the exempted period depending on CYC_Qmax*/

    // trigger lockout interval based on inspired-volume
    if (Vti >= 250)
	{
		TriggTime = VEN_RiseCompute(Vti, 250, cTIME_TRIG_I_MIN, 1900, cTIME_TRIG_I_MAX);
	}
	else
	{
		TriggTime = VEN_RiseCompute(Vti, 50, cTIME_TRIG_I_MIN_PED, 250, cTIME_TRIG_I_MAX_PED);
	}

    switch (AdjustInspSens)
	{
    case TRIGGER_LEVEL_0P:
        TriggTime = 300;
        TriggerIValue = 6;
        MaxAdjustTriggerI = 2;
        break;
    case TRIGGER_LEVEL_1P:
        TriggTime = 500;
        TriggerIValue = 8;
        break;
    case TRIGGER_LEVEL_2:
        TriggerIValue = (AdjustPeep <= 140) ? 11 : 13;
        break;
    case TRIGGER_LEVEL_3:
        TriggerIValue = (AdjustPeep <= 140) ? 13 : 15;
        break;
    case TRIGGER_LEVEL_4:
        TriggerIValue = (AdjustPeep <= 140) ? 14 : 16;
        break;
    case TRIGGER_LEVEL_5:
        TriggerIValue = (AdjustPeep <= 140) ? 16 : 18;
        break;
    default:
        TriggerIValue = 11;
        break;
	}

    /*%C the following compute is done one call out of two */
    /*%C because the callof the function is twice faster than the use*/
	DeltaCompute = DeltaCompute + 1;
    if (DeltaCompute == 2)
	{
        /*%C  RAZ the DeltaCompute */ 
		DeltaCompute = 0; 
        /*%C  Flow delta compute :*/
        /*%C 	DeltaFlow_filter = Qinsp_filter - PreviousFlow2_filter */
		DeltaFlow_filter = Qinsp_filter - PreviousFlow2_filter;

        /*%C  management of flow values stack */
        /*%C  Memorizing the Qinsp value for the next use (PreviousFlow1)*/
		PreviousFlow1_filter = Qinsp_filter;
        /*%C  Memorizing the PreviousFlow value for the next use (PreviousFlow2)*/
		PreviousFlow2_filter = PreviousFlow1_filter;


        /*%C		Flow delta trigger :*/ 
        /*%C if the DeltaFlow_Filter is equal 														*/
        /*%C to or upper than (Trigger value - CounterTe/750), and DeltaFlow_Filter */
        /*%C is equal to or upper than (Trigger value - 4), and  counterTe is  equal */
        /*%C to or upper than trigger time, then*/
        if (  (DeltaFlow_filter >= (TriggerIValue - (SWORD16)(VenTeCounter / 750u))) 
              && (DeltaFlow_filter >= (TriggerIValue - MaxAdjustTriggerI))
              && (VenTeCounter >= TriggTime) )
			{
            /*%C Inspiration Trigger is detected,*/
					TriggerIDetected = TRUE;
        }
        /*%C 		else, */
			else
			{
            /*%C Inspiration trigger is not detected */
		      TriggerIDetected = FALSE;
			}
 	}
    /*%C else,Inspiration trigger is not detected */
	else
	{
		TriggerIDetected = FALSE;
	}

    /*%C If no isnp sens is adjusted,then no trigger is detected. */
    if (AdjustInspSens == TRIGGER_LEVEL_OFF)
	{
		TriggerIDetected = FALSE;
	}

    /*%C the value of trigger state is returned */
	return(TriggerIDetected);
}
