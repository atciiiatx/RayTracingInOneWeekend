#pragma once

#include <array>
#include <cmath>
#include <fstream>
#include <type_traits>

class Vector3D {
 public:
  enum class Coordinate { X, Y, Z };
  Vector3D() : _elements({0, 0, 0}) {}
  Vector3D(float x, float y, float z) : _elements({x, y, z}) {}
  Vector3D(const Vector3D &other) {
    if (this != &other) {
      setX(other.x());
      setY(other.y());
      setZ(other.z());
    }
  }

  Vector3D one() { return Vector3D(1, 1, 1); }
  Vector3D zero() { return Vector3D(0, 0, 0); }

  float x() const { return _elements[0]; }
  float y() const { return _elements[1]; }
  float z() const { return _elements[2]; }
  void setX(const float x) { _elements[0] = x; }
  void setY(const float y) { _elements[1] = y; }
  void setZ(const float z) { _elements[2] = z; }

  Vector3D &operator+() { return *this; }
  Vector3D operator-() { return Vector3D(-x(), -y(), -z()); }
  float &operator[](const int index) { return _elements[index]; }

  Vector3D &operator+=(const Vector3D &other) {
    setX(x() + other.x());
    setY(y() + other.y());
    setZ(z() + other.z());
    return *this;
  }

  Vector3D &operator-=(const Vector3D &other) {
    setX(x() - other.x());
    setY(y() - other.y());
    setZ(z() - other.z());
    return *this;
  }

  Vector3D operator*=(const Vector3D &other) {
    setX(x() * other.x());
    setY(y() * other.y());
    setZ(z() * other.z());
    return *this;
  }
  Vector3D &operator/=(const Vector3D &other) {
    setX(x() / other.x());
    setY(y() / other.y());
    setZ(z() / other.z());
    return *this;
  }
  Vector3D &operator*=(const float value) {
    setX(x() * value);
    setY(y() * value);
    setZ(z() * value);
    return *this;
  }

  Vector3D &operator/=(const float value) {
    setX(x() / value);
    setY(y() / value);
    setZ(z() / value);
    return *this;
  }

  float dot(const Vector3D &other) {
    return x() * other.x() + y() * other.y() + z() * other.z();
  }

  Vector3D &cross(const Vector3D &other) {
    Vector3D v(y() * other.z() - z() * other.y(),
               z() * other.x() - x() * other.z(),
               x() * other.y() - y() * other.x());
    return v;
  }

  float length() const { return std::sqrt(squaredLength()); }

  float squaredLength() const { return x() * x() + y() * y() + z() * z(); }

  void makeUnitVector() { *this /= length(); }

  Vector3D &operator+(const Vector3D &other) const {
    Vector3D v(x() + other.x(), y() + other.y(), z() + other.z());
    return v;
  }

  Vector3D &operator-(const Vector3D &other) const {
    Vector3D v(x() - other.x(), y() - other.y(), z() - other.z());
    return v;
  }

  Vector3D &operator*(const Vector3D &other) const {
    Vector3D v(x() * other.x(), y() * other.y(), z() * other.z());
    return v;
  }

  Vector3D &operator/(const Vector3D &other) const {
    Vector3D v(x() / other.x(), y() / other.y(), z() / other.z());
    return v;
  }

  Vector3D &operator*(const float value) const {
    Vector3D v(x() * value, y() * value, z() * value);
    return v;
  }

  Vector3D &operator/(const float value) const {
    Vector3D v(x() / value, y() / value, z() / value);
    return v;
  }

  static Vector3D unitVector(const Vector3D &v) { return v / v.length(); }

 protected:
  std::array<float, 3> _elements;
};

const Vector3D operator*(float value, const Vector3D &v) {
  Vector3D u(v.x() * value, v.y() * value, v.z() * value);
  return u;
}

std::ifstream &operator<<(std::ifstream &is, Vector3D &v) {
  float x, y, z;
  is >> x >> y >> z;
  return is;
}

std::ofstream &operator<<(std::ofstream &os, Vector3D &v) {
  os << v.x() << " " << v.y() << " " << v.z() << std::endl;
  return os;
}
