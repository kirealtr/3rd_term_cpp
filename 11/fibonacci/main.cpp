#include <iostream>

using namespace std;

template<unsigned int n>
struct Fibonacci {
  static const unsigned int value = Fibonacci<n - 1>::value + Fibonacci<n - 2>::value;
};

template<>
struct Fibonacci<0> {
  static const unsigned int value = 0;
};

template<>
struct Fibonacci<1> {
  static const unsigned int value = 1;
};

void Print() {}

template<typename Head, typename... Tail>
void Print(const Head& head, const Tail&... tail) {
  cout << head << " ";
  Print(tail...);
}

int main() {
  Print<int, int>(Fibonacci<10>::value, Fibonacci<11>::value, Fibonacci<12>::value, Fibonacci<13>::value, Fibonacci<14>::value);
  cout << endl;
}