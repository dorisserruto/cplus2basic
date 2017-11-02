#ifndef CNODO_H_INCLUDED
#define CNODO_H_INCLUDED

class CNodo:public Object{
    private:
        Object * oDato;
        CNodo * pAnt;
        CNodo * pSig;
    public:
        CNodo (Object * odato);
        CNodo (const CNodo & cnOther);
        Object * clone();

        void Print();
        void Delete_you();
};

#endif // CNODO_H_INCLUDED
