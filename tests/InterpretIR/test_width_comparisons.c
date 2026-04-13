// Tests: sized comparisons at all widths (8/16/32/64), signed and unsigned.
// Also tests float comparisons at both 32 and 64 bit precision.

int test_width_comparisons(void) {
    // --- 8-bit signed ---
    {
        signed char a = -1, b = 1;
        if (!(a == a)) return 1;
        if (!(a != b)) return 2;
        if (!(a < b)) return 3;
        if (!(a <= a)) return 4;
        if (!(b > a)) return 5;
        if (!(b >= b)) return 6;
    }

    // --- 8-bit unsigned ---
    {
        unsigned char a = 255, b = 0;
        if (!(a > b)) return 10;     // 255 > 0 unsigned
        if (!(a >= a)) return 11;
        if (!(b < a)) return 12;
        if (!(b <= b)) return 13;
        // Key: 255 as signed char is -1, which is < 0. As unsigned, 255 > 0.
    }

    // --- 16-bit signed ---
    {
        short a = -32000, b = 32000;
        if (!(a < b)) return 20;
        if (!(b > a)) return 21;
        if (a == b) return 22;
        if (!(a != b)) return 23;
    }

    // --- 16-bit unsigned ---
    {
        unsigned short a = 65535, b = 0;
        if (!(a > b)) return 30;
        if (b >= a) return 31;
    }

    // --- 32-bit signed ---
    {
        int a = -2000000000, b = 2000000000;
        if (!(a < b)) return 40;
        if (!(a <= a)) return 41;
        if (!(b > a)) return 42;
        if (!(b >= b)) return 43;
        if (a == b) return 44;
        if (!(a != b)) return 45;
    }

    // --- 32-bit unsigned ---
    {
        unsigned int a = 4000000000u, b = 1;
        if (!(a > b)) return 50;
        if (a < b) return 51;
        // As signed, 4000000000 is negative. As unsigned, it's > 1.
    }

    // --- 64-bit signed ---
    {
        long long a = -9000000000000000000LL, b = 9000000000000000000LL;
        if (!(a < b)) return 60;
        if (!(b > a)) return 61;
        if (a == b) return 62;
    }

    // --- 64-bit unsigned ---
    {
        unsigned long long a = 18000000000000000000ULL, b = 1;
        if (!(a > b)) return 70;
        if (a < b) return 71;
    }

    // --- Float 32-bit comparisons ---
    {
        float a = 1.0f / 3.0f, b = 0.5f;
        if (!(a < b)) return 80;
        if (!(b > a)) return 81;
        if (a == b) return 82;
        if (!(a != b)) return 83;
        if (!(a <= b)) return 84;
        if (!(b >= a)) return 85;

        // NaN comparisons (if supported).
        // float nan = 0.0f / 0.0f;
        // All comparisons with NaN should be false except !=.
    }

    // --- Float 64-bit comparisons ---
    {
        double a = 1.0 / 3.0, b = 0.5;
        if (!(a < b)) return 90;
        if (!(b > a)) return 91;
        if (a == b) return 92;
        if (!(a != b)) return 93;
    }

    // --- Cross-width comparison: values equal in wider type but differ in narrow ---
    {
        // 16777217 can't be represented exactly in float (rounds to 16777216).
        // In double, it's exact. This tests that float comparisons use float precision.
        float f1 = 16777216.0f;
        float f2 = 16777217.0f;  // rounds to 16777216.0f in float
        if (f1 != f2) return 100;  // should be equal in float!

        double d1 = 16777216.0;
        double d2 = 16777217.0;
        if (d1 == d2) return 101;  // should be different in double
    }

    return 0;
}
