#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
public:
  virtual ~Stack();

  ////////////////////
  /* metode publice */
  ////////////////////

  /* videaza stiva curenta */
  void operator-();

  /* verificam daca stiva this este egala cu stiva stack */
  bool operator==(Stack &stack);

  /* verificam daca stiva this nu este egala cu stiva stack */
  bool operator!=(Stack &stack);

  /* overload operator de atribuire */
  Stack &operator=(Stack &stack);

  /////////////////////////
  /* metode pure publice */
  /////////////////////////

  /* facem push la un intreg, valoarea o trimitem prin valoare, returnam
   * referinta la stiva curenta pentru a permite push mutiple */
  virtual Stack &operator<<(int value) = 0;

  /* facem pop la un intreg, valoarea o trimitem prin referinta, returnam
   * referinta la stiva curenta pentru a permite pop mutiple */
  virtual Stack &operator>>(int &value) = 0;

  /* testam daca stiva este vida */
  virtual bool operator!() = 0;
};

#endif
