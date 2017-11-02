#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

//Define que se utilizará un template
//T será reemplazado para indicar el tipo
template <class T>

class Nodo {
    private:
        //dato será del tipo T
        T dato;
        //Declara un array de punteros a Nodos tipo T
        Nodo <T> * pSon[2];
    public:
        //Constructor de nodo
        Nodo (T d){
            //inicializa a los Nodos hijos en 0
            pSon[0] = pSon[1] = 0;
            // Asigna el valor d en dato
            dato = d;
        }
        // Destructor del nodo
        virtual ~Nodo();
};

#endif // NODO_H_INCLUDED
