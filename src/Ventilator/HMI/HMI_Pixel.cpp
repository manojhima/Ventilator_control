/******************************************************************************/
/*                                                                            */
/* Project N�  :  RB0505                                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Filename  : HMI_Pixel.cpp 		 	  								 						*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*%C                     Functionnal description :                            */
/*%C                                                                          */
/*%C Pixel parameters															 			  	*/
/*		                                                                   	 	*/
/******************************************************************************/


/******************************************************************************/
/*                           HEADER INCLUDE FILE		                        */
/******************************************************************************/

#include "HMI_Pixel.hpp"
				 
/******************************************************************************/
/*                           OTHER INCLUDE FILE		                	   		*/
/******************************************************************************/

/******************************************************************************/
/*                           CONSTRUCTEUR/DESTRUCTEUR                			*/
/******************************************************************************/
Pixel::Pixel()
{
   Init(0,0);
}
/*----------------------------------------------------------------------------*/
Pixel::Pixel(UWORD16 _X,UWORD16 _Y)
{
   Init(_X,_Y);
}
/*----------------------------------------------------------------------------*/
void Pixel::Init(UWORD16 _X,UWORD16 _Y)
{
   SetX(_X);
   SetY(_Y);
}
/*----------------------------------------------------------------------------*/
bool Pixel::operator!=(const Pixel&  _P)
{
   return (GetX() != _P.GetX()) || (GetY() != _P.GetY());
}
/*----------------------------------------------------------------------------*/
void Pixel::SetX(UWORD16 _X)
{
   X = _X;
}
/*----------------------------------------------------------------------------*/
UWORD16 Pixel::GetX()const
{
   return X;
}
/*----------------------------------------------------------------------------*/
void Pixel::SetY(UWORD16 _Y)
{
   Y = _Y;
}
/*----------------------------------------------------------------------------*/
UWORD16 Pixel::GetY()const
{
   return Y;
}
/*----------------------------------------------------------------------------*/
e_BOOL Pixel::IsZero()
{
   return (e_BOOL)((GetX() == 0) && (GetY() == 0));
}