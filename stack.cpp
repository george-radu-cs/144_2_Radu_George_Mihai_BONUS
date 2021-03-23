#include "stack.h"

Stack::Stack() {}

Stack::~Stack() {

}

///////////////////////////////////////
/* functiile independente ne-prieten */
///////////////////////////////////////

std::istream &operator>>(std::istream &in, Stack &stack) {
  return in;
}

std::ostream &operator<<(std::ostream &out, const Stack &stack) {
  return out;
}

void Stack::operator-() const {

}

bool Stack::operator==(const Stack &stack) const {
  return true;
}

bool Stack::operator!=(const Stack &stack) const {

  return true;
}

Stack &Stack::operator=(const Stack &stack) {
  return *this;
}