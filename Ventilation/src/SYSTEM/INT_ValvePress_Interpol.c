/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : INT_ValvePress_Interpol.c                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C           Valve pressure values conversion                               */
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter : NONE                                                   */
/*%IO Input/Output : NONE                                                     */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/

/*1) SFSYSTEV3.59
VALVE PRESSURE OFFSET DEFAULT
the software shall record this event when the VALVE PRESSURE OFFSET DEFAULT is
detected.

2)SFSYSTEV3.67
VERY LOW VALVE PRESSURE
the software shall record this event when the VERY LOW VALVE PRESSURE default is detected


3)SFSYSTEV3.118
CONNECT VALVE / CHANGE PRESS
the software shall record this event when the CONNECT VALVE / CHANGE PRESS alarm is
detected

4) SFSYSTEV3.119
END OF CONNECT VALVE / CHANGE PRESS
the software shall record this event when the CONNECT VALVE / CHANGE PRESS alarm is
canceled

5) SFSYSTEV3.120
DISCONNECT VALVE / CHANGE PI PE
the software shall record this event when the DISCONNECT VALVE / CHANGE PI PE alarm is
detected

6) SFSYSTEV3.121
END OF DISCONNECT VALVE / CHANGE PI PE
the software shall record this event when the DISCONNECT VALVE / CHANGE PI PE alarm is
canceled
*/


/******************************************************************************/
/*                                INCLUDE FILES                               */
/******************************************************************************/
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../DATABASE/DB_Compute.h"
#include "../DATABASE/DB_Measurement.h"
#include "../DATABASE/DB_Config.h"
#include "INT_ValvePress_Interpol.h"
//#include "../DRIVERS/Driver_Datas.h"

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
t_AD_Digit AD_Digit;
void INT_ValvePress_Interpol(void)
{
/*%CVariables for gliding window of filtering compute */
	static SWORD16 ValvePressSample[10] = {0,0,0,0,0,0,0,0,0,0};
   static UBYTE ValvePressSampleNb = 0;
   SWORD32 ValvePressSampleCumul = 0;
	SWORD32 TempCompute = 0;
	UWORD16 Offset_Valve_press = 0;
	UWORD16 Offset_Valve_press2 = 0;
	SWORD16 Measure_Valve_press = 0;
	SWORD16 Filtered_Valve_Press = 0;
	UWORD16 i = 0;

/******************************************************************************/
/*                            Valve Pressure                                  */
/******************************************************************************/

/*%C Pressure is computed in xx.x H2O cm 	 */
/*%C The equation is:           */
/*%C      Press = ((ADC_Valve_Pressure_Value - Offset) * Sensitivity / 1000 */
/*%C Sensitivity is the value of one increment of the ADC : 0.1343 cm H2O */
/*%c So in the software, it is a constant witch is 1343 cm H2O*/
/*%C So the result is divided by 1000 to have a correct value in cm H2O . */


/* ------------------------------ NOTA -------------------------------------- */
/* how to compute the sensitivity for a pressure sensor -10 to +100 cm H2O:  */
/*   - sensor sensitivity = 4000 mV / 110 cmH2O = 36.363mV/cmH2O       */
/*   - ADC value for 1 cnH2O = (36.363mV * 1024) / 5000mV             */
/*     = 7.44714 CAN /mbar ==> 1 increment of ADC = 0.13428 cmH2O  */
/*----------------------------------------------------------------------------*/
    
/*%C So, first, Read the offsets of valve pressure in the "config" data base*/
	Offset_Valve_press = DB_ConfigRead(OFFSET_VALVE_PRESS_U16);
	Offset_Valve_press2 = DB_ConfigRead(OFFSET_VALVE_PRESS_2_U16);


/*%C Second, the valve pressure is computed with the equation above */
	TempCompute = (SWORD32)AD_Digit.ValvePressure - (SWORD32)Offset_Valve_press;
	TempCompute = TempCompute * 400;
	TempCompute = TempCompute /((SWORD32)Offset_Valve_press2 - (SWORD32)Offset_Valve_press);
	Measure_Valve_press = (SWORD16)(TempCompute);

/*%C Valve pressure filtering on 10 values */
   ValvePressSample[ValvePressSampleNb++] = Measure_Valve_press;
   ValvePressSampleNb = (UBYTE)(ValvePressSampleNb % 10);
   ValvePressSampleCumul = 0;
   for(i=0; i<10; i++)
   {
   	ValvePressSampleCumul = ValvePressSampleCumul + ValvePressSample[i];
	}
	Filtered_Valve_Press = (SWORD16)(ValvePressSampleCumul / 10);                


/*%C The computed valve pressure is stored into the Compute base  */
   DB_ComputeWrite(MEASURE_VALVE_PRESSURE_S16,
                   Measure_Valve_press);

/*%C The filtered valve pressure is stored into the Compute base  */
   DB_ComputeWrite(FILTER_VALVE_PRESSURE_S16,
                   Filtered_Valve_Press);

/*%C The CAN value of valve pressure is stored into Measurement data base */  
   DB_MeasurementWrite(VALVE_PRESSURE_CAN_U16,
                       AD_Digit.ValvePressure);	
	
}
