#ifndef CPILA_H_INCLUDED
#define CPILA_H_INCLUDED

class CPila:public CLista{
    //phead
    //pSig
    public:
        Object * clone();

        void push(Object * o);
        void pop();
        Object * getTop();
};

#endif // CPILA_H_INCLUDED
