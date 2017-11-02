#include "DoubleList.h"
#include "DoubleListTraits.h"

int main()
{
	char waitByKey;
	DoubleList<DoubleListTraits> lista_prueba;

	cout<<"Lista Doblemente Enlazada"<<endl;

	for (int i= 1; i < 10; i++){
		lista_prueba.insert(i);
	}
	
	lista_prueba.remove(3);

	cout<<"Impresión Normal con Iterator"<<endl;
	lista_prueba.print();

	cout<<"Impresión Inversa con Iterator"<<endl;
	lista_prueba.inverse_print();

	cin>>waitByKey;
	return 0;
}