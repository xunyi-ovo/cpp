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
		cout << endl;
	}
	void test2(const list<int>& ls)
	{
		list<int>::const_iterator it1 = ls.begin();
		while (it1 != ls.end())
		{
			cout << *it1 << "  ";
			it1++;
		}

	}
}
int& add()
{
	int a = 333;
	return a;
}
int main()
{
	xunyi::test1();
	xunyi::list<int> ls;
	ls.push_back(1);
	ls.push_back(3);
	add() = 2;
	return 0;
}