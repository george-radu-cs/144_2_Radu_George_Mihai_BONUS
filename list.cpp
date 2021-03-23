#include "list.h"

List::List() {}

List::~List() {}

void List::operator-() const {

}

bool List::operator==(const List &list) const {
  return true;
}

bool List::operator!=(const List &list) const {
  return true;
}

List &List::operator=(const List &list) {
  return const_cast<List &>(list);
}