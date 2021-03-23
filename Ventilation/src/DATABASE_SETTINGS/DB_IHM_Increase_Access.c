/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: DB_IhmIncreaseAccess.c 			   			                  	*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	this function manages the increase		*/
/*%C        operation in the different bases function of DbType parameter		*/
/*                                                            				  		*/
/*                                                            				  		*/
/******************************************************************************/
/*%I Input Parameter :				Id                                    		  	*/
/*%I                    			DbType                                		  	*/
/*%I                    			DataOperation                         		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/
/*
1) SFSYSTUSB1.6.23
The software shall read the settings in database and write them in the settings file according to
SFSYSTCOMFILE1

2) SFSYSTUSB1.4.24
The software shall read the settings in database and write them in the settings file according to
SFSYSTCOMFILE

note: SFSYSTCOMFILE1
SETTINGS FILE FORMAT
Settings data shall be recorded in a "SPR_Settings.spr" file.
Settings file shall have the following format :
Serial Number (12 bytes).
Date and Hour (5 bytes).
Setting data packet (108 bytes) (Refers to SFSYSTCOMDP14).
CCITT CRC (2 bytes) (CRC computed on all data excepted the 2 last bytes).
*/
/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/

#include "../../inc/GENERAL/typedef.h"
#include "../../inc/GENERAL/enum.h"
#include "../../inc/GENERAL/Structure.h"
#include "../../inc/DATABASE/DB_Control.h"
#include "../../inc/DATABASE/DB_Rtc.h"
#include "../../inc/DATABASE/DB_Usb.h"
#include "../../inc/DRIVERS/DRV_VarEeprom.h"
#include "../../inc/DATABASE/DB_Event.h"
#include "../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
#include "../../inc/DATABASE/DB_AlarmStatus.h"
#include "../../inc/DATABASE_SETTINGS/DB_IHM_Increase_Access.h"
#include "../../inc/DATABASE/DB_Current.h"
//#include "../../inc/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb.h"
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/

