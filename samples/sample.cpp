#include <iostream>
#include <conio.h>
#include "Polinom.h"
using namespace std;

int main()
{
	cout << "Poly testing" << endl;
	int ms1[][2] = { { 1, 543 }, { 3, 432 }, { 5, 321 }, { 7, 210 }, { 9, 100 } };
		int mn1 = sizeof(ms1) / (2 * sizeof(int));
	TPolinom p(ms1, mn1);
	cout << "1 poly" << endl<<p;

	int ms2[][2] = { {2, 643}, {4, 431}, {-5, 321}, {8, 110}, {10, 50} };
	int mn2 = sizeof(ms2) / (2 * sizeof(int));
	TPolinom q(ms2, mn2);
	cout << "2 poly" << endl << q;
	p += q;
	cout << "result " << endl << p;
	cout << "Press any key" << endl;
	getch();
	return 0;
}