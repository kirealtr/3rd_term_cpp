#include <iostream>

using namespace std;

void swap(int* a, int* b) {
  *a ^= *b;
  *b = *a ^ *b;
  *a ^= *b;
}

int main() {
  int x, y;
  cout << "Enter x: ";
  cin >> x;
  cout << "Enter y: ";
  cin >> y;

  cout << "Swaping..." << endl;
  swap(&x, &y);

  cout << "Now x = " << x << " and y = " << y << endl;
}