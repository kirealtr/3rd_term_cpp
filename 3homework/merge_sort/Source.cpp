#include <iostream>
#include <iomanip>

using namespace std;

void MergeSort(int* array, int size);
void ArrPrint(int* array, int size);
void ArrCopy(int* dest, int* source, int size);

int main() {
  int n;
  cout << "Enter array size: ";
  cin >> n;

  int* arr = new int[n];
  cout << "Enter array elements" << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Array before sorting: ";
  ArrPrint(arr, n);
  MergeSort(arr, n);
  cout << "Array after sorting:  ";
  ArrPrint(arr, n);
}

void MergeSort(int* array, int size) {
  if (size == 1)
    return;

  int left_size = size / 2, *left = new int[left_size];
  int right_size = size - left_size, * right = new int[right_size];

  ArrCopy(left, array, left_size);
  ArrCopy(right, array + left_size, right_size);

  MergeSort(left, left_size);
  MergeSort(right, right_size);

  int iter_left = 0, iter_right = 0;
  while ((iter_left < left_size) and (iter_right < right_size)) {
    if (left[iter_left] < right[iter_right])
      array[iter_left + iter_right] = left[iter_left++];
    else
      array[iter_left + iter_right] = right[iter_right++];
  }
  
  ArrCopy(array + (iter_left + iter_right), right + iter_right, right_size - iter_right);
  ArrCopy(array + (iter_left + iter_right), left + iter_left, left_size - iter_left);
}

void ArrCopy(int* dest, int* source, int size) {
  for (int i = 0; i < size; i++)
    dest[i] = source[i];
}

void ArrPrint(int* array, int size) {
  for (int i = 0; i < size; i++)
    cout << setfill(' ') << setw(7) << array[i];
  cout << endl;
}