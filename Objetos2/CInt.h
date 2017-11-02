#ifndef CINT_H_INCLUDED
#define CINT_H_INCLUDED

#include "Object.h"

class CInt:public Object{
    private:
        int iDato;
    public:
        CInt (int idato): iDato(idato){};

        CInt (const CInt & ciOther);
        //void Print();
};

#endif // CINT_H_INCLUDED
