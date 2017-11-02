#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "Nodo.h"

//Define que se utilizará un template
//T será reemplazado para indicar el tipo
template <class T>

class Arbol{
    private:
        // Crea un punto a un Nodo tipo T
        // Este nodo apuntará a la raíz del árbol
        Nodo <T> * m_pRoot;
    public:
        Arbol(){
            //Asigna el valor de 0 al puntero a la raiz
            m_pRoot = 0;
        }
        virtual ~Arbol();

    // Crea una funcion find para encontrar un dato en el árbol
    bool find (T d){
        // Crea un puntero a Nodo tipo T "p"
        // Le asigna como valor la raíz del árbol
        Nodo <T> * p = m_pRoot;
        // Mientras p tenga un valor
        while (p){
            // si el dato en p es igual a d, retorna verdadero
            if (p -> dato == d) return true;
            // asigna a p el valor del nodo hijo dependiendo del valor del dato
            // si el dato buscado es menor que el dato en p, dara false(0) y tomara el valor del hijo de la izquierda (pSon[0])
            // si el dato buscado es mayor que el dato en p, dara true(1) y tomara el valor del hijo de la izquierda (pSon[1])
            p = p -> pSon[(p -> dato) < d];
        }
        // si no encontró el valor, retorna false
        return false;
    }

    // Crea una función find para encontrar el dato
    bool find (T d, Nodo <T> ** &p){
        //Asigna a p la dirección del puntero al Nodo Raiz del arbol
        p = &m_pRoot;
        // Mientras p tenga un valor
        while (*p){
            // si el dato en p es igual a d, retorna verdadero
            if ((*p)->dato == d) return true;
            // asigna a p el valor del nodo hijo dependiendo del valor del dato
            // si el dato buscado es menor que el dato en p, dara false(0) y tomara el valor del hijo de la izquierda (pSon[0])
            // si el dato buscado es mayor que el dato en p, dara true(1) y tomara el valor del hijo de la izquierda (pSon[1])
            p = &(*p)->pSon[((*p)->dato) < d];
        }
         // si no encontró el valor, retorna false
        return false;
    }

    // Crear una funcion recursiva find
    bool findR(T d, Nodo <T> *p){
        // Si p no tiene valor, retorna false
        if (!p) return false;
        // Si el dato en p es igual a d (dato buscado) retorna true
        if ((p->dato) == d) return true;
        // Llamada recursiva a find
        // Envia el dato que esta siendo buscado: d
        // Y envia el valor del puntero al nodo hijo segun sea el caso:
            // si el dato buscado es menor que el dato en p, dara false(0) y tomara el valor del hijo de la izquierda (pSon[0])
            // si el dato buscado es mayor que el dato en p, dara true(1) y tomara el valor del hijo de la izquierda (pSon[1])
        return findR(d,p -> pSon[(p->date) < d]);
    }

    // Crear una funcion para añadir un Nodo
    bool add (T d){
        //declara un puntero a un puntero a un Nodo tipo T
        Nodo <T> ** pnt;
        // Si encuentra el dato que se desea ingresar, retorna false (no inserta el dato)
        if (find(d,pnt))
            return false;
        // Declara un nuevo Nodo tipo T con el valor del dato d
        Nodo <T> * nuevo = new Nodo <T> (d);
        // La funcion find,al buscar, se posicionó en el lugar en el cual debe insertarse el nuevo nodo
        // Se asigna al contenido en pnt el valor de nuevo.
        (*pnt) = nuevo;
        // Retorna true al haber realizado la inserción
        return true;
    }

    // Crear una funcion para añadir un Nodo (Recursiva)
    void addR(T d,Nodo <T> * &p){
        // Si p no tiene valor
        if (!p){
            // Asigna a p el nuevo Nodo tipo T
            p = new Nodo <T> (d);
            return;
        }
        // Si el dato en p es igual al dato buscado d
        if (p -> dato == d)
            // No realiza nada, ya que ya existe
            return;
        // Llamada recursiva a addR
        //Envia el dato que se desea insertar: d
        // Y envia el valor del puntero al nodo hijo segun sea el caso:
            // si el dato a insertar es menor que el dato en p, dara false(0) y tomara el valor del hijo de la izquierda (pSon[0])
            // si el dato a insertar es mayor que el dato en p, dara true(1) y tomara el valor del hijo de la izquierda (pSon[1])
        return addR(d,p -> pSon[(p->date) < d]);
    }
};

#endif // ARBOL_H_INCLUDED
