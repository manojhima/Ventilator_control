/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : DRV_BuzInit.c                                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :   Buzzer driver function   */
/*%C                                                                          */
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter :  NONE                                                  */
/*%IO Input/Output :    NONE                                                  */
/*%O Output Parameter : NONE                                                  */
/******************************************************************************/

/******************************************************************************/
/*                                INCLUDE FILES		                           */
/******************************************************************************/
//#ifndef _TASKING
//#include "LH_ST10F276.h"
//#include <intrins.h>
//#else
//#include "regf276e.h"
//#endif
#include "../GENERAL/io_stubs.h"
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../DATABASE/DB_Config.h"
#include "../DATABASE/DB_Control.h"
#include "../GENERAL/io_declare.h"
#include "DRV_BuzInit.h"
#include "../DRIVERS/Driver_Datas.h"

/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/
void DRV_BuzInit(void)
{
	UWORD16 Version = DB_VersionRead(VERSION_NUMBER_0);
	static UWORD16 FirstBuzInit = TRUE;
    static UWORD16 Frequency_Buzzer;
	
	/*%C Si premiere initialisation au d�marrage de l'appareil, on initialise 	 */
	/*%C tous les registres PWM et Timer */
	if (FirstBuzInit == TRUE)
	{
       e_Alarm_Tone Sound_Type_Select = DB_ConfigRead(SOUND_TYPE_SELECT_U16);
 
        if (Sound_Type_Select == ORIGINAL)
        {
            Frequency_Buzzer = CLASSIC_FREQUENCY_BUZZER;
        }
        else
        {
            Frequency_Buzzer = COMPLIANT_FREQUENCY_BUZZER;
        }

		/*%C Mise � jour du flag de 1�re initialisation */ 
 	    FirstBuzInit = FALSE; 

		//Programmation du pwm3 g�n�ration du niveau sonore du buzzer
		//Registre PWMCON1
		//PW3 programm� pa PM3 PS3 = 0
		//PS2 ne concerne pas le canal 3
		//PB01 ne concerne pas le canal 3
		//Canal 3 en mode standard PM3 = 0
		//Signal en sortie canal 3 PEN3 = 1
		//PWMCON3 =0xxx xxxx 0xxx 1xxx 
		PWMCON1 |= 0x0080;	   
		PWMCON1 &= 0x7F7F;  
		//Registre PWMCON0
		//Pas de demande d'interruption PIR3 = 0
		//Interruption non autoris�e PIE3 = 0
		//Entr�e d'horloge = FCPU PT3 = 0
		//Canal 3 en fonctionnement PTR3 = 1
		//PWMCON0 =0xxx 0xxx 0xxx 1xxx	
		PWMCON0 |= 0x0008;	   
		PWMCON0 &= 0x777F;	   
		PP3 = 10E8/(25*FREQUENCY_SOUND_LEVEL); //Programmation de la p�riode du PWM3
		//Programmation du PWM par timer T8 g�n�ration de la fr�quence buzzer
		//Programmation du registre de controle Timer T7
		//T7I = 000 Prescaler = FCPU/8 r�solution 200ns � 40MHz
		//T7M = 0 Mode timer
		//Bit R�serv� = 00
		//T7R = 0 Timer 7 � l'arr�t
		T78CON &= 0XFFF0;
		// Programmation du registre CCM2 pour CC28 capture compare mode
		//Capture compare mode register CCM0
		// ACC28 allou� au timer 7
		// CCMOD7 mode 3 compare reset de la sortie � overflow  de timer  
		// ACC31,ACC30,ACC29,CCMOM31,CCMOD30,CCMOD29 non programm�s
		// ==> CCM7 = xxxx xxxx  xxxx 0111 = 0x XXX7
		CCM7 &= 0xFFF7;  //Reset ACC27
		CCM7 |= 0x0007;  //Set CMOD28
	
	
		//Pr�chargement des valeurs du BUZZER 
 	    //Calcul du rechargement du timer T7 pour fixer la p�riode du PWM de r�glage du niveau sonore 
	    //T7REL = 65535 - (1/Fr�quence buzzer en ns) / R�solution du timer en ns(FCPU /8)200ns voir registre T78CON) 
        T7REL = 65535 - (10E9/Frequency_Buzzer)/(10E3/(FCPU/8)); 

		//Programmation du registre CC28 capture compare pour sortie P7.4
		//Rapport cyclique du PWM � 50%
		CC28 = (UWORD16)(T7REL + (65535 - T7REL)/2);
		
		//Arr�t du timer T7
		T7R = 0;
		// sortie Pwm3 d�sactiv�e
		PWMCON1 &= 0xFFF7;    	
		// Desactivation Buzzer S�curit�
		SEC_BUZ = 0;
	}
	else
	{
		
		//Pr�chargement des valeurs du BUZZER 
 	    //Calcul du rechargement du timer T7 pour fixer la p�riode du PWM de r�glage du niveau sonore 
 	    //T7REL = 65535 - (1/Fr�quence buzzer en ns) / R�solution du timer en ns(FCPU /8)200ns voir registre T78CON) 
        T7REL = 65535 - (10E9/Frequency_Buzzer)/(10E3/(FCPU/8)); 
		//Programmation du registre CC28 capture compare pour sortie P7.4
		//Rapport cyclique du PWM � 50%
		CC28 = (UWORD16)(T7REL + (65535 - T7REL)/2);
		
	}
}
