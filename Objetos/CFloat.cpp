#include <iostream.h>
#include "CFloat.h"

CFloat::CFloat (const CFloat & cfOther){
    fDato = cfOther.fDato;
}

Object * clone(){
//    return new CFloat(*this);
}

void Print(ostream & os){
    os<<"Este es un flotante: "<<fDato<<endl;
}
