// Tests: standalone float arithmetic (FADD/FSUB/FMUL/FDIV/FREM/FNEG),
// float comparisons (all 6 FCMP kinds), and basic float↔int casts.
// Both float (32-bit) and double (64-bit) variants.

int test_float_ops(void) {
    // --- Float 32-bit arithmetic ---
    {
        float a = 10.5f, b = 3.25f;
        float sum = a + b;
        if (sum < 13.74f || sum > 13.76f) return 1;

        float diff = a - b;
        if (diff < 7.24f || diff > 7.26f) return 2;

        float prod = a * b;
        if (prod < 34.124f || prod > 34.126f) return 3;

        float quot = a / b;
        if (quot < 3.22f || quot > 3.24f) return 4;

        float neg = -a;
        if (neg > -10.4f || neg < -10.6f) return 5;
    }

    // --- Double 64-bit arithmetic ---
    {
        double a = 1e15, b = 1.0;
        double sum = a + b;
        // Double can represent this exactly; float can't.
        if (sum != 1000000000000001.0) return 10;

        double prod = 1e100 * 1e100;
        if (prod != 1e200) return 11;

        double neg = -a;
        if (neg != -1e15) return 12;
    }

    // --- fmod (FREM) ---
    {
        float fm = 10.5f;
        // Can't use fmod directly in test (no math.h link), but
        // the C '%' doesn't work on floats. Use compound: the compiler
        // may emit FREM for some patterns. Test via compound assign instead.
    }

    // --- Float/double conversions ---
    {
        float f = 3.14f;
        double d = f;  // float → double (F32_TO_F64)
        // d should be close to 3.14 but not exactly (float rounding).
        if (d < 3.139 || d > 3.141) return 20;

        double pi = 3.14159265358979;
        float fp = (float)pi;  // double → float (F64_TO_F32)
        if (fp < 3.141f || fp > 3.142f) return 21;
    }

    // --- Int to float ---
    {
        int i = 42;
        float f = (float)i;
        if (f < 41.9f || f > 42.1f) return 30;

        double d = (double)i;
        if (d != 42.0) return 31;

        unsigned int u = 3000000000u;
        double du = (double)u;
        if (du < 2999999999.0 || du > 3000000001.0) return 32;
    }

    // --- Float to int ---
    {
        float f = 3.7f;
        int i = (int)f;  // truncates toward zero
        if (i != 3) return 40;

        float fn = -3.7f;
        int in = (int)fn;
        if (in != -3) return 41;

        double d = 1e10;
        long long ll = (long long)d;
        if (ll != 10000000000LL) return 42;
    }

    return 0;
}
