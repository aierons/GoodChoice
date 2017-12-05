#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream>
using namespace std;

/*
 * Class representing a 2D vector with elements x and y.
 *
 * Given Vector v, size_t i, double d, std::ostream os, the following should be defined:
 *  Vector(): initializes elements to 0
 *  Vector(v): copy construction
 *  Vector(d1, d2): initializes x to d1 and y to d2
 *  v.setX(d): set x to d
 *  v.setY(d): set y to d
 *  v.getX(): returns x
 *  v.getY(): returns y
 *  os << v1: streams x and y separated by a space
 *  v1[i]: non-const and const element access; index 0 for x, index 1 for y; assertion failure on any other index
 *  v1 = v2: element-wise assignment
 *  v1 == v2; v1 != v2: element-wise (in)equality comparison
 *  -v: element-wise negation
 *  v1 += v2, v1 + v2, v1 -= v2, v1 - v2: element-wise addition or subtraction
 *  v *= d, v * d, d * v, v /= d, v / d: element-wise multiplication or division; assertion failure on division by 0.0
 */
class Vector {
public:
  Vector ();
  Vector (const Vector& v);
  Vector (double d1, double d2);
  void setX(double d);
  void setY(double d);
  double getX();
  double getY();
  friend ostream& operator<<(ostream& os, const Vector& v1);
  double& operator[](const int i);
  Vector& operator=(const Vector& v1);
  bool operator==(const Vector& v1);
  bool operator!=(const Vector& v1);
  Vector operator-() const;
  Vector operator+(const Vector& v1) const;
  Vector& operator+=(const Vector& v1);
  Vector operator-(const Vector& v1) const;
  Vector& operator-=(const Vector& v1);
  Vector operator*(double d) const;
  friend Vector& operator*(double d, const Vector& v);
  Vector& operator*=(double d);
  Vector operator/(double d) const;
  Vector& operator/=(double d);

private:
  double m_x;
  double m_y;
};

#endif
