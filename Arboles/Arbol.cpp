//#include <cstdlib>
#include <stack>
#include "Nodo.h"
#include "Arbol.h"

using namespace std;

//FUNCIONES PARA:
//1.IMPRIMIR EL PADRE DE UN NODO
//2.IMPRIMIR EL HERMANO DE UN ARBOL BINARIO
//3.IMPRIMIR EN PRE ORDEN - IN ORDEN - POST ORDEN
//4.CREAR UNA FUNCIONES MOVENEXT, MOVEPREVIOUS, BEGIN, END
//5.HALLAR LA ALTURA DEL ARBOL
//6.HALLAR EL NIVEL DE UN NODO
//7.IMPRIMIR POR NIVELES
//8.IMPRIMIR EL CAMINO DE LA RAIZ HASTA EL NODO X

template <class T>

//1.Obtener el padre de un nodo
Nodo <T> * Arbol <T>::getFather( T dato ){
    stack <Nodo <T> *> Pila;
    if (!pRoot) return 0;
    if ( pRoot->dato == dato) return 0;

    Nodo <T> * Nx = pRoot;
    while (Nx){
        Pila.push(Nx);
        Nx = Nx ->pSon[ Nx->dato < dato];
        if (!Nx) return 0;
        if (Nx ->dato == dato)
            return Pila.top();
    }
}
//2. Obtener el hermano de un nodo
Nodo <T> * Arbol<T>::getBrother( T dato ){
    stack <Nodo <T> *> Pila;
    if (!pRoot) return 0;
    if ( pRoot->dato == dato) return 0;

    Nodo <T> * Nx = pRoot;
    while (Nx){
        Pila.push(Nx);
        Nx = Nx ->pSon[ Nx->dato < dato];
        if (!Nx) return 0;
        if (Nx ->dato == dato)
            Pila.top()->pSon[];
    }

}

//3.1. Imprimir el arbol en In Order
void Arbol <T>::printInOrder(Nodo <T> p){
    if (!p) return;
    printInOrder (p->pSon[0]);
    cout<<p->dato;
    printInOrder (p->pSon[1]);
}

//3.2. Imprimir el arbol en Pre Order
void Arbol <T>::printPreOrder(Nodo <T> p){
    if (!p) return;
    cout<<p->dato;
    printPreOrder (p->pSon[0]);
    printPreOrder (p->pSon[1]);
}

//3.3. Imprimir el arbol en Post Order
void Arbol <T>::printPostOrder(Nodo <T> p){
    if (!p) return;
    printPostOrder (p->pSon[0]);
    printPostOrder (p->pSon[1]);
    cout<<p->dato;
}

//5. Obtener la altura del arbol
/*int Arbol <T>::getHeight(){
    stack <Nodo <T> *> Pila;
    if (!pRoot) return 0;
    //if ( pRoot->dato == dato) return 0;

    Nodo <T> * Nx = pRoot;
    while (Nx){
        Pila.push(Nx);
        Nx = Nx ->pSon[ Nx->dato < dato];
        if (!Nx) return 0;
        if (Nx ->dato == dato)
            return Pila.size();
    }
}*/

//6.1.Obtener el nivel de un nodo
int Arbol <T>::getLevel0(T dato){
    stack <Nodo <T> *> Pila;
    if (!pRoot) return 0;
    if ( pRoot->dato == dato) return 0;

    Nodo <T> * Nx = pRoot;
    while (Nx){
        Pila.push(Nx);
        Nx = Nx ->pSon[ Nx->dato < dato];
        if (!Nx) return 0;
        if (Nx ->dato == dato)
            return Pila.size();
    }
}

//6.2.Obtener el nivel de un nodo
int Arbol::getLevel1 (Nodo <T> * p, T d){
    static int N = 0;
    if (!p) return - 1;
    if ( p -> dato == d) return N;
    N++;
    getLevel(p->pSon[p->dato < d];
}

//6.3.Obtener el nivel de un nodo
Nodo <T> * Arbol::getLevel2 (T d, int &N){
    Nodo <T> * p = pRoot;
    Nodo <T> * q;
    while (p){
        q = p;
        p = p -> pSon[p->dato < d];
        N++;
        if (!p) return -1;
        if (p->dato == d) return q;
    }
    return -1;
}
