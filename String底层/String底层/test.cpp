#include <string>
#include <math.h>
#include <iostream>
#include <iomanip>
#include "string.h"
using namespace std;
namespace bit
{
	void test_string1()
	{
		string a = "hello ";
		string b = a;
		cout << b;
	}
}

int main()
{
	bit::test_string1();
	return 0;
}


