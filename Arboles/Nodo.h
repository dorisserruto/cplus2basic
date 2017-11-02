#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

template <class T>

class Nodo{
    private:
        Nodo <T> * pSon[2];
        T dato;
    public:
        Nodo(T d){
            pSon[0] = pSon[1] = 0;
            dato = d;
        }
};

#endif // NODO_H_INCLUDED

