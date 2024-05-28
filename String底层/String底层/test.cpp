#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
#include "string.h"
using namespace std;
namespace bit
{
	void test_string1()
	{
		string a = "hello";
		a.insert(0,"fuck");
		a.insert(3,"you");
		cout << a.c_str();
		return;
	}
}

int main()
{
	bit::test_string1();
	
	return 0;
}
