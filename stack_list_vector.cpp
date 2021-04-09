#include "stack_list_vector.h"

Stack_List_Vector::Stack_List_Vector() : Stack_List(), Vector() {}

Stack_List_Vector::Stack_List_Vector(int x) : Stack_List(), Vector(x) {}

Stack_List_Vector::Stack_List_Vector(const Stack_List_Vector &slv)
    : Stack_List(), Vector(slv) {}

Stack_List_Vector::~Stack_List_Vector() {}

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
    if (-CAPAT_INTERVAL <= value && value <= CAPAT_INTERVAL) {
      (*this)[k + 1] = value; /* inseram valoarea dupa pozitia curenta */
    } else {
      std::cout << value << " nu se afla in intervalul [" << -CAPAT_INTERVAL
                << "," << CAPAT_INTERVAL << "], vom inlocui cu 0.\n";
      (*this)[k + 1] = 0; /* inseram valoarea dupa pozitia curenta */
    }

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

  /* backup pentru cele doua stackuri */
  int *ls1, *ls2, n{0};
  ls1 = new int[n];
  ls2 = new int[n];

  bool elem_egale{true};
  /* cat timp ambele stackuri sunt vide */
  while (!(*this) == false && !slv == false) {
    /* facem cate un pop in ambele colectii */
    (*this) >> v1;
    slv >> v2;

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
    slv << ls2[i];
  }

  if (!elem_egale) {
    return false;
  } else {
    /* daca am terminat de verificat stackurile element cu element si am vidat
     * cel putin una, atunci verificam ca ambele sa fie goale ca ultim test de
     * egalitate */
    return !(*this) == !slv;
  }
}

bool Stack_List_Vector::operator!=(Stack_List_Vector &slv) {
  return !((*this) == slv);
}

Stack_List_Vector &Stack_List_Vector::operator=(Stack_List_Vector &slv) {
  if (this != &slv) {   /* nu mai facem atribuirea daca elementul in care vom
                           salva datele este acelasi din care le luam */
    Stack::operator-(); /* vidam colectia curenta */

    int x; /* vom retinele elementele din stack la care dam pop */
    int n{0};
    int *temp = new int[n]; /* vom retine elementele din stack pentru copiere,
                               restaurare */
    while (!slv == false) { /* cat timp mai sunt elemente in stack */
      slv >> x;             /* dam pop la stack si salvam in x */
      n++;
      temp[n - 1] = x;
    }
    for (int i = n - 1; i >= 0; i--) {
      (*this) << temp[i]; /* dam push la x in stackul this */
      slv << temp[i];     /* restauram stack */
    }
  }

  return *this;
}
