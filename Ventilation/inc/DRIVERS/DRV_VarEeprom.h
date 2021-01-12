/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: DRV_VarEeprom.h     		   				                  		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 	declaration for var eeprom	            */
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameter : 			None		      	                          	*/
/*%IO Input/Output Parameter : 	None 	        			                  		*/
/*%O 	Output Parameter : 			None                        				  		*/
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/


/************************************************************************/
/*                           INCLUDE FILES		                        */
/************************************************************************/
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../DATABASE/DB_Current.h"
#include "../DATABASE/DB_Config.h"

/************************************************************************/
/*                   EXTERNAL CONSTANT DECLARATION                     	*/
/************************************************************************/
#if 0
/*%C Eeprom start address for the address memorization                        */
/*%C This address is written in the file "_Legendair_US.ilo" for the          */
/*%C eeprom segment                                                           */
#define BEGIN_RAM_ADRESS_OF_EEP_DATA 0xFF000


#ifdef EEP_VAR_SOURCE
#define _EXTERN
#else
#define _EXTERN extern
#endif



/************************************************************************/
/*                   EXTERNAL VARIABLE DECLARATION                    	*/
/************************************************************************/


/************************************************************************/
/*                   EXTERNAL FUNCTION DECLARATION	                    */
/************************************************************************/

/* ---------------------------------------------------------------------------*/
/*		 /\																						   */
/*    /!!\		ATTENTION, DECLARER EN 1er LE NUMERO DE VERSION						*/
/*   /____\																							*/
/* ---------------------------------------------------------------------------*/

//#ifndef _BORLAND //commented by bhavya

	//#ifndef _TASKING //commented by bhavya
/* Version number */
_EXTERN UWORD16  EEP_DB_Version_Number[end_of_db_version_table];

// D�finition de la Table des para de r�glage pour la configuration
_EXTERN UWORD16  EEP_DB_Config[end_of_db_config_table];

/* Setting parameter table for the VOL mode */
_EXTERN UWORD16  EEP_DB_VOL_Adjust[end_of_adjust_table];

/* Setting parameter table for the PRES mode */
_EXTERN UWORD16  EEP_DB_PRES_Adjust[end_of_adjust_table];

/* Setting parameter table for the PSV mode */
_EXTERN UWORD16  EEP_DB_PSV_Adjust[end_of_adjust_table];

/* Setting parameter table for the VSIMV mode */
_EXTERN UWORD16  EEP_DB_VSIMV_Adjust[end_of_adjust_table];

/* Setting parameter table for the PSIMV mode */
_EXTERN UWORD16  EEP_DB_PSIMV_Adjust[end_of_adjust_table];

/* Setting parameter table for the CPAP mode */
_EXTERN UWORD16  EEP_DB_CPAP_Adjust[end_of_adjust_table];

/* Setting parameter table for the TREND Data */
_EXTERN UWORD16  EEP_DB_TREND[end_of_db_trend_table];

/* PUST ERROR variable definition and location */
//_EXTERN UWORD16 huge End_Of_Database;	// commented by manoj

/* PUST ERROR variable definition and location */
//_EXTERN UWORD16 huge PUST_ERROR;		// commented by manoj



#if 0
/* Version number */
_EXTERN UWORD16 _huge EEP_DB_Version_Number[end_of_db_version_table];

// D�finition de la Table des para de r�glage pour la configuration
_EXTERN UWORD16 _huge EEP_DB_Config[end_of_db_config_table];

/* Setting parameter table for the VOL mode */
_EXTERN UWORD16 _huge EEP_DB_VOL_Adjust[end_of_adjust_table];

/* Setting parameter table for the PRES mode */
_EXTERN UWORD16 _huge EEP_DB_PRES_Adjust[end_of_adjust_table];

/* Setting parameter table for the PSV mode */
_EXTERN UWORD16 _huge EEP_DB_PSV_Adjust[end_of_adjust_table];

/* Setting parameter table for the VSIMV mode */
_EXTERN UWORD16 _huge EEP_DB_VSIMV_Adjust[end_of_adjust_table];

/* Setting parameter table for the PSIMV mode */
_EXTERN UWORD16 _huge EEP_DB_PSIMV_Adjust[end_of_adjust_table];

/* Setting parameter table for the CPAP mode */
_EXTERN UWORD16 _huge EEP_DB_CPAP_Adjust[end_of_adjust_table];

/* Setting parameter table for the TREND Data */
_EXTERN UWORD16 _huge EEP_DB_TREND[end_of_db_trend_table];

/* PUST ERROR variable definition and location */
_EXTERN UWORD16 _huge End_Of_Database;

/* PUST ERROR variable definition and location */
_EXTERN UWORD16 _huge PUST_ERROR;
	#endif //by bhavya


//#else //by bhavya
_EXTERN UWORD16 EEP_DB_Version_Number[end_of_db_version_table];

// D�finition de la Table des para de r�glage pour la configuration
_EXTERN UWORD16 EEP_DB_Config[end_of_db_config_table];

/* Setting parameter table for the VOL mode */
_EXTERN UWORD16 EEP_DB_VOL_Adjust[end_of_adjust_table];

/* Setting parameter table for the PRES mode */
_EXTERN UWORD16 EEP_DB_PRES_Adjust[end_of_adjust_table];

/* Setting parameter table for the PSV mode */
_EXTERN UWORD16 EEP_DB_PSV_Adjust[end_of_adjust_table];

/* Setting parameter table for the VSIMV mode */
_EXTERN UWORD16 EEP_DB_VSIMV_Adjust[end_of_adjust_table];

/* Setting parameter table for the PSIMV mode */
_EXTERN UWORD16 EEP_DB_PSIMV_Adjust[end_of_adjust_table];

/* Setting parameter table for the CPAP mode */
_EXTERN UWORD16 EEP_DB_CPAP_Adjust[end_of_adjust_table];

/* Setting parameter table for the TREND Data */
_EXTERN UWORD16 EEP_DB_TREND[end_of_db_trend_table];

/* PUST ERROR variable definition and location */
_EXTERN UWORD16 End_Of_Database;

/* PUST ERROR variable definition and location */
_EXTERN UWORD16 PUST_ERROR;
#endif
 //Commented Actual driver file and defined
/* Version number */
UWORD16  EEP_DB_Version_Number[10]; //bhavya

// D�finition de la Table des para de r�glage pour la configuration
UWORD16  EEP_DB_Config[104]; //bhavya

/* Setting parameter table for the VOL mode */
UWORD16  EEP_DB_VOL_Adjust[56]; //bhavya

/* Setting parameter table for the PRES mode */
UWORD16  EEP_DB_PRES_Adjust[56]; //bhavya

/* Setting parameter table for the PSV mode */
UWORD16  EEP_DB_PSV_Adjust[56]; //bhavya

/* Setting parameter table for the VSIMV mode */
UWORD16  EEP_DB_VSIMV_Adjust[56]; //bhavya

/* Setting parameter table for the PSIMV mode */
UWORD16  EEP_DB_PSIMV_Adjust[56]; //bhavya

/* Setting parameter table for the CPAP mode */
UWORD16  EEP_DB_CPAP_Adjust[56]; //bhavya

/* Setting parameter table for the TREND Data */
UWORD16  EEP_DB_TREND[43]; //bhavya
