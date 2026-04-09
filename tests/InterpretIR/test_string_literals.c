// Tests: string literal handling (STRING_LITERAL objects, ALLOCA for string
// storage, non-power-of-2 sizes → MEMCPY for initialization),
// array initialization from string literals, string pointer assignment.

static int my_strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int test_string_literals(void) {
    // String literal initialization of char array.
    // "hello" is char[6] (5 chars + null) — non-power-of-2 → MEMCPY.
    char buf[6] = "hello";
    if (buf[0] != 'h') return 1;
    if (buf[4] != 'o') return 2;
    if (buf[5] != '\0') return 3;

    // String pointer (decays to pointer to string literal storage).
    const char *p = "world";
    if (p[0] != 'w') return 4;
    if (p[4] != 'd') return 5;

    // String literal in function call.
    int len = my_strlen("test");
    if (len != 4) return 6;

    // Longer string (> 8 bytes, definitely MEMCPY).
    char long_buf[16] = "0123456789abcde";
    if (long_buf[0] != '0') return 7;
    if (long_buf[9] != '9') return 8;
    if (long_buf[14] != 'e') return 9;
    if (long_buf[15] != '\0') return 10;

    // Empty string.
    char empty[1] = "";
    if (empty[0] != '\0') return 11;

    // Single character string.
    char single[2] = "x";
    if (single[0] != 'x') return 12;
    if (single[1] != '\0') return 13;

    return 0;
}
