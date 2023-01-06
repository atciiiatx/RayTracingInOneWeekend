#include "Color3f.h"
#include "Color3i.h"

Color3i::Color3i() : _elements({0, 0, 0}) {}

Color3i::Color3i(const int r, const int g, const int b) {
  setR(r);
  setG(g);
  setB(b);
}

Color3i::Color3i(const Color3i &other) {
  if (this != &other) {
    setR(other.r());
    setG(other.g());
    setB(other.b());
  }
}

Color3i::Color3i(const Color3f &color) {
  setR(255.99 * color.r());
  setG(255.99 * color.g());
  setB(255.99 * color.b());
}

int Color3i::r() const { return _elements[0]; }

int Color3i::g() const { return _elements[1]; }

int Color3i::b() const { return _elements[2]; }

void Color3i::setR(const int r) { _elements[0] = r; }

void Color3i::setG(const int g) { _elements[1] = g; }

void Color3i::setB(const int b) { _elements[2] = b; }
