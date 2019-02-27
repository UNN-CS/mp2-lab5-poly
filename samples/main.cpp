#include <iostream>
#include "../include/datlist.h"

using namespace std;

int main()
{
  TDatList l;
  l.InsFirst();
  l.InsFirst();

  int i = 0;
  for(l.Reset(); !l.IsListEnded(); l.DelFirst())
  {
    cout << i++ << '\n';
  }

  return 0;
}
