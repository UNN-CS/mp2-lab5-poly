// main
#include <iostream>
#include "tpolinom.h"

using namespace std;

int main()
{
	int ms1[][2] = { {1,200}, {1, 20}, {1,2} };
	int ms2[][2] = { {1,200}, {1, 20}, {1,2} };
	TPolinom p1(ms1, 3), p2(ms2, 3);
	cout << "First polinom: " << p1 << endl;
	cout << "Second polinom: " << p2 << endl;
	p1 += p2;
	cout << "Summary: " << p1;
	return 0;
}

