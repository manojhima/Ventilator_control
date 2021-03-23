/*****************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505 				                                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : SYS_SPO2Interpol.c                               					*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C             		 Calibration des capteurs	                        		*/
/******************************************************************************/
/*%I Input Parameter :  NONE                                                  */
/*%IO Input/Output :    NONE	                                                */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/

/*
1) SFSYSTCOMDP93.2.38
SpO2 measure
Offset (byte): 31
Format: 8 bits
Data: SpO2
Range: 0 = NO, 0 to 100
Unit: %

2)SFSYSTCOMDP303.2.18
SpO2 measure
Offset (byte): 24
Format: 8 bits
Data: SpO2
Range: 0 to 100
Unit: %
*/

/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
//#ifndef _TASKING
//#include "LH_ST10F276.h"
//#include <intrins.h>
//#else
//#include "regf276e.h"
//#endif
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "SYS_SPO2Interpol.h"
#include "DB_Compute.h" //bhavya
#include "DB_Control.h" //bhavya

void SYS_SPO2Interpol(void)
{
	t_DataSpo2 Data;
	Data = SYS_ReadDataSpo2();

// D�tection d'une erreur sur le capteur
// Possibilit� de lire data.status mais � chaque fois que la mesure est impossible data.spo2 = 127
//Data.Spo2 = 0 -> Capteur non branch� - rien sur la liaison s�rie
if((Data.Spo2 == 0) || (Data.Spo2 == 127))
DB_ControlWrite(ERROR_SPO2_SENSOR_DETECTED, TRUE);
else
DB_ControlWrite(ERROR_SPO2_SENSOR_DETECTED, FALSE);
// Ecriture en base de donn�e
DB_ComputeWrite(MEASURE_SPO2_U16, Data.Spo2);
}
