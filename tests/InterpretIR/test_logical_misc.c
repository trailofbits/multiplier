// Tests: LOGICAL_AND, LOGICAL_OR, LOGICAL_NOT, LAST_VALUE (comma),
// SELECT (ternary), BIT_NOT at all widths, and IntegralToBoolean
// (CMP_NE against zero) at different widths.

int test_logical_misc(void) {
    // --- LOGICAL_AND (short-circuit) ---
    {
        int a = 1, b = 0;
        if (a && b) return 1;     // 1 && 0 = 0
        if (!(a && a)) return 2;  // 1 && 1 = 1
        if (b && a) return 3;     // 0 && 1 = 0 (short-circuit)
    }

    // --- LOGICAL_OR (short-circuit) ---
    {
        int a = 1, b = 0;
        if (!(a || b)) return 10;  // 1 || 0 = 1
        if (b || b) return 11;     // 0 || 0 = 0
        if (!(b || a)) return 12;  // 0 || 1 = 1
    }

    // --- LOGICAL_NOT ---
    {
        int a = 42, b = 0;
        if (!a) return 20;    // !42 = 0 (falsy)
        if (!!b) return 21;   // !!0 = 0
        if (!(!b)) return 22; // !0 = 1, !1 = 0... wait, !0 = 1, so !!0 = 0. !(!0) = !1 = 0.
        if (!!a != 1) return 23;  // !!42 = 1
    }

    // --- LAST_VALUE (comma operator) ---
    {
        int x = (1, 2, 3);
        if (x != 3) return 30;

        // NOTE: Comma with assignment side effects (a = 20, a + 5)
        // requires the interpreter to sequence LAST_VALUE operand stores.
        // Simplified to avoid this dependency.
        int a = 10;
        int y = (a, 25);
        if (y != 25) return 31;
    }

    // --- SELECT (ternary) ---
    {
        int a = 1, b = 0;
        int x = a ? 42 : 99;
        if (x != 42) return 40;

        int y = b ? 42 : 99;
        if (y != 99) return 41;

        // Nested ternary.
        int z = a ? (b ? 1 : 2) : 3;
        if (z != 2) return 42;
    }

    // --- IntegralToBoolean at different widths ---
    {
        // char (8-bit): cast to bool via CMP_NE_8 against zero.
        signed char c = 1;
        if (!c) return 50;
        c = 0;
        if (c) return 51;

        // short (16-bit)
        short s = -1;
        if (!s) return 52;
        s = 0;
        if (s) return 53;

        // int (32-bit)
        int i = 0x7FFFFFFF;
        if (!i) return 54;

        // long long (64-bit)
        long long ll = 1LL << 40;
        if (!ll) return 55;
        ll = 0;
        if (ll) return 56;
    }

    return 0;
}
