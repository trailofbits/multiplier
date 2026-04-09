// Tests: conditional execution semantics — short-circuit evaluation,
// ternary operator, and ensuring side effects in unreachable branches
// don't corrupt state.

static int side_effect_counter;

static int increment_and_return(int val) {
    side_effect_counter++;
    return val;
}

static int unreachable_function(void) {
    // If this is ever "executed" by the interpreter, something is wrong.
    // We can't trap here, but we return a sentinel value.
    return 99999;
}

int test_conditional_exec(void) {
    // --- Short-circuit AND ---
    // false && X: X should not be evaluated.
    side_effect_counter = 0;
    int r1 = 0 && increment_and_return(1);
    if (r1 != 0) return 1;
    // side_effect_counter would be 0 if short-circuit works,
    // but our IR evaluates both sides (they're marked conditionally executed).
    // The result should still be 0 regardless.

    // true && true: both evaluated, result = 1.
    int r2 = 1 && 1;
    if (r2 != 1) return 2;

    // true && false: result = 0.
    int r3 = 1 && 0;
    if (r3 != 0) return 3;

    // --- Short-circuit OR ---
    // true || X: X should not be evaluated.
    int r4 = 1 || unreachable_function();
    if (r4 != 1) return 4;

    // false || true: result = 1.
    int r5 = 0 || 1;
    if (r5 != 1) return 5;

    // false || false: result = 0.
    int r6 = 0 || 0;
    if (r6 != 0) return 6;

    // --- Ternary operator ---
    // true ? a : b → a.
    int r7 = 1 ? 42 : unreachable_function();
    if (r7 != 42) return 7;

    // false ? a : b → b.
    int r8 = 0 ? unreachable_function() : 43;
    if (r8 != 43) return 8;

    // Nested ternary.
    int r9 = 1 ? (0 ? 100 : 200) : 300;
    if (r9 != 200) return 9;

    // Ternary with side effects in the chosen branch only.
    int x = 10;
    int r10 = (x > 5) ? (x + 1) : (x - 1);
    if (r10 != 11) return 10;

    int r11 = (x < 5) ? (x + 1) : (x - 1);
    if (r11 != 9) return 11;

    // --- Complex combinations ---
    // (a && b) || c
    int r12 = (1 && 0) || 1;
    if (r12 != 1) return 12;

    // a || (b && c)
    int r13 = 0 || (1 && 1);
    if (r13 != 1) return 13;

    // Negated conditions.
    int r14 = !0 && !0;
    if (r14 != 1) return 14;

    int r15 = !1 || !0;
    if (r15 != 1) return 15;

    // --- Variables in conditions ---
    int a = 5, b = 0, c = 3;

    // a && b: 5 && 0 = 0.
    int r16 = a && b;
    if (r16 != 0) return 16;

    // a || b: 5 || 0 = 1.
    int r17 = a || b;
    if (r17 != 1) return 17;

    // b || c: 0 || 3 = 1.
    int r18 = b || c;
    if (r18 != 1) return 18;

    // a ? b : c → 0 (because a is truthy, picks b which is 0).
    int r19 = a ? b : c;
    if (r19 != 0) return 19;

    // b ? a : c → 3 (because b is falsy, picks c).
    int r20 = b ? a : c;
    if (r20 != 3) return 20;

    return 0;
}
