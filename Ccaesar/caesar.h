// caesar.h: interface for the Ccaesar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAESAR_H__1A86AC0B_A831_4AB4_859E_F1173B596E58__INCLUDED_)
#define AFX_CAESAR_H__1A86AC0B_A831_4AB4_859E_F1173B596E58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <string>
using namespace std;

class Ccaesar  
{
public:
	int k;
	string alfabeto;

	Ccaesar(int k);
	virtual ~Ccaesar();

	string cifrar (string m);
	string descifrar (string m);

};

#endif // !defined(AFX_CAESAR_H__1A86AC0B_A831_4AB4_859E_F1173B596E58__INCLUDED_)
