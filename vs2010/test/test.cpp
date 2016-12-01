// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

typedef void (*test)();

int _tmain(int argc, _TCHAR* argv[])
{
	HINSTANCE hdll = LoadLibrary(_T("testdll.dll"));

	if(hdll == NULL)
	{
		cout << "load library fail" << endl;
		return 0;
	}

	test t = (test)GetProcAddress(hdll, "test");

	if(t == NULL)
	{
		FreeLibrary(hdll);
		cout << "get proc address fail" << endl;
	}

	t();

	return 0;
}

