/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : HMI_VPoint.hpp                            	 	  					*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C                                                                          */
/*%C Classe declaration for HMI_VPoint.cpp	                         			*/
/*		                                                                   	 	*/
/******************************************************************************/

#ifndef VPointH
#define VPointH

/******************************************************************************/
/*                           HEADER INCLUDE FILE		                  		*/
/******************************************************************************/

extern "C"
{
#include "../GENERAL/typedef.h"
}
#include "HMI_Pixel.hpp"

/******************************************************************************/
/*                           CLASSE DECLARATION                    	      	*/
/******************************************************************************/

class Scale;
class VPoint
{
private:

   /* Parametres */

	/*%C X [ 0 : 320] */
   SWORD16 X;
	/*%C Y [ 0 : 240] */
   SWORD16 Y;

   /* M�thodes */

protected:

   /* Parametres */

   /* M�thodes */

public:
   
   /* Parametres */

   /* M�thodes */

   VPoint();
   bool operator!=(VPoint&  P);
   void Init(	SWORD16 X, 
   				SWORD16 Y);
   void SetX(SWORD16 X);
   SWORD16 GetX();
   void SetY(SWORD16 Y);
   SWORD16 GetY();
   Pixel& ToPixel(Scale *Ex,
   					Scale *Ey);
};

/******************************************************************************/
/*                           HEADER INCLUDE FILE		                  		*/
/******************************************************************************/
#include "HMI_Scale.hpp"

#endif
