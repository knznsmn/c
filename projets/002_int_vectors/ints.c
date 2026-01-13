#include <stdlib.h>

struct Ints {
  int *x;
  int len;
  size_t size;
};

Ints int_init() {
  Ints *n = malloc(sizeof *n);

}
Ints int_push(Ints *n, const int x);
Ints int_pop(ints *n)
