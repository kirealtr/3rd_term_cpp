#include <iostream>

using namespace std;

int main() {
  double a, b, c;
  cout << "This program solves equations of the form (a*x^2 + b*x + c = 0), where (a != 0)." << endl;

  cout << "Enter coefficient a: ";
  cin >> a;
  if (a == 0) {
    cout << "It is linear equation!" << endl;
    exit(0);
  }

  cout << "Enter coefficient b: ";
  cin >> b;

  cout << "Enter coefficient c: ";
  cin >> c;

  double D = b * b - 4 * a * c;
  if (D < 0)
    cout << "No solutions" << endl;
  else if (D == 0)
    cout << "One solution: " << - b/(2 * a) << endl;
  else {
    double x1 = (-b - sqrt(D)) / (2 * a), x2 = (-b + sqrt(D)) / (2 * a);
    cout << "Two solutions: " << x1 << " and " << x2 << endl;
  }
}