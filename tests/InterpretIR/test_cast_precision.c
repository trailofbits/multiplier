// Tests: exact precision of int↔float and float↔float casts.
// These ONLY pass if casts use the correct source/destination width.

int test_cast_precision(void) {
    // --- Unsigned int → float (must not sign-extend) ---
    {
        unsigned int u = 3000000000u;  // > INT_MAX
        float f = (float)u;
        // float can't represent exactly, but must be close to 3e9, not negative.
        if (f < 2.9e9f || f > 3.1e9f) return 1;

        double d = (double)u;
        // double can represent exactly.
        if (d != 3000000000.0) return 2;
    }

    // --- Unsigned char → float ---
    {
        unsigned char uc = 200;
        float f = (float)uc;
        if (f < 199.0f || f > 201.0f) return 5;

        double d = (double)uc;
        if (d != 200.0) return 6;
    }

    // --- Signed int → float (negative values) ---
    {
        int i = -1000000;
        float f = (float)i;
        if (f > -999999.0f || f < -1000001.0f) return 10;

        double d = (double)i;
        if (d != -1000000.0) return 11;
    }

    // --- Float → int (truncation toward zero) ---
    {
        float f = 3.9f;
        int i = (int)f;
        if (i != 3) return 20;

        float fn = -3.9f;
        int in = (int)fn;
        if (in != -3) return 21;

        // Float → char (truncated to 8 bits)
        float fc = 200.0f;
        signed char c = (signed char)(int)fc;
        if (c != -56) return 22;  // 200 truncated to int8 = -56

        // Float → unsigned char
        float fuc = 200.0f;
        unsigned char uc = (unsigned char)(unsigned int)fuc;
        if (uc != 200) return 23;
    }

    // --- Double → float precision loss ---
    {
        // 16777217.0 is exact in double but rounds to 16777216.0 in float.
        double d = 16777217.0;
        float f = (float)d;
        if (f != 16777216.0f) return 30;  // must round, not truncate to int

        // 1.0000000000000002 (double) → 1.0f (float) — precision lost
        double d2 = 1.0 + 1e-16;
        float f2 = (float)d2;
        if (f2 != 1.0f) return 31;
    }

    // --- Float → double (exact widening) ---
    {
        float f = 1.5f;
        double d = (double)f;
        if (d != 1.5) return 40;  // exact representation in both

        // Float's imprecision is preserved in double.
        float f2 = 1.0f / 3.0f;
        double d2 = (double)f2;
        double expected = (double)(1.0f / 3.0f);
        if (d2 != expected) return 41;
    }

    // --- 64-bit int → float ---
    {
        long long ll = 9007199254740993LL;  // 2^53 + 1, not exact in double
        double d = (double)ll;
        // Should round to 2^53 = 9007199254740992.0
        if (d != 9007199254740992.0) return 50;

        long long ll2 = 9007199254740992LL;  // 2^53, exact in double
        double d2 = (double)ll2;
        if (d2 != 9007199254740992.0) return 51;
    }

    return 0;
}
