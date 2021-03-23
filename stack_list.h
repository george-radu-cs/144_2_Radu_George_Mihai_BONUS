#ifndef STACK_LIST_H
#define STACK_LIST_H

#include "stack.h"
#include "list.h"

class Stack_List : public Stack, private List{
public:
  virtual ~Stack_List();

  virtual Stack &operator<<(int value) const override;

  virtual Stack &operator>>(int &value) const override;

  virtual bool operator!() const override;

  ////////////////////////////////////
  /* meintem pure metodele lui list */
  ////////////////////////////////////

  /* pozitia curenta nu se plaseaza inaintea primului element */
  virtual void reset() const = 0;

  /* pozitia curenta avanseaza un element, daca se poate */
  virtual bool next() const = 0;

  /* test daca dupa pozitia curenta nu mai sunt elemente */
  virtual bool end() const = 0;

  /* insereaza un intreg dupa pozitia curenta, daca se poate */
  virtual bool ins_next(int value) const = 0;

  /* elimina elementul de dupa pozitia curenta, daca exista */
  virtual bool del_next() const = 0;

  /* furnizeaza elementul de dupa pozitia curenta(prin referinta), daca
   * exista, returnam bool  */
  virtual bool get_next(int &value) const = 0;
};

#endif