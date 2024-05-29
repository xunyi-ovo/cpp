#include <string>
#include <iostream>
#include "string.h"
using namespace std;
namespace bit
{
	void test_string1()
	{
		string a = "abcdef";
		a.eraser(2,1);
		cout << a.c_str();
		return;
	}
}

int main()
{
	bit::test_string1();
	
	return 0;
}
