// ccaesar1.cpp: implementation of the ccaesar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ccaesar1.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ccaesar::ccaesar(int t)
{
	
}

ccaesar::~ccaesar()
{

}

string cifrar (string m)
{
	string result;
	int pos, n;

	for (int i=0; i<m.length; i++)
	{
		pos = alfabeto.find (m[i]);
		pos = pos+k;
		result+ = alfabeto [pos];
	}

	return result;
}

string cifrar (string m)
{}