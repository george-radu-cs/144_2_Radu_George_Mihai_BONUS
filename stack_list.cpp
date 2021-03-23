#include "stack_list.h"

Stack_List::~Stack_List() {}

Stack &Stack_List::operator<<(int value) const {
  return (Stack &) *this;
}

Stack &Stack_List::operator>>(int &value) const {
  return (Stack &) *this;
}

bool Stack_List::operator!() const {
  return true;
}
