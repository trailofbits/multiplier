// Tests: pointer arithmetic (PTR_ADD, PTR_DIFF), pointer increment/decrement
// (RMW with PTR_ADD), pointer compound assignment (ptr += n, ptr -= n),
// array subscript, dereferencing, address-of (ALLOCA as pointer),
// GEP_FIELD for struct member access.

struct Point {
    int x;
    int y;
};

int test_pointers(void) {
    int arr[5] = {10, 20, 30, 40, 50};

    // Array subscript.
    if (arr[0] != 10) return 1;
    if (arr[4] != 50) return 2;

    // Pointer arithmetic.
    int *p = arr;
    p = p + 2;
    if (*p != 30) return 3;

    // Pointer subtraction.
    int *q = &arr[4];
    long diff = q - p;
    if (diff != 2) return 4;

    // Pointer increment.
    int *r = arr;
    r++;
    if (*r != 20) return 5;

    // Pointer decrement.
    r = &arr[3];
    r--;
    if (*r != 30) return 6;

    // Pointer compound assignment.
    int *s = arr;
    s += 3;
    if (*s != 40) return 7;
    s -= 2;
    if (*s != 20) return 8;

    // Struct member access (GEP_FIELD).
    struct Point pt;
    pt.x = 100;
    pt.y = 200;
    if (pt.x != 100) return 9;
    if (pt.y != 200) return 10;

    // Pointer to struct member.
    struct Point *pp = &pt;
    pp->x = 300;
    if (pt.x != 300) return 11;

    return 0;
}
