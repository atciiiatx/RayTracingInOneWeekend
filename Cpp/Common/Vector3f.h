#pragma once

#include <array>
#include <fstream>

class Vector3f {
 public:
  Vector3f();
  Vector3f(float x, float y, float z);
  Vector3f(const Vector3f &other);

  Vector3f one();
  Vector3f zero();

  float x() const;
  float y() const;
  float z() const;
  void setX(const float x);
  void setY(const float y);
  void setZ(const float z);

  Vector3f &operator+();
  Vector3f operator-();
  float &operator[](const int index);

  Vector3f &operator+=(const Vector3f &other);

  Vector3f &operator-=(const Vector3f &other);

  Vector3f operator*=(const Vector3f &other);

  Vector3f &operator/=(const Vector3f &other);

  Vector3f &operator*=(const float value);

  Vector3f &operator/=(const float value);

  float dot(const Vector3f &other);

  Vector3f &cross(const Vector3f &other);

  float length() const;

  float squaredLength() const;

  void makeUnitVector();

  Vector3f &operator+(const Vector3f &other) const;

  Vector3f &operator-(const Vector3f &other) const;

  Vector3f &operator*(const Vector3f &other) const;

  Vector3f &operator/(const Vector3f &other) const;

  Vector3f &operator*(const float value) const;

  Vector3f &operator/(const float value) const;

  static Vector3f unitVector(const Vector3f &v);

 protected:
  std::array<float, 3> _elements;
};

const Vector3f operator*(float value, const Vector3f &v);

std::ifstream &operator<<(std::ifstream &is, Vector3f &v);

std::ofstream &operator<<(std::ofstream &os, Vector3f &v);
