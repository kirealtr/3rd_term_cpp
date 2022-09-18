#include <iostream>
#include <cmath>

using namespace std;

void f(int i) {
  i = pow(i, 4);
  cout << "int i = " << i << endl;
}

void f(double d) {
  d = pow(d, 4);
  cout << "double d = " << d << endl;
}

int main() {
  long i = 2;
  cout << i << endl;
  f(i);
}