// Tests: pointer arithmetic (PTR_ADD, PTR_DIFF), pointer increment/decrement
// (RMW with PTR_ADD), pointer compound assignment (ptr += n, ptr -= n),
// array subscript, dereferencing, address-of (ALLOCA as pointer),
// GEP_FIELD for struct member access.

/*
 * Expected IR (ENTRY block):
 *
 * function test_pointers (NORMAL) {
 *   objects:
 *     obj_0 RETURN_SLOT size=4 align=1
 *     obj_1 LOCAL_VALUE size=20 align=1 (arr)
 *     obj_2 LOCAL_VALUE size=8 align=1 (p)
 *     obj_3 LOCAL_VALUE size=8 align=1 (q)
 *     obj_4 LOCAL_VALUE size=8 align=1 (diff)
 *     obj_5 LOCAL_VALUE size=8 align=1 (r)
 *     obj_6 LOCAL_VALUE size=8 align=1 (s)
 *     obj_7 LOCAL size=8 align=1 (pt)
 *     obj_8 LOCAL_VALUE size=8 align=1 (pp)
 *   blocks:
 *   block_1 ENTRY:
 *     >> %9 = ENTER_SCOPE
 *          %arr.0 = ALLOCA/LOCAL size=20 align=1
 *          %arr.10 = CONST/UINT8 0
 *          %arr.11 = CONST/UINT64 20
 *     >> %arr.12 = MEMORY/MEMSET [%arr.0, %arr.10, %arr.11]
 *          %arr.0 = ALLOCA/LOCAL size=20 align=1
 *          %13 = CONST/INT32 10
 *     >> %arr.14 = MEMORY/STORE_LE_32 [%arr.0, %13]
 *          %arr.16 = PTR_ADD elem_size=4 [%arr.0, %arr.15]
 *          %17 = CONST/INT32 20
 *     >> %arr.18 = MEMORY/STORE_LE_32 [%arr.16, %17]
 *          %arr.20 = PTR_ADD elem_size=4 [%arr.0, %arr.19]
 *          %21 = CONST/INT32 30
 *     >> %arr.22 = MEMORY/STORE_LE_32 [%arr.20, %21]
 *          %arr.24 = PTR_ADD elem_size=4 [%arr.0, %arr.23]
 *          %25 = CONST/INT32 40
 *     >> %arr.26 = MEMORY/STORE_LE_32 [%arr.24, %25]
 *          %arr.28 = PTR_ADD elem_size=4 [%arr.0, %arr.27]
 *          %29 = CONST/INT32 50
 *     >> %arr.30 = MEMORY/STORE_LE_32 [%arr.28, %29]
 *     ... (truncated, continues with pointer ops and GEP_FIELD for struct access)
 * }
 */

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
