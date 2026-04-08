// Tests: goto (GOTO), labels (LABEL), goto compensation blocks
// (COMPENSATION) for cross-scope jumps, forward gotos, backward gotos,
// and goto into nested scopes.

int test_goto(void) {
    int result = 0;

    // Forward goto.
    goto forward;
    result = -1;  // should be skipped
forward:
    if (result != 0) return 1;

    // Backward goto (simple loop).
    int count = 0;
loop:
    if (count >= 5) goto done;
    count++;
    goto loop;
done:
    if (count != 5) return 2;

    // Goto across scope boundaries (compensation block needed).
    result = 0;
    {
        result = 10;
        goto skip_inner;
        result = -1;
    }
skip_inner:
    if (result != 10) return 3;

    // Goto out of nested scopes.
    {
        {
            goto escape;
        }
    }
escape:
    result = 99;
    if (result != 99) return 4;

    return 0;
}
