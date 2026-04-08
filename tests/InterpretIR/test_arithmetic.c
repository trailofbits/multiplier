// Tests: integer arithmetic (ADD, SUB, MUL, DIV, REM), unary (NEG),
// bitwise (AND, OR, XOR, SHL, SHR, NOT), logical (AND, OR, NOT),
// comparisons (EQ, NE, LT, LE, GT, GE), and the comma operator (LAST_VALUE).

int test_arithmetic(void) {
    int a = 10, b = 3;

    // Basic arithmetic.
    int add = a + b;       // 13
    int sub = a - b;       // 7
    int mul = a * b;       // 30
    int div = a / b;       // 3
    int rem = a % b;       // 1

    // Unary.
    int neg = -a;          // -10

    // Bitwise.
    int band = a & b;      // 2
    int bor  = a | b;      // 11
    int bxor = a ^ b;      // 9
    int shl  = a << 1;     // 20
    int shr  = a >> 1;     // 5
    int bnot = ~a;         // -11

    // Logical.
    int land = a && b;     // 1
    int lor  = a || 0;     // 1
    int lnot = !a;         // 0

    // Comparisons.
    int eq = (a == b);     // 0
    int ne = (a != b);     // 1
    int lt = (a < b);      // 0
    int le = (a <= b);     // 0
    int gt = (a > b);      // 1
    int ge = (a >= b);     // 1

    // Comma operator (LAST_VALUE).
    int comma = (1, 2, 3); // 3

    // Verify all results.
    if (add != 13) return 1;
    if (sub != 7) return 2;
    if (mul != 30) return 3;
    if (div != 3) return 4;
    if (rem != 1) return 5;
    if (neg != -10) return 6;
    if (band != 2) return 7;
    if (bor != 11) return 8;
    if (bxor != 9) return 9;
    if (shl != 20) return 10;
    if (shr != 5) return 11;
    if (bnot != -11) return 12;
    if (land != 1) return 13;
    if (lor != 1) return 14;
    if (lnot != 0) return 15;
    if (eq != 0) return 16;
    if (ne != 1) return 17;
    if (lt != 0) return 18;
    if (le != 0) return 19;
    if (gt != 1) return 20;
    if (ge != 1) return 21;
    if (comma != 3) return 22;

    return 0;
}
