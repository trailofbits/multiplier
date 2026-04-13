// Tests: float vs double precision. These tests ONLY pass when the
// interpreter uses float (32-bit) precision for _32 ops and double
// (64-bit) precision for _64 ops.

int test_float_precision(void) {
    // 16777217 = 2^24 + 1. This is exactly representable in double but
    // NOT in float (float has 24 bits of mantissa, so 2^24+1 rounds to 2^24).
    float f = 16777216.0f;  // 2^24, exact in float
    f += 1.0f;
    // In float precision: 16777216.0f + 1.0f = 16777216.0f (rounds down!)
    // In double precision: 16777216.0 + 1.0 = 16777217.0 (exact)
    // If the interpreter incorrectly uses double for float ops, f would be 16777217.
    if (f != 16777216.0f) return 1;  // must equal 2^24, not 2^24+1

    // Same test with multiplication: 1.0000001f * 1.0000001f.
    // float: limited precision causes different rounding than double.
    float a = 1.0000001f;
    float b = a * a;
    // Verify it matches C float semantics, not double.
    float expected = 1.0000001f * 1.0000001f;  // computed at float precision
    if (b != expected) return 2;

    // Double precision should be exact for larger values.
    double d = 16777216.0;
    d += 1.0;
    if (d != 16777217.0) return 3;  // double CAN represent 2^24+1

    // Float comparison precision: two values that are equal as float
    // but different as double.
    float x = 1.0f / 3.0f;          // float: 0.33333334...
    float y = 0.333333343267f;       // close to 1/3 in float
    // These should compare as float, not double.
    if (x != y) return 4;

    // Float compound assign precision.
    float g = 16777216.0f;
    g += 1.0f;  // RMW(FADD_32): must use float precision
    if (g != 16777216.0f) return 5;  // stays 2^24 in float

    // Float pre-increment precision.
    float h = 16777216.0f;
    ++h;  // RMW(FADD_32, delta=1.0f): must use float precision
    if (h != 16777216.0f) return 6;

    return 0;
}
