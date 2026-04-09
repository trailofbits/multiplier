// Tests: unsigned integer operations — zero extension, unsigned arithmetic,
// unsigned comparisons, unsigned overflow/wrap-around, mixing signed/unsigned.

int test_unsigned(void) {
    // Basic unsigned values.
    unsigned int ua = 200;
    unsigned int ub = 100;

    // Unsigned arithmetic.
    unsigned int sum = ua + ub;
    if (sum != 300) return 1;

    unsigned int diff = ua - ub;
    if (diff != 100) return 2;

    // Unsigned comparison.
    if (!(ua > ub)) return 3;
    if (ua < ub) return 4;
    if (ua == ub) return 5;

    // Unsigned wrap-around (underflow).
    unsigned int wrapped = 0u - 1u;
    if (wrapped != 4294967295u) return 6;

    // Unsigned char to unsigned int (zero extension).
    unsigned char uc = 200;
    unsigned int zext = uc;
    if (zext != 200) return 7;

    // Signed char to int (sign extension).
    signed char sc = -5;
    int sext = sc;
    if (sext != -5) return 8;

    // Unsigned division.
    unsigned int udiv = 10u / 3u;
    if (udiv != 3) return 9;

    // Unsigned modulo.
    unsigned int umod = 10u % 3u;
    if (umod != 1) return 10;

    // Large unsigned values.
    unsigned int large = 0xFFFFFFFF;
    if (large != 4294967295u) return 11;

    unsigned int half = large / 2;
    if (half != 2147483647u) return 12;

    // Unsigned shift.
    unsigned int shifted = 1u << 31;
    if (shifted != 2147483648u) return 13;

    unsigned int rshifted = shifted >> 1;
    if (rshifted != 1073741824u) return 14;

    // Mixing: unsigned compared to signed constant.
    unsigned int uval = 42;
    if (uval != 42) return 15;

    return 0;
}
