#include "heap.h"
#include <iostream>

using namespace std;

int main() {
  cout << "  Tests with int heap  " << endl;
  Heap<int> hi = { 4, 5, 2, 15, 99, 44 };
  cout << "Current max element: " << hi.ExtractMax() << endl;
  cout << "Position of 45: " << hi.Add(45) << endl;
  cout << "Current max element: " << hi.ExtractMax() << endl;
  cout << "Current heap size: " << hi.GetSize() << endl;

  cout << endl;

  cout << "  Tests with double heap  " << endl;
  Heap<double> hd = { 4.67, 4.3, 25.3, 1, 3.14, 2.71 };
  cout << "Current max element: " << hd.ExtractMax() << endl;
  cout << "Position of -0.5: " << hd.Add(-0.5) << endl;
  cout << "Current max element: " << hd.GetMax() << endl;
  cout << "Current heap size: " << hd.GetSize() << endl;
}