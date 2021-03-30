#include "stack_list_vector.h"

void Stack_List_Vector::reset() {
  /* in vector pozitia 0 reprezinta pozitia de dinainte de primul element, fie
   * ca colectia este vida sau nu */
  k = 0;
}

bool Stack_List_Vector::next() {
  if (k < length()) { /* putem avansa pozitia curenta doar daca aceasta nu este
                         pozitia ultimului element */
    k++;
    return true;
  }

  return false;
}

bool Stack_List_Vector::end() {
  /* daca pozitia curenta este la ultimul element, atunci nu mai exista alte
   * elemente dupa */
  if (k == length()) {
    return false;
  } else {
    return true;
  }
}

bool Stack_List_Vector::ins_next(int value) {
  if (truncate(length() + 1)) { /* incercam sa dam resize */
    /* mutam valorile de la final cu o pozitie in fata */
    for (int i = length() + 1; i > k + 1; i--) {
      (*this)[i] = (*this)[i - 1];
    }
    (*this)[k + 1] = value; /* inseram valoarea dupa pozitia curenta */

    return true; /* daca am inserat cu succes */
  } else {
    return false;
  }
}

bool Stack_List_Vector::del_next() {
  if (k != length()) { /* pozitia lui k trebuie sa fie mai mica decat n,
               intrucat stergem urmatorul element dupa pozitia k, i.e. k+1 */
    /* pentru a sterge un element dintr-un vector va trebui sa il suprascriem */
    for (int i = k + 1; i < length(); i++) {
      (*this)[i] = (*this)[i + 1];
    }

    /* dupa trebuie sa stergem ultimul element din colectie */
    if (this->truncate(length() - 1)) {
      return true;
    } else {
      return false;
    }
  }

  return false;
}

bool Stack_List_Vector::get_next(int &value) {
  if (k < length()) {       /* daca exista un element dupa pozitia curenta */
    value = (*this)[k + 1]; /* il vom returna prin referinta */
    return true; /* si intoarcem true deoare am reusit sa trimitem elementul
                    prin referinta */
  } else { /* daca nu am putut intoarce prin referinta elementul vom intoarce
              false */
    return false;
  }
}

bool Stack_List_Vector::operator==(Stack_List_Vector &slv) {
  int v1, v2; /* vom retine valorile din cele doua stackuri */

  /* cat timp ambele stackuri sunt vide */
  while (!(*this) && !slv) {
    /* facem cate un pop in ambele colectii */
    (*this) >> v1;
    slv >> v2;
    if (v1 != v2) { /* daca cele 2 elemente nu sunt egale */
      return false;
    }
  }

  /* daca am terminat de verificat stackurile element cu element si am vidat cel
   * putin una, atunci verificam ca ambele sa fie goale ca ultim test de
   * egalitate */
  return !(*this) == !slv;
}

bool Stack_List_Vector::operator!=(Stack_List_Vector &slv) {
  return !((*this) == slv);
}

Stack_List_Vector &Stack_List_Vector::operator=(Stack_List_Vector &slv) {
  Stack::operator-(); /* vidam colectia curenta */

  int x; /* vom retinele elementele din stack pe care trebuie sa le copiem */
  while (!slv) {  /* cat timp mai sunt elemente in stack */
    slv >> x;     /* dam pop la stack si salvam in x */
    (*this) << x; /* dam push la x in stakul this */
  }

  return *this;
}
