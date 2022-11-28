#include <iostream>

template <typename T>
struct IsFunction {
  static const bool value = false;
};

template <typename F, typename... Args>
struct IsFunction<F(Args ...)> {
  static const bool value = true;
};

template <typename F, typename... Args>
struct IsFunction<F(Args ..., ...)> {
  static const bool value = true;
};

const int Func(...) { return 1; };

int main() {
  std::cout << IsFunction<decltype(Func)>::value << std::endl;
  std::cout << IsFunction<decltype(main)>::value << std::endl;
}