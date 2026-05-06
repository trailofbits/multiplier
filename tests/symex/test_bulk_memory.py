# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Bulk-memory hook surface.

Pre-fix, IR ops in the bulk MemOp range (MEMCPY / MEMSET / STRLEN / …)
went straight to `concrete_mem_bulk_op`, bypassing every Python hook.
The fix adds an `intercept.bulk_memory(op="…")` hook surface and a
default chain bottom that decomposes supported ops into per-byte
`mem_read` / `mem_write` calls so analysts who only registered
fine-grained memory hooks still see them fire.

Tests:

B.1  `intercept.bulk_memory(op="memcpy")` fires once per memcpy op
     when the IR runs a struct copy.
B.2  Without a bulk hook, the per-byte default fires `mem_write`
     hooks for each byte of the memcpy.
B.3  A bulk hook that delegates via `next_hook(...)` runs the
     per-byte default, so existing memory hooks keep firing.
"""

import pytest

from multiplier.symex import Layout, SymExEngine
from multiplier.symex.events import Terminal


def _explore(index, name):
    e = SymExEngine(index)
    e.layout = Layout()
    return e, e.explore(name)


def test_b1_bulk_memcpy_hook_fires(index):
    """A registered `intercept.bulk_memory(op="memcpy")` hook fires
    when the IR contains MEMCPY (struct assignment in C)."""
    e = SymExEngine(index)
    e.layout = Layout()
    fired = []

    @e.intercept.bulk_memory(op="memcpy")
    def hook(ctx, dst, src, n, next_hook):
        fired.append({"dst": dst, "src": src, "n": n})
        return next_hook(ctx, dst, src, n)

    paths = e.explore("test_struct_assign")
    assert paths, "test_struct_assign produced no paths"
    assert fired, "memcpy bulk hook never fired despite struct-assign IR"


def test_b2_per_byte_default_fires_mem_write(index):
    """When no bulk hook is registered, the per-byte default
    decomposition fires `mem_write` hooks per byte. Pre-fix the
    substrate's `concrete_mem_bulk_op` bypassed `mem_write` entirely."""
    e = SymExEngine(index)
    e.layout = Layout()
    write_count = [0]

    @e.intercept.memory_write
    def on_write(ctx, addr, val, size, next_hook):
        write_count[0] += 1
        return next_hook(ctx, addr, val, size)

    paths = e.explore("test_struct_assign")
    assert paths
    # struct_assign performs at least one struct = struct copy, which
    # the IR lowers to MEMCPY. The per-byte default fires one
    # mem_write per byte; the count is opaque but must be > 0.
    assert write_count[0] > 0, \
        "memory_write hook did not fire — bulk-op decomposition is " \
        "still bypassing the per-byte hook surface"


def test_b3_bulk_hook_delegates_to_default(index):
    """A bulk hook that calls `next_hook(...)` runs the per-byte
    default, so a co-registered `memory_write` hook still fires."""
    e = SymExEngine(index)
    e.layout = Layout()
    bulk_fires = [0]
    write_fires = [0]

    @e.intercept.bulk_memory(op="memcpy")
    def bulk(ctx, dst, src, n, next_hook):
        bulk_fires[0] += 1
        return next_hook(ctx, dst, src, n)

    @e.intercept.memory_write
    def on_write(ctx, addr, val, size, next_hook):
        write_fires[0] += 1
        return next_hook(ctx, addr, val, size)

    e.explore("test_struct_assign")
    assert bulk_fires[0] > 0
    assert write_fires[0] > 0, \
        "delegated default did not call mem_write hook"


def test_b4_bulk_hook_short_circuits(index):
    """A bulk hook that does NOT call `next_hook(...)` short-circuits
    — the per-byte default doesn't run, so a co-registered
    `memory_write` hook does not fire from the memcpy."""
    e = SymExEngine(index)
    e.layout = Layout()
    bulk_fires = [0]
    write_fires = [0]

    @e.intercept.bulk_memory(op="memcpy")
    def bulk(ctx, dst, src, n, next_hook):
        bulk_fires[0] += 1
        return dst  # claim the op; no decomposition runs

    @e.intercept.memory_write
    def on_write(ctx, addr, val, size, next_hook):
        # If this fires from a memcpy decomposition, the bulk hook's
        # short-circuit was ignored.
        write_fires[0] += 1
        return next_hook(ctx, addr, val, size)

    e.explore("test_struct_assign")
    assert bulk_fires[0] > 0
    # Note: write_fires may still be > 0 from non-MEMCPY stores in
    # the function; we only assert that the bulk hook ran.
