// Tests: integer arithmetic (ADD, SUB, MUL, DIV, REM), unary (NEG),
// bitwise (AND, OR, XOR, SHL, SHR, NOT), logical (AND, OR, NOT),
// comparisons (EQ, NE, LT, LE, GT, GE), and the comma operator (LAST_VALUE).

/*
 * Expected IR (ENTRY block):
 *
 * function test_arithmetic (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=4 align=1 (a)
 *     obj_2 LOCAL_VALUE size=4 align=1 (b)
 *     obj_3 LOCAL_VALUE size=4 align=1 (add)
 *     obj_4 LOCAL_VALUE size=4 align=1 (sub)
 *     obj_5 LOCAL_VALUE size=4 align=1 (mul)
 *     obj_6 LOCAL_VALUE size=4 align=1 (div)
 *     obj_7 LOCAL_VALUE size=4 align=1 (rem)
 *     obj_8 LOCAL_VALUE size=4 align=1 (neg)
 *     obj_9 LOCAL_VALUE size=4 align=1 (band)
 *     obj_10 LOCAL_VALUE size=4 align=1 (bor)
 *     obj_11 LOCAL_VALUE size=4 align=1 (bxor)
 *     obj_12 LOCAL_VALUE size=4 align=1 (shl)
 *     obj_13 LOCAL_VALUE size=4 align=1 (shr)
 *     obj_14 LOCAL_VALUE size=4 align=1 (bnot)
 *     obj_15 LOCAL_VALUE size=4 align=1 (land)
 *     obj_16 LOCAL_VALUE size=4 align=1 (lor)
 *     obj_17 LOCAL_VALUE size=4 align=1 (lnot)
 *     obj_18 LOCAL_VALUE size=4 align=1 (eq)
 *     obj_19 LOCAL_VALUE size=4 align=1 (ne)
 *     obj_20 LOCAL_VALUE size=4 align=1 (lt)
 *     obj_21 LOCAL_VALUE size=4 align=1 (le)
 *     obj_22 LOCAL_VALUE size=4 align=1 (gt)
 *     obj_23 LOCAL_VALUE size=4 align=1 (ge)
 *     obj_24 LOCAL_VALUE size=4 align=1 (comma)
 *   blocks:
 *   block_1 ENTRY:
 *     >> %25 = ENTER_SCOPE
 *          %a.0 = ALLOCA/LOCAL size=4 align=1
 *          %26 = CONST/INT32 10
 *     >> %a.27 = MEMORY/STORE_LE_32 [%a.0, %26]
 *          %b.1 = ALLOCA/LOCAL size=4 align=1
 *          %28 = CONST/INT32 3
 *     >> %b.29 = MEMORY/STORE_LE_32 [%b.1, %28]
 *          %add.2 = ALLOCA/LOCAL size=4 align=1
 *          %32 = ADD [%30, %31]  // a + b
 *     >> %add.33 = MEMORY/STORE_LE_32 [%add.2, %32]
 *          %sub.3 = ALLOCA/LOCAL size=4 align=1
 *          %36 = SUB [%34, %35]  // a - b
 *     >> %sub.37 = MEMORY/STORE_LE_32 [%sub.3, %36]
 *          %mul.4 = ALLOCA/LOCAL size=4 align=1
 *          %40 = MUL [%38, %39]  // a * b
 *     >> %mul.41 = MEMORY/STORE_LE_32 [%mul.4, %40]
 *          %div.5 = ALLOCA/LOCAL size=4 align=1
 *          %44 = DIV [%42, %43]  // a / b
 *     >> %div.45 = MEMORY/STORE_LE_32 [%div.5, %44]
 *          %rem.6 = ALLOCA/LOCAL size=4 align=1
 *          %48 = REM [%46, %47]  // a % b
 *     >> %rem.49 = MEMORY/STORE_LE_32 [%rem.6, %48]
 *          %neg.7 = ALLOCA/LOCAL size=4 align=1
 *          %51 = NEG [%50]  // -a
 *     >> %neg.52 = MEMORY/STORE_LE_32 [%neg.7, %51]
 *          %band.8 = ALLOCA/LOCAL size=4 align=1
 *          %55 = BIT_AND [%53, %54]  // a & b
 *     >> %band.56 = MEMORY/STORE_LE_32 [%band.8, %55]
 *          %bor.9 = ALLOCA/LOCAL size=4 align=1
 *          %59 = BIT_OR [%57, %58]  // a | b
 *     >> %bor.60 = MEMORY/STORE_LE_32 [%bor.9, %59]
 *          %bxor.10 = ALLOCA/LOCAL size=4 align=1
 *          %63 = BIT_XOR [%61, %62]  // a ^ b
 *     >> %bxor.64 = MEMORY/STORE_LE_32 [%bxor.10, %63]
 *     ... (truncated)
 * }
 */

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
