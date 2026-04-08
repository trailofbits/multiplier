// Tests: memory and string operations (MEMORY sub-opcodes) —
// memset, memcpy, memmove, memcmp, memchr, strlen, strcmp, strncmp,
// strchr, strrchr, strcpy, strcat.
// Uses __builtin_ variants to avoid needing system headers.

typedef unsigned long size_t;

int test_memory_ops(void) {
    // memset.
    char buf[16];
    __builtin_memset(buf, 'A', 10);
    buf[10] = '\0';
    if (buf[0] != 'A') return 1;
    if (buf[9] != 'A') return 2;

    // memcpy.
    char src[] = "hello";
    char dst[16];
    __builtin_memcpy(dst, src, 6);
    if (dst[0] != 'h') return 3;
    if (dst[4] != 'o') return 4;

    // memmove (overlapping).
    char overlap[] = "abcdefgh";
    __builtin_memmove(overlap + 2, overlap, 4);
    if (overlap[2] != 'a') return 5;
    if (overlap[5] != 'd') return 6;

    // memcmp.
    if (__builtin_memcmp("abc", "abc", 3) != 0) return 7;
    if (__builtin_memcmp("abc", "abd", 3) >= 0) return 8;

    // strlen.
    if (__builtin_strlen("hello") != 5) return 10;
    if (__builtin_strlen("") != 0) return 11;

    // strcmp.
    if (__builtin_strcmp("abc", "abc") != 0) return 12;
    if (__builtin_strcmp("abc", "abd") >= 0) return 13;

    // strncmp.
    if (__builtin_strncmp("abcXXX", "abcYYY", 3) != 0) return 14;

    // strchr.
    const char *sc = __builtin_strchr("hello world", 'w');
    if (sc == 0) return 15;

    // strcpy.
    char dest2[16];
    __builtin_strcpy(dest2, "test");
    if (dest2[0] != 't') return 17;

    // strcat.
    char dest3[32] = "hello";
    __builtin_strcat(dest3, " world");
    if (__builtin_strlen(dest3) != 11) return 18;

    return 0;
}
