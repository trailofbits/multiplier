// Tests: dynamic stack allocation (ALLOCA/DYNAMIC), VLAs, alloca() builtin,
// scope-tracked dynamic objects.

int test_dynamic_alloca(void) {
    int n = 5;

    // VLA — ALLOCA/DYNAMIC with runtime size.
    int vla[n];
    for (int i = 0; i < n; i++) {
        vla[i] = i * 10;
    }
    if (vla[0] != 0) return 1;
    if (vla[4] != 40) return 2;

    // VLA in a nested scope.
    {
        int m = 3;
        int inner_vla[m];
        inner_vla[0] = 100;
        inner_vla[2] = 300;
        if (inner_vla[0] != 100) return 3;
        if (inner_vla[2] != 300) return 4;
    }
    // inner_vla is now out of scope.

    // VLA size from computation.
    int sz = n + 3;
    int bigger_vla[sz];
    bigger_vla[0] = 1;
    bigger_vla[sz - 1] = 99;
    if (bigger_vla[0] != 1) return 5;
    if (bigger_vla[7] != 99) return 6;

    return 0;
}
