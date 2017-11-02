// ccaesar1.h: interface for the ccaesar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CCAESAR1_H__5B5E51D7_0EE7_462B_8732_D4F384E56B1A__INCLUDED_)
#define AFX_CCAESAR1_H__5B5E51D7_0EE7_462B_8732_D4F384E56B1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using namespace std;

class ccaesar  
{
public:
	int k;
	string alfabeto;

	ccaesar(int k);
	virtual ~ccaesar();

	string cifrar (string m);
	string descifrar (string m);

};

#endif // !defined(AFX_CCAESAR1_H__5B5E51D7_0EE7_462B_8732_D4F384E56B1A__INCLUDED_)
