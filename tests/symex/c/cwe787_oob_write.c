// Copyright (c) 2026-present, Trail of Bits, Inc.
//
// CWE-787 (out-of-bounds write) sample for the symex Phase 7
// worked example. `copy_into` performs a length-bounded copy;
// when the bounds check is bypassed (mid-loop entry via the
// engine's `start_block=` API), the loop body's `dst[i] = src[i]`
// stores past `dst_size`.
//
// Used by tests/symex/test_phase7.py P7.5 / P7.6.

#include <stddef.h>

void copy_into(char *dst, size_t dst_size,
               const char *src, size_t n) {
    if (n > dst_size) {
        return;  // bounds check
    }
    for (size_t i = 0; i < n; ++i) {
        dst[i] = src[i];
    }
}

// Helper for the simpler P7 tests: a function whose load goes
// directly through a symbolic index without the bounds check
// (analogous to symbolic_test_ptr_add but writing).
void store_at(char *base, int index, char value) {
    base[index] = value;
}

// Variant that takes a size_t index — exercises a 64-bit
// PTR_ADD path without sign-extension worries.
void store_at_u64(char *base, size_t index, char value) {
    base[index] = value;
}
