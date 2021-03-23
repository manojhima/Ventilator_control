/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : It_watchdog.c 				                                       */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*
1)SFSYSTMON15
WATCHDOG CHECK
Min Val: 0
Max Val: 99.9
Rounded to: 0.1

2)SSOFT12
watchdog function
the software must be protected from a 200 ms software task overflow (watchdog function).

*/
/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C           Watchdog function (software and hardware)                      */
/*                                                                            */
/******************************************************************************/
/*%I Input Parameter : None                                                   */
/*%IO Input/Output : None                                                     */
/*%O Output Parameter : None 					                                    */
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
//#include "../GENERAL/io_declare.h"

void It_watchdog(void)
{
 	#define P2_4 0
	int WDOG =	P2_4;

/*%C Watch dog Hard activ� dans le scheduler toutes les 20 ms */
	WDOG = !WDOG;

/*%C Watch dog interne */
	_srvwdt_();
}
