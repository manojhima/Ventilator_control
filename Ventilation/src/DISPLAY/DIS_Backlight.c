/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : DIS_Backlight.c                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*
SFSYSTSET1.5
Backlight
Unit: N.A.
Min Value: N.A.
Max Value: N.A.
List of Values: Yes, OFF
Step: 0
Default Value: OFF
Links: N.A.
Auto-adjustement: N.A.
Comments: No comment
common in all mode

SFSYST1.2
When the user starts the device, the software must turn on the BACKLIGHT

SFSYST19
BACKLIGHT
No text (title)
SFSYST19.1
The software must light on the BACKLIGHT, when it starts.

SFSYST19.2
The software must light on the BACKLIGHT, when the BACKLIGHT is off and an alarm is
detected.
SFSYST19.3
The software must light on the BACKLIGHT, when the BACKLIGHT is off and a key is pressed.
SFSYST19.4
The software must always activate the BACKLIGHT, when the BACKLIGHT setting is on .
SFSYST19.5
The software must light off the BACKLIGHT, when the BACKLIGHT is off and no key was
pressed and no alarm was present for 1 minute.

/******************************************************************************/
/*%C                     Functionnal description :   								  */
/*%C                                                                          */
/*%C                                                */
/******************************************************************************/
/*%I Input Parameter :  e_BOOL On                                            */
/*%IO Input/Output :    NONE                                                  */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          */
/******************************************************************************/
//#ifndef _TASKING
//#include "LH_ST10F276.h"
//#include <intrins.h>
//#else
//#include "regf276e.h"
//#endif
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/DISPLAY/DIS_Backlight.h"

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

void DIS_Backlight(e_TYPE_BACKLIGHT_LEVEL Level)
{
	static UWORD16 Memo_Backlight = SWITCH_ON;

// Gestion Backlight
	if (Level != Memo_Backlight)
	{
		DIS_FifoWrite(DRV_BACKLIHGHTADJUST,(UWORD16)Level,0,0,0,0,0,0,0,0,0,0,0);
	}
	Memo_Backlight = Level;
}
