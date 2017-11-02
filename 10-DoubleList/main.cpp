#include "DoubleList.h"
#include "DoubleListTraits.h"

int main()
{
	DoubleList<DoubleListTraits> lista_prueba;

	for (int i= 1; i < 10; i++){
		lista_prueba.insert(i);
	}
}