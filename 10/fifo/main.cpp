#include <iostream>
#include <deque>
#include <initializer_list>

using namespace std;

template <typename T, class Cont = deque<T>>
class Queue {
private:
  int size_ = 0;
  Cont content_;
public:
  Queue(void) {  }

  Queue(initializer_list<T> arr) : Queue() {
    for (int i = 0; i < arr.size(); i++)
      Append(*(arr.begin() + i));
  }

  void Append(T val) {
    content_.push_back(val);
    size_++;
  }

  T Pop(void) {
    size_--;
    T tmp = content_[0];
    content_.pop_front();
    return tmp;
  }

  int Size(void) { return size_; }

  ~Queue(void) {
    content_.clear();
  }
};

template <typename T, typename C>
class Queue<T, C*> {
private:
  int size_ = 0;
  T* content_;
  int used_mem_ = 0;
  T* mem_block_;
public:
  Queue(void) {
    used_mem_ = 1;
    mem_block_ = content_ = new T[1];
  }

  Queue(initializer_list<T> arr) : Queue() {
    for (int i = 0; i < arr.size(); i++)
      Append(*(arr.begin() + i));
  }

  void Append(T val) {
    if (size_ + (content_ - mem_block_) == used_mem_) { // reallocate memory
      T* tmp = content_;
      mem_block_ = content_ = new T[size_ * 2];
      used_mem_ = size_ * 2;
      for (int i = 0; i < size_; i++)
        content_[i] = tmp[i];
      delete[] tmp;
    }

    content_[size_] = val;
    size_++;
  }

  T Pop(void) {
    T tmp = content_[0];
    content_++;
    size_--;
    return tmp;
  }

  int Size(void) { return size_; }

  ~Queue(void) { delete[] mem_block_; }
};

int main() {
  deque<int> b = { 2 };

  Queue<int, int*> a = { 1, 2, 3, 4, 5, 6, 9 };
  a.Append(3);
  while (a.Size())
    cout << a.Pop() << endl;
}