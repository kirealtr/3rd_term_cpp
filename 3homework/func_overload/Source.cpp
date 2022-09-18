#include <iostream>
#include <cmath>

using namespace std;

void f(int i, double d) {
  i = pow(i, 4);
  d = pow(d, 3);
}

void f(double d, int i) {
  d = pow(d, 4);
  i = pow(i, 3);
}

int main() {
  int i = 2;
  cout << i;
  f(i, i);
  cout << i;
}