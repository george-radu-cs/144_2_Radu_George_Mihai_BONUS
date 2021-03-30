#ifndef LIST_H
#define LIST_H

class List {
private:
  int *current_position;

public:
  List();

  virtual ~List();

  ////////////////////
  /* metode publice */
  ////////////////////

  /* videaza lista curenta */
  void operator-();

  /* testeaza egal */
  bool operator==(List &list);

  /* testeaza diferit */
  bool operator!=(List &list);

  /* atribuire */
  List &operator=(List &list);

  /////////////////////////
  /* metode publice pure */
  /////////////////////////
  /* pozitia curenta se plaseaza inaintea primului element */
  virtual void reset() = 0;

  /* pozitia curenta avanseaza un element, daca se poate */
  virtual bool next() = 0;

  /* test daca dupa pozitia curenta nu mai sunt elemente */
  virtual bool end() = 0;

  /* insereaza un intreg dupa pozitia curenta, daca se poate */
  virtual bool ins_next(int value) = 0;

  /* elimina elementul de dupa pozitia curenta, daca exista */
  virtual bool del_next() = 0;

  /* furnizeaza elementul de dupa pozitia curenta(prin referinta), daca
   * exista, returnam bool  */
  virtual bool get_next(int &value) = 0;
};

#endif
