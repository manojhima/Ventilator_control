/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505													  */
/*																			  */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : DRV_TREND_PageWrite.c  										  */
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

//#ifndef _TASKING
//	#include "LH_ST10F276.h"
//	#include <intrins.h>
//#else
// 		#include "regf276e.h"
//#endif
#include "../GENERAL/enum.h"
#include "../GENERAL/io_declare.h"
#include "../GENERAL/typedef.h"
#include "../GENERAL/define.h"
#include "../GENERAL/Structure.h"
#include "Flash_Monit_Data.h"
#include "DRV_TREND_PageWrite.h"

			 
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void DRV_TREND_PageWrite(void)
{

/* Monitoring Flash pointer declaration */
UBYTE *MONITFLASH_Data = (UBYTE *)MONITORING_FLASH_POINTER_ADDRESS;
static UBYTE First_Start = TRUE;

   			
 	DRV_TREND_Step = DRV_TREND_Step + 1;

	
	if(DRV_TREND_Step == 1)
	{
 	 
 
                 /**********************************************/
/*%C Writing command is launched :*/
/*%C   Write first Command */
		   	DRV_NAND_CommandInput(0x80) ;
			CMD_ME1 = 0 ; 

/*%C the right address is sent */
			DRV_NAND_AddressInput( DRV_TREND_Address_Write_Flash.Block
								 , DRV_TREND_Address_Write_Flash.Page
								 , DRV_TREND_Address_Write_Flash.Column) ;
			ALE_ME1 =  0 ; 

		 
		 
			DRV_TREND_Data_Load();

	}
	else if((DRV_TREND_Step > 1) && (DRV_TREND_Step <= 16))
	{
			DRV_TREND_Data_Load();
	}
	else
	{
	}

/*EOF*/
}
