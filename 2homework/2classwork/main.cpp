#include <iostream>

using namespace std;

const int m = 3, n = 3;
double* ext_matrix[m];

void swap_str(int i, int j) {
  double* tmp = ext_matrix[i];
  ext_matrix[i] = ext_matrix[j];
  ext_matrix[j] = tmp;
}

int main() {
  for (int i = 0; i < m; i++) {
    ext_matrix[i] = new double[n + 1];
    for (int j = 0; j < n + 1; j++) {
      cout << "string " << i << ", column " << j << ": ";
      cin >> ext_matrix[i][j];
    }
  }

  for (int col = 0; col < n; col++) {
    int str;
    
    for (str = col; str < m; str++) {
      if (ext_matrix[str][col])
        break;
    }
    if (str >= m) {
      cout << "System has infinite number of solutions";
      exit(0);
    }
    
    swap_str(str, col);

    for (str = 0; str < m; str++) {
      if (str == col)
        continue;
      double k = ext_matrix[str][col] / ext_matrix[col][col];
      for (int j = col; j < n + 1; j++)
        ext_matrix[str][j] -= ext_matrix[col][j] * k;
    }
    double t = ext_matrix[col][col];
    for (int j = col; j < n + 1; j++)
      ext_matrix[col][j] /= t;

  }

  for (int str = 0; str < m; str++) {
    cout << "x" << str << " = " << ext_matrix[str][n] << endl;
  }
}