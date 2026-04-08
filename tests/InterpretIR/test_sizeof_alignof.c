// Tests: sizeof and alignof lowered to CONST, offsetof lowered via
// EvaluateAsInt, and various type size queries.

#define offsetof(type, member) __builtin_offsetof(type, member)

struct Packed {
    char a;
    int b;
    char c;
};

int test_sizeof_alignof(void) {
    // sizeof basic types.
    if (sizeof(char) != 1) return 1;
    if (sizeof(int) < 2) return 2;
    if (sizeof(long long) < 8) return 3;

    // sizeof struct.
    if (sizeof(struct Packed) < 6) return 4;

    // sizeof array.
    int arr[10];
    if (sizeof(arr) != 10 * sizeof(int)) return 5;

    // sizeof pointer.
    if (sizeof(int *) != sizeof(void *)) return 6;

    // alignof.
    if (_Alignof(int) < 1) return 7;
    if (_Alignof(double) < 1) return 8;

    // offsetof.
    if (offsetof(struct Packed, a) != 0) return 9;
    if (offsetof(struct Packed, b) < 1) return 10;

    return 0;
}
