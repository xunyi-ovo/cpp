#include "list.h"
#include <list>
#include <algorithm>
namespace xunyi
{
	void test1()
	{
		class Pos
		{
		public:
			int _row;
			int _col;
			Pos(int row=0,int col=0):_row(row),_col(col)
			{}
		};
		list<Pos> ls1;
		ls1.push_back(Pos(1, 2));
		ls1.push_back(Pos(1, 2));
		ls1.push_back(Pos(1, 4));
		list<Pos>::iterator it = ls1.begin();
		while (it != ls1.end())
		{
			cout << "(" << it->_row << "," << it->_col << ")" << endl;
			it++;
		}
	}
	void test2()
	{
		list<int> ls;
		ls.push_back(1);
		ls.push_back(2);
		ls.push_back(3);
		list<int>::iterator it1 = ls.begin();
		while (it1 != ls.end())
		{
			cout << *it1++ << " ";
		}
	}
	void test3()
	{
		list<int> ls;
		ls.push_back(5);
		ls.push_back(2);
		ls.push_back(0);
		ls.push_back(1);
		ls.push_back(1);
		auto it1 = ls.begin();
		for (auto& e : ls)
		{
			cout << e << " ";
		}
	}
}
int main()
{
	//xunyi::test2();
	xunyi::test3();

	return 0;
}