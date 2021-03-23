/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Usb_Monitor_Transfer.c    	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function controls the limits		*/
/*%C        of Monitor Transfer setting             	     							*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
SFSYSTCOMFR32
USB MONITORINGS TRANSFER REQUEST FRAME
USB monitorings transfer request frame shall have the following format :
STX : Start sequence (0x02, 0x05, 0x07) (3 bytes).
0x42 : Request ID (1 byte).
Amount of monitoring : amount of monitoring to transfer (0 -> no transfer; 1 -> 4h; 2 -> 8h ... 5 -
> 20; 6 -> 24h; 7 -> 36h; 8 -> 48h) (1 byte).
ETX : End sequence (0x07, 0x05, 0x02) (3 bytes).


SFSYSTCOMFR33
USB MONITORINGS TRANSFER ANSWER FRAME
USB monitoring transfer answer frame shall have the following format :
STX : Start sequence (0x02, 0x05, 0x07) (3 bytes).
0x06 : Answer ID (1 byte).
Error code : answer error code (0x00 -> COM_MONIT_TO_KEY_TRANSFER_START_OK
0x01 ->
COM_MONIT_TO_KEY_TRANSFER_ERROR_NO_KEY
0x02 ->
COM_MONIT_TO_KEY_TRANSFER_ERROR_TOO_MANY_KEYS
0x03 ->
COM_MONIT_TO_KEY_TRANSFER_ERROR_FLASH_BUSY
0x04 ->
COM_MONIT_TO_KEY_TRANSFER_NOT_IN_USB_MENU) (1 bytes).
CRC : CCITT CRC (2 bytes) (CRC computed on answer error code).

/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/DATABASE/DB_Usb.h"
#include "../../inc/DATABASE/DB_Current.h"
#include "../../inc/DATABASE/DB_Config.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"

extern void DB_UsbWrite(e_DB_USB Id, UWORD16 Value);
extern UWORD16 DB_UsbRead(e_DB_USB Id);
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Adjust_Usb_Monitor_Transfer(UWORD16 *Value,
																   UWORD16 Id)
{
#if 0
/* Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Limit tests */
/*%C Down Limit test */
   if ( (*Value <= cDB_TEST_USB_DB[Id].mini) ||
        (*Value > cDB_TEST_USB_DB[Id].maxi + cDB_TEST_USB_DB[Id].step))
	{
/*%C  Value limited to its min */
      *Value = cDB_TEST_USB_DB[Id].mini;
/*%C  Flag writing by DB_UsbWrite function call 	*/
		DB_UsbWrite(USB_MONITOR_TRANSFER_SELECT_U16, (UWORD16) FALSE);
		Function_Result = FALSE;
	}
/*%C Up Limit test */
   else if (*Value >= cDB_TEST_USB_DB[Id].maxi)
   {
/*%C  Value limited to its max */
      *Value = cDB_TEST_USB_DB[Id].maxi;
      Function_Result = FALSE;
   }
/*%C If "select flag" cancelled => "select flag"  activated*/
	else if ((e_BOOL) DB_UsbRead(USB_MONITOR_TRANSFER_SELECT_U16) == FALSE)
	{
/*%C  Flag writing by DB_UsbWrite function call 	*/
		DB_UsbWrite(USB_MONITOR_TRANSFER_SELECT_U16, (UWORD16) TRUE);
		Function_Result = FALSE;
	}
   else
   {
/*%C  Setting authorized */
      Function_Result = FALSE;
   }

	return(Function_Result);
#endif
}
