/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : ACT_ValveDetected.c										   	  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C                  Detection of the valve						 	      */
/******************************************************************************/
/*%I Input Parameter :  NONE                                  				  */
/*%IO Input/Output :    NONE	                                              */
/*%O Output Parameter : NONE												  */
/******************************************************************************/

/*
1) SFSYSTHMI10.7
If a valve is detected, only Vol control, Pres Control, PSV, PSIMV and VSIMV modes are
available

2) SFSYSTHMI10.8
If no valve is detected, only CPAP, Pres Control and PSV modes are available

3) SFSYSTAL28
CHECK EXH. VALVE (CHECK VALVE)
Detection Conditions: During exhalation phase (EVTI < - VTI * 4/10 and VTI>20mL)
OR (VALVE CURRENT > 50.0 mA) OR (VALVE CURRENT < 40.0 mA) OR
((VEN_FLEAK_MEASURED < VEN_TARGET_FLOW*0.8) AND (INSP_FLOW_MEASURED < -
15 lpm at 500 ms after exhalation start))
Validation Delay: shall be no more than two breath cycles or 5 s, whichever is greater.
Cancel Conditions: Auto
Priority: High priority
Audio Pause: yes
Alarm Pause: No
Modes: VOL A/C; PRES A/C; PSV; VOL SIMV; PRES SIMV
Actions: Events CHECK VALVE + END OF CHECK VALVE
Resetconditions: ventilation change; Ventilation std-by
Replaceventifpersistmessage: Yes
Circuit: valve

4) SFSYSTAL30
EXH. VALVE LEAKAGE (VALVE LEAKAGE)
Detection Conditions: sum(IQE) > 0.7 x sum(QI) during inspiration
and VTI>40mL.
Validation Delay: 3 consecutive cycles
Cancel Conditions: Auto
Priority: Medium priority
Audio Pause: yes
Alarm Pause: No
Modes: VOL A/C; PRES A/C; PSV; VOL SIMV; PRES SIMV
Actions: Events VALVE LEAKAGE + END OF VALVE LEAKAGE
Resetconditions: ventilation change; Ventilation std-by
Replaceventifpersistmessage: No
Circuit: valve

5) SFSYSTAL35
VALVE PRESSURE OFFSET FAULT (n°4)
Detection Conditions: valve pressure offsets or I_REF out of range during calibration. Successive
valve PWM offsets difference lower than 15.
Validation Delay: Immediate
Cancel Conditions: NA
Priority: Visual
Audio Pause: no
Alarm Pause: No
Modes: All
Actions: default offset
or precedent PWM offset -15 if difference with precedent is lower than 15
+ Event VALVE PRESSURE OFFSET
Resetconditions: N/A
Replaceventifpersistmessage: No
Circuit: all

6) SFSYSTAL43
VERY LOW VALVE PRESSURE (n°11)
Detection Conditions: VALVE PRESSURE < -10 cmH2O
Validation Delay: 15 s
Cancel Conditions: NA
Priority: Visual
Audio Pause: no
Alarm Pause: No
Modes: All
Actions: Event VERY LOW VALVE PRESSURE
Resetconditions: N/A
Replaceventifpersistmessage: No
Circuit: all

7) SFSYSTAL65
CHECK VALVE PRESSURE
Detection Conditions: VALVE PRESSURE = Constant (+/- 1 cmH2O)
Validation Delay: Max [Disconnection time, 60/R-Rate + 2] PC, VC
Max [Disconnection time, Apnea Time + 4 sec] CPAP, PSV
Max [Disconnection time, 60/R-Rate + Insp Time + 2] PSIMV, VSIMV
Cancel Conditions: Auto
Priority: High priority
Audio Pause: yes
Alarm Pause: No
Modes: VOL A/C; PRES A/C; PSV; VOL SIMV; PRES SIMV
Actions: Events CHECK VALVE PRESSURE + END OF CHECK VALVE PRESSURE
Resetconditions: ventilation change; Ventilation std-by
Replaceventifpersistmessage: No
Circuit: valve

8) SFSYSTAL66
CONNECT VALVE / CHANGE PRES
Detection Conditions: No valve detected during initialization phase and (PEEP < 4mbar or
Pcontrol / P support > 30 mbar)
Validation Delay: immediate
Cancel Conditions: Auto
Priority: High priority
Audio Pause: yes
Alarm Pause: No
Modes: PRES A/C; PSV
Actions: don't allow the ventilation and continue the turbine speed test
Events CONNECT VALVE CHANGE PI PE + END OF CONNECT VALVE CHANGE PI PE
Resetconditions: ventilation change; Ventilation std-by
Replaceventifpersistmessage: No
Circuit: valve

9) SFSYSTAL67
DISCONNECT VALVE/ CHANGE PRES
Detection Conditions: Valve detection during initialization phase and Psupport/Pcontrol - PEEP <
5 mbar
Validation Delay: immediate
Cancel Conditions: Auto
Priority: High priority
Audio Pause: yes
Alarm Pause: No
Modes: PRES A/C; PSV; CPAP
Actions: don't allow the ventilation and continue the turbine speed test
Events DISCONNECT VALVE CHANGE PI PE + END OF DISCONNECT VALVE CHANGE PI
PE
Resetconditions: ventilation change; Ventilation std-by
Replaceventifpersistmessage: No
Circuit: leak

10) SFSYSTAL68
CONNECT VALVE
Detection Conditions: No valve detected during initialization phase and CV/ACV or SIMV modes
are set.
Validation Delay: immediate
Cancel Conditions: Auto
Priority: High priority
Audio Pause: yes
Alarm Pause: No
Modes: VOL A/C; VOL SIMV; PRES SIMV
Actions: don't allow the ventilation and continue the turbine speed test
Events CONNECT VALVE + END OF CONNECT VALVE
Resetconditions: ventilation change; Ventilation std-by
Replaceventifpersistmessage: No
Circuit: valv

11) SFSYSTAL69
DISCONNECT VALVE
Detection Conditions: Valve detection during initialization phase and CPAP mode is set
Validation Delay: immediate
Cancel Conditions: Auto
Priority: High priority
Audio Pause: yes
Alarm Pause: No
Modes: CPAP
Actions: don't allow the ventilation and continue the turbine speed test
Events DISCONNECT VALVE + END OF DISCONNECT VALVE
Resetconditions: ventilation change; Ventilation std-by
Replaceventifpersistmessage: No
Circuit: leak
*/
/******************************************************************************/
/*                                INCLUDE FILES		                          */
/******************************************************************************/

