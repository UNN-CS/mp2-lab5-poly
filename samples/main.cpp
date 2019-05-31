#include <iostream>
#include "Polinom.h"

using namespace std;

int main()
{
    int m1[][2] = { { 2, 25 },{ 3, 35 },{ 4, 45 } };
    int m2[][2] = { { 4, 45 },{ 3, 35 },{ 2, 25 } };
    TPolinom p1(m1, 3), p2(m2, 3);
    p1.Print();
    cout << endl;
    p2.Print();
    cout << endl;
    return 0;
}