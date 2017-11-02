#include <iostream>
#include <vector>

#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>

using namespace std;

template <class T>
class mergeSort
{
private:
	vector<T>& v;
	T ini, med, fin;

public:
	//pv: vector a ordenar
	// i: posicion inicial - //m: posicion media - //f: posicion final
	mergeSort(vector<T>& pv, T i, T m, T f)
	{
		vector<T>& v = pv;
		T ini = i;
		T med = m;
		T fin = f;
	}

	void merge() 
	{
		//Ordena el sub-vector que recibe desde su constructor
		vector<T> aux(fin - ini + 1);
    
		int i = ini; // Índice de la parte izquierda
		int j = med + 1; // Índice de la parte derecha
		int k = 0; // Índice del vector aux
 
		//Guarda el elemento mas pequeño en aux
		while (i <= med && j <= fin) 
		{
			if (v[i] < v[j]) {
				aux[k] = v[i];
				i++;
			}
			else {
				aux[k] = v[j];
				j++;
			}
			k++;
		}

		// Copia el resto de los subvectores
		while (i <= med) {
			aux[k] = v[i];
			i++;
			k++;
		}
		while (j <= fin) {
			aux[k] = v[j];
			j++;
			k++;
		}
 
		//Copia los elementos ordenados de aux al vector original
		for (int n = 0; n < aux.size(); ++n) v[ini + n] = aux[n];	
	}

	void operator () ()
	{
		if (ini < fin) {
			//Obtiene la posicion del medio
			int med = (ini + fin)/2;

			//Subvectores como threads
			boost::thread leftThread(mergeSort(v, ini, med));
			boost::thread rightThread(mergeSort(v, med + 1, fin));
			//Wait
			leftThread.join();
			rightThread.join();
			//Unir los subvectores
			merge();
		}	
	}

	void printVector()
	{
		for (int i=0; i < v.size(); i++)
			cout<<v[i]<<endl;
	}	
};
    
int main(int argc, char* argv[])
{
	int a= 0;
	cout << "Threaded MergeSort" << endl;

	//Prueba con cantidad pequeña
	int myints[] = {16,2,77,29,50,23,11,5};
	vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	mergeSort<int> mS(fifth,0,4,8);

	return 0;
}