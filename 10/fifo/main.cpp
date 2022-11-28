#include <iostream>
#include <deque>
#include <initializer_list>
#include <string>

using namespace std;

template <typename T, typename Cont = deque<T>>
class Queue {
private:
  int size_ = 0;
  Cont content_;
public:
  Queue(void) {  }

  Queue(initializer_list<T> arr) : Queue() {
    for (unsigned int i = 0; i < arr.size(); i++)
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

  const T operator[](int index) { return content_[index]; }

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
    for (unsigned int i = 0; i < arr.size(); i++)
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

  const T operator[](int index) { return content_[index]; }

  ~Queue(void) { delete[] mem_block_; }
};

template <>
class Queue<string, string*> {
private:
  int size_ = 0;
  string** content_;
  int used_mem_ = 0;
  string** mem_block_;
public:
  Queue(void) {
    used_mem_ = 1;
    mem_block_ = content_ = new string*[1];
  }

  Queue(initializer_list<string> arr) : Queue() {
    string* init_cont = new string[arr.size()];
    for (unsigned int i = 0; i < arr.size(); i++)
      init_cont[i] = *(arr.begin() + i);

    for (unsigned int i = 0; i < arr.size(); i++)
      Append(init_cont + i);
    
  }

  void Append(string* val) {
    if (size_ + (content_ - mem_block_) == used_mem_) { // reallocate memory
      string** tmp = content_;
      content_ = new string*[size_ * 2];
      mem_block_ = content_;
      used_mem_ = size_ * 2;
      for (int i = 0; i < size_; i++)
        content_[i] = tmp[i];
      delete[] tmp;
    }

    content_[size_] = val;
    size_++;
  }

  void Append(string &val) { Append(&val); }
  void Append(const char* char_arr) {
    int n = 0;
    while (char_arr[n++] != '\0');
    string* str = new string;
    for (int i = 0; i < n; i++)
      *str += char_arr[i];

    Append(str);
  }

  string Pop(void) {
    if (!size_)
      return NULL;

    string str = *(content_[0]);
    size_--;
    if (size_)
      content_++;
    else
      content_ = mem_block_;
    return (str);
  }

  int Size(void) { return size_; }

  const string operator[](int index) { return *content_[index]; }

  ~Queue(void) { delete[] mem_block_; }
};

int main() {
  cout << "Queue with pointer container test:" << endl;
  Queue<int, int*> a = { 1, 2, 3, 4, 5, 6, 9 };
  a.Append(3);
  cout << a[3] << endl;
  while (a.Size())
    cout << a.Pop() << "  ";

  cout << endl;

  cout << "Queue with deque container test:" << endl;
  Queue<int> b = { 1, 2, 3, 4, 5, 6, 9 };
  b.Append(3);
  cout << b[3] << endl;
  while (b.Size())
    cout << b.Pop() << "  ";

  cout << endl;

  cout << "Queue of strings test:" << endl;
  Queue<string, string*> c = { "Hello", ", ", "World!" };
  string str = "eeee";
  c.Append(str);
  c.Append("EE");
  cout << c[3] << endl;
  while (c.Size())
    cout << c.Pop() << "  ";

  cout << endl;
}