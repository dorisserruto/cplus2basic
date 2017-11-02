#ifndef CFLOAT_H_INCLUDED
#define CFLOAT_H_INCLUDED

#include "Object.h"

class CFloat:public Object{
    private:
        int fDato;
    public:
        CFloat (int fdato): fDato(fdato){};

        CFloat (const CFloat & cfOther);
        //void Print();
};


#endif // CFLOAT_H_INCLUDED
