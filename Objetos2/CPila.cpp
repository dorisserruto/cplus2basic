#include "CPila.h"

void CPila::push(Object * o):addByHead(o);

void CPila::pop():deleteByHead();

Object * CPila::getTop(){
    return pHead->oDato;
}

