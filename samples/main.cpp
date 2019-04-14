#include <iostream>
#include "Polynom.h"
using namespace std;
int main()
{
	int x, y, z;
	TPolynom *p;
	TPolynom *p2;
	p = new TPolynom();
	p2 = new TPolynom();
	//input
	cout << "input polynom 1:" << endl;
	cin >> *p;
	cout << "--------------------\ninput polynom 2:" << endl;
	cin >> *p2;
	//output
	cout << "--------------------\npolynom 1" << endl << *p << endl;
	cout << "--------------------\npolynom 2" << endl << *p2 << endl;
	//sum
	cout << "--------------------\nsum of polynoms = " << *p + *p2 << endl;
	//calculating
	cout << "--------------------\ncalculating of polynoms" << endl;
	cout << "input x" << endl;
	cin >> x;
	cout << "input y" << endl;
	cin >> y;
	cout << "input z" << endl;
	cin >> z;
	cout << "polynom 1 = " << p->CalculatePolynom(x, y, z) << endl;
	cout << "polynom 2 = " << p2->CalculatePolynom(x, y, z) << endl;
	system("pause");
}