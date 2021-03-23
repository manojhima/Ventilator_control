/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : SYS_Fio2Detection.c          	                              	*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C           		Detection of the Fio2 sensor      						      */
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter : NONE                                                   */
/*%IO Input/Output : NONE                                                     */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/

/*SFSYST80
FiO2 sensor detection
if FiO2 > 0.3V during 2s, the software must detect a FiO2 sensor .
The software must display FiO2 value when a sensor is detected and ventilation is on
*/

/******************************************************************************/
/*                           INCLUDE FILES                                    */
/******************************************************************************/

#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../GENERAL/define.h"
#include "../DATABASE/DB_Config.h"
#include "../DATABASE/DB_Control.h"
//#include "../DRIVERS/Driver_Datas.h"
#include "../TIMERS/Timer_Data.h"
//#include "../DRIVERS/DRV_VarEeprom.h"
#include "SYS_Fio2Detection.h"


t_AD_Digit AD_Digit;
UWORD16  EEP_DB_Config[];


/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void SYS_Fio2Detection(void)
{

	static UWORD16  Fio2Detected = FALSE;
	static UWORD16 MemoFio2Detected = FALSE;
	static UWORD16 Mutex_Detected = FALSE;
	static UWORD16 FirstDetection = FALSE;

/*%C Fio2 first detection  */
	if (FirstDetection == FALSE)
	{
		TIM_StartDecounter(SYS_TIME_DETECT_FIO2, TIME_DETECT_FIO2);
		FirstDetection = TRUE;
	}

/*%C Fio2 detection  */
   if (AD_Digit.Fio2 > cFIO2_DIGIT_MIN_LEVEL)
	{
/*%C 	if the Fio2 timer detection is reached,  */
		if ( (TIM_ReadDecounterValue(SYS_TIME_DETECT_FIO2) == 0)
		  && (Mutex_Detected == FALSE) )
		{
			Fio2Detected = TRUE;
/*%C 		the Fio2 detection is made and stored in control base  */
 	   	DB_ControlWrite(DETECTED_FIO2_SENSOR, TRUE);
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
			DB_WriteDataInEepAndRam(&EEP_DB_Config[FIO2_LOW_SELECT],
											TRUE);
/*%C  Flag writing by DB_WriteDataInEepAndRam function call 	*/
			DB_WriteDataInEepAndRam(&EEP_DB_Config[FIO2_HIGH_SELECT],
											TRUE);
/*%C 		exclusion start  */
			Mutex_Detected = TRUE;

		}
	}
	else
	{
/*%C 	end of exclusion  */
		Mutex_Detected = FALSE;
/*%C 	Fio2 timer launch for new detection */
		TIM_StartDecounter(SYS_TIME_DETECT_FIO2, TIME_DETECT_FIO2);
		Fio2Detected = FALSE;
/*%C 	Flag writing in database  */
	   DB_ControlWrite(DETECTED_FIO2_SENSOR, FALSE);


		if (Fio2Detected != MemoFio2Detected)
		{
/*%C 		CALIBRATED_FIO2_SENSOR reset when the sensor is deconnected  */
			DB_ControlWrite(CALIBRATED_FIO2_SENSOR, FALSE);

		}
	}

/*%C Sensor state memorization */
	MemoFio2Detected = Fio2Detected;
}
