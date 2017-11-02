#include "CCola.h"

void CCola::encolar(Object * o):addByTail(o);

void CCola::desencolar():deleteByTail();

Object * CCola::getFirst(){
    return pHead->oDato;
}
