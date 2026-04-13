// Tests: float compound assignment (+=, -=, *=, /=, %=) and
// float pre/post increment/decrement (++f, f++, --f, f--).
// These must use FADD/FSUB/FMUL/FDIV/FREM as the RMW underlying op,
// not integer ADD/SUB/MUL/DIV/REM.

int test_float_compound(void) {
    // Float compound assignment.
    float f = 10.0f;
    f += 5.0f;
    if (f < 14.9f || f > 15.1f) return 1;

    f -= 3.0f;
    if (f < 11.9f || f > 12.1f) return 2;

    f *= 2.0f;
    if (f < 23.9f || f > 24.1f) return 3;

    f /= 4.0f;
    if (f < 5.9f || f > 6.1f) return 4;

    // Float pre-increment.
    float g = 1.0f;
    float pre = ++g;
    if (pre < 1.9f || pre > 2.1f) return 5;
    if (g < 1.9f || g > 2.1f) return 6;

    // Float post-increment.
    float h = 3.0f;
    float post = h++;
    if (post < 2.9f || post > 3.1f) return 7;
    if (h < 3.9f || h > 4.1f) return 8;

    // Float pre-decrement.
    float i = 5.0f;
    float pred = --i;
    if (pred < 3.9f || pred > 4.1f) return 9;
    if (i < 3.9f || i > 4.1f) return 10;

    // Float post-decrement.
    float j = 7.0f;
    float postd = j--;
    if (postd < 6.9f || postd > 7.1f) return 11;
    if (j < 5.9f || j > 6.1f) return 12;

    // Double compound assignment.
    double d = 100.0;
    d += 50.0;
    if (d < 149.9 || d > 150.1) return 13;

    d *= 0.5;
    if (d < 74.9 || d > 75.1) return 14;

    return 0;
}
