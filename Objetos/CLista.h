#ifndef CLISTA_H_INCLUDED
#define CLISTA_H_INCLUDED

#include <iostream.h>
#include <fstream.h>
#include "Object.h"
#include "CNodo.h"

class CLista:public Object{
    protected:
        CNodo * pHead;
        CNodo * pTail;
    public:
        CLista();
        ~CLista();
        CLista (const CLista & clOther);

        //void Print(ostream & os);

        void addByHead(Object * o);
        void addByTail(Object * o);
        void deleteByHead();
        void deleteByTail();
        bool findSeq(Object * o);
        void reverseList();
        bool isEmpty();

        ostream & operator <<(ostream & os);

};

#endif // CLISTA_H_INCLUDED