UWORD16 DB_IHM_Increase_Access(UWORD16 *Value,
                              UWORD16 Id,
                              e_TYPE_OF_DB_TARGET DbType)
{											 
   e_MODE_TYPES ActualMode = VOL;


/* Function result declaration */
   UWORD16 Function_Result = FALSE;

/* Current mode recovery */
   ActualMode = EEP_DB_Config[ADJUST_MODE_U16];

/*%C Base choice for the increase operation */     
   switch (DbType)
	{
/*%C	Increase operation in the adjust base. */
		case ADJUST:
		{
/*%C     Mode choice for the increase operation in the adjust base */     
			switch (ActualMode)
			{
#ifdef CONFIG_VOL_MODE
/*%C        Increase operation in the adjust base for the VOL mode */     
				case VOL: 
				{
/*%C				Value recovery from the base and increase operation */
               *Value = *Value + cDB_VOL_TEST_ADJUST_DB[Id].step;

/*%C           Settings check function call in the adjust base */
/*%C           for the VOL mode */     
			   	Function_Result = DB_IHM_Setting_Adjust_Vol_Mode(Value,
			   	                                                 Id);
/*%C				Value recovery from the base and increase operation */
               if(Function_Result == TRUE)
               {
                  *Value = *Value - cDB_VOL_TEST_ADJUST_DB[Id].step;
               }
               break;
		    	}
#endif
/*%C        Increase operation in the adjust base for the PRES mode */     
				case PRES: 
				{	
/*%C				Value recovery from the base and increase operation */
               *Value = *Value + cDB_PRES_TEST_ADJUST_DB[Id].step;
/*%C           Settings check function call in the adjust base */
/*%C           for the PRES mode */
			  	 	Function_Result = DB_IHM_Setting_Adjust_Pres_Mode(Value,
			   	                                                  Id);
/*%C				Value recovery from the base and increase operation */
               if(Function_Result == TRUE)
               {
                  *Value = *Value - cDB_PRES_TEST_ADJUST_DB[Id].step;
               }

               break;
		    	}

/*%C        Increase operation in the adjust base for the PSV mode */
				case PSVT: 
				{
/*%C				Value recovery from the base and increase operation */
               *Value = *Value + cDB_PSV_TEST_ADJUST_DB[Id].step;

/*%C           Settings check function call in the adjust base */
/*%C           for the PSV mode */
			   	Function_Result = DB_IHM_Setting_Adjust_Psv_Mode(Value,
			   	                                                 Id);
/*%C				Value recovery from the base and increase operation */
               if(Function_Result == TRUE)
               {
                  *Value = *Value - cDB_PSV_TEST_ADJUST_DB[Id].step;
               }
                break;
		    	}

/*%C        Increase operation in the adjust base for the CPAP mode */
            case CPAP:
				{
/*%C				Value recovery from the base and increase operation */
               *Value = *Value + cDB_CPAP_TEST_ADJUST_DB[Id].step;

/*%C           Settings check function call in the adjust base */
/*%C           for the CPAP mode */
			   	Function_Result = DB_IHM_Setting_Adjust_Cpap_Mode(Value,
			   	                                                 Id);
/*%C				Value recovery from the base and increase operation */
               if(Function_Result == TRUE)
               {
                  *Value = *Value - cDB_CPAP_TEST_ADJUST_DB[Id].step;
               }
                break;
		    	}
#ifdef CONFIG_SIMV_MODE
/*%C        Increase operation in the adjust base for the VSIMV mode */     
				case VSIMV:	
				{
/*%C				Value recovery from the base and increase operation */
               *Value = *Value + cDB_VSIMV_TEST_ADJUST_DB[Id].step;

/*%C           Settings check function call in the adjust base */
/*%C           for the VSIMV mode */     
			   	Function_Result = DB_IHM_Setting_Adjust_Vsimv_Mode(Value,
			   	                                                   Id);
/*%C				Value recovery from the base and increase operation */
               if(Function_Result == TRUE)
               {
                  *Value = *Value - cDB_VSIMV_TEST_ADJUST_DB[Id].step;
               }
               break;
		    	}
/*%C        Increase operation in the adjust base for the PSIMV mode */
				case PSIMV:
				{
/*%C				Value recovery from the base and increase operation */
			   *Value = *Value + cDB_PSIMV_TEST_ADJUST_DB[Id].step;

/*%C           Settings check function call in the adjust base */
/*%C           for the PSIMV mode */
				Function_Result = DB_IHM_Setting_Adjust_Psimv_Mode(Value,
																   Id);
/*%C				Value recovery from the base and increase operation */
			   if(Function_Result == TRUE)
			   {
                  *Value = *Value - cDB_PSIMV_TEST_ADJUST_DB[Id].step;
               }
               break;
		    	}
#endif
				default:
				{
			   	Function_Result = FALSE;
				   break;
				}
         }

		break;
   	}
/*%C	Increase operation in the config base. */
		case CONFIG:
		{
			Function_Result = DB_IHM_Increase_Config(Value,
													 Id);
			break;
		}
/*%C	Increase operation in the control base. */
		case CONTROL:
		{
/*%C  Rolling menu for screen stand by (Max -> Min)									*/
			if (Id == RECORD_SETTINGS_USB_U16 ||
				 Id == APPLY_SETTINGS_USB_U16 ||
				 Id == ERASE_KEY_USB_U16)
			{
/*%C     	If value < max - step => value is increased of one step 					*/
				if (*Value <= (cDB_TEST_CONTROL_DB[Id].maxi -
								cDB_TEST_CONTROL_DB[Id].step) )
				{
					*Value = *Value + cDB_TEST_CONTROL_DB[Id].step;
					Function_Result = TRUE;
				}
/*%C     	else, value is set to its min													 	*/
				else
				{
					*Value = cDB_TEST_CONTROL_DB[Id].mini;
					Function_Result = TRUE;
				}
			}
			else
			{
/*%C     	If value < max - step => value is increased of one step 					*/
				if (*Value <= (cDB_TEST_CONTROL_DB[Id].maxi -
								cDB_TEST_CONTROL_DB[Id].step) )
				{
					*Value = *Value + cDB_TEST_CONTROL_DB[Id].step;
					Function_Result = TRUE;
				}
/*%C     	else, value is set to its max													 	*/
				else
				{
					*Value = cDB_TEST_CONTROL_DB[Id].maxi;
					Function_Result = FALSE;
				}
			}

		break;
		}



/*%C	Increase operation in the alarm base. */
		case ALARMS:
		{
			DB_AlarmStatusWrite(Id, (UBYTE)*Value);
			Function_Result = TRUE;
			break;
		}
/*%C	Increase operation in the RTC base. */
		case RTC:
		{
/*%C 		Day setting  */
         if (Id == ADJUST_RTC_DAY_U16)
         {
            *Value = *Value + cDB_TEST_RTC_DB[Id].step;
/*%C 		   Day setting function call */
			   Function_Result = DB_IHM_Setting_Rtc_Day(Value);
         }
/*%C 		Month and year settings (rolling values) */
         else
         {
            if (*Value <= (cDB_TEST_RTC_DB[Id].maxi -
			                  cDB_TEST_RTC_DB[Id].step))
            {
               *Value = *Value + cDB_TEST_RTC_DB[Id].step;
            }
            else
            {
               *Value = cDB_TEST_RTC_DB[Id].mini;
            }
			   Function_Result = TRUE;
         }
			break;
		}

/*%C	Increase operation in the USB base. */
      case USB:
		{
/* for USB monitoring transfert, the step is 4 until 24 and after it is 12*/
		if(Id == USB_MONITOR_TRANSFER_U16)
		{
			if((*Value < cUSB_MONIT_THRESHOLD_FOR_NEW_STEP) || (*Value >= cDB_TEST_USB_DB[Id].maxi))
			{
/*%C 	   Value recovery from the base and increase operation */
	         *Value = *Value + cDB_TEST_USB_DB[Id].step;
			}
			else
			{
/*%C 	   Value recovery from the base and increase operation */
	         *Value = *Value + cUSB_MONIT_NEW_STEP;
			}
		}
		else
		{
/*%C 	   Value recovery from the base and increase operation */
	         *Value = *Value + cDB_TEST_USB_DB[Id].step;
		}
/*%C     Settings check function call in the Usb base */
         Function_Result = DB_IHM_Setting_Adjust_Usb(Value, Id);

/*%C     Value recovery from the base and increase operation */
         if(Function_Result == TRUE)
         {
            *Value = *Value - cDB_TEST_USB_DB[Id].step;
         }
         break;
		}
		default:
		{
			Function_Result = FALSE;
			break;
		}
	}

	return(Function_Result);
}
