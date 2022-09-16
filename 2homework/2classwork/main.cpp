#include <iostream>

using namespace std;

//const int m = 3, n = 3;

void swap_row(int i, int j, double **dim2_arr) {
  double* tmp = dim2_arr[i];
  dim2_arr[i] = dim2_arr[j];
  dim2_arr[j] = tmp;
}

int main() {
  int m, n;
  cout << "Enter size of a square matrix: ";
  cin >> n;
  m = n;
  cout << "Enter matrix elements" << endl;

  double** ext_matrix = new double* [m];

  for (int i = 0; i < m; i++) {
    ext_matrix[i] = new double[n + 1];
    for (int j = 0; j < n + 1; j++) {
      cout << "row " << i << ", column " << j << ": ";
      cin >> ext_matrix[i][j];
    }
  }

  for (int col = 0; col < n; col++) {
    int row;
    
    for (row = col; row < m; row++) {
      if (ext_matrix[row][col])
        break;
    }
    if (row >= m) {
      cout << "System has infinite number of solutions";
      exit(0);
    }
    
    swap_row(row, col, ext_matrix);

    for (row = 0; row < m; row++) {
      if (row == col)
        continue;
      double k = ext_matrix[row][col] / ext_matrix[col][col];
      for (int j = col; j < n + 1; j++)
        ext_matrix[row][j] -= ext_matrix[col][j] * k;
    }
    double t = ext_matrix[col][col];
    for (int j = col; j < n + 1; j++)
      ext_matrix[col][j] /= t;

  }

  for (int row = 0; row < m; row++) {
    cout << "x" << row << " = " << ext_matrix[row][n] << endl;
    delete[] ext_matrix[row];
  }

  delete[] ext_matrix;
}