#include "Vector.hpp"
#include "math.h"
#include <cassert>

Vector::Vector() {
  m_x = 0;
  m_y = 0;
}

Vector::Vector(const Vector& v) {
  m_x = v.m_x;
  m_y = v.m_y;
}

Vector::Vector(double d1, double d2) {
  m_x = d1;
  m_y = d2;
}

void Vector::setX(double d) {
  m_x = d;
}

void Vector::setY(double d) {
  m_y = d;
}

double Vector::getX() {
  return m_x;
}

double Vector::getY() {
  return m_y;
}

ostream& operator<<(ostream& os, const Vector& v1) {
  os << v1.m_x << " " << v1.m_y;
  return os;
}

double& Vector::operator[](const int i) {
  assert(i >= 0 && i < 2);
  if (i == 0) {
    return m_x;
  } else if (i == 1) {
    return m_y;
  }
}

Vector& Vector::operator=(const Vector& v1) {
  m_x = v1.m_x;
  m_y = v1.m_y;

  return *this;
}

bool Vector::operator==(const Vector& v1) {
  return abs(m_x - v1.m_x) < 0.01
      && abs(m_y - v1.m_y) < 0.01;
}

bool Vector::operator!=(const Vector& v1) {
  return abs(m_x - v1.m_x) >= 0.01
      || abs(m_y - v1.m_y) >= 0.01;
}

Vector& Vector::operator-() {
  Vector * result = new Vector(-m_x, -m_y);
  return *result;
}

Vector& Vector::operator+(const Vector& v1) {
  Vector * result = new Vector(m_x + v1.m_x, m_y + v1.m_y);
  return * result;
}

Vector& Vector::operator+=(const Vector& v1) {
  m_x += v1.m_x;
  m_y += v1.m_y;
  return *this;
}

Vector& Vector::operator-(const Vector& v1) {
  Vector * result = new Vector(m_x - v1.m_x, m_y - v1.m_y);
  return * result;
}

Vector& Vector::operator-=(const Vector& v1) {
  m_x -= v1.m_x;
  m_y -= v1.m_y;
  return *this;
}

Vector& Vector::operator*(double d) {
  Vector * result = new Vector(m_x * d, m_y * d);
  return * result;
}

Vector& operator*(double d, const Vector& v) {
  Vector * result = new Vector(v.m_x * d, v.m_y * d);
  return * result;
}

Vector& Vector::operator*=(double d) {
  m_x *= d;
  m_y *= d;
  return *this;
}

Vector& Vector::operator/(double d) {
  assert(d != 0);
  Vector * result = new Vector(m_x / d, m_y / d);
  return * result;
}

Vector& Vector::operator/=(double d) {
  assert(d != 0);
  m_x /= d;
  m_y /= d;
  return *this;
}