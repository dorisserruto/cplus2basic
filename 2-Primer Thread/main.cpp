#include <iostream>
#include <cstdlib>
#include <boost/thread.hpp>

//hack que debe añadirse, en windows
extern "C" void tss_cleanup_implemented() {}

using namespace std;

class funcObj
{
    string myname;
    int mytime;

    public:

    funcObj(string name, int time)
    {
        myname = name;
        mytime = time;
    }
    void operator () ()
    {
        HANDLE hMutex;

        hMutex= ::
        cout<<"Started task:"<<myname<<endl;
        boost::xtime xt;
        boost::xtime_get(&xt, boost::TIME_UTC);
        xt.sec += mytime;
        boost::this_thread::sleep(xt);
        cout<<"Finished task:"<<myname<<endl;
    }
};

int main{
    funcObj f1 ("NombreA", int(rand()%20));
    funcObj f2 ("NombreB", int(rand()%20));
    funcObj f3 ("NombreC", int(rand()%20));
    //using namespace boost;

    boost::thread t1(f1);
    boost::thread t2(f2);
    boost::thread t3(f3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
