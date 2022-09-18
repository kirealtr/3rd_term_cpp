#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void ArrPrint(int* array, int size);

int main() {
  int n;
  cout << "Enter array size: ";
  cin >> n;

  int* arr = new int[n];
  cout << "Enter array elements" << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Array before sorting:   ";
  ArrPrint(arr, n);

  for (int is_descending = 0; is_descending < 2; is_descending ++) {
    cout << "Array sorted " << (is_descending ? "ascending: " : "descending:");
    sort(arr, arr + n, [is_descending](int a, int b) { return(is_descending ? a < b : a > b); });
    ArrPrint(arr, n);
  }
}

void ArrPrint(int* array, int size) {
  for (int i = 0; i < size; i++)
    cout << setfill(' ') << setw(7) << array[i];
  cout << endl;
}