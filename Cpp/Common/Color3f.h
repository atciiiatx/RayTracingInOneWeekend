#pragma once

#include "Vector3f.h"

class Color3i;

class Color3f : Vector3f {
 public:
  Color3f();
  Color3f(const float r, const float g, const float b);
  Color3f(const Color3f &other);
  Color3f(const Color3i &color);

  float r() const;
  float g() const;
  float b() const;
  void setR(const float r);
  void setG(const float g);
  void setB(const float b);
};
