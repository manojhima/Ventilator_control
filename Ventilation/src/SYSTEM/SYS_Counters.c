/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : SYS_Counters.c                                           		*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C           Patient & Machine counters management                          */
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter : NONE                                                   */
/*%IO Input/Output : NONE                                                     */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES	                             */
/******************************************************************************/

#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../TIMERS/Timer_Data.h"
#include "../DATABASE/DB_Control.h"
#include "../DATABASE/DB_Config.h"
#include "../DATABASE/DB_AlarmStatus.h"
//#include "../DRIVERS/DRV_VarEeprom.h"
#include "System_Datas.h"
#include "SYS_Counters.h"

/*
PATIENT COUNTER : Patient ventilation counter displayed in SET UP MENU.
1) SFSYSTSETUP2.2
PATIENT COUNTER
when the VALIDATION KEY is SHORT PRESS on the PATIENT COUNTER field, the cursor
must go on the field "Reset Counter". To reset the PATIENT COUNTER the user must first make
a SHORT PRESS on VALIDATION KEY then press on UP KEY to change the display from "OFF"
to "YES" and finally make a SHORT PRESS on VALIDATION KEY to reset the counter.
When the PATIENT COUNTER is reset, a long beep must be triggered.

2)SFSYSTEV1.21
PATIENT COUNTER RESET
The software shall record the PATIENT COUNTER RESET

3)SFSYSTUSB2.8
TRANSFER MACHINE COUNTER

4)SFSYSTCOMDP325.2.1
Machine counter
Offset (byte): 0
Format: 2*8 bits
Data: Machine counter
Range: 0 to 65535
Unit: h
*/



/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
void SYS_Counters(void)
{
	UWORD16 Ventil_state = DB_ControlRead(VENTIL_STATE_U16);
	UWORD16 Alarm_Disconnection = DB_AlarmStatusRead(ALARM_DISCONNECTION_U16);
	UWORD16 Timer_OverFlow = FALSE;
	
/*%C Patient and machine counters management	  */
/*%C Do following operations each 60 seconds	  */
	Timer_OverFlow = TIM_TestOverflowOk(SYS_1MINPAT);
	if (Timer_OverFlow == TRUE)
	{
/*%C  When the ventilation is running  */
   	if (Ventil_state != VEN_VENTIL_DISABLE)
	   {
/*%C     Increasing of  machine minute counter	  */
	      SYS_CounterMachineMin = SYS_CounterMachineMin +1;

/*%C     Updating machine minutes and hours each 60 min	  */
	      if (SYS_CounterMachineMin > cFIFTY_NINE_MINUTES)
	      {
/*%C        re-init machine minute counter	 */
   	      SYS_CounterMachineMin = 0;
/*%C        increasing machine hour counter	 */
    	      SYS_CounterMachineHour = SYS_CounterMachineHour +1;
	      }
/*%C     re-init hour machine counter  on overflow */
/*%C     (CounterMachineHour > 65000)*/
	      if (SYS_CounterMachineHour > cOVERFLOW_LIMIT)
	      {
	         SYS_CounterMachineHour = 0;
	      }

/*%C     Storage of the new values of the machine counters in the Control */
/*%C     Data base */
	      DB_ControlWrite(CURRENT_MACHINE_COUNTER_MIN_U16,
	                      SYS_CounterMachineMin);
	      DB_ControlWrite(CURRENT_MACHINE_COUNTER_HOUR_U16,
	                      SYS_CounterMachineHour);
	   }

/*%C 	When ventilation is running & Alarm disconnection is unactivated */
	   if ( ( (Alarm_Disconnection == ALARM_FALSE) 
          || (Alarm_Disconnection == ALARM_DETECTED) )
	     && (Ventil_state != VEN_VENTIL_DISABLE) )
	   {	
/*%C     Increasing of patient minute counter		 */
	      SYS_CounterPatientMin = SYS_CounterPatientMin +1;

/*%C     Updating patient minutes and hours each 60 min */
	      if (SYS_CounterPatientMin > cFIFTY_NINE_MINUTES)
	      {
/*%C        re-init patient minute counter	 */
	         SYS_CounterPatientMin = 0;
/*%C        increasing patient hour counter	 */
	         SYS_CounterPatientHour = SYS_CounterPatientHour +1;
	      }
/*%C     re-init hour patient counter on overflow (CounterPatientHour > 65000)*/
		   if (SYS_CounterPatientHour > cOVERFLOW_LIMIT)
	      {
	         SYS_CounterPatientHour = 0;
	      }
/*%C     Storage of the new values of the patient counters in the Control*/
/*%C     Data base */		   
	      DB_ControlWrite(CURRENT_PATIENT_COUNTER_MIN_U16,
	                      SYS_CounterPatientMin);
	      DB_ControlWrite(CURRENT_PATIENT_COUNTER_HOUR_U16,
	                      SYS_CounterPatientHour);
	   }
/*%C  End of operations to do each 60 seeconds		 */

/*%C  re-loading  minute patient timer			 */
	   TIM_StartDecounter(SYS_1MINPAT,
	                      TIME_1MINPAT);
	}
}
