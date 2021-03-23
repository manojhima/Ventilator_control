/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : SYS_SetupLaunch.c      		 	                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*
SFSYST1.3
When the inhibition key is pressed continuously during the INITIALIZATION PHASE and the
ventilation was VOLUNTARILY SWITCHED OFF, the software starts in SETUP MENU
*/

/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C           Management of keyboard and backlight,            					*/
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter : NONE                                                   */
/*%IO Input/Output : NONE                                                     */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/

/******************************************************************************/
/*                           INCLUDE FILES                                    */
/******************************************************************************/

#include "SYS_SetupLaunch.h"

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void SYS_SetupLaunch(void)
{

/*%C The function below are launched on this order :      		               */
/*%C   -	SYS_Keyboard()*/
/*%C   - SYS_Backlight_Mngt() */
/*%C   - DRV_Key_Sound_Bip() */

	SYS_Keyboard();
	SYS_Backlight_Mngt();
	//DRV_Key_Sound_Bip(); //bhavya
	SYS_Fio2Detection();

}
