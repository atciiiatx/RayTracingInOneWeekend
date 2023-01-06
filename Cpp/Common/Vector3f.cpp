#pragma once

#include <cmath>
#include <fstream>

#include "Vector3f.h"

Vector3f::Vector3f() : _elements({0, 0, 0}) {}

Vector3f ::Vector3f(float x, float y, float z) : _elements({x, y, z}) {}

Vector3f ::Vector3f(const Vector3f &other) {
  if (this != &other) {
    setX(other.x());
    setY(other.y());
    setZ(other.z());
  }
}

Vector3f Vector3f::one() { return Vector3f(1, 1, 1); }

Vector3f Vector3f::zero() { return Vector3f(0, 0, 0); }

float Vector3f::x() const { return _elements[0]; }

float Vector3f::y() const { return _elements[1]; }

float Vector3f::z() const { return _elements[2]; }

void Vector3f::setX(const float x) { _elements[0] = x; }

void Vector3f::setY(const float y) { _elements[1] = y; }

void Vector3f::setZ(const float z) { _elements[2] = z; }

Vector3f &Vector3f::operator+() { return *this; }

Vector3f Vector3f::operator-() { return Vector3f(-x(), -y(), -z()); }

float &Vector3f::operator[](const int index) { return _elements[index]; }

Vector3f &Vector3f::operator+=(const Vector3f &other) {
  setX(x() + other.x());
  setY(y() + other.y());
  setZ(z() + other.z());
  return *this;
}

Vector3f &Vector3f::operator-=(const Vector3f &other) {
  setX(x() - other.x());
  setY(y() - other.y());
  setZ(z() - other.z());
  return *this;
}

Vector3f Vector3f::operator*=(const Vector3f &other) {
  setX(x() * other.x());
  setY(y() * other.y());
  setZ(z() * other.z());
  return *this;
}

Vector3f &Vector3f::operator/=(const Vector3f &other) {
  setX(x() / other.x());
  setY(y() / other.y());
  setZ(z() / other.z());
  return *this;
}

Vector3f &Vector3f::operator*=(const float value) {
  setX(x() * value);
  setY(y() * value);
  setZ(z() * value);
  return *this;
}

Vector3f &Vector3f::operator/=(const float value) {
  setX(x() / value);
  setY(y() / value);
  setZ(z() / value);
  return *this;
}

float Vector3f::dot(const Vector3f &other) {
  return x() * other.x() + y() * other.y() + z() * other.z();
}

Vector3f &Vector3f::cross(const Vector3f &other) {
  Vector3f v(y() * other.z() - z() * other.y(),
              z() * other.x() - x() * other.z(),
              x() * other.y() - y() * other.x());
  return v;
}

float Vector3f::length() const { return std::sqrt(squaredLength()); }

float Vector3f::squaredLength() const {
  return x() * x() + y() * y() + z() * z();
}

void Vector3f::makeUnitVector() { *this /= length(); }

Vector3f &Vector3f::operator+(const Vector3f &other) const {
  Vector3f v(x() + other.x(), y() + other.y(), z() + other.z());
  return v;
}

Vector3f &Vector3f::operator-(const Vector3f &other) const {
  Vector3f v(x() - other.x(), y() - other.y(), z() - other.z());
  return v;
}

Vector3f &Vector3f::operator*(const Vector3f &other) const {
  Vector3f v(x() * other.x(), y() * other.y(), z() * other.z());
  return v;
}

Vector3f &Vector3f::operator/(const Vector3f &other) const {
  Vector3f v(x() / other.x(), y() / other.y(), z() / other.z());
  return v;
}

Vector3f &Vector3f::operator*(const float value) const {
  Vector3f v(x() * value, y() * value, z() * value);
  return v;
}

Vector3f &Vector3f::operator/(const float value) const {
  Vector3f v(x() / value, y() / value, z() / value);
  return v;
}

Vector3f Vector3f::unitVector(const Vector3f &v) {
  return v / v.length();
}

const Vector3f operator*(float value, const Vector3f &v) {
  Vector3f u(v.x() * value, v.y() * value, v.z() * value);
  return u;
}

std::ifstream &operator<<(std::ifstream &is, Vector3f &v) {
  float x, y, z;
  is >> x >> y >> z;
  return is;
}

std::ofstream &operator<<(std::ofstream &os, Vector3f &v) {
  os << v.x() << " " << v.y() << " " << v.z() << std::endl;
  return os;
}
