
#include "Color3f.h"
#include "Color3i.h"

Color3f::Color3f():  Vector3f() {}

Color3f::Color3f(const float r, const float g, const float b)
    : Vector3f(r, g, b) {}

Color3f::Color3f(const Color3f &other) : Vector3f(other) {}

Color3f::Color3f(const Color3i &color) { 
  setR(color.r() / 255.0);
  setG(color.g() / 255.0);
  setB(color.b() / 255.0);
}

float Color3f::r() const { return x(); }

float Color3f::g() const { return y(); }

float Color3f::b() const { return z(); }

void Color3f::setR(const float r) { setX(r); }

void Color3f::setG(const float g) { setY(g); }

void Color3f::setB(const float b) { setZ(b); }

