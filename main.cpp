#include "stack_list_vector.h"

int main() {
  Stack_List_Vector s, t;
  std::cin >> s;
  /* std::cout << s; */
  t = s;
  std::cout << "afisam t: " << t;
  std::cout << "afisam t: " << t;

  /* inversam t in stiva r */
  Stack_List_Vector r;
  int x; /* vom retine elementele din t la care vom face pop */
  while (!t == false) {
    t >> x;
    r << x;
  }
  std::cout << "afisam r: " << r;

  /* din moment ce inversam stiva t in r, t != r, stim deja t==s => r != s */
  if (s == r) {
    std::cout << "\nStiva s este egala cu stiva r.\n";
  } else {
    std::cout << "\nStiva s nu este egala cu stiva r.\n";
  }

  /* std::cout << s; */
  /* std::cout << r; */

  return 0;
}
