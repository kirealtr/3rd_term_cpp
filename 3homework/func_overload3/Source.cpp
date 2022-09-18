#include <iostream>
#include <cmath>

using namespace std;

void f(int i, ...) {
  i = pow(i, 4);
  cout << "int i = " << i << endl;
}

void f(double d, int i) {
  d = pow(d, 4);
  i *= 2;
  cout << "double d = " << d << endl;
  cout << "int i = " << i << endl;
}

int main() {
  int i = 2;
  double d = 2.2;
  cout << i << ' ' << d<< endl;
  f(i, d);
}