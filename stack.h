#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
public:
  Stack();

  virtual ~Stack();

  ////////////////////
  /* metode publice */
  ////////////////////

  /* videaza stiva curenta */
  void operator-() const;

  /* verificam daca stiva this este egala cu stiva stack */
  bool operator==(const Stack &stack) const;

  /* verificam daca stiva this nu este egala cu stiva stack */
  bool operator!=(const Stack &stack) const;

  /* overload operator de atribuire */
  Stack &operator=(const Stack &stack);

  /////////////////////////
  /* metode pure publice */
  /////////////////////////

  /* facem push la un intreg, valoarea o trimitem prin valoare, returnam
   * referinta la stiva curenta pentru a permite push mutiple */
  virtual Stack &operator<<(int value) const = 0;

  /* facem pop la un intreg, valoarea o trimitem prin referinta, returnam
   * referinta la stiva curenta pentru a permite pop mutiple */
  virtual Stack &operator>>(int &value) const = 0;

  /* testam daca stiva este vida */
  virtual bool operator!() const = 0;
};

#endif