#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>

using namespace boost;

mutex io_mutex;

struct count
{
  count(char i) : id(i) { }
  void operator()()
  {
    //unsigned long count = 0;
	for (long i = 0; i < 3000000; ++i)
    {
		mutex::scoped_lock lock(io_mutex);
		printf("%c", id);

		//count += i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i;
		//count = i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i*i;
    }
	printf("(%c)", id);
  }
  char id;
};

int main(int argc, char* argv[])
{
	int i, nthreads = 8;
	thread* ths = new thread[nthreads];

	for ( i = 0; i < nthreads; i++ )
		ths[i] = thread(count(char('a'+i)));

	for ( i = 0; i < nthreads; i++ )
		ths[i].join();

	delete[] ths;
	return 0;
}
