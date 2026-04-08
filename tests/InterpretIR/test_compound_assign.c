// Tests: read-modify-write (READ_MODIFY_WRITE) for compound assignment
// operators (+=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=),
// pre/post increment/decrement (++x, x++, --x, x--),
// and pointer increment/decrement.

int test_compound_assign(void) {
    int x = 10;

    // Compound assignment operators.
    x += 5;   if (x != 15) return 1;
    x -= 3;   if (x != 12) return 2;
    x *= 2;   if (x != 24) return 3;
    x /= 6;   if (x != 4) return 4;
    x %= 3;   if (x != 1) return 5;

    x = 0xFF;
    x &= 0x0F;  if (x != 0x0F) return 6;
    x |= 0xF0;  if (x != 0xFF) return 7;
    x ^= 0xFF;  if (x != 0x00) return 8;

    x = 1;
    x <<= 4;  if (x != 16) return 9;
    x >>= 2;  if (x != 4) return 10;

    // Pre-increment.
    x = 5;
    int pre = ++x;
    if (pre != 6) return 11;
    if (x != 6) return 12;

    // Post-increment.
    x = 5;
    int post = x++;
    if (post != 5) return 13;
    if (x != 6) return 14;

    // Pre-decrement.
    x = 5;
    pre = --x;
    if (pre != 4) return 15;

    // Post-decrement.
    x = 5;
    post = x--;
    if (post != 5) return 16;
    if (x != 4) return 17;

    // Pointer increment.
    int arr[3] = {10, 20, 30};
    int *p = arr;
    p++;
    if (*p != 20) return 18;

    // Pointer decrement.
    p = &arr[2];
    p--;
    if (*p != 20) return 19;

    // Pointer compound assign.
    p = arr;
    p += 2;
    if (*p != 30) return 20;
    p -= 1;
    if (*p != 20) return 21;

    return 0;
}
