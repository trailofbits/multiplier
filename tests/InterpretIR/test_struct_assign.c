// Tests: direct struct assignment using MEMCPY (not LOAD+STORE),
// struct parameter passing, struct return values, nested struct assignment,
// non-power-of-2 sized structs.

struct Small {
    int x;
    int y;
};

struct Large {
    int a;
    int b;
    int c;
    int d;
    int e;  // 20 bytes — too big for scalar LOAD/STORE
};

struct Packed {
    char a;
    short b;
    char c;
    // 4 bytes with padding, but some ABIs may pack to 4 or 5 bytes
};

struct Nested {
    struct Small s;
    int z;
};

static struct Small make_small(int x, int y) {
    struct Small s;
    s.x = x;
    s.y = y;
    return s;
}

static int sum_large(struct Large l) {
    return l.a + l.b + l.c + l.d + l.e;
}

int test_struct_assign(void) {
    // Direct struct assignment: a = b → MEMCPY.
    struct Small a;
    a.x = 10;
    a.y = 20;
    struct Small b = a;  // MEMCPY(b, a, sizeof(Small))
    if (b.x != 10) return 1;
    if (b.y != 20) return 2;

    // Modify copy, original unchanged.
    b.x = 99;
    if (a.x != 10) return 3;

    // Large struct assignment.
    struct Large la;
    la.a = 1; la.b = 2; la.c = 3; la.d = 4; la.e = 5;
    struct Large lb = la;  // MEMCPY for 20-byte struct
    if (lb.a != 1) return 4;
    if (lb.e != 5) return 5;

    // Pass large struct to function (by value).
    int total = sum_large(la);
    if (total != 15) return 6;

    // Struct return.
    struct Small c = make_small(100, 200);
    if (c.x != 100) return 7;
    if (c.y != 200) return 8;

    // Nested struct assignment.
    struct Nested n1;
    n1.s.x = 1;
    n1.s.y = 2;
    n1.z = 3;
    struct Nested n2 = n1;
    if (n2.s.x != 1) return 9;
    if (n2.z != 3) return 10;

    // Re-assignment.
    struct Small d;
    d.x = 0; d.y = 0;
    d = a;  // a = b style assignment → MEMCPY
    if (d.x != 10) return 11;
    if (d.y != 20) return 12;

    return 0;
}
