#include "vector.h"
namespace bit
{
	void test()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(3);
		v.push_back(5);
		v.push_back(7);
		v.push_back(9);
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << endl;
		}
	}
}

int main()
{
	bit::test();
	return 0;
}