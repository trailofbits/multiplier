// Tests: unsigned compound assignment operators that must use UDIV/UREM/USHR
// instead of signed DIV/REM/SHR. Also tests unsigned pre/post increment.

int test_unsigned_compound(void) {
    // Unsigned right shift (logical, not arithmetic).
    unsigned int u = 0x80000000u;  // high bit set
    u >>= 1;
    // Logical shift: 0x80000000 >> 1 = 0x40000000
    if (u != 0x40000000u) return 1;

    // Unsigned division.
    unsigned int a = 0xFFFFFFFFu;  // 4294967295
    a /= 2u;
    if (a != 2147483647u) return 2;

    // Unsigned remainder.
    unsigned int b = 0xFFFFFFFFu;
    b %= 10u;
    if (b != 5u) return 3;  // 4294967295 % 10 = 5

    // Unsigned increment (should wrap).
    unsigned int c = 0xFFFFFFFFu;
    c++;
    if (c != 0u) return 4;

    // Unsigned decrement (should wrap).
    unsigned int d = 0u;
    d--;
    if (d != 0xFFFFFFFFu) return 5;

    // Unsigned compound add.
    unsigned int e = 0xFFFFFFF0u;
    e += 0x20u;
    if (e != 0x10u) return 6;  // wraps

    return 0;
}
