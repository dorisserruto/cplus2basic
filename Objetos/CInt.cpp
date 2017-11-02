#include <iostream.h>
#include "CInt.h"

CInt::CInt (const CInt & ciOther){
    iDato = ciOther.iDato;
}

Object * clone(){
    //return new CInt(*this);
}

void CInt::Print(ostream & os){
    os<<"Este es un entero: "<<iDato<<endl;
}
