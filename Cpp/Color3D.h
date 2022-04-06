#pragma once

#include "Vector3D.h"

class Color3D : Vector3D {
public:
  enum class ColorComponent { Red, Green, Blue };
  Color3D() : Vector3D() {}
  Color3D(const float r, const float g, const float b) : Vector3D(r, g, b) {}
  Color3D(const Color3D &other) : Vector3D(other) {}
  float r() const { return x(); }
  float g() const { return y(); }
  float b() const { return z(); }
  void setR(const float r) { setX(r); }
  void setG(const float g) { setY(g); }
  void setB(const float b) { setZ(b); }
};
