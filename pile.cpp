#include "pile.h"
#include "Element.h"
#include <cstdlib>

Pile::Pile()
{
    last = NULL;
}
  
Pile::Pile(Element * e)
{
    last = e;
}

Pile::~Pile()
{
    delete last;
}

void Pile::empiler(int v)
{
    if (Pleine())
    {
        cerr << "Pile Pleine !" << endl;
        exit(2);
    }

    Element * e = new Element(last, v);
    last = e;
}

int Pile::depiler()
{
    int v;

    if (Vide())
    {
        cerr << "Pile vide !" << endl;
        exit(1);
    }

    v = last->getContent();
    last = last->getPrevious();
    return v;
}

bool Pile::Pleine()
{
    return false;
}

bool Pile::Vide()
{
    return last == NULL;
}

void Pile::Afficher()
{
    cout << "[";
    Afficher(last);
    cout << "]" << endl;
}

void Pile::Afficher(Element * e)
{
    if(e != NULL)
    {
        cout << e->getContent();

        if(e->getPrevious() != NULL)
        {
            cout << ", ";
            Afficher(e->getPrevious());
        }
    }
}

Element * Pile::getLast()
{
    return last;
}

// 

Element::Element()
{
    previous = NULL;
    content = 0;
}

Element::Element(Element * e, int c)
{
    previous = e;
    content = c;
}

Element::~Element()
{
    delete previous;
}

Element * Element::getPrevious()
{
    return previous;
}

void Element::setPrevious(Element * e)
{
    previous = e;
}

int Element::getContent()
{
    return content;
}

void Element::setContent(int i)
{
    content = i;
}

