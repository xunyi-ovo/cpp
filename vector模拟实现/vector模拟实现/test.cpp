#include "vector.h"
namespace bit
{
	void test()
	{
		vector<int> v;
		v.push_back(1);
		auto e = v.end();
		v.erase(--e);
	}
}

int main()
{
	bit::test();
	return 0;
}