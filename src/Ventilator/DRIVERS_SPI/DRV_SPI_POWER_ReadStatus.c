/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : DRV_SPI_POWER_ReadStatus.c                         */
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
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../GENERAL/io_declare.h"
#include "../DATABASE/DB_Control.h"
#include "DRV_SPI_POWER_Data.h"
#include "DRV_SPI_POWER_ReadStatus.h"



/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

e_DRV_SPI_POWER_ERROR DRV_SPI_POWER_ReadStatus(void)
{		
	return DRV_SPI_POWER_Status;	
}


