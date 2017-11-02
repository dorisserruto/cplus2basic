#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "Nodo.h"

template <class T>

class Arbol{
    private:
        Nodo <T> * pRoot;
    public:
        Arbol(){pRoot = 0;}

        Nodo <T> * getFather( T dato);
        int getLevel0( T dato);
        int getLevel1 (Nodo <T> * p, T d);
        Nodo <T> * getLevel2 (T d, int &N);

};
#endif // ARBOL_H_INCLUDED
