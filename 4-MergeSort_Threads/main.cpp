#include <iostream>
#include <vector>
#include <stack>

#include <boost/thread.hpp>

using namespace std;

template <class T>
class MergeSort
{
	void ordena(vector<T>& v, T ini, T med, T fin) {
    
	vector<T> temp(fin - ini + 1);
    int i = ini; 
    int j = med + 1; 
    int k = 0;
 
    while (i <= med && j <= fin) {
        if (v[i] < v[j]) {
            temp[k] = v[i];
            i++;
        }
        else {
            temp[k] = v[j];
            j++;
        }
        k++;
    }
 
    while (i <= med) {
        temp[k] = v[i];
        i++;
        k++;
    }
 
    while (j <= fin) {
        temp[k] = v[j];
        j++;
        k++;
    }
    for (int n = 0; n < temp.size(); ++n) v[ini + n] = temp[n];
}
	
	void merge_sort(vector<T>& v, T ini, T fin) {
		if (ini < fin) {
		/*Considerar que el valor de med siempre es redondeado hacia abajo.*/
			int med = (ini + fin)/2;
			merge_sort(v, ini, med);
			merge_sort(v, med + 1, fin);
			ordena(v, ini, med, fin);
		}
	}

	void operator () (){
		
	}
};

vector <int> generarNumeros(int cantidad)
{
	vector <int> nuevoVector;

	//Peor caso, la lista está ordenada al revés
	for (int i = cantidad; i < 0; i--)
		nuevoVector.push_back(i);
	return nuevoVector;
}

int main(int argc, char* argv[])
{
	//Llenar el vector de numeros con 10 millones de nros
	vector <int> nrosXOrdenar;
	nrosXOrdenar = generarNumeros(10000);
	
	//Crear intervalos del vector para almacenarlos en la cola
	int nroElem = nrosXOrdenar.size();

	//Crear tantos threads como procesadores disponibles existan
	int nroProc = boost::thread::hardware_concurrency();

	//Colocar las sublistas en una cola


	//Pasarle a la thread objetos mergesort con sublistas segun turno en la cola
	boost::thread_group hilosOrdenan;
	for (int i= 0; i<= nroProc;i++)
		hilosOrdenan.create_thread(new MergeSort <int>());
}