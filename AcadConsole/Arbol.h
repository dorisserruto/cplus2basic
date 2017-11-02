#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "Nodo.h"

template <class T>

class Arbol{
    private:
        Nodo <T> * m_proot;
    public:
        Arbol(){
            m_proot = 0;
        }
        ~Arbol();
};

#endif // NODO_H_INCLUDED
