#include "vector.h"
namespace bit
{
	void test()
	{
		vector<string> v;
		v.push_back("xunyi");
		v.push_back("xunyi");
		v.push_back("xunyi");
		v.push_back("xunyi");
		v.push_back("xunyi");
		for (auto& e : v)
		{
			cout << e << " ";
		}
	}
}

int main()
{
	bit::test();
	int a = 10u;
	return 0;
}