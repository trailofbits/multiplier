// Tests: evil goto patterns, Duff's device, gotos crossing scope boundaries,
// gotos into/out of switch cases, interleaved loops and gotos.

// Classic Duff's device: copy n bytes from src to dst.
static void duffs_copy(char *dst, const char *src, int n) {
    int remaining = n;
    if (remaining <= 0) return;
    int chunks = (remaining + 7) / 8;
    switch (remaining % 8) {
        case 0: do { *dst++ = *src++;
        case 7:      *dst++ = *src++;
        case 6:      *dst++ = *src++;
        case 5:      *dst++ = *src++;
        case 4:      *dst++ = *src++;
        case 3:      *dst++ = *src++;
        case 2:      *dst++ = *src++;
        case 1:      *dst++ = *src++;
                } while (--chunks > 0);
    }
}

// Goto into a nested scope — variable declared in scope, goto skips init.
static int goto_into_scope(void) {
    int result = 0;
    goto inside;
    {
        int x = 99;  // skipped by goto
inside:
        // x is uninitialized here (skipped), but result is valid.
        result = 42;
    }
    return result;
}

// Goto out of deeply nested scopes.
static int goto_escape_nested(void) {
    int val = 0;
    {
        int a = 1;
        {
            int b = 2;
            {
                int c = 3;
                val = a + b + c;  // 6
                goto escape;
                val = 999;  // unreachable
            }
            val = 888;  // unreachable
        }
        val = 777;  // unreachable
    }
escape:
    return val;
}

// Forward goto skipping variable declarations.
static int goto_skip_decls(void) {
    int r = 0;
    goto skip;
    int x = 10;  // skipped
    r = x;       // skipped
skip:
    // x exists but was never initialized. r should still be 0.
    return r;
}

// Goto used as a loop with scope entry/exit each iteration.
static int goto_loop_with_scope(void) {
    int total = 0;
    int i = 0;
loop_top:
    if (i >= 5) goto loop_done;
    {
        int increment = i + 1;
        total += increment;
        i++;
    }
    goto loop_top;
loop_done:
    // total = 1 + 2 + 3 + 4 + 5 = 15
    return total;
}

// Goto between switch cases (not fallthrough — explicit goto).
static int goto_between_cases(int selector) {
    int result = 0;
    switch (selector) {
        case 1:
            result = 10;
            goto case3_body;
        case 2:
            result = 20;
            break;
        case 3:
case3_body:
            result += 100;
            break;
    }
    return result;
}

// Multiple gotos to the same label from different scopes.
static int multi_source_goto(int path) {
    int result = 0;
    if (path == 1) {
        int x = 10;
        result = x;
        goto merge;
    }
    if (path == 2) {
        int y = 20;
        result = y;
        goto merge;
    }
    result = 30;
merge:
    return result;
}

int test_evil_goto(void) {
    // Duff's device.
    {
        char src[11] = "0123456789";
        char dst[11] = {0};
        duffs_copy(dst, src, 10);
        if (dst[0] != '0') return 1;
        if (dst[9] != '9') return 2;
        if (dst[10] != '\0') return 3;

        // Duff with non-multiple-of-8 count.
        char dst2[4] = {0};
        duffs_copy(dst2, src, 3);
        if (dst2[0] != '0') return 4;
        if (dst2[2] != '2') return 5;
    }

    // Goto into scope.
    if (goto_into_scope() != 42) return 6;

    // Goto escaping nested scopes.
    if (goto_escape_nested() != 6) return 7;

    // Goto skipping declarations.
    if (goto_skip_decls() != 0) return 8;

    // Goto loop with scope entry/exit.
    if (goto_loop_with_scope() != 15) return 9;

    // Goto between switch cases: case 1 → goto case3_body → result = 10 + 100 = 110.
    if (goto_between_cases(1) != 110) return 10;
    // Case 2 → result = 20.
    if (goto_between_cases(2) != 20) return 11;
    // Case 3 → result = 0 + 100 = 100.
    if (goto_between_cases(3) != 100) return 12;

    // Multi-source goto.
    if (multi_source_goto(1) != 10) return 13;
    if (multi_source_goto(2) != 20) return 14;
    if (multi_source_goto(0) != 30) return 15;

    return 0;
}
