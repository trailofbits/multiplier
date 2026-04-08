// Tests: aggregate initialization via InitListExpr decomposition —
// array init (PTR_ADD + STORE per element), struct init (GEP_FIELD + STORE),
// nested struct/array, partial initialization (MEMSET zeroes rest),
// designated initializers (.field = val), compound literals.

struct Inner {
    int a;
    int b;
};

struct Outer {
    struct Inner inner;
    int c;
};

int test_init_lists(void) {
    // Array initialization.
    int arr[4] = {10, 20, 30, 40};
    if (arr[0] != 10) return 1;
    if (arr[3] != 40) return 2;

    // Partial init (rest zeroed).
    int partial[5] = {1, 2};
    if (partial[0] != 1) return 3;
    if (partial[1] != 2) return 4;
    if (partial[2] != 0) return 5;
    if (partial[4] != 0) return 6;

    // Struct initialization.
    struct Inner s = {100, 200};
    if (s.a != 100) return 7;
    if (s.b != 200) return 8;

    // Nested struct.
    struct Outer o = {{5, 6}, 7};
    if (o.inner.a != 5) return 9;
    if (o.inner.b != 6) return 10;
    if (o.c != 7) return 11;

    // Designated initializer.
    struct Inner d = {.b = 42, .a = 10};
    if (d.a != 10) return 12;
    if (d.b != 42) return 13;

    // Compound literal.
    struct Inner cl = (struct Inner){99, 88};
    if (cl.a != 99) return 14;
    if (cl.b != 88) return 15;

    // Zero initialization.
    struct Outer z = {0};
    if (z.inner.a != 0) return 16;
    if (z.c != 0) return 17;

    return 0;
}
