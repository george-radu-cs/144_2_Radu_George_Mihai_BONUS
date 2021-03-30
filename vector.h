#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
  int *buf; /* adresa zonei cu elementele, alocata dinamic, inexararea
               elementelor se face de la 1 */
  int n;    /* nr de elemente */

public:
  /* initializam vectorul vid */
  Vector();

  /* constructor de conversie, i.e. creeaza un vector cu un intreg */
  Vector(int x);

  /* constructor de copiere */
  Vector(Vector &vector);

  /* destructorul elibereaza resursele vectorului */
  ~Vector();

  /* operator de indexare, returneaza referinta la int de la poz index, daca
   * index >= n realocam zona cu elementele */
  int &operator[](int index);

  /* operator de atribuire */
  Vector &operator=(Vector &vector);

  /* realoca/truncheaza vectorul la dimensiunea data ca parametru si
   * returneaza true/false in functie de succes/esec */
  bool truncate(int size);

  /* returnam lungimea vectorului, i.e. n */
  int length() { return n; };
};

#endif
