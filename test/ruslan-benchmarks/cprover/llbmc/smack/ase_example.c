#include <stdio.h>
/* #include <stdlib.h> */
#include "smack.h"

typedef struct {
  int f1;
  int f2;
} Elem;

inline Elem* alloc(int size) {
  return (Elem*)malloc(size * sizeof(Elem));
}

inline void init(int size) {
  int i;
  Elem *a1 = alloc(size);
  Elem *a2 = alloc(size);

  for (i = 0; i < size; i++) {
    a1[i].f1 = 1;
  }

  for (i = 0; i < size; i++) {
    a1[i].f2 = 0;
    a2[i].f1 = 0;
  }

  for (i = 0; i < size; i++) {
    __SMACK_assert(a1[i].f1 == 1);
  }
}

int main() {
  init(10);
  return 0;
}

