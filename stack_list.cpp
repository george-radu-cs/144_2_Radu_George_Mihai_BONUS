#include "stack_list.h"

Stack_List::~Stack_List() {}

Stack &Stack_List::operator<<(int value) {
  /* setam pozitia curenta la finalul colectiei de elemente */
  while (next())
    ;

  ins_next(value); /* inseram elementul la final */

  return (Stack &)*this;
}

Stack &Stack_List::operator>>(int &value) {
  /* setam pozitia curenta la penultimul element din colectie */
  /* TODO */

  get_next(value); /* scoatem ultimul element din colectie */

  return (Stack &)*this;
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
