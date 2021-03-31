#include "stack_list.h"

Stack_List::~Stack_List() {}

Stack &Stack_List::operator<<(int value) {
  /* setam pozitia curenta la finalul colectiei de elemente */
  reset();
  while (next())
    ;

  ins_next(value); /* inseram elementul la final */

  return (Stack &)(*this);
}

Stack &Stack_List::operator>>(int &value) {
  /* setam pozitia curenta la penultimul element din colectie */
  reset();
  int x{0};
  while (next()) {
    x++;
  }
  reset();
  while (x != 1) {
    x--;
    next();
  }
  get_next(value); /* scoatem ultimul element din colectie */
  del_next();

  return (Stack &)(*this);
}

bool Stack_List::operator!() {
  /* resetam pozitia curenta in colectie */
  reset();
  if (next()) {   /* daca putem seta pozitia curenta la primul element */
    return false; /* atunci e evident ca lista nu este vida */
  } else {        /* daca nu atunci lista este vida */
    return true;
  }
}
