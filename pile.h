#ifndef __PILE_H__
#define __PILE_H__

#include <iostream>
#include "Element.h"

using namespace std;

class Pile
{
    Element * last;
    
    public:
        Pile();
        Pile(Element *);
        ~Pile();
        void empiler(int v);
        int depiler();
        bool Pleine();
        bool Vide();
        void Afficher();
        Element * getLast();

    private :
        void Afficher(Element *);
};


#endif

