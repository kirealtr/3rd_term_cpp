#include <iostream>

unsigned int SizeInBytes(void) { return 0; }

template<typename Head, typename... Tail>
unsigned int SizeInBytes(const Head& head, const Tail&... tail) {
  return (sizeof(Head) + SizeInBytes(tail...));
}

int main() {
  long long ll = 1;
  int i = 1;
  double d = 1;
  std::cout << SizeInBytes(ll, i, d, "Hello") << std::endl;
}