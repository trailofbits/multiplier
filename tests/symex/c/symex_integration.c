// Copyright (c) 2026-present, Trail of Bits, Inc.
//
// Corpus for symex integration tests (phases 9-14).
// Each function is designed to exercise a specific aspect of the
// symbolic executor's Python API without depending on a full
// application binary.
//
// Naming convention: si_<feature>_<variant>

#include <stdint.h>
#include <stddef.h>

// -----------------------------------------------------------------------
// Phase 9 targets: global variable access triggers address_for hooks.
// -----------------------------------------------------------------------

int32_t  si_g_int   = 7;
char     si_g_buf[32];
int32_t  si_g_table[8];

// Reads si_g_int — triggers address_for(kind="global") for si_g_int.
int32_t si_read_global(void) {
    return si_g_int;
}

// Writes a byte to si_g_buf[idx] (bounds-checked).
void si_write_global_buf(int32_t idx, int32_t val) {
    if (idx >= 0 && idx < 32)
        si_g_buf[idx] = (char)val;
}

// Reads two globals and returns their sum.
int32_t si_sum_globals(void) {
    return si_g_int + si_g_table[0];
}

// -----------------------------------------------------------------------
// Phase 10 targets: arithmetic that propagates symbolic args so that
// path.return_value is a z3 expression traceable via path.origin().
// -----------------------------------------------------------------------

// Identity — return_value is exactly the fresh_int arg.
int32_t si_identity(int32_t x) {
    return x;
}

// Linear combination — return_value = a + b.
int32_t si_add(int32_t a, int32_t b) {
    return a + b;
}

// Three-arg: return_value = (a + b) * c.
int32_t si_multiply_sum(int32_t a, int32_t b, int32_t c) {
    return (a + b) * c;
}

// -----------------------------------------------------------------------
// Phase 11 targets: conditional branches produce multiple paths.
// -----------------------------------------------------------------------

// Two paths: x > 0 → 1, else → 0.
int32_t si_positive(int32_t x) {
    if (x > 0) return 1;
    return 0;
}

// Three paths: positive / negative / zero.
int32_t si_sign(int32_t x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

// Nested conditions — four leaf paths.
int32_t si_quadrant(int32_t x, int32_t y) {
    if (x >= 0) {
        if (y >= 0) return 1;
        return 4;
    }
    if (y >= 0) return 2;
    return 3;
}

// -----------------------------------------------------------------------
// Phase 12 targets: SMT-query helpers (can_be / must_be /
// possible_values / value_range) on real path conditions.
// -----------------------------------------------------------------------

// Clamps x to [0, 255] — on the returned path condition, value_range
// of the return should be [0, 255] when x is unconstrained.
int32_t si_clamp_u8(int32_t x) {
    if (x < 0)   return 0;
    if (x > 255) return 255;
    return x;
}

// Returns x only if it is in [lo, hi], else 0.  On the in-range path,
// path.value_range(return_value) ⊆ [lo, hi].
int32_t si_range_filter(int32_t x, int32_t lo, int32_t hi) {
    if (x < lo || x > hi) return 0;
    return x;
}

// -----------------------------------------------------------------------
// Phase 13 targets: snapshot / restore round-trips on real paths.
// -----------------------------------------------------------------------

// Simple two-path function: take a snapshot before the branch, fork,
// restore, fork again — both restores should yield identical paths.
int32_t si_branch_a_or_b(int32_t flag) {
    if (flag) return 100;
    return 200;
}

// -----------------------------------------------------------------------
// Phase 14 targets: diverse event kinds for EventLog groupby / unique.
// -----------------------------------------------------------------------

// Reads and writes memory, hits branches → event log has multiple kinds.
int32_t si_rw_branch(int32_t *arr, int32_t n, int32_t val) {
    if (n <= 0) return -1;
    arr[0] = val;
    return arr[0];
}

// -----------------------------------------------------------------------
// Symbolic-switch corpus.
// -----------------------------------------------------------------------

// Three single-value cases + default. Symbolic selector forks 4 paths.
int32_t si_switch_three(int32_t sel) {
    switch (sel) {
        case 1: return 10;
        case 2: return 20;
        case 3: return 30;
        default: return -1;
    }
}

// GNU range case + default — symbolic selector forks 2 paths.
int32_t si_switch_range(int32_t sel) {
    switch (sel) {
        case 2 ... 5: return 100;
        default: return -1;
    }
}

// No default — symbolic selector forks exactly 2 paths (one per case).
// Falls through to an implicit return 0 for unmatched selectors.
int32_t si_switch_no_default(int32_t sel) {
    int32_t r = 0;
    switch (sel) {
        case 1: r = 10; break;
        case 2: r = 20; break;
    }
    return r;
}

// Pre-constrained selector: an early branch narrows `sel` to {0, 1}.
// Cases 2 and the default block become infeasible and the engine should
// drop them rather than enqueueing dead paths.
int32_t si_switch_constrained(int32_t sel) {
    if (sel > 1) return -2;
    switch (sel) {
        case 0: return 100;
        case 1: return 200;
        case 2: return 300;
        default: return -1;
    }
}

// -----------------------------------------------------------------------
// EnumConstantDecl reference regression corpus.
//
// A `DeclRefExpr` to an `EnumConstantDecl` is an rvalue that yields the
// enumerator's integer value — it must lower to a CONST, never to a
// MEMORY/LOAD. The functions and global below pin every shape of
// EnumConstantDecl reference we hit in C (aggregate initializer,
// scalar return, comparison, switch selector, function-call argument).
// -----------------------------------------------------------------------

enum si_color { si_red = 1, si_green = 2, si_blue = 3 };

struct si_color_entry {
    const char *name;
    enum si_color k;
};

// Aggregate initializer: each entry's `k` is a DeclRefExpr to an
// EnumConstantDecl. Without the fix these lower to MEMORY/LOAD_*.
static struct si_color_entry si_color_table[] = {
    { "red",   si_red   },
    { "green", si_green },
    { "blue",  si_blue  },
};

// Direct rvalue use: `return si_red;` is the bare DeclRefExpr.
int32_t si_enum_return(void) {
    return (int32_t)si_red;
}

// Comparison: scalar use of EnumConstantDecl on the rhs of ==.
int32_t si_enum_cmp(int32_t k) {
    if ((enum si_color)k == si_blue) return 100;
    return 0;
}

// Pass an EnumConstantDecl as a function call argument.
int32_t si_enum_take(int32_t k) { return k + 1; }
int32_t si_enum_arg(void) {
    return si_enum_take(si_green);
}

// Read the table back so the global initializer is reachable.
const char *si_enum_table_name(int32_t i) {
    if (i < 0 || i >= 3) return (const char *)0;
    return si_color_table[i].name;
}
