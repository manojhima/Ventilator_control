/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename		: DB_IHM_Setting_Adjust_Cpap_Mode_Peep.c         	       		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functional description : 	this function controls the limits		*/
/*%C        of the Peep setting in the Cpap mode    	     							*/
/*                                                            				  		*/
/*%C Peep [min:30, max:200, step:10, default:0]                  					*/
/*%C Peep is include in its own limits(otherwise, value is saturated)	      */
/******************************************************************************/
/*%I 	Input Parameter :				Id                                    		  	*/
/*%IO Input/Output Parameter : 	*Value  	        			                  	*/
/*%O 	Output Parameter : 			True/False 	                 				  		*/
/******************************************************************************/


/******************************************************************************/
/*                                INCLUDE FILES		                          	*/
/******************************************************************************/
#include "../GENERAL/typedef.h"
#include "../GENERAL/enum.h"
#include "../GENERAL/Structure.h"
#include "../GENERAL/define.h"
//#include "../DRIVERS/DRV_VarEeprom.h"
#include "../DATABASE/DB_Control.h"
#include "../DATABASE/DB_Current.h"
#include "../DATABASE/DB_Rtc.h"
#include "../DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h"
			
/* locate database code to specific section */
#include "../GENERAL/locate_database_code.h"
/******************************************************************************/
/*                                FUNCTION BODY		                          	*/
/******************************************************************************/

UWORD16 DB_IHM_Setting_Adjust_Cpap_Mode_Peep(UWORD16 *Value,
														  UWORD16 Id)
{

/* Function result declaration */
   UWORD16 Function_Result = FALSE;

/*%C Up and down limit test 								                  */
/*%C Up limit test */
   if ( (*Value < cDB_CPAP_TEST_ADJUST_DB[Id].mini)
     || (*Value > cDB_CPAP_TEST_ADJUST_DB[Id].maxi)	)
   {
		Function_Result = TRUE;
   }
   else
   {
      Function_Result = FALSE;
   }

	return(Function_Result);
}
