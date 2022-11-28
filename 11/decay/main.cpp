#include <iostream>
#include <type_traits>

using namespace std;

template<typename T, int n = 0>
struct Decay {
  using type = T;
};

template<typename T>
struct Decay<T*> {
  using type = typename Decay<T>::type;
};

template<typename T>
struct Decay<T&> {
  using type = typename Decay<T>::type;
};

template<typename T>
struct Decay<const T> {
  using type = typename Decay<T>::type;
};

template<typename T, int n>
struct Decay<array<T, n>> {
  using type = typename Decay<T>::type;
};

int main() {
  cout << is_same_v<Decay<int***>::type, int> << endl;
  cout << is_same_v<Decay<array<const string***, 15>>::type, string> << endl;
}