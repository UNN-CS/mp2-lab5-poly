#include <iostream>
#include "TPolinom.h"
using namespace std;

int main()
{
	int m1[][2] = { { 23, 333 },{ -47, 159 },{ 69, 67 } };
	int m2[][2] = { { 2, 931 },{ 8, 930 },{ -3, 159 },{ 100, 91 },{ -400, 2 } };
	TPolinom p1(m1, 3), p2(m2, 5);
	cout << "p1: " << p1 << "p2: " << p2 << std::endl;
	p1 += p2;
	cout << "p1 = p1 + p2: " << p1;
	system("pause");
	return 0;
};