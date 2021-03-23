#include "vector.h"

Vector::Vector() {}

Vector::Vector(int x) {}

Vector::~Vector() {}

int &Vector::operator[](int index) {
  int *i = nullptr;
  return *i;
}

Vector &Vector::operator=(const Vector &vector) {
  return *this;
}

bool Vector::truncate(int size) const {
  return true;
}