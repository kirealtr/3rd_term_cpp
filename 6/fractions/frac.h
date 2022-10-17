#pragma once

int GCD(int a, int b);

class Frac {
private:
  int num_;
  unsigned int den_;
  void Reduce(void);
public:
  Frac(int num, int den);
  Frac(int n = 1); // default initialization is possible
  explicit operator double() const; //conversion Frac->double is available only explicitly
                                    //to prevent a conflict with conversion int->Frac

  int GetNumerator(void) { return num_; }
  unsigned int GetDenominator(void) { return den_; }

  void Set(int num, int den);
  void Input(void);
  void Print(void);

  Frac Reciprocal(void);

  friend const Frac operator +(const Frac& left, const Frac& right);
  friend const Frac operator -(const Frac& left, const Frac& right);
  friend const Frac operator *(const Frac& left, const Frac& right);
  friend const Frac operator /(const Frac& left, const Frac& right);

  Frac& operator +=(const Frac& right);
  Frac& operator -=(const Frac& right);
  Frac& operator *=(const Frac& right);
  Frac& operator /=(const Frac& right);

  friend bool operator <(const Frac& left, const Frac& right);
  friend bool operator >(const Frac& left, const Frac& right);
  friend bool operator <=(const Frac& left, const Frac& right);
  friend bool operator >=(const Frac& left, const Frac& right);
  friend bool operator ==(const Frac& left, const Frac& right);

  Frac& operator =(const Frac& right);

  Frac& operator ++(void);
  Frac& operator ++(int);
  Frac& operator --(void);
  Frac& operator --(int);

};
