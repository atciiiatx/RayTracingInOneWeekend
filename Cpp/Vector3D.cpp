#include "Vector3D.h"

Vector3D::Vector3D(): _elements({0,0,0}){}

Vector3D::Vector3D(float x, float y, float z): _elements({r, g, b}) {}
Vector3D::Vector3D(const Vector3D &other){}
float Vector3D::x() const{}
float Vector3D::y() const{}
float Vector3D::z() const{}
void Vector3D::setX(const float x){}
void Vector3D::setY(const float y){}
void Vector3D::setZ(const float z){}

Vector3D &Vector3D::operator+(){}
Vector3D Vector3D::operator-(){}
float &Vector3D::operator[](const int index){}

Vector3D &Vector3D::operator+=(const Vector3D &v2){}
Vector3D &Vector3D::operator-=(const Vector3D &v2){}
Vector3D &Vector3D::operator*=(const Vector3D &v2){}
Vector3D &Vector3D::operator+=(const Vector3D &v2){}
Vector3D &Vector3D::operator+=(const float t){}
Vector3D &Vector3D::operator+=(const float t){}

float Vector3D::length() const{}
float Vector3D::squaredLength() const{}
void Vector3D::makeUnitVector(){}
