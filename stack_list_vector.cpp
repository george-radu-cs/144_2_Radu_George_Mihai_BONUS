#include "stack_list_vector.h"

void Stack_List_Vector::reset() const {}

bool Stack_List_Vector::next() const {
  return true;
}

bool Stack_List_Vector::end() const {
  return true;
}

bool Stack_List_Vector::ins_next(int value) const {
  return true;
}

bool Stack_List_Vector::del_next() const {
  return true;
}

bool Stack_List_Vector::get_next(int &value) const {
  return true;
}

bool Stack_List_Vector::operator==(const Stack_List_Vector &slv) const {

  return true;
}

bool Stack_List_Vector::operator!=(const Stack_List_Vector &slv) const {
  return true;
}

Stack_List_Vector &Stack_List_Vector::operator=(const
                                                Stack_List_Vector &slv) {
  return *this;
}
