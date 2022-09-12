#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void VecInsSort(vector <int> &);
void VecPrint(vector <int>);

int main() {
  cout << "Enter size of an array: ";
  int n;
  cin >> n;
  vector <int> arr(n);

  cout << "Enter array's elements" << endl;
  for (int i = 0; i < n; i++) 
    cin >> arr[i];

  cout << "Array before sorting: ";
  VecPrint(arr);
  VecInsSort(arr);
  cout << "Array after sorting:  ";
  VecPrint(arr);
}

void VecInsSort(vector <int> &vec) {
  int n = vec.size();
  for (int i = 0; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (vec[j + 1] >= vec[j]) 
        break;
      swap(vec[j], vec[j + 1]);
    }
  }
}

void VecPrint(vector <int> vec) {
  int n = vec.size();
  for (int i = 0; i < n; i++) 
    cout << setfill(' ') << setw(5) << vec[i];
  cout << endl;
}