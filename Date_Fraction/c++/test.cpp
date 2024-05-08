#include "Date.h"
#include "Frac.h"
int main()
{
	Fraction f1(1,2);
	Fraction f2(2,3);
	cin >> f1 >> f2;
	Fraction f3 = f1 / f2;
	cout <<"商:" << f3;

}