#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Compute.h"
#include "../../inc/ACTUATOR/ACT_ValveDetected.h"


/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
void ACT_ValveDetected(void)
{
SWORD16 MeasureValvePressure 
							= (SWORD16)DB_ComputeRead(MEASURE_VALVE_PRESSURE_S16);
e_BOOL ValveDetected = FALSE;

/*%C If timer reached delay, then 								  	  		  */
	if (TIM_ReadDecounterValue(VEN_VALVE_TIM) == 0)
	{
/*%C  Valve Detection :		  												  */
/*%C  if MEASURE_VALVE_PRESSURE_S16 < cVALVE_DETECT_LEVEL, then 			  */
		if (MeasureValvePressure < (SWORD16)cVALVE_DETECT_LEVEL) 
		{
/*%C	ValveDetected = FALSE												  */
			ValveDetected = FALSE;
		}
/*%C  else, ValveDetected = TRUE											  */
		else
		{
			ValveDetected = TRUE;
		}
/*%C	End if 																  */
/*%C  Storage of Valve detection state in data base	 						  */
/*%C  VALVE_DETECTED_U16 = ValveDetected									  */	
		DB_ControlWrite(VALVE_DETECTED_U16,ValveDetected);
/*%C VALVE_DETECT_IN_PROGRESS_U16 = FALSE									  */
		DB_ControlWrite(VALVE_DETECT_IN_PROGRESS_U16,FALSE);
	}
}
