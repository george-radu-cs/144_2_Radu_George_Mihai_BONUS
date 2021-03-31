#ifndef STACk_LIST_VECTOR_H
#define STACk_LIST_VECTOR_H

#include "stack_list.h"
#include "vector.h"

class Stack_List_Vector : public Stack_List, private Vector {
private:
  int k; /* pozitia curenta in sensul lui List, 0<=k<=n
          * daca k=0 atunci pozitia se afla inainte de primul element
          * daca k=i atunci pozitia se afla la elementul i, cu i in [1,n] */

public:
  /* pozitia curenta se plaseaza inaintea primului element */
  virtual void reset() override;

  /* pozitia curenta avanseaza un element, daca se poate */
  virtual bool next() override;

  /* test daca dupa pozitia curenta nu mai sunt elemente */
  virtual bool end() override;

  /* insereaza un intreg dupa pozitia curenta, daca se poate */
  virtual bool ins_next(int value) override;

  /* elimina elementul de dupa pozitia curenta, daca exista */
  virtual bool del_next() override;

  /* furnizeaza elementul de dupa pozitia curenta(prin referinta), daca
   * exista, returnam bool  */
  virtual bool get_next(int &value) override;

  /* testeaza egal */
  bool operator==(Stack_List_Vector &slv);

  /* testeaza diferit */
  bool operator!=(Stack_List_Vector &slv);

  /* atribuire */
  Stack_List_Vector &operator=(Stack_List_Vector &slv);
};

#endif
