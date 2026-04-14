// Tests: sized integer arithmetic at all 4 widths (8/16/32/64).
// Verifies ADD, SUB, MUL, DIV, REM, NEG, BIT_NOT at each width,
// plus unsigned UDIV, UREM, USHR.
// Each operation is tested with values that exercise the width boundary.

#include <limits.h>

int test_width_arithmetic(void) {
    // --- 8-bit signed ---
    {
        signed char a = 100, b = 27;
        if ((signed char)(a + b) != 127) return 1;
        if ((signed char)(a - b) != 73) return 2;
        if ((signed char)(a * 2) != (signed char)200) return 3;  // wraps to -56
        signed char d = -120;
        if (d / 4 != -30) return 4;
        if (d % 7 != -1) return 5;  // -120 % 7 = -1
        if (-d != 120) return 6;
        signed char e = 0x55;
        if ((signed char)(~e) != (signed char)0xAA) return 7;
    }

    // --- 8-bit unsigned ---
    {
        unsigned char ua = 200, ub = 7;
        if (ua / ub != 28) return 10;     // 200/7 = 28
        if (ua % ub != 4) return 11;      // 200%7 = 4
        unsigned char uc = 0x80;
        if ((uc >> 1) != 0x40) return 12;  // logical shift
    }

    // --- 16-bit signed ---
    {
        short a = 30000, b = 2767;
        if ((short)(a + b) != 32767) return 20;
        if ((short)(a - b) != 27233) return 21;
        if ((short)(a * 2) != (short)60000) return 22;  // wraps to -5536
        short d = -30000;
        if (d / 100 != -300) return 23;
        if (d % 100 != 0) return 24;
        if (-d != 30000) return 25;
        short e = 0x5555;
        if ((short)(~e) != (short)0xAAAA) return 26;
    }

    // --- 16-bit unsigned ---
    {
        unsigned short ua = 50000, ub = 7;
        if (ua / ub != 7142) return 30;   // 50000/7 = 7142
        if (ua % ub != 6) return 31;      // 50000%7 = 6
        unsigned short uc = 0x8000;
        if ((uc >> 1) != 0x4000) return 32;
    }

    // --- 32-bit signed ---
    {
        int a = 2000000000, b = 147483647;
        if (a + b != 2147483647) return 40;
        if (a - b != 1852516353) return 41;
        int d = -2000000000;
        if (d / 100 != -20000000) return 42;
        if (d % 100 != 0) return 43;
        if (-d != 2000000000) return 44;
        int e = 0x55555555;
        if (~e != (int)0xAAAAAAAA) return 45;
    }

    // --- 32-bit unsigned ---
    {
        unsigned int ua = 4000000000u, ub = 7;
        if (ua / ub != 571428571u) return 50;
        if (ua % ub != 3u) return 51;
        unsigned int uc = 0x80000000u;
        if ((uc >> 1) != 0x40000000u) return 52;
    }

    // --- 64-bit signed ---
    {
        long long a = 4000000000LL, b = 3000000000LL;
        if (a + b != 7000000000LL) return 60;
        if (a - b != 1000000000LL) return 61;
        if (a * 2 != 8000000000LL) return 62;
        long long d = -9000000000LL;
        if (d / 1000 != -9000000LL) return 63;
        if (d % 1000 != 0) return 64;
        if (-d != 9000000000LL) return 65;
    }

    // --- 64-bit unsigned ---
    {
        unsigned long long ua = 18000000000000000000ULL, ub = 7;
        if (ua / ub != 2571428571428571428ULL) return 70;
        if (ua % ub != 4ULL) return 71;
        unsigned long long uc = 0x8000000000000000ULL;
        if ((uc >> 1) != 0x4000000000000000ULL) return 72;
    }

    // --- Shifts at all widths ---
    {
        signed char s8 = 1;
        if ((signed char)(s8 << 6) != 64) return 80;
        signed char neg = -128;
        if ((signed char)(neg >> 1) != -64) return 81;  // arithmetic shift

        short s16 = 1;
        if ((short)(s16 << 14) != 16384) return 82;

        int s32 = 1;
        if (s32 << 30 != 1073741824) return 83;

        long long s64 = 1LL;
        if (s64 << 62 != 4611686018427387904LL) return 84;
    }

    // --- Bitwise at all widths ---
    {
        signed char a8 = 0x3C, b8 = 0x5A;
        if ((a8 & b8) != 0x18) return 90;
        if ((a8 | b8) != 0x7E) return 91;
        if ((a8 ^ b8) != 0x66) return 92;

        short a16 = 0x3C3C, b16 = 0x5A5A;
        if ((a16 & b16) != 0x1818) return 93;

        int a32 = 0x3C3C3C3C, b32 = 0x5A5A5A5A;
        if ((a32 & b32) != 0x18181818) return 94;

        long long a64 = 0x3C3C3C3C3C3C3C3CLL, b64 = 0x5A5A5A5A5A5A5A5ALL;
        if ((a64 & b64) != 0x1818181818181818LL) return 95;
    }

    return 0;
}
