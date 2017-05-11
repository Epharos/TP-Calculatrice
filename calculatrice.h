#ifndef __CALCULATRICE_H__
#define __CALCULATRICE_H__

#include <iostream>
#include <string>
#include "pile.h"

class Calculatrice
{
	Pile P;
  
  	public:
  	Calculatrice();
  	char saisie(int & V);
  	bool number(char);
};

#endif
