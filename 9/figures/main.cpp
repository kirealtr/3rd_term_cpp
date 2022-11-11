#include <iostream>

using namespace std;

class Shape {
public:
  double virtual Area() = 0;
  double virtual Perimeter() = 0;
  void virtual Display() = 0;
};

class Polygon : Shape {
private:
  int vert_num_;
  double* vert_coord_;
public:
  Polygon()
};