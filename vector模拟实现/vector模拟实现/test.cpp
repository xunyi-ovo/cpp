#include "vector.h"
namespace bit
{
	void test()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(3);
		v.push_back(5);
		v.pop_back();
		v.push_back(7);
		v.push_back(9);
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.insert(v.begin(), 0);
		v.insert(v.begin(), 0);
		
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;

	
	}
}

int main()
{
	bit::test();
	return 0;
}