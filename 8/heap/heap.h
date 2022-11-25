#pragma once
#include <initializer_list>
#include <algorithm>

#define ANCES(ind) ((ind - 1) / 2)
#define MAX(a, b) (a > b ? a : b)

using namespace std;

template <typename T>
class Heap {
private:
  int size_;
  T* cont_;
  int used_mem_;

  int SiftUp(int index);
  void SiftDown(int index);
public:
  Heap(void);
  Heap(std::initializer_list<T> arr);
  int Add(T elem); // returns element index in a heap
  T GetMax(void) { return cont_[0]; }
  int GetSize(void) { return size_; }
  T GetElem(int index) { return cont_[index]; }
  T ExtractMax(void); // returns deleted element
  ~Heap(void) { delete[] cont_; }
};

template <typename T>
int Heap<T>::SiftUp(int index) {
  int i = index;
  while ((i > 0) and (cont_[i] > cont_[ANCES(i)])) {
    swap(cont_[i], cont_[ANCES(i)]);
    i = ANCES(i);
  }
  return i;
}

template <typename T>
void Heap<T>::SiftDown(int index) {
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  int greatest = index;

  if ((left < size_) and (cont_[greatest] < cont_[left]))
    greatest = left;
  if ((right < size_) and (cont_[greatest] < cont_[right]))
    greatest = right;

  if (greatest != index) {
    swap(cont_[index], cont_[greatest]);
    SiftDown(greatest);
  }
}

template <typename T>
Heap<T>::Heap(void) {
  size_ = 0;
  used_mem_ = 1;
  cont_ = new T[1];
}

template <typename T>
Heap<T>::Heap(initializer_list<T> arr) {
  size_ = 0;
  used_mem_ = 1;
  cont_ = new T[1];
  for (int i = 0; i < arr.size(); i++)
    Add(*(arr.begin() + i));
}

template <typename T>
int Heap<T>::Add(T elem) {
  if (size_ == used_mem_) { // reallocate memory
    T* tmp = cont_;
    cont_ = new T[used_mem_ * 2];
    used_mem_ *= 2;
    for (int i = 0; i < size_; i++)
      cont_[i] = tmp[i];
    delete[] tmp;
  }

  cont_[size_] = elem;
  return SiftUp(size_++);
}

template <typename T>
T Heap<T>::ExtractMax(void) {
  T max = cont_[0];
  cont_[0] = cont_[--size_];
  SiftDown(0);
  return max;
}
