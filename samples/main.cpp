#include <iostream>
#include "Polinom.h"

using namespace std;

int main()
{
	int a1[][2] = { {5, 333}, {7, 321}, {4, 213}, {9, 113}, {1, 10} };
	int a2[][2] = { {6, 333}, {4, 322}, {3, 321}, {7, 110}, {4, 10}, {5, 2}, {5, 3} };
	TPolinom p1(a1, 5);
	TPolinom p2(a2, 7);
	cout << p1 << "\n+\n" << p2 << "\n=\n";
	p1 += p2;
	cout << p1;
	return 0;
}