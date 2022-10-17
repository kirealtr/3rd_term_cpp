#include "frac.h"
#include <iostream>

#define SIGN(a) ((a) >= 0 ? 1 : -1);

using namespace std;

//Greatest common divisor
int GCD(int a, int b) {
  a *= SIGN(a); b *= SIGN(b);
  if (a == b)
    return a;
  else if (a > b)
    return GCD(a - b, b);
  else
    return GCD(a, b - a);
}

/*******************Frac class definitions********************/
//Private methods
void Frac::Reduce(void) {
  int gcd = GCD(num_, den_);
  if (!gcd) return;

  num_ /= gcd;
  den_ /= gcd;
}

//Constructors
Frac::Frac(int num, int den) {
  Set(num, den);
}

Frac::Frac(int n) {
  num_ = n;
  den_ = 1;
} // also conversion int->Frac, can be implicit

//Conversion Frac->double (explicit only)
Frac::operator double() const {
  return (double(num_) / double(den_));
}

//Setters
void Frac::Set(int num, int den) {
  if (!den) {
    cout << "Denominator cannot be a zero" << endl;
    exit(1);
  }

  num_ = num * SIGN(den);
  den_ = den * SIGN(den);
  Reduce();
}

void Frac::Input(void) {
  cout << "Enter numerator and denominator (!=0) of a fraction: ";
  int num, den;
  cin >> num; cin >> den;
  Set(num, den);
}

//Other methods
void Frac::Print(void) {
  cout << num_ << "/" << den_ << endl;
}

Frac Frac::Reciprocal(void) {
  return Frac(den_, num_);
}

/***************Mathematical operators***************/
//Binary
const Frac operator +(const Frac& left, const Frac& right) {
  int num = (left.num_ * right.den_) + (right.num_ * left.den_);
  int den = left.den_ * right.den_;
  return Frac(num, den);
}

const Frac operator -(const Frac& left, const Frac& right) {
  int num = (left.num_ * right.den_) - (right.num_ * left.den_);
  int den = left.den_ * right.den_;
  return Frac(num, den);
}

const Frac operator *(const Frac& left, const Frac& right) {
  int num = left.num_ * right.num_;
  int den = left.den_ * right.den_;
  return Frac(num, den);
}

const Frac operator /(const Frac& left, const Frac& right) {
  int num = left.num_ * right.den_;
  int den = left.den_ * right.num_;
  return Frac(num, den);
}

Frac& Frac::operator +=(const Frac& right) {
  num_ = (num_ * right.den_) + (right.num_ * den_);
  den_ *= right.den_;
  Reduce();
  return *this;
}

Frac& Frac::operator -=(const Frac& right) {
  num_ = (num_ * right.den_) - (right.num_ * den_);
  den_ *= right.den_;
  Reduce();
  return *this;
}

Frac& Frac::operator *=(const Frac& right) {
  num_ *= right.num_;
  den_ *= right.den_;
  Reduce();
  return *this;
}

Frac& Frac::operator /=(const Frac& right) {
  num_ *= right.den_;
  den_ *= right.num_;
  Reduce();
  return *this;
}

//Comparison
bool operator <(const Frac& left, const Frac& right) {
  return ((left.num_ * right.den_) < (right.num_ * left.den_));
}

bool operator >(const Frac& left, const Frac& right) {
  return ((left.num_ * right.den_) > (right.num_ * left.den_));
}

bool operator <=(const Frac& left, const Frac& right) {
  return ((left.num_ * right.den_) <= (right.num_ * left.den_));
}

bool operator >=(const Frac& left, const Frac& right) {
  return ((left.num_ * right.den_) >= (right.num_ * left.den_));
}

bool operator ==(const Frac& left, const Frac& right) {
  return ((left.num_ * right.den_) == (right.num_ * left.den_));
}

//Assignment
Frac& Frac::operator =(const Frac& right) {
  if (this == &right)
    return *this;

  num_ = right.num_;
  den_ = right.den_;
  return *this;
}

//Incrementation and decrementation
Frac& Frac::operator ++(void) {
  num_ += den_;
  return *this;
}

Frac& Frac::operator ++(int) {
  Frac tmp = *this;
  num_ += den_;
  return tmp;
}

Frac& Frac::operator --(void) {
  num_ -= den_;
  return *this;
}

Frac& Frac::operator --(int) {
  Frac tmp = *this;
  num_ -= den_;
  return tmp;
}