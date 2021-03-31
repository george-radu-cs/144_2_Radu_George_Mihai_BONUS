#include "list.h"

void List::operator-() {
  /* reseteam pozitia curenta a listei */
  this->reset();
  while (!this->end()) {
    this->del_next();
  }
}

bool List::operator==(List &list) {
  /* resetam pozitia curenta a celor 2 liste */
  this->reset();
  list.reset();

  int v1, v2; /* vom retine valorile din cele doua liste */

  /* cat timp in ambele liste mai sunt elemente */
  while (!this->end() && !list.end()) {
    /* cat timp ambele liste mai au elemente */
    if (this->get_next(v1) && list.get_next(v2)) {
      if (v1 != v2) { /* daca cele 2 elemente nu sunt egale */
        return false;
      }

      /* avansam cu cele 2 liste */
      this->next();
      list.next();
    }
  }

  /* daca am terminat de verificat element cu element listele si am parcurs cel
   * putin una din ele pana la final comparand o cu cealalta si am descoperit ca
   * sunt egale, atunci vom testa daca ambele liste s au terminat
   * OBS: Cu aceasta metoda acoperim si cazurile in care una din liste era deja
   * goala, ambele erau goale, una din ele se termina mai repede, sau ambele se
   * termina de parcurs in acelasi timp */
  return this->next() == list.next();
}

bool List::operator!=(List &list) { return !(*this == list); }

List &List::operator=(List &list) {
  /* resetam pozitia curenta a celor 2 liste */
  this->reset();
  list.reset();

  /* cat timp list mai are elemente (din ea vrem sa copiem) */
  while (!list.end()) {
    int v; /* vom retine elementele din list la fiecare iteratie */
    if (list.get_next(v)) { /* luam urmatorul element din list */
      /* inlocuim in this elementul prin stergerea vechiului element si
       * inserarea altuia */
      this->del_next();
      this->ins_next(v);
    } else {
      break;
    }

    /* avansam cu cele 2 liste */
    this->next();
    list.next();
  }

  /* stergem posibilele elemente din lista this care au ramas din lista anterior
   * existenta */
  while (!this->end()) {
    this->del_next();
  }

  return *this;
}
