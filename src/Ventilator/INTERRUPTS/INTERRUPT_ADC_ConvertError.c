/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : INTERRUPT_ADC_ConvertError.c                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C                     */
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter : NONE                                                   */
/*%IO Input/Output : NONE                                                     */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                           */
/******************************************************************************/
//#ifndef _TASKING
//#include "LH_ST10F276.h"
//#include <intrins.h>
//#else
//#include "regf276e.h"
//#endif
#include "../GENERAL/io_stubs.h"
#include "../GENERAL/typedef.h"
#include "INTERRUPT_ADC_ConvertError.h"
#include "../DRIVERS_ADC/Driver_ADConverter_Data.h"


/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

//#ifndef _TASKING
//void INTERRUPT_ADC_ConvertError(void) interrupt 0x29
//#else
//interrupt (0x29)
  void INTERRUPT_ADC_ConvertError(void)
//#endif
{ 
	UWORD16 Read;

	ADST = 0;
	ADEIE = 0;
	ADEIR = 0;
	//Vidage des registres du r�sultat de convertion
 	Read = ADDAT;
	Read = ADDAT2;
	Read = Read+1;// to avoid warning
	DRV_ADC_ConvertInit();
	ErrorNumber++;
	ADEIE = 1;
}
