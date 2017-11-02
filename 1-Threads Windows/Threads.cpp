#include <stdio.h>
#include <windows.h> 
#include "winbase.h"


//example 2
HANDLE hMutex;

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	char c = (char)lpParameter;
	//long sum = 0;
	for ( long i = 0; i < 10000; i++ )
	{
	
		//i+i+i+i+i+i+i+i+i*i*i*i*i*i;
		//sum += i+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1;
		
		WaitForSingleObject(hMutex, INFINITE); 
			printf("%c", c);
		ReleaseMutex(hMutex);
	}
	
	return 0;	
}

int main(int argc, char* argv[])
{
	const int nThreads = 15;
	unsigned long id[nThreads];
	HANDLE tHandle[nThreads];
	
	hMutex = ::CreateMutex(NULL, NULL, NULL);
	
	for ( int i = 0; i < nThreads; i++ )
	{
		id[i] = 1;
		tHandle[i] = ::CreateThread(NULL, 1024, ThreadProc, (void*)(char(i+97)), NULL, &id[i]);	
	}

	::WaitForMultipleObjects(nThreads, tHandle, true, INFINITE);
	return 0;
}







/*
//example 1
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	char c = (char)lpParameter;
	for ( int i = 0; i < 100; i++ )
		printf("%c", c);
	
	return 0;	
}

int main(int argc, char* argv[])
{
	unsigned long id = 1234;
	HANDLE thandle;
	thandle = ::CreateThread(NULL, 1024, ThreadProc, (void*)'c', NULL, &id);
	::WaitForSingleObject(thandle, INFINITE);
	return 0;
}
*/