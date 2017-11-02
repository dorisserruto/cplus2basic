#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

boost::mutex prod;
boost::mutex cons;

using namespace std;

const int iSlots = 10;
static int  array[iSlots];

static int iProd;
static int iCons;

void Iniciar()
{
	// Llena el array de vacío
    for(int i = 0; i< iSlots; i++)
       array[i]=-1;

	//Inicializa los valores de avance de productor y consumidor
	iProd = 0;
	iCons = 0;
}

class Productor
{
  public:
   Productor(){}

  void operator () ()
  {
       srand(time(NULL));
	   int iRandom;

       while(true)
       {
             if(array[iProd]==-1)
             {
				iRandom = rand()%iSlots;
				array[iProd]= iRandom;
                cout<<"P---> "<<array[iProd]<<endl;

				iProd = (iProd+1)%iSlots;
                cons.unlock();
				boost::this_thread::sleep(boost::posix_time::seconds(iRandom/8));
            }
             else
			{	prod.lock();}
       }
  }
};

class Consumidor
{
  public:
   Consumidor(){}

  void operator () ()
  {
       srand(time(NULL));
       while(true)
       {
             if(array[iCons]!=-1)
				{
					boost::xtime xt;
					boost::xtime_get(&xt, boost::TIME_UTC);
					xt.sec += array[iCons];
					boost::this_thread::sleep(xt);

					array[iCons]=-1;
					cout<<"C---> "<<array[iCons]<<endl;
					iCons = (iCons+1)%iSlots;
					prod.unlock();
				}
            else
				{cons.lock();}
       }
  }
};

int main()
{
	//Inician bloqueados ambos procesos.
    prod.lock();
    cons.lock();

	//Inicializamos
    Iniciar();

	//Instanciamos productor y consumidor
    Productor x;
    Consumidor y;

    boost::thread tx(x);
    boost::thread ty(y);

    tx.join();
    ty.join();
}