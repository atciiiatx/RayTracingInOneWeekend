#pragma once

#include <array>

class Color3f;

class Color3i {
 public:
  Color3i();
  Color3i(const int r, const int g, const int b);
  Color3i(const Color3i &other);
  Color3i(const Color3f &other);

  int r() const;
  int g() const;
  int b() const;
  void setR(const int r);
  void setG(const int g);
  void setB(const int b);

 protected:
  std::array<int, 3> _elements;
};
