/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: TIM_StartDecounter.c    	   					               		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                Functionnal description : 	               					*/
/*                                                            				  		*/
/*%C This function is a decounter                       								*/
/******************************************************************************/
/*%I 	Input Parameter : 			offset_table     			                  	*/
/*%I 	Input Parameter : 			value           			                  	*/
/*%IO Input/Output Parameter :   None                                		  	*/
/*%O 	Output Parameter : 			None     	                				  		*/
/******************************************************************************/

/************************************************************************/
/*                           INCLUDE FILES		                        */
/************************************************************************/
//#ifndef _TASKING
//#include "LH_ST10F276.h"
//#include <intrins.h>
//#else
//#include "regf276e.h"
//#endif
#include "../GENERAL/io_declare.h"
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../TIMERS/Timer_Data.h"
			 
/******************************************************************************/
/*                            FUNCTION BODY                                   */
/******************************************************************************/


void TIM_StartDecounter(e_TIM_TABLE_ID offset_table, UWORD16 value)
{
	TIM_TableOfCntAndDecnt[offset_table].type = DECOUNT;
	TIM_TableOfCntAndDecnt[offset_table].value = value;
	TIM_TableOfCntAndDecnt[offset_table].activate = TRUE;		
}
