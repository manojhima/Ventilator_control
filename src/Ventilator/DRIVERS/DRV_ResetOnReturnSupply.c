/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : DRV_ResetOnReturnSupply.c                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C                                                                          */
/*%C Power supply turn back checking, and reset activation on watchdog			*/
/*%C activation cancellation								                           */
/*                                                                            */
/******************************************************************************/
/*%I  Input Parameter :   NONE                                                */
/*%IO Input/Output :      NONE                                                */
/*%O  Output Parameter :  NONE                                                */
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                           */
/******************************************************************************/
//#ifndef _TASKING
//	#include "LH_ST10F276.h"
//	#include <intrins.h>
//#else
// 		#include "regf276e.h"
//#endif
#include "../GENERAL/io_stubs.h"
#include "../GENERAL/io_declare.h"
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/define.h"
#include "../DATABASE/DB_Control.h"
#include "../DATABASE/DB_Config.h"
#include "../DRIVERS_DISPLAY/Driver_Display_Data.h"
#include "../DATABASE/DB_AlarmStatus.h"
#include "DRV_ResetOnReturnSupply.h"

void DRV_ResetOnReturnSupply(void)
{
	  	UWORD16 Supply;
	 	UWORD32 SupplyCumul;
		UWORD32 SupplySample;
		Supply = 0;
		SupplyCumul = 0;
		SupplySample = 0;

		//Demande d'ouverture de l'afficheur
		DRV_DIS_HostRequest ( 1 ) ;
	
		//Lancement du timer permettant de controler le temps d'excution
		T2IR = 0;		// RAZ du flag underflow timer 2
		T2IC = 0;
		T2 = 5000;   	// 5000*200ns, duree du timer2 = 1 ms Temps allou� a l'ex�cution
		T2CON  = 0x00C0;   // count down,Prescaller 200nS FCPU/8, start timer
		do {It_watchdog();}
		while (MASTERBUSY && (T2IR == 0));
		T2CON = 0x0000;     // stop Timer2

		//Effaccement des pages de l'afficheur
		DIS_ErasePage(PAGE3);
		DIS_ErasePage(PAGE2);
		DIS_ErasePage(PAGE1);

		//Demande de fermeture de l'afficheur
		DRV_DIS_HostRequest (0) ;

  		// Configuration du CAN en convertion voie unique
		// Registre de contr�le du convertisseur ad ADCON
		// s�lection du canal  voie 2 ADCH = 0010
		// conversion continue sur un canal ADM = 00
		// Non significatif                  0            
		// d�marrage de la conversion ADST = 0
		// Status de la conversion, pas de conversion en cours ADBSY = 0
		// Lancement conversion selon ADM ADWR = 0
		// Pas d'autorisation d'injection ADCIN = 0
		// Flag de demande d'injection ADCRQ = 0
		// Temps d'�chantillonnage = temps de conversion ADSTC = 11
		// Temps de conversion  TLSC * 24  ADCTC = 11
		// ==> ADCON = 1111000000001101 
		ADST = 0;
		ADCON = 0xF00D;
		ADCIR = 0;
	  	//si une source d'alimentation est pr�sente l'appareil ce r�initialisera
  		do
		{
			//Interdiction des interruptions convrertisseur
			//pour convertion unique sur une voie
			ADCIR = 0;			 
			ADST = 1; // remis � 0 lors de la lecture de ADDAT
			//Attente de fin de conversion
			do
			{
				It_watchdog();	//Activation du watchdog
			}
			while (ADCIR == 0);//mis � 1 en fin de conversion
			//Cumul des acquisitions pour filtrage 
		  	SupplyCumul += (ADDAT & 0x03FF);
/* Tant que l'alimentation n'est pas � 20V pendant 1s (50000 mesures), on ne red�marre pas !!!!!!*/
			if (SupplySample == 50000)
			{
				Supply = (UWORD16)(SupplyCumul / 1000);
				SupplySample = 0;
				SupplyCumul = 0;
			}
			//Nouvel �chantillon 
			SupplySample++;
			//Si l'alimentation > 20 V  activation d'un reset HARD par suppression de l'activation du watchdog HARD
			//Attention c'est un reset � chaud 
			while (Supply >= 682) //> 20 /(REF CAN(5v)/1023)*(R40+R36)/R40
			{	
				//on garde le Reset Soft actif pour faire un reset par le Hard (apres 1.6s)
				//Remarque:l'afficheur restera �teint jusqu'au prochain pilotage soft
				_srvwdt_();
			}
			//Activation du watchdog				 
		 	It_watchdog();
		}	
		while(1);
	}
