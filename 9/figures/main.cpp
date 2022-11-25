#include <iostream>
#include <initializer_list>
#include <math.h>

#define PI        3.1415926535897932384626433832795

using namespace std;

double distance(pair<double, double> p1, pair<double, double> p2) {
  return (sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2)));
}

class Shape {
protected:
  double area_ = 0;
  double perimeter_ = 0;
public:
  double Area() { return area_; }
  double Perimeter() { return perimeter_; }
  void virtual DisplayInfo() = 0;
};

class Polygon : public virtual Shape {
protected:
  int vert_num_;
  pair<double, double>* vert_coord_;
  double* sides_;

  void CalcSides(void) {
    sides_ = new double[vert_num_];
    for (int i = 0; i < vert_num_; i++)
      sides_[i] = distance(vert_coord_[(i + 1) % vert_num_], vert_coord_[i]);
  }
public:
  Polygon(initializer_list<pair<double, double>> arr) {
    vert_num_ = arr.size();
    vert_coord_ = new pair<double, double>[vert_num_];
    for (int i = 0; i < vert_num_; i++)
      vert_coord_[i] = *(arr.begin() + i);

    area_ = 0;
    for (int i = 0; i < vert_num_; i++)
      area_ += vert_coord_[i % vert_num_].first * vert_coord_[(i + 1) % vert_num_].second - 
               vert_coord_[(i + 1) % vert_num_].first * vert_coord_[i % vert_num_].second;

    area_ /= 2;
    area_ = abs(area_);

    CalcSides();
    perimeter_ = 0;
    for (int i = 0; i < vert_num_; i++)
      perimeter_ += sides_[i];
  }

  void DisplayInfo() {
    cout << "Polygon Info" << endl;
    cout << "  Area: " << area_ << endl;
    cout << "  Perimeter: " << perimeter_ << endl;
    cout << "  Number of vertices: " << vert_num_ << endl;
  }

  ~Polygon(void) {
    delete vert_coord_;
    delete sides_;
  }
};

class Triangle : public Polygon {
private:
  double angles[3] = { 0 };
  pair<double, double> circumcenter_;
  double circumradius_;

  void CalcAngles(void) {
    for (int i = 0; i < 3; i++)
      angles[i] = acos((pow(sides_[(i + 2) % 3], 2) + pow(sides_[i], 2) - pow(sides_[(i + 1) % 3], 2)) /
                                                                   (2 * sides_[(i + 2) % 3] * sides_[i]));
  }
public:
  Triangle(initializer_list<pair<double, double>> arr) : Polygon(arr) {
    CalcAngles();

    double sin_sum = sin(2 * angles[0]) + sin(2 * angles[1]) + sin(2 * angles[2]);
    double x = 0, y = 0;
    for (int i = 0; i < 3; i++) {
      x += vert_coord_[i].first * sin(2 * angles[i]);
      y += vert_coord_[i].second * sin(2 * angles[i]);
    }

    circumcenter_ = { x / sin_sum, y / sin_sum };
    circumradius_ = distance(circumcenter_, vert_coord_[0]);
  }

  pair<double, double> Circumcenter(void) { return circumcenter_; }

  double Circumradius(void) { return circumradius_; }
};

class Ellipse : public virtual Shape {
protected:
  pair<double, double> foc1_coord_;
  pair<double, double> foc2_coord_;
  double a_; // semi-major axis
  double b_; // semi-minor axis
public:
  Ellipse(pair<double, double> foc1, pair<double, double> foc2, double semi_min_ax) {
    foc1_coord_ = foc1;
    foc2_coord_ = foc2;
    b_ = semi_min_ax;
    a_ = sqrt(pow(semi_min_ax, 2) + pow(distance(foc1, foc2) / 2, 2));

    area_ = PI * a_ * b_;
    perimeter_ = PI * sqrt(2 * (pow(a_, 2) + pow(b_, 2)));
  }

  double SemiMajorAxis(void) { return a_; }
  double SemiMinorAxis(void) { return b_; }

  double Eccentricity(void) { return sqrt(1 - pow(b_ / a_, 2)); }

  void DisplayInfo(void) {
    cout << "Ellipse Info" << endl;
    cout << "  Area: " << area_ << endl;
    cout << "  Perimeter: " << perimeter_ << endl;
    cout << "  Semi-major axis: " << a_ << endl;
    cout << "  Semi-minor axis: " << b_ << endl;
    cout << "  Eccentricity: " << sqrt(1 - pow(b_ / a_, 2)) << endl;
  }
};

class Circle : public Ellipse {
public:
  Circle(pair<double, double> centre, double rad) : Ellipse(centre, centre, rad) {  }
};
  
int main() {
  Triangle tr1 = { {1, 2}, {2, 2}, {1, 3} };
  tr1.DisplayInfo();
  //cout << "Circumcenter: " << tr1.Circumcenter().first << ", " << tr1.Circumcenter().second << endl;
  //cout << "Circumradius: " << tr1.Circumradius() << endl;

  Ellipse el = { {0, 1}, {1, 0}, sqrt(2) };
  el.DisplayInfo();

  Circle cc = { tr1.Circumcenter(), tr1.Circumradius() };
  cc.DisplayInfo();
} 