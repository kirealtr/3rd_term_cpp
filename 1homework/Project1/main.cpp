#include <iostream>

using namespace std;

const double kMetresToCentimetres = 1e+2;
const double kKilogramsToGram = 1e+3;
const double kNewtonsToDynes = 1e+7;

int main() {
  int mode = 1;
  cout << "SI -> CGS converter" << endl;
  cout << "To convert metres to centimeters, type 1." << endl <<
    "To convert kylograms to grams, type 2." << endl <<
    "To convert newtons to dynes, type 3." << endl <<
    "To exit, type 0." << endl;

  while (mode) {
    cout << "Enter mode: ";
    cin >> mode;
    
    double value;
    switch (mode)
    {
    case 1:
      cout << "Enter value in m: ";
      cin >> value;
      cout << scientific << value << " m = " << scientific <<
        value * kMetresToCentimetres << "cm" << endl;
      break;
    case 2:
      cout << "Enter value in kg: ";
      cin >> value;
      cout << scientific << value << " kg = " << scientific <<
        value * kKilogramsToGram << "g" << endl;
      break;
    case 3:
      cout << "Enter value in N: ";
      cin >> value;
      cout << scientific << value << " N = " << scientific <<
        value * kNewtonsToDynes << "dyn" << endl;
      break;
    default:
      break;
    }
  }
}
