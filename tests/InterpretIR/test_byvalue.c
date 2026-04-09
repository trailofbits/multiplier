// Tests: by-value struct parameters and returns, exercising the full
// EXPRESSION_SCOPE → ALLOCA/ARG → PARAM_PTR → RETURN_PTR → ALLOCA/RETURN
// chain for both small (≤8 byte) and large (>8 byte) structs.

struct Small {
    int x;
    int y;
};

struct Large {
    int a, b, c, d, e;  // 20 bytes
};

struct Packed3 {
    char a, b, c;  // 3 bytes — non-power-of-2, must use MEMCPY
};

// Return a small struct by value.
static struct Small make_small(int x, int y) {
    struct Small s;
    s.x = x;
    s.y = y;
    return s;
}

// Return a large struct by value.
static struct Large make_large(int base) {
    struct Large l;
    l.a = base;
    l.b = base + 1;
    l.c = base + 2;
    l.d = base + 3;
    l.e = base + 4;
    return l;
}

// Take a small struct by value, return sum.
static int sum_small(struct Small s) {
    return s.x + s.y;
}

// Take a large struct by value, return sum.
static int sum_large(struct Large l) {
    return l.a + l.b + l.c + l.d + l.e;
}

// Take a 3-byte struct by value.
static int sum_packed3(struct Packed3 p) {
    return p.a + p.b + p.c;
}

// Pass struct through: take by value, return by value.
static struct Small identity_small(struct Small s) {
    return s;
}

// Chain: make → pass → sum.
static int chain_test(int x, int y) {
    struct Small s = make_small(x, y);
    return sum_small(s);
}

int test_byvalue(void) {
    // Small struct return.
    struct Small s = make_small(10, 20);
    if (s.x != 10) return 1;
    if (s.y != 20) return 2;

    // Small struct parameter.
    int sum = sum_small(s);
    if (sum != 30) return 3;

    // Large struct return.
    struct Large l = make_large(100);
    if (l.a != 100) return 4;
    if (l.e != 104) return 5;

    // Large struct parameter.
    int lsum = sum_large(l);
    if (lsum != 510) return 6;

    // Non-power-of-2 struct.
    struct Packed3 p;
    p.a = 1;
    p.b = 2;
    p.c = 3;
    int psum = sum_packed3(p);
    if (psum != 6) return 7;

    // Pass-through (param → return).
    struct Small s2 = identity_small(s);
    if (s2.x != 10) return 8;
    if (s2.y != 20) return 9;

    // Chained calls.
    int chained = chain_test(5, 15);
    if (chained != 20) return 10;

    // Nested call in expression: sum_small(make_small(1, 2)).
    int nested = sum_small(make_small(1, 2));
    if (nested != 3) return 11;

    return 0;
}
