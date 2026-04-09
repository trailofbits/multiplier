// Tests: array-to-pointer decay (ArrayToPointerDecay → EmitLValue, not EmitRValue),
// passing arrays to functions, array parameters adjusted to pointers by Clang.

static int sum_array(int *arr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

static int first_element(int arr[10]) {
    // Clang adjusts int arr[10] to int *arr.
    return arr[0];
}

static void fill_array(int *dst, int val, int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = val;
    }
}

int test_array_decay(void) {
    int arr[5] = {10, 20, 30, 40, 50};

    // Pass array to function — array decays to pointer.
    // The ALLOCA for arr IS the decayed pointer.
    int total = sum_array(arr, 5);
    if (total != 150) return 1;

    // Pass array with explicit size in parameter type.
    int first = first_element(arr);
    if (first != 10) return 2;

    // Pass array to function that modifies it.
    int buf[3];
    fill_array(buf, 42, 3);
    if (buf[0] != 42) return 3;
    if (buf[1] != 42) return 4;
    if (buf[2] != 42) return 5;

    // Assign array element via decayed pointer.
    int *p = arr;
    p[2] = 99;
    if (arr[2] != 99) return 6;

    // Array decay in expressions.
    int *q = arr + 3;
    if (*q != 40) return 7;

    return 0;
}
