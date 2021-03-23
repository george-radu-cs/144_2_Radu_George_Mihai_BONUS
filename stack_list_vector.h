#ifndef STACk_LIST_VECTOR_H
#define STACk_LIST_VECTOR_H

#include "stack_list.h"
#include "vector.h"

class Stack_List_Vector : public Stack_List, private Vector {
private:
  int k; /* pozitia curenta in sensul lui List */

public:
  ////////////////////////////////////////////////////////
  /* implementam metodele pure mostenite din Stack_List */
  ////////////////////////////////////////////////////////

  /* pozitia curenta nu se plaseaza inaintea primului element */
  virtual void reset() const override;

  /* pozitia curenta avanseaza un element, daca se poate */
  virtual bool next() const override;

  /* test daca dupa pozitia curenta nu mai sunt elemente */
  virtual bool end() const override;

  /* insereaza un intreg dupa pozitia curenta, daca se poate */
  virtual bool ins_next(int value) const override;

  /* elimina elementul de dupa pozitia curenta, daca exista */
  virtual bool del_next() const override;

  /* furnizeaza elementul de dupa pozitia curenta(prin referinta), daca
   * exista, returnam bool  */
  virtual bool get_next(int &value) const override;

  /////////////////////////////////////////////////////////
  /* redefinim operatorii prezenti si in clasele de baza */
  /////////////////////////////////////////////////////////

  /* testeaza egal */
  bool operator==(const Stack_List_Vector&slv) const;

  /* testeaza diferit */
  bool operator!=(const Stack_List_Vector&slv) const;

  /* atribuire */
  Stack_List_Vector &operator=(const Stack_List_Vector&slv);
};

#endif