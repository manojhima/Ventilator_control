/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : MAIN_Ventilation_Init.c                              		  		*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C           			  Init of ventilation function                      	*/
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter : NONE                                                   */
/*%IO Input/Output : NONE                                                     */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES	                             */
/******************************************************************************/

//#ifndef _TASKING
//	#include "LH_ST10F276.h"
//	#include <intrins.h>
//#else
// 		#include "regf276e.h"
//#endif
#include "../GENERAL/io_declare.h"
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../VENTILATION/Ventilation_Constants.h"
#include "../VENTILATION/Ventilation_Datas.h"
#include "../VENTILATION/Ventilation_Cycles_Datas.h"
#include "../DATABASE/DB_Config.h"
#include "../DATABASE/DB_Control.h"
#include "../TIMERS/Timer_Data.h"
#include "MAIN_Ventilation_Init.h"

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
void MAIN_Ventilation_Init(void)
{
	UWORD16 i = 0;
   UWORD16 VentilReq = DB_ConfigRead(VENTIL_REQ_U16);

	// initialisation mat�rielle
	BRAKE_BLOWER = 1;
	TIM_Temporize(10000);
	BRAKE_BLOWER = 0;

	// Configuration de la sortie frein P2.1 en PWM
	//Utilisation du timer 0
	// Registre de controle du timer T0 et T1
	// 8 bit poids faible du timer 0 non programm�s
	// Pr�diviseur = 8 T0I = 000 r�solution 400ns
	// Mode timer 	   T0M = 0
	// Timer en marche T0R = 0 
	// T01CON = xxxxxxxx00000000
//	T01CON &= 0xFF00;			// platform specific code manoj
//	T01CON |= 0x0001;			// platform specific code manoj
	// init registre de reload 	T0REL = 0; 
	// T0REL = 65535 - (periode PWM / 400ns) 
	// Pour PWM a 15Khz T0REL = 65535 - 66,6us/400ns = 65369
//	T0REL = BRAKE_PERIOD;		// platform specific code manoj
	//Capture compare mode register CCM0
	// ACC1 allou� au timer 0
	// CCMOD1 mode 3 compare reset de la sortie � overflow  de timer  
	// ACC0,ACC2,ACC3,CCMOM0,CCMOD2,CCMOD3 non programm�s
	// ==> CCM0 = xxxx xxxx 0111 xxxx = 0x XX7X
//	CCM0 &= 0xFF7F;				// platform specific code manoj
//	CCM0 |= 0x0070;				// platform specific code manoj
   BRAKE_BLOWER = 1;
//	CC1 = 0;					// platform specific code manoj
	ACT_BrakePower(0);
  	//Programmation des PWM0, PWM1 et PW2
	//Regitre PWMCCON0 
	//Pas de demande d'interruption PIR0 = PIR1 = PIR2 = 0
	//Interruption non autoris�e PIE0 = PIE1 = PIE2 = 0
	//	Entr�e d'horloge FCPU  PTI0 = PTI1 = PTI2 =0
	//Canal 0 et canal 1 en fonctionnement PTR0 = PTR1 = PTR2 = 1
	//PWMCCON0 = x000x000x000x111
#ifndef CONFIG_REGUL_O2
//	PWMCON0 |= 0x0003; 			// platform specific code manoj
#else
//	PWMCON0 |= 0x0007;			// platform specific code manoj
#endif
	    
//	PWMCON0 &= 0x888F;			// platform specific code manoj
	//Registre PWMCON1
	//PS2 en mode standard PS2 = 0
	//Bit r�sev�
	//Canal 0 et 1 ind�pendants PB01 = 0 
	//Canal en mode Asym�trique PM0 = PM1 = PM2 = 0
	//Sinal en sortie PWM PEN0 = PEN1 = PEN2 = 1
	//PWMCON1 = x0x0 xxxx x000 x111	 
#ifndef CONFIG_REGUL_O2
//	PWMCON1 |= 0x0003; // platform specific code manoj // La fonction PWM2 est disabled sur le port P7.2, on utilise ce port en sortie push pull
	 					// tout ou rien
#else
//	PWMCON1 |= 0x0007; 	// platform specific code manoj
#endif

//	PWMCON1 &= 0xAFFF; // platform specific code manoj

//	PP0      = 4096; // platform specific code manoj	 				// Registre P�riode PWM 0 F=1/(4096(12bits)*25ns(1/Fcpu)) = 9,765 KHz
//	PW0      = cBLOWER_CMD_OFF; // platform specific code manoj	// Registre Largeur impulsion PWM 0

// 	PP1		= 2671;	  // platform specific code manoj				// Registre P�riode PWM 1 F=1/(2666(14bits)*25ns(1/Fcpu)) = 14.975 KHz
//	PW1 		= cVALVE_CMD_OFF;	// platform specific code manoj	// Registre Largeur impulsion PWM 1

#ifdef CONFIG_REGUL_O2
// 	PP2		= 2671;	  // platform specific code manoj				// Registre P�riode PWM 2 F=1/(2666(14bits)*25ns(1/Fcpu)) = 14.975 KHz
//	PW2 		= cVALVEO2_CMD_OFF;	// platform specific code manoj // Registre Largeur impulsion PWM 2
#endif

   BRAKE_BLOWER = 1;


/*%C Stop turbine */
// 	BLOWER_CMD = cBLOWER_CMD_OFF; // platform specific code manoj
	ACT_BrakePower(cPOWER_MAX);
/*%C Temporization (2 sec) */
//	TIM_Temporize(2000); // platform specific code manoj

/*%C Measured values initialization */
	for(i=0; i<cPEP_MEASURE_NUMBER; i++)
		VEN_MeasuredValues.MesurePep[i] = 0;
	for(i=0; i<cPVALVE_MEASURE_NUMBER; i++)
		VEN_MeasuredValues.MeasurePvalve[i] = 0;
	for(i=0; i<cFLEAK_MEASURE_NUMBER; i++)
		VEN_MeasuredValues.MeasureFlowLeak[i] = 0;

/*%C Ventilation state of the active mode */
	CYC_ActiveModeState.VolPres = ACTIVATED;
	CYC_ActiveModeState.Psv = ACTIVATED;
	CYC_ActiveModeState.Vsimv = ACTIVATED;
	CYC_ActiveModeState.Psimv = ACTIVATED;
	CYC_ActiveModeState.Cpap = ACTIVATED;


/*%C If the ventilation starts after an unvolontary stop, a flag is set			*/
	if (VentilReq == TRUE)
	{
		VEN_UnvolontaryStop = TRUE;
	}

	TIM_StartDecounter(SYS_1MINPAT, TIME_1MINPAT);

	/*%C Valve detection initialization at TRUE - Valve Mode */
	DB_ControlWrite(VALVE_DETECTED_U16,TRUE);

	/*%C The detection of the valve hasn't been done yet.*/
	DB_ControlWrite(VALVE_DETECT_IN_PROGRESS_U16,TRUE);
}
