#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

const int kDefaultPrecision = 3;

class Complex {
private:
  double re_, im_;
  double arg_, mod_;

  void CalcPolar(void) {
    mod_ = sqrt(re_ * re_ + im_ * im_);
    if ((re_ < 0) and (im_ == 0))
      arg_ = acos(-1); // pi number
    else if (mod_ == 0)
      arg_ = 0; // we can't define an argument of complex 0, but let it be 0
    else
      arg_ = 2 * atan(im_ / (mod_ + re_));
  }
  void CalcParts(void) {
    re_ = mod_ * cos(arg_);
    im_ = mod_ * sin(arg_);
  }
public:
  //Setters
  Complex(void) {
    SetParts(0, 0);
  };
  Complex(double real, double imaginary) {
    SetParts(real, imaginary);
  }
  void SetParts(double real, double imaginary) {
    re_ = real;
    im_ = imaginary;
    CalcPolar();
  }
  void SetPolar(double modulus, double argument) {
    mod_ = modulus;
    arg_ = argument;
    CalcParts();
  }
  //Getters
  double GetRe(void) {
    return re_;
  }
  double GetIm(void) {
    return im_;
  }
  double GetMod(void) {
    return mod_;
  }
  double GetArg(void) {
    return arg_;
  }
  //Output in different forms
  void PrintAlgF(int prec = kDefaultPrecision) {
    if (!mod_)
      cout << 0 << endl;
    else
      cout << setprecision(prec) << re_ << " + i*" << im_ << endl;
  }
  void PrintTrigF(int prec = kDefaultPrecision) {
    if (!mod_)
      cout << 0 << endl;
    else
      cout << setprecision(prec) << mod_ << "*(cos" << arg_ << " + sin" << arg_ << ')' << endl;
  }
  void PrintExpF(int prec = kDefaultPrecision) {
    if (!mod_)
      cout << 0 << endl;
    else
      cout << setprecision(prec) << mod_ << "*exp(i*" << arg_ << ')' << endl;
  }
  //Arithmetical operations
  Complex Add(double operand) {
    Complex result;
    result.SetParts(this->GetRe() + operand, im_);
    return result;
  }
  Complex Add(Complex operand) {
    Complex result;
    result.SetParts(this->GetRe() + operand.GetRe(), this->GetIm() + operand.GetIm());
    return result;
  }
  
  Complex Subtract(double operand) {
    Complex result;
    result.SetParts(re_ - operand, im_);
    return result;
  }
  Complex Subtract(Complex operand) {
    Complex result;
    result.SetParts(re_ - operand.GetRe(), im_ - operand.GetIm());
    return result;
  }

  Complex Multiply(double operand) {
    Complex result;
    result.SetPolar(mod_ * operand, arg_);
    return result;
  }
  Complex Multiply(Complex operand) {
    Complex result;
    result.SetPolar(mod_ * operand.GetMod(), arg_ + operand.GetArg());
    return result;
  }

  Complex Divide(double operand) {
    Complex result;
    if (operand == 0) {
      cout << "You can't divide numbers by 0!";
      //result.SetParts(0, 0);
      //return result;
      exit(1);
    }
    result.SetPolar(mod_ / operand, arg_);
    return result;
  }
  Complex Divide(Complex operand) {
    Complex result;
    if (operand.GetMod() == 0) {
      cout << "You can't divide numbers by 0!";
      //result.SetParts(0, 0);
      //return result;
      exit(1);
    }
    result.SetPolar(mod_ / operand.GetMod(), arg_ - operand.GetArg());
    return result;
  }

  Complex Conjugate(void) {
    Complex result;
    result.SetParts(re_, - im_);
    return result;
  }
  Complex Power(double operand) {
    Complex result;
    result.SetPolar(pow(re_, operand), arg_ * operand);
    return result;
  }
  Complex Sqrt(void) {
    return Power(0.5);
  }
};

int main() {
  Complex z1;
  Complex z2;
  Complex result;

  double re, im;
  cout << "Enter Re and Im of z1: "; 
  cin >> re; cin >> im;
  z1.SetParts(re, im);

  cout << "Enter Re and Im of z2 (but don't enter both 0!): ";
  cin >> re; cin >> im;
  z2.SetParts(re, im);

  cout << "z1 = "; z1.PrintExpF(7);
  cout << "z2 = "; z2.PrintExpF(5);
  cout << endl;

  result = z1.Add(z2);
  cout << "z1 + z2 = "; result.PrintTrigF(9);

  result = z1.Subtract(z2);
  cout << "z1 - z2 = "; result.PrintExpF();

  result = z1.Multiply(z2);
  cout << "z1 * z2 = "; result.PrintAlgF();

  result = z1.Divide(z2);
  cout << "z1 / z2 = "; result.PrintAlgF();

  result = z1.Power(3);
  cout << "z1^3 = "; result.PrintAlgF();
}