// Tests: C11 atomic operations (_Atomic, atomic_load, atomic_store,
// atomic_fetch_add, etc.) that produce AtomicExpr in the AST and
// ATOMIC_* memory operations in the IR.

#include <stdatomic.h>

int test_atomics(void) {
    // 1. Basic atomic load/store
    _Atomic int ai = 0;
    atomic_store(&ai, 42);
    if (atomic_load(&ai) != 42) return 1;

    // 2. Atomic fetch_add
    _Atomic int counter = 10;
    int old = atomic_fetch_add(&counter, 5);
    if (old != 10) return 2;
    if (atomic_load(&counter) != 15) return 3;

    // 3. Atomic fetch_sub
    old = atomic_fetch_sub(&counter, 3);
    if (old != 15) return 4;
    if (atomic_load(&counter) != 12) return 5;

    // 4. Atomic fetch_and
    _Atomic int mask = 0xFF;
    old = atomic_fetch_and(&mask, 0x0F);
    if (old != 0xFF) return 6;
    if (atomic_load(&mask) != 0x0F) return 7;

    // 5. Atomic fetch_or
    _Atomic int bits = 0x0F;
    old = atomic_fetch_or(&bits, 0xF0);
    if (old != 0x0F) return 8;
    if (atomic_load(&bits) != 0xFF) return 9;

    // 6. Atomic fetch_xor
    _Atomic int xval = 0xAA;
    old = atomic_fetch_xor(&xval, 0xFF);
    if (old != 0xAA) return 10;
    if (atomic_load(&xval) != 0x55) return 11;

    // 7. Atomic exchange
    _Atomic int ex = 100;
    old = atomic_exchange(&ex, 200);
    if (old != 100) return 12;
    if (atomic_load(&ex) != 200) return 13;

    // 8. Atomic compare_exchange (success case)
    _Atomic int cas = 10;
    int expected = 10;
    int ok = atomic_compare_exchange_strong(&cas, &expected, 20);
    if (!ok) return 14;
    if (atomic_load(&cas) != 20) return 15;

    // 9. Atomic compare_exchange (failure case)
    expected = 999;  // wrong expected value
    ok = atomic_compare_exchange_strong(&cas, &expected, 30);
    if (ok) return 16;
    if (atomic_load(&cas) != 20) return 17;
    // expected should be updated to current value
    if (expected != 20) return 18;

    // 10. Different atomic sizes
    _Atomic char ac = 0;
    atomic_store(&ac, 'X');
    if (atomic_load(&ac) != 'X') return 19;

    _Atomic short as = 0;
    atomic_store(&as, 1234);
    if (atomic_load(&as) != 1234) return 20;

    _Atomic long long all = 0;
    atomic_store(&all, 0x123456789ABCDEF0LL);
    if (atomic_load(&all) != 0x123456789ABCDEF0LL) return 21;

    return 0;
}
