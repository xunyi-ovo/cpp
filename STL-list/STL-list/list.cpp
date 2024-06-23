#include "list.h"
#include <list>
#include <algorithm>
void test1()
{
	list<int> ls = { 1,2,3,4,5,6,7};
	list<int>::iterator ls_iter1 = find(ls.begin(),ls.end(), 4);
	ls.splice(ls.begin(), ls, ls_iter1,ls.end());
	for (auto& e : ls)
	{
		cout << e << " ";
	}
}
int main()
{
	test1();
	return 0;
}