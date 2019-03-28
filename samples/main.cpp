#include <iostream>
#include "../include/polinom.h"

using namespace std;

int main()
{
  int command;
  TPolinom *p1, *p2, *sum;
  p1 = p2 = sum = nullptr;

  do
  {
    cout << "\n1. Enter polinom 1\n"
         << "2. Enter polinom 2\n"
         << "3. Show polinom 1\n"
         << "4. Show polinom 2\n"
         << "5. Delete polinom 1\n"
         << "6. Delete polinom 2\n"
         << "7. Show summ\n"
         << "0. Exit" << endl;
    cin >> command;
    switch(command)
    {
    case 1:
      if(p1 == nullptr)
        p1 = new TPolinom;
      cin >> *p1;
      delete sum;
      sum = nullptr;
      break;
    case 2:
      if(p2 == nullptr)
        p2 = new TPolinom;
      cin >> *p2;
      delete sum;
      sum = nullptr;
      break;
    case 3:
      cout << "Polinom 1:" << endl;
      if(p1 != nullptr)
        cout << *p1;
      else
        cout << 0;
      cout << endl;
      break;
    case 4:
      cout << "Polinom 2:" << endl;
      if(p2 != nullptr)
        cout << *p2;
      else
        cout << 0;
      cout << endl;
      break;
    case 5:
      delete p1;
      p1 = nullptr;
      break;
    case 6:
      delete p2;
      p2 = nullptr;
      break;
    case 7:
      if(sum == nullptr)
      {
        sum = new TPolinom(*p1);
        *sum += *p2;
      }
      cout << *sum << endl;
      break;
    case 0:
      delete sum;
      delete p1;
      delete p2;
      exit(0);
    }
  }
  while(true);

  delete sum;
  delete p1;
  delete p2;

  return 0;
}

