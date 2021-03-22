# Proiect 2 POO

Nume: Radu

Prenume: George-Mihai

Grupa: 144

## Subiecte pentru proiectul 2

Scrieti un program care contine urmatoarele:

- clasa abstracta 'stack', care descrie conceptul de stiva de intregi, avand:
  metode pure publice:
    operatorii '<<' (push), '>>' (pop), '!' (test stiva vida);
    detalii: '<<', resp. '>>',  au intregul inserat, resp. extras, ca
     parametru prin valoare, resp. referinta; '<<' si '>>' returneaza stiva
     curenta prin referinta (pentru a permite push/pop miltiple); '!'
     returneaza true/false;
  metode virtuale publice:
    destructor;
  metode publice:
    operatorii '-' (unar, videaza stiva curenta), '==' (testeaza egal) '!='
    (testeaza diferit), '=' (atribuire);
    detalii: '==', '!=', '=' au ca parametru prin referinta o stiva; '-' nu
      returneaza nimic, '==' si '!=' returneaza 'true'/'false', '='
      returneaza referinta la stiva curenta; '-', '==', '!=', '=' se vor
      implementa deasupra primitivelor '<<', '>>', '!';
- functiile independente (ne-prieten pentru 'stack'):
    operatorii '>>' (citire 'stack' dintr-un 'istream'), '<<' (scriere
      'stack'intr-un 'ostream');
    detalii: '>>' si '<<' au ca parametri prin referinta streamul si stiva si
     returneaza prin referinta streamul; ei se vor implementa deasupra
     metodelor publice ale clasei 'stack';
- clasa abstracta 'list', care descrie conceptul de lista de intregi simplu
    inlantuita, avand o pozitie curenta si permitand inserarea/eliminarea/
    consultarea unui element dupa pozitia curenta; clasa contine:
  metode publice pure:
    'reset' (pozitia curenta se plaseaza inaintea primului element);
    'next' (pozitia curenta avanseaza un element, daca se poate);
    'end' (test daca dupa pozitia curenta nu mai sunt elemente);
    'ins_next' (insereaza un intreg dupa pozitia curenta, daca se poate);
    'del_next' (elimina elementul de dupa pozitia curenta, daca exista):
    'get_next' (furnizeaza elementul de dupa pozitia curenta, daca exista);
    detalii: 'ins_next' / 'get_next' au intregul inserat, resp. furnizat, ca
     parametru prin valoare, resp. referinta; celelalte metode nu au
     parametri; 'reset' nu returneaza nimic, celelalte metode returneaza
     'true'/'false';
  metode virtuale publice:
    destructor;
  metode publice:
    operatorii '-' (unar, videaza lista curenta), '==' (testeaza egal) '!='
    (testeaza diferit), '=' (atribuire);
    detalii: '==', '!=', '=' au ca parametru prin referinta o lista; '-' nu
      returneaza nimic, '==' si '!=' returneaza 'true'/'false', '='
      returneaza referinta la lista curenta; '-', '==', '!=', '=' se vor
      implementa deasupra primitivelor 'reset', 'next', 'end', 'ins_next',
      'del_next', 'get_next'; '==' si '!=' vor lasa la sfarsit lista curenta
      nemodificata, inclusiv in privinta pozitiei curente;
- clasa 'vector', care descrie conceptul de vector de intregi, avand:
  membri data privati:
    'buf' (pointer la 'int', retine adresa zonei cu elementele, care este
     alocata dinamic), 'n' ('int', numarul de elemente);
  metode publice:
    constructor implicit (initializeaza 'buf' si 'n' pentru vectorul vid);
    constructor de conversie dinspre 'int' (creaza un vector cu un intreg);
    constructor de copiere;
    destructor (elibereaza resursele vectorului);
    operatorul '[]' (indezare, returneaza referinta la intregul corespunzator
      indicelui dat ca parametru, iar daca indicele este >= 'n', realoca zona
      cu elementele);
    operatorul '=' (atribuire, sursa este primita ca parametru prin referinta
      la zona constanta, returneaza prin referinta vectorul curent);
    'truncate" (realoca/truncheaza vectorul la dimensiunea data ca parametru
      si returneaza 'true'/'false', insemnand succes/esec);
    'length' (fara parametri, returneaza 'n');
- clasa abstracta 'stack_list', care descrie implementarea clasei 'stack'
   deasupra clasei 'list'; clasa are urmetoarele:
  mosteneste public 'stack' si privat 'list';
  destructor public virtual;
  mentine pure metodele lui 'list': 'reset', ''next', 'end', 'ins_next',
    'del_next', 'get_next';
  implementeaza metodele pure mostenite din 'stack': '<<', '>>', '!',
    deasupra metodelor pure metodele lui 'list': 'reset', ''next', 'end',
    'ins_next', 'del_next', 'get_next';
- clasa 'stack_list_vector', care implementeaza clasa 'stack_list' deasupra
    clasei 'vector'; clasa are urmatoarele:
  mosteneste public 'stack_list' si privat 'vector';
  membru data privat 'k' ('int', pozitia curenta in sensul lui 'list');  
  implementeaza metodele pure mostenite din 'stack_list': 'reset', ''next',
   'end', 'ins_next','del_next', 'get_next', deasupra metodelor lui 'vector';
  redefineste operatorii prezenti si in clasele de baza '==', '!=', '=', a.i.
   sa opereze cu obiecte 'stack_list_vector'; ei se vor implementa pe baza
   operatorilor similari din 'stack';
- in programul principal, se citeste 's' de tip 'stack_list_vector' (folosind
   '>>' pentru 'stack'), se atribuie 's' lui 't' (de acelasi tip), se afisaza
   't' de doua ori (folosind '<<' pentru 'stack'), se inverseaza 't' intr-o
   stiva 'r' (folosind push, pop, test vida), se afisaza 'r', se testeaza
   daca 's' si 'r' sunt egale (folosind '==') si se afisaza un mesaj adecvat.

## compilare si rulare

Script bash

> ./build.sh

Cmake

> cmake CMakeLists.txt && make

Rulare Program

> ./144_2_Radu_George_Mihai_BONUS

## notite

## TODO
