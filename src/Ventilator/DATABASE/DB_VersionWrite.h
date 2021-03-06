/******************************************************************************/
/*																										*/
/* Project Number	: 	RB0505     			     		                       	  		*/
/*																										*/
/*----------------------------------------------------------------------------*/
/*                                                                 			  	*/
/* Filename	: DB_VersionWrite.h 			   				                  		*/
/*                                                           				  		*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C 			Functionnal description : 														*/
/*                                                            				  		*/
/******************************************************************************/
/*%I 	Input Parameters :  			None          			                  		*/
/*%IO Input/Output Parameters :  None          			                  		*/
/*%O 	Output Parameters :  		None         			                  		*/
/******************************************************************************/
#ifndef DB_VERSIONWRITE_H
#define DB_VERSIONWRITE_H

//extern void DB_WriteDataInEepAndRam(UWORD16 xhuge *data_address,UWORD16 value);
extern void DB_WriteDataInEepAndRam(UWORD16 *data_address,UWORD16 value);

#endif
