#ifndef LIST_H
#define LIST_H

class List {
public:
  List();

  virtual ~List();

  ////////////////////
  /* metode publice */
  ////////////////////

  /* videaza lista curenta */
  void operator-() const;

  /* testeaza egal */
  bool operator==(const List&list) const;

  /* testeaza diferit */
  bool operator!=(const List&list) const;

  /* atribuire */
  List &operator=(const List&list);

  /////////////////////////
  /* metode publice pure */
  /////////////////////////
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
