#include "CLista.h"

CLista::CLista(){
    pHead = 0;
    pTail = 0;
}

CLista::CLista (const CLista & clOther){

}

CLista::~CLista(){
    if (pHead) pHead->Delete_you();
}

Object * clone(){
    //return new CLista(*this);
}

void Print(ostream & os){
    CNodo * tmp = pHead;
    for ( ;tmp;tmp=tmp->pSig){
        tmp->Print(os);
    }
}

ostream & CLista::operator <<(ostream & os){
    Print(os);
    return os;
}

void CLista::addByHead(Object * o){
    CNodo * nNuevo = new CNodo(o);
    if (!pHead){
        pHead = pTail = nNuevo;
    }
    else {
        nNuevo->pSig = pHead;
        pHead = nuevo
    }
}

void CLista::addByTail(Object * o){
    CNodo * nNuevo = new CNodo(o);
    CNodo * tmp = pHead;
    if (!tmp){
        pHead = pTail = nNuevo;
        return;
    }
    while (tmp->pSig){tmp = tmp->pSig;}
    tmp->pSig = nuevo;
}

void CLista::deleteByHead(){
    if (pHead){
        CNodo * tmp = pHead;
        pHead = pHead->pSig;
        delete tmp;
    }
}

void CLista::deleteByTail(){
    if (pHead){
        CNodo * tmp = pTail;
        pTail = pTail->pAnt;
        delete tmp;
    }
}

bool CLista::findSeq(Object * o){
    CNodo * tmp;
    for (;tmp;tmp = tmp->pSig){
        if (tmp->oDato == o)
            return true;
    }
    return false;
}

void CLista::reverseList(){
    CNodo * tmpPnt;
    CNodo * tmp;

    tmp = pHead;

    while (tmp){
        tmpPnt = tmp->pAnt;
        tmp->pAnt = tmp->pSig;
        tmp->pSig = tmpPnt;

        tmp = tmp->pAnt;
    }
    tmp = pTail;
    pTail = pHead;
    pHead = tmp;
}

bool CLista::isEmpty(){
    if (pHead == 0)
        return true;
    return false;
}
/*
encontrar maximo
encontrar minimo
*/
