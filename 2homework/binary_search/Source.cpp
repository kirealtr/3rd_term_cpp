#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

void VecInsSort(vector <int>&);
void VecPrint(vector <int>);
bool VecBinSearch(vector <int>, int);
bool IsNumber(string);

int main() {
  cout << "Enter size of an array: ";
  int n;
  cin >> n;
  vector <int> arr(n);

  cout << "Enter array's elements" << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  VecInsSort(arr);
  cout << "Your sorted array:  ";
  VecPrint(arr);

  while (1) {
    int elem;
    cout << "Enter an element to find (any string to quite): ";
    string str;
    cin >> str;
    if (IsNumber(str)) {
      stringstream ss;
      ss << str;
      ss >> elem;
    }
    else {
      arr.clear();
      arr.shrink_to_fit();
      return 0;
    }

    if (VecBinSearch(arr, elem))
      cout << "Your array contains " << elem << endl;
    else
      cout << "Your array does not contain " << elem << endl;
  }
}

bool IsNumber(string str) {
  int n = str.length();
  for (int i = 0; i < n; i++) {
    if (!isdigit(str[i]))
      return false;
  }
  return true;
}

void VecInsSort(vector <int>& vec) {
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
    cout << setfill(' ') << setw(6) << vec[i];
  cout << endl;
}

bool VecBinSearch(vector <int> vec, int x) {
  int n = vec.size() / 2;
  while (n > 0) {
    if (vec[n] == x)
      return true;
    else if (vec[n] < x) {
      vec.erase(vec.begin(), vec.begin() + n);
      n /= 2;
    }
    else {
      vec.erase(vec.begin() + n + 1, vec.end());
      n /= 2;
    }
  }

  if (vec[n] == x)
    return true;
  else
    return false;
}