/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505													  */
/*																			  */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : DRV_NAND_Erase_Flash.c  										  */
/* 																			  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C																		  */
/******************************************************************************/
/*%I Input Parameter :  NONE												  */
/*%IO Input/Output :    NONE												  */
/*%O Output Parameter : NONE												  */
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          */
/******************************************************************************/

	
#include "../GENERAL/enum.h"
#include "../GENERAL/typedef.h"
#include "../GENERAL/define.h"
#include "../GENERAL/Structure.h"
#include "Flash_Monit_Data.h"


			 
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void DRV_NAND_Erase_Flash(void)
{

	DRV_MONIT_Address_Start_Read_Flash_Recording.Block = DRV_NAND_First_Partition_Block_Start;
	DRV_MONIT_Address_Start_Read_Flash_Recording.Page = 0;
	DRV_MONIT_Address_Start_Read_Flash_Recording.Column = 0;
	DRV_MONIT_Partition_Full = FALSE;

	DRV_TREND_Address_Start_Read_Flash_Recording.Block = DRV_NAND_Second_Partition_Block_Start;
	DRV_TREND_Address_Start_Read_Flash_Recording.Page = 0;
	DRV_TREND_Address_Start_Read_Flash_Recording.Column = 0;
	DRV_TREND_Partition_Full = FALSE;	
 
/*EOF*/	 
}
