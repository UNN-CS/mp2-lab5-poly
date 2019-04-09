#include <iostream>
#include "Polinom.h"
using namespace std;

int main()
{
    int m1[][2] = {{1, 594}, {12, 132}, {2, 98}, {10, 19}, {-5, 6}, {-10, 0}};
    int m2[][2] = {{9, 786}, {3, 594}, {-12, 132}, {3, 97}, {15, 20}, {-5, 6}, {20, 0}};
    TPolinom p1(m1, 6), p2(m2, 7);
    cout<<"p1 += p2 operation \n";
    cout<< p1 << " and \n" << p2 <<"\n";
    p1 += p2;
    "Answer is\n";
    cout<< p1 <<"\n";
    
    return 0;
}
