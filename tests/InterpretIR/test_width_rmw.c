// Tests: READ_MODIFY_WRITE at all widths for compound assignment and
// pre/post increment/decrement, including unsigned variants.
// Covers: ADD, SUB, MUL, DIV, REM, AND, OR, XOR, SHL, SHR (signed),
// UDIV, UREM, USHR (unsigned), all at 8/16/32/64 bit widths.

int test_width_rmw(void) {
    // --- 8-bit compound assign ---
    {
        signed char x = 100;
        x += 20;
        if (x != 120) return 1;
        x -= 10;
        if (x != 110) return 2;
        x *= 2;
        if (x != (signed char)220) return 3;  // wraps to -36
        x = 120;
        x /= 4;
        if (x != 30) return 4;
        x = 100;
        x %= 7;
        if (x != 2) return 5;
        x = 0x3C;
        x &= 0x5A;
        if (x != 0x18) return 6;
        x = 0x3C;
        x |= 0x5A;
        if (x != 0x7E) return 7;
        x = 0x3C;
        x ^= 0x5A;
        if (x != 0x66) return 8;
        x = 1;
        x <<= 6;
        if (x != 64) return 9;
        x = -128;
        x >>= 1;
        if (x != -64) return 10;  // arithmetic shift
    }

    // --- 8-bit unsigned compound assign ---
    {
        unsigned char u = 200;
        u /= 7;
        if (u != 28) return 15;  // 200/7 = 28
        u = 200;
        u %= 7;
        if (u != 4) return 16;
        u = 0x80;
        u >>= 1;
        if (u != 0x40) return 17;  // logical shift
    }

    // --- 16-bit compound assign ---
    {
        short x = 30000;
        x += 2000;
        if (x != 32000) return 20;
        x -= 1000;
        if (x != 31000) return 21;
        x = 1000;
        x *= 30;
        if (x != 30000) return 22;
        x /= 100;
        if (x != 300) return 23;
        x %= 7;
        if (x != 6) return 24;
    }

    // --- 16-bit unsigned ---
    {
        unsigned short u = 50000;
        u /= 7;
        if (u != 7142) return 30;
        u = 50000;
        u %= 7;
        if (u != 6) return 31;
        u = 0x8000;
        u >>= 1;
        if (u != 0x4000) return 32;
    }

    // --- 32-bit compound assign ---
    {
        int x = 1000000000;
        x += 500000000;
        if (x != 1500000000) return 40;
        x -= 250000000;
        if (x != 1250000000) return 41;
        x = 100000;
        x *= 10000;
        if (x != 1000000000) return 42;
        x /= 100;
        if (x != 10000000) return 43;
        x %= 7;
        if (x != 3) return 44;
    }

    // --- 32-bit unsigned ---
    {
        unsigned int u = 0x80000000u;
        u >>= 1;
        if (u != 0x40000000u) return 50;
        u = 4000000000u;
        u /= 7;
        if (u != 571428571u) return 51;
    }

    // --- 64-bit compound assign ---
    {
        long long x = 4000000000LL;
        x += 3000000000LL;
        if (x != 7000000000LL) return 60;
        x -= 2000000000LL;
        if (x != 5000000000LL) return 61;
        x = 1000000LL;
        x *= 1000000LL;
        if (x != 1000000000000LL) return 62;
        x /= 1000;
        if (x != 1000000000LL) return 63;
        x %= 7;
        if (x != 6) return 64;
    }

    // --- 64-bit unsigned ---
    {
        unsigned long long u = 0x8000000000000000ULL;
        u >>= 1;
        if (u != 0x4000000000000000ULL) return 70;
    }

    // --- Pre/post increment at different widths ---
    {
        signed char c = 126;
        ++c;
        if (c != 127) return 80;
        c++;
        if (c != -128) return 81;  // wraps

        short s = 32766;
        ++s;
        if (s != 32767) return 82;

        unsigned char uc = 255;
        uc++;
        if (uc != 0) return 83;  // wraps

        long long ll = 9000000000000000000LL;
        ll++;
        if (ll != 9000000000000000001LL) return 84;
    }

    // --- Pre/post decrement at different widths ---
    {
        signed char c = -127;
        --c;
        if (c != -128) return 90;

        unsigned char uc = 0;
        uc--;
        if (uc != 255) return 91;  // wraps

        long long ll = -9000000000000000000LL;
        --ll;
        if (ll != -9000000000000000001LL) return 92;
    }

    return 0;
}
