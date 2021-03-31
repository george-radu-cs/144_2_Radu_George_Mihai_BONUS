#ifndef STACK_LIST_H
#define STACK_LIST_H

#include "list.h"
#include "stack.h"

class Stack_List : public Stack, private List {
public:
  virtual ~Stack_List();

  /* facem push la un intreg, valoarea o trimitem prin valoare, returnam
   * referinta la stiva curenta pentru a permite push mutiple */
  virtual Stack &operator<<(int value) override;

  /* facem pop la un intreg, valoarea o trimitem prin referinta, returnam
   * referinta la stiva curenta pentru a permite pop mutiple */
  virtual Stack &operator>>(int &value) override;

  /* testam daca stiva este vida */
  virtual bool operator!() override;

  /* pozitia curenta se plaseaza inaintea primului element */
  virtual void reset() override = 0;

  /* pozitia curenta avanseaza un element, daca se poate */
  virtual bool next() override = 0;

  /* test daca dupa pozitia curenta nu mai sunt elemente */
  virtual bool end() override = 0;

  /* insereaza un intreg dupa pozitia curenta, daca se poate */
  virtual bool ins_next(int value) override = 0;

  /* elimina elementul de dupa pozitia curenta, daca exista */
  virtual bool del_next() override = 0;

  /* furnizeaza elementul de dupa pozitia curenta(prin referinta), daca
   * exista, returnam bool  */
  virtual bool get_next(int &value) override = 0;
};

#endif
