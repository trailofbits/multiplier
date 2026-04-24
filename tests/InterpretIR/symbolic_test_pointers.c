#include <stdint.h>
#include <stddef.h>

struct S {
    int x;
    int y;
};

int symbolic_test_ptr_add(int *base, int index) { return base[index]; }
long symbolic_test_ptr_diff(int *p, int *q) { return p - q; }
int symbolic_test_gep_field(struct S *s) { return s->y; }
int symbolic_test_ptr_offset(int *base) { return *(base + 1); }
