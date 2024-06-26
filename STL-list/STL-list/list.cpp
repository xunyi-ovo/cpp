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
		ls1.push_back({3,4});
		ls1.push_back(Pos(3,4));
		ls1.push_back(Pos(5,3));
		auto it = ls1.begin();
		while (it != ls1.end())
		{
			cout << "(" << it->_row << "," << it->_col << ")" << endl;
			it++;
		}
	}
	void test2()
	{

	}
}
int main()
{
	xunyi::test1();
	return 0;
}