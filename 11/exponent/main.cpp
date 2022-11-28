#include <iostream>
#include <iomanip>

using namespace std;

constexpr long int Factorial(int n) {
  return (n <= 1 ? 1 : (n * Factorial(n - 1)));
}

constexpr long double e(int precision) {
  return (precision == 0 ? 1 : e(precision - 1) + ((long double)1.0 / (long double)Factorial(precision)));
}

int main() {
  cout.precision(15);
  cout << e(18) << endl;
}