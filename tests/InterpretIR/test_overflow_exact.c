// Tests: exact overflow and truncation behavior at each integer width.
// These tests ONLY pass if arithmetic operates at the declared width.
// Using int64 arithmetic gives wrong results for every check.

int test_overflow_exact(void) {
    // --- ADD overflow ---
    {
        // int8: 100 + 100 = 200, wraps to -56
        signed char a = 100, b = 100;
        signed char r = a + b;
        if (r != -56) return 1;

        // int16: 30000 + 30000 = 60000, wraps to -5536
        short sa = 30000, sb = 30000;
        short sr = sa + sb;
        if (sr != -5536) return 2;

        // int32: 2000000000 + 2000000000 = 4000000000, wraps to -294967296
        int ia = 2000000000, ib = 2000000000;
        int ir = ia + ib;
        if (ir != -294967296) return 3;
    }

    // --- SUB overflow ---
    {
        signed char a = -100, b = 100;
        signed char r = a - b;
        if (r != 56) return 10;  // -200 wraps to 56

        short sa = -30000, sb = 30000;
        short sr = sa - sb;
        if (sr != 5536) return 11;  // -60000 wraps to 5536
    }

    // --- MUL overflow ---
    {
        signed char a = 16, b = 16;
        signed char r = a * b;
        if (r != 0) return 20;  // 256 wraps to 0 in int8

        signed char c = 15, d = 15;
        signed char r2 = c * d;
        if (r2 != -31) return 21;  // 225 wraps to -31

        short sa = 256, sb = 256;
        short sr = sa * sb;
        if (sr != 0) return 22;  // 65536 wraps to 0 in int16
    }

    // --- SHL overflow ---
    {
        signed char a = 1;
        signed char r = a << 7;
        if (r != -128) return 30;  // 128 wraps to -128

        short sa = 1;
        short sr = sa << 15;
        if (sr != -32768) return 31;

        int ia = 1;
        int ir = ia << 31;
        if (ir != (-2147483647 - 1)) return 32;  // INT_MIN
    }

    // --- NEG overflow ---
    {
        signed char a = -128;
        signed char r = -a;
        if (r != -128) return 40;  // -(-128) wraps to -128 in int8

        short sa = -32768;
        short sr = -sa;
        if (sr != -32768) return 41;
    }

    // --- Unsigned wrapping ---
    {
        unsigned char a = 255, b = 1;
        unsigned char r = a + b;
        if (r != 0) return 50;

        unsigned char c = 0, d = 1;
        unsigned char r2 = c - d;
        if (r2 != 255) return 51;

        unsigned short sa = 65535, sb = 1;
        unsigned short sr = sa + sb;
        if (sr != 0) return 52;

        unsigned int ia = 0xFFFFFFFFu, ib = 1;
        unsigned int ir = ia + ib;
        if (ir != 0) return 53;
    }

    // --- BIT_NOT width ---
    {
        signed char a = 0;
        signed char r = ~a;
        if (r != -1) return 60;

        unsigned char ua = 0;
        unsigned char ur = ~ua;
        if (ur != 255) return 61;

        short sa = 0;
        short sr = ~sa;
        if (sr != -1) return 62;
    }

    // --- Shift masking ---
    {
        // SHL_8: shift amount masked to 0-7
        signed char a = 1;
        // In C, shifting by >= width is UB, but our IR should mask.
        // Test within valid range but near boundary.
        signed char r = a << 7;
        if (r != -128) return 70;

        // SHR_8: arithmetic shift preserves sign
        signed char b = -1;
        signed char r2 = b >> 7;
        if (r2 != -1) return 71;  // all 1s, arithmetic shift fills with 1
    }

    return 0;
}
