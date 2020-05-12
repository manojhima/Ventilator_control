/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: DRV_VarEeprom.c     		   				                  		*/
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


#ifndef _BORLAND
    #ifndef _TASKING
    // Permet de ranger les adresses dans l'ordre de leur d�claration
      #pragma ORDER
    // Toutes les variables d�clar�s ici seront plac� � l'adresse EEPROM
       #pragma RENAMECLASS(HDATA0=EEPROM)
	#else
/* le pragma ORDER (ordonner les variables dans la m�moire dans l'ordre des 
d�claration, est assur� sous TASKING par l'option de compilation sur ce fichier " -Ot" */
	   	   #pragma class HB=EEPROM
		  #endif
#endif


#define EEP_VAR_SOURCE

#include "../GENERAL/typedef.h"
#include "DRV_VarEeprom.h"
//#include "database.h"

// Les variables locales sont automatiquement import�es par le preprocesseur
// lors de la compilation.

// Cette d�claration permet de rendre visible toute la base pour l'�mulateur
void TestReadBaseEmulator(void) { ; }

#undef EEP_VAR_SOURCE
