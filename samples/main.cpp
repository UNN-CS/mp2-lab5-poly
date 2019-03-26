#include <iostream>
#include "C:/Users/DDD/Desktop/Labs/mp2-lab5-poly-master/include/Polinom.h"

using namespace std;

int main()
{
	int ms1[][2] = { {1,200}, {1, 20}, {1,2} };
	int ms2[][2] = { {1,200}, {1, 20}, {1,2} };
	TPolinom p1(ms1, 3), p2(ms2, 3);
	p1.Print();
	cout << endl;
	p2.Print();
	cout << endl;
	return 0;
}