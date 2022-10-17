#include "frac.h"
#include <iostream>

using namespace std;

int main() {
  Frac a, b;
  a.Input();
  b.Input();
  
  a /= a.Reciprocal();
  b -= ++a;
  Frac r1 = a * b;
  Frac r2 = a - 3.0;
  double r3 = 3.0 + double(a);
  int r4 = double(a / b);

  a.Print();
  b.Print();
  r1.Print();
  r2.Print();
  cout << r3 << endl;
  cout << r4 << endl;
}