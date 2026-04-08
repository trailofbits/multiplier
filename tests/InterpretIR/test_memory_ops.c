// Tests: memory and string operations (MEMORY/MULTIMEM sub-opcodes) —
// memset, memcpy, memmove, memcmp, memchr, strlen, strcmp, strncmp,
// strchr, strrchr, strcpy, strcat.

#include <string.h>

int test_memory_ops(void) {
    // memset.
    char buf[16];
    memset(buf, 'A', 10);
    buf[10] = '\0';
    if (buf[0] != 'A') return 1;
    if (buf[9] != 'A') return 2;

    // memcpy.
    char src[] = "hello";
    char dst[16];
    memcpy(dst, src, 6);
    if (dst[0] != 'h') return 3;
    if (dst[4] != 'o') return 4;

    // memmove (overlapping).
    char overlap[] = "abcdefgh";
    memmove(overlap + 2, overlap, 4);
    if (overlap[2] != 'a') return 5;
    if (overlap[5] != 'd') return 6;

    // memcmp.
    if (memcmp("abc", "abc", 3) != 0) return 7;
    if (memcmp("abc", "abd", 3) >= 0) return 8;

    // memchr.
    const void *found = memchr("abcdef", 'd', 6);
    if (found == 0) return 9;

    // strlen.
    if (strlen("hello") != 5) return 10;
    if (strlen("") != 0) return 11;

    // strcmp.
    if (strcmp("abc", "abc") != 0) return 12;
    if (strcmp("abc", "abd") >= 0) return 13;

    // strncmp.
    if (strncmp("abcXXX", "abcYYY", 3) != 0) return 14;

    // strchr.
    const char *sc = strchr("hello world", 'w');
    if (sc == 0) return 15;

    // strrchr.
    const char *src2 = strrchr("abcabc", 'b');
    if (src2 == 0) return 16;

    // strcpy.
    char dest2[16];
    strcpy(dest2, "test");
    if (dest2[0] != 't') return 17;

    // strcat.
    char dest3[32] = "hello";
    strcat(dest3, " world");
    if (strlen(dest3) != 11) return 18;

    return 0;
}
