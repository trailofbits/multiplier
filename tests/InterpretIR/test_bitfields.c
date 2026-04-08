// Tests: bit-field access (BIT_READ_LE/BE, BIT_WRITE_LE/BE),
// bit-field initialization, reading back bit-field values,
// and bit-field in compound expressions.

struct Flags {
    unsigned int read  : 1;
    unsigned int write : 1;
    unsigned int exec  : 1;
    unsigned int mode  : 4;
    unsigned int pad   : 25;
};

int test_bitfields(void) {
    struct Flags f = {0};

    // Write individual bit-fields.
    f.read = 1;
    f.write = 0;
    f.exec = 1;
    f.mode = 7;

    // Read back.
    if (f.read != 1) return 1;
    if (f.write != 0) return 2;
    if (f.exec != 1) return 3;
    if (f.mode != 7) return 4;

    // Init list for bit-fields.
    struct Flags g = {1, 1, 0, 5};
    if (g.read != 1) return 5;
    if (g.write != 1) return 6;
    if (g.exec != 0) return 7;
    if (g.mode != 5) return 8;

    // Modify via compound assignment.
    f.mode = f.mode & 3;
    if (f.mode != 3) return 9;

    return 0;
}
