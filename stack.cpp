#include "stack.h"

void Stack::operator-() {
  int x;                      /* vom retine elementele din stack de la pop */
  while (!(*this) == false) { /* cat timp lista mai are elemente */
    (*this) >> x;             /* dam pop la element */
  }
}

bool Stack::operator==(Stack &stack) {
  int v1, v2; /* vom retine valorile din cele doua stackuri */

  /* backup pentru cele doua stackuri */
  int *ls1, *ls2, n{0};
  ls1 = new int[n];
  ls2 = new int[n];

  bool elem_egale{true};
  /* cat timp ambele stackuri sunt vide */
  while (!(*this) == false && !stack == false) {
    /* facem cate un pop in ambele colectii */
    (*this) >> v1;
    stack >> v2;

    /* salvam elementele */
    n++;
    ls1[n - 1] = v1;
    ls2[n - 1] = v2;

    if (v1 != v2) { /* daca cele 2 elemente nu sunt egale */
      elem_egale = false;
    }
  }

  /* refacem cele doua stive */
  for (int i = n - 1; i >= 0; i--) {
    (*this) << ls1[i];
    stack << ls2[i];
  }

  if (!elem_egale) {
    return false;
  } else {
    /* daca am terminat de verificat stackurile element cu element si am vidat
     * cel putin una, atunci verificam ca ambele sa fie goale ca ultim test de
     * egalitate */
    return !(*this) == !stack;
  }
}

bool Stack::operator!=(Stack &stack) { return !((*this) == stack); }

Stack &Stack::operator=(Stack &stack) {
  if (this != &stack) { /* nu mai facem atribuirea daca elementul in care vom
                          salva datele este acelasi din care le luam */
    -(*this);          /* vidam colectia curenta */

    int x; /* vom retinele elementele din stack la care dam pop */
    int n{0};
    int *temp = new int[n]; /* vom retine elementele din stack pentru copiere,
                               restaurare */
    while (!stack) {        /* cat timp mai sunt elemente in stack */
      stack >> x;           /* dam pop la stack si salvam in x */
      n++;
      temp[n - 1] = x;
    }

    for (int i = n - 1; i >= 0; i--) {
      (*this) << temp[i]; /* dam push la x in stackul this */
      stack << temp[i];   /* restauram stack */
    }
  }

  return *this;
}

std::istream &operator>>(std::istream &in, Stack &stack) {
  int n; /* cate nr vom adauga la stack */
  std::cout << "Nr elemente: ";
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
  if (!stack) {
    out << "\nStackul este gol!\n";
  } else {
    int x; /* vom retine in x elementele lui stack */

    /* retinem elementele din stack intr-un vector alocat dinamic */
    int n = 0;
    int *temp = new int[n];

    while (!stack == false) { /* cat timp stackul nu este gol */
      /* facem pop la elemente si le afisam */
      stack >> x;
      out << x << " ";

      /* salvam elementul */
      n++;
      temp[n - 1] = x;
    }
    out << '\n';

    for (int i = n - 1; i >= 0; i--) { /* restauram stackul */
      stack << temp[i];
    }
  }

  return out;
}
