#include "vector.h"

Vector::Vector() {
  n = 0;
  buf = new int[n + 1];
}

Vector::Vector(int x) {
  n = 1;
  buf = new int[n + 1];
  buf[1] = x;
}

Vector::Vector(Vector &vector) {
  n = vector.n;
  buf = new int[n + 1];
  for (int i = 1; i <= n; i++) {
    buf[i] = vector.buf[i];
  }
}

Vector::~Vector() { delete[] buf; }

int &Vector::operator[](int index) {
  if (index >= n) { /* daca indexul dat este mai mare decat sizeul vectorului,
                       atunci vom mari vectorul */
    /* salvam vectorul anterior */
    int last_size = n;
    int *buf_copy =
        new int[n + 1]; /* facem un vector temporar pentru copiere */

    for (int i = 0; i <= n; i++) { /* copiem vectorul vechi in vectorul temp */
      buf_copy[i] = buf[i];
    }

    buf = new int[index + 1];
    for (int i = 0; i <= n; i++) { /* copiem datele in noul vector resized  */
      buf[i] = buf_copy[i];
    }
    n = index; /* marim lungimea */

    delete[] buf_copy; /* clean up */
  }

  return buf[index];
}

Vector &Vector::operator=(Vector &vector) {
  this->n = vector.n;
  this->buf = new int[n + 1];
  for (int i = 0; i <= n; i++) {
    this->buf[i] = vector.buf[i];
  }

  return *this;
}

bool Vector::truncate(int size) {
  if (n != size) { /* daca sizeul este cat lungimea nu mai facem trunchierea */
    int last_size = n;
    int *buf_copy =
        new int[n + 1];            /* facem un vector temporar pentru copiere */
    for (int i = 0; i <= n; i++) { /* copiem vectorul vechi in vectorul temp */
      buf_copy[i] = buf[i];
    }

    buf = new int[size + 1];
    if (size < n) {
      n = size;
    }
    for (int i = 0; i <= n; i++) { /* copiem datele in noul vector resized */
      buf[i] = buf_copy[i];
    }

    delete[] buf_copy;
  }
  return true;
}
