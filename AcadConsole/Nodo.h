#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

template <class T>

class Nodo{
    private:
        T tDato;
        Nodo <T> * pSon[2];
    public:
        Nodo (T d){
            pSon[0] = pSon[1] = 0;
            tDato = d;
        }
        ~Nodo();
};

#endif // NODO_H_INCLUDED
