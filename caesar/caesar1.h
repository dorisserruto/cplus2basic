// caesar1.h: interface for the caesar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAESAR1_H__190F66D6_EFD7_4C47_9AAE_C5FB1C9F16E8__INCLUDED_)
#define AFX_CAESAR1_H__190F66D6_EFD7_4C47_9AAE_C5FB1C9F16E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <string>
using namespace std;

class caesar  
{
public:
	int k;
	string alfabeto;

	caesar();
	virtual ~caesar();

	string cifrar (string m);
	string descifrar (string m);
};

#endif // !defined(AFX_CAESAR1_H__190F66D6_EFD7_4C47_9AAE_C5FB1C9F16E8__INCLUDED_)
