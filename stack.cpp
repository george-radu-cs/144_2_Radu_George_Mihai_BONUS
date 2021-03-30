#include "stack.h"

Stack::~Stack() {}

void Stack::operator-() {
  int x; /* vom retine elementele din stack de la pop */
  while (!(*this)) {
    (*this) >> x;
  }
}

bool Stack::operator==(Stack &stack) {
  int v1, v2; /* vom retine valorile din cele doua stackuri */

  /* cat timp ambele stackuri sunt vide */
  while (!(*this) && !stack) {
    /* facem cate un pop in ambele colectii */
    (*this) >> v1;
    stack >> v2;
    if (v1 != v2) { /* daca cele 2 elemente nu sunt egale */
      return false;
    }
  }

  /* daca am terminat de verificat stackurile element cu element si am vidat cel
   * putin una, atunci verificam ca ambele sa fie goale ca ultim test de
   * egalitate */
  return !(*this) == !stack;
}

bool Stack::operator!=(Stack &stack) { return !((*this) == stack); }

Stack &Stack::operator=(Stack &stack) {
  -(*this); /* vidam colectia curenta */

  int x; /* vom retinele elementele din stack pe care trebuie sa le copiem */
  while (!stack) { /* cat timp mai sunt elemente in stack */
    stack >> x;    /* dam pop la stack si salvam in x */
    (*this) << x;  /* dam push la x in stakul this */
  }

  return *this;
}

///////////////////////////////////////
/* functiile independente ne-prieten */
///////////////////////////////////////

std::istream &operator>>(std::istream &in, Stack &stack) {
  int n; /* cate nr vom adauga la stack */
  in >> n;
  int x; /* vom retine in x ce elemente vom adauga la fiecare iteratie */
  while (n > 0) {
    in >> x;    /* citim intregul */
    stack << x; /* facem push in stack */
    n--;
  }

  return in;
}

std::ostream &operator<<(std::ostream &out, Stack &stack) {
  if (!stack) { /* daca stack ul nu este vid ii afisam elementele */
    out << "\nAfisare stack:\n";
    int x; /* vom retine in x elementele lui stack */
    while (!stack) {
      stack >> x;
      out << x << " ";
    }
  } else {
    out << "\nStackul este gol!\n";
  }

  return out;
}
