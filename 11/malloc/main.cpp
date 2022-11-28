#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T, typename... ArgsT>
T* MemAllocate(const ArgsT&... args) {
  T tmp = { args... };
  T* obj = new T;
  *obj = tmp;
  return obj;
}

int main() {
  std::string* str_p = MemAllocate<std::string>("Hello");
  std::cout << *str_p << std::endl;

  std::vector<int>* arr_p = MemAllocate<std::vector<int>>(1, 2, 3);
  for (int i = 0; i < 3; i++)
    std::cout << (*arr_p)[i] << std::endl;
}