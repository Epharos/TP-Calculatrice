#include "calculatrice.h"
#include "Element.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Calculatrice::Calculatrice()
{		
    // Cette fonction appelle la fonction saisie
		// et effectue l'opération en fonction du caractère
		// retourné par saisie.
		// Il est pratique de l'écrire avec un grand switch 
		// a l'interieur d'un boucle qui s'arretera si saisie
		// retourne 'q' (ou 'Q').

		// ...

    int v;
    char c;

    bool flag = true;
    bool printPile = false;

    while(flag)
    {
        c = saisie(v);

        switch(c)
        {
            case 'q' :
                flag = false;
                break;

            case 'a' :
                printPile = !printPile;
                break;

            case 'd' :
                if(!P.Vide())
                    P.empiler(P.getLast()->getContent());
                else
                    cerr << "Rien à dupliquer :/" << endl;
                break;

            case ':' :
            {
                int i = P.getLast()->getContent();
                P.depiler();

                if(!P.Vide())
                    cout << P.getLast()->getContent() << endl;
                else
                    cerr << "Aucune valeur à afficher :/" << endl;
                
                P.empiler(i);
                break;
            }

            case '+' :
            {
                int right = P.depiler();
                int left = P.depiler();
                P.empiler(left + right);
                break;
            }
            case '-' :
            {
                int right = P.depiler();
                int left = P.depiler();
                P.empiler(left - right);
                break;
            }
            case '*' :
            {
                int right = P.depiler();
                int left = P.depiler();
                P.empiler(left * right);
                break;
            }
            case '/' :
            {
                int right = P.depiler();
                int left = P.depiler();
                P.empiler(left / right);
                break;
            }
            case '%' :
            {
                int right = P.depiler();
                int left = P.depiler();
                P.empiler(left % right);
                break;
            }
            case '=' :
            {
                int value = P.depiler();
                cout << "> " << value << endl;
                break;
            }

            case 'v' :
                P.empiler(v);
                break;

            default :
                cout << "Une erreur est survenue" << endl;
                break;
        }

        if(printPile)
            P.Afficher();
    }
}
  
char Calculatrice::saisie(int & V)
{		// Cette fonction saisit une string (S) l'analyse
  	// puis renvoie un caractere indiquant le type saisie :
	    // 'v' pour une valeur stockee dans V
		// le caractere pour un operateur ('+', '-'...)
		// ou une commande ('a', 'q'...)
    // Dans le cas d'une valeur celle-ci est retournée 
    // dans l'argument V
  
    string S;

    cout << "< ";
    cin >> S;

    switch(S[0])
    {
        case '+' :
            return '+';
        case '-' :
            return '-';
        case '*' :
            return '*';
        case '/' :
            return '/';
        case '%' :
            return '%';
        case '=' :
            return '=';

        case 'q' :
            return 'q';
        case 'Q' :
            return 'q';
        case 'a' :
            return 'a';
        case 'A' :
            return 'a';
        case ':' :
            return ':';
        case 'd' :
            return 'd';
        case 'D' :
            return 'd';

        default :
        {
            if(number(S[0]))
            {
                stringstream convert(S);
                convert >> V;
                return 'v';
            }
        }
    }
}

bool Calculatrice::number(char c)
{
    return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
            c == '5' || c == '6' || c == '7' || c == '8' || c == '9';
}

