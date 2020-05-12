/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : DRV_EVENT_Erase_Flash.c                                     */
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
//	#include <intrins.h>
//#endif
#include "../GENERAL/io_stubs.h"
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../GENERAL/define.h"
#include "../MAIN/Main_Data.h"
#include "Flash_Event_Data.h"

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void DRV_EVENT_Erase_Flash(void)
{   
#ifndef _BORLAND
/*%C Flash memory index*/
//	UWORD16 xhuge *adr_flash;
	UWORD16 *adr_flash;
	UBYTE i;

/*%C 1st cycle erazing s�quence 				 */
//	adr_flash = (UWORD16 xhuge *)(EVENT_FLASH_START_ADDRESS + 0xAAA);
	adr_flash = (UWORD16 *)(EVENT_FLASH_START_ADDRESS + 0xAAA);
	*adr_flash = 0x00AA;
/*%C 2d cycle erazing s�quence 				 */
//	adr_flash = (UWORD16 xhuge *)(EVENT_FLASH_START_ADDRESS +0x554);
	adr_flash = (UWORD16 *)(EVENT_FLASH_START_ADDRESS +0x554);
	*adr_flash = 0x0055;
/*%C 3d cycle erazing s�quence 				 */
//	adr_flash = (UWORD16 xhuge *)(EVENT_FLASH_START_ADDRESS +0xAAA);
	adr_flash = (UWORD16 *)(EVENT_FLASH_START_ADDRESS +0xAAA);
	*adr_flash = 0x0080;
/*%C 4ith cycle erazing s�quence 				 */
//	adr_flash = (UWORD16 xhuge *)(EVENT_FLASH_START_ADDRESS +0xAAA);
	adr_flash = (UWORD16 *)(EVENT_FLASH_START_ADDRESS +0xAAA);
	*adr_flash = 0x00AA;
/*%C 5th cycle erazing s�quence 				 */
//	adr_flash = (UWORD16 xhuge *)(EVENT_FLASH_START_ADDRESS + 0x554);
	adr_flash = (UWORD16 *)(EVENT_FLASH_START_ADDRESS + 0x554);
	*adr_flash = 0x0055; 
/*%C 6th cycle erazing s�quence 				*/
//	adr_flash = (UWORD16 xhuge *)(EVENT_FLASH_START_ADDRESS + 0x0AAA);
	adr_flash = (UWORD16 *)(EVENT_FLASH_START_ADDRESS + 0x0AAA);
	*adr_flash = 0x0010; 
/*%C Tempo 24.8�s waiting erazing validation		*/
/*%C Tempo v�rifi�e sur oscilloscope					*/

	for (i=0;i<165;i++) 
		{
		_nop_();
		}
/*%C 	Waiting the end of erazing				  */
	Flash_State = DRV_EVENT_ERASE;
#endif
}
