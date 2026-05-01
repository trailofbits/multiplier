# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Region first-class objects for the symex layout.

A `Region` owns a name, base/size, and a kind ("global" | "function" |
"lazy"). It optionally carries a per-region z3 Array overlay backing
symbolic-offset reads/writes; the overlay is created on first symbolic
touch so concrete-only workloads pay nothing.

`RegionTable` is the sorted-by-base interval index that backs
`Layout.region_containing(addr)` and `regions_overlapping(lo, hi)`.
A bisect lookup is enough at the ~10^4-region scale this engine is
intended for.
"""

import bisect
from dataclasses import dataclass
from typing import Optional


@dataclass
class Region:
    """A named address-space extent.

    Globals and placed functions both flow through this type. The
    `_overlay` slot lazily holds a z3 `Array(BitVec(64), BitVec(8))`
    that backs symbolic-offset reads/writes; it is created on first
    symbolic touch and stays None for regions that never see one.
    """

    name: str
    base: int
    size: int
    kind: str  # "global" | "function" | "lazy"
    align: int = 8
    init: object = None
    _overlay: object = None

    @property
    def end(self) -> int:
        return self.base + self.size

    def overlay(self):
        """Get the z3 Array overlay, creating it on first call.

        Concrete-only regions never call this, so the cost of the
        z3 import / Array construction is paid only when a symbolic
        access actually crosses the region. The starting array is
        the constant-zero array `K(BitVec(64), 0)` so that bytes
        which haven't been written via the overlay read back as 0;
        analysts who want "unknown initial bytes" can layer a fresh
        Array variable on top via `assert_eq`-style constraints.
        Matching the user's `Memory.py` blueprint, this gives the
        overlay well-defined per-byte semantics.
        """
        if self._overlay is None:
            import z3
            self._overlay = z3.K(z3.BitVecSort(64), z3.BitVecVal(0, 8))
        return self._overlay

    def has_overlay(self) -> bool:
        return self._overlay is not None

    def store_byte(self, addr_expr, byte_expr):
        """Store one byte into the overlay; creates the overlay on
        first call. `addr_expr` may be a Python int (concrete) or a
        z3 BitVec; `byte_expr` may be an int 0..255 or a z3 BitVec(8).
        """
        import z3
        ov = self.overlay()
        if isinstance(addr_expr, int):
            addr_expr = z3.BitVecVal(addr_expr, 64)
        if isinstance(byte_expr, int):
            byte_expr = z3.BitVecVal(byte_expr & 0xFF, 8)
        self._overlay = z3.Store(ov, addr_expr, byte_expr)
        return self._overlay

    def select_byte(self, addr_expr):
        """Read one byte from the overlay. Creates the overlay if it
        doesn't exist (caller almost certainly wants a defined Select
        when asking)."""
        import z3
        ov = self.overlay()
        if isinstance(addr_expr, int):
            addr_expr = z3.BitVecVal(addr_expr, 64)
        return z3.Select(ov, addr_expr)


@dataclass
class LazyRegion(Region):
    """A region materialized on demand for an unbacked symbolic
    pointer. `max_size` caps the bound the engine asserts on the
    path condition (`addr ∈ [base, base + max_size)`)."""

    max_size: int = 4096


class RegionTable:
    """Sorted-by-base interval index for layout regions.

    Point queries (`containing(addr)`) bisect to O(log n); range
    queries (`overlapping(lo, hi)`) bisect to the first candidate
    then linear-scan forward until the lo crosses `hi`. Suitable
    up to ~10^4 regions; switch to an interval tree if the layout
    ever balloons past that.
    """

    def __init__(self):
        # `_bases[i]` is `_regions[i].base`; kept parallel for bisect.
        self._regions: list[Region] = []
        self._bases: list[int] = []
        self._by_name: dict[str, Region] = {}

    def add(self, region: Region) -> None:
        """Insert `region`. Raises `ValueError` if it would overlap
        any existing region (zero-size function placements are
        treated as point intervals and never overlap a non-zero
        region)."""
        idx = bisect.bisect_left(self._bases, region.base)
        if idx < len(self._regions):
            nxt = self._regions[idx]
            if region.size > 0 and nxt.base < region.base + region.size:
                raise ValueError(
                    f"region {region.name!r} ({region.base:#x}, "
                    f"size={region.size}) overlaps {nxt.name!r}")
        if idx > 0:
            prev = self._regions[idx - 1]
            if prev.size > 0 and region.base < prev.base + prev.size:
                raise ValueError(
                    f"region {region.name!r} ({region.base:#x}, "
                    f"size={region.size}) overlaps {prev.name!r}")
        self._regions.insert(idx, region)
        self._bases.insert(idx, region.base)
        self._by_name[region.name] = region

    def remove(self, name: str) -> None:
        region = self._by_name.pop(name, None)
        if region is None:
            raise KeyError(name)
        idx = bisect.bisect_left(self._bases, region.base)
        while idx < len(self._regions) and self._regions[idx] is not region:
            idx += 1
        del self._regions[idx]
        del self._bases[idx]

    def get(self, name: str) -> Optional[Region]:
        return self._by_name.get(name)

    def __iter__(self):
        return iter(self._regions)

    def __len__(self):
        return len(self._regions)

    def all(self) -> list[Region]:
        return list(self._regions)

    def containing(self, addr: int) -> Optional[Region]:
        """Return the region whose `[base, base+size)` covers `addr`,
        preferring non-zero-size regions over zero-size function
        placements that share a base."""
        if not self._regions:
            return None
        idx = bisect.bisect_right(self._bases, addr) - 1
        if idx < 0:
            return None
        r = self._regions[idx]
        if r.size > 0 and r.base <= addr < r.base + r.size:
            return r
        if r.size == 0 and r.base == addr:
            return r
        return None

    def overlapping(self, lo: int, hi: int) -> list[Region]:
        """Return regions whose `[base, base+size)` intersects
        `[lo, hi)`. Linear scan past the first candidate; OK at
        layout scale."""
        out = []
        if lo >= hi or not self._regions:
            return out
        idx = bisect.bisect_right(self._bases, lo) - 1
        if idx < 0:
            idx = 0
        for r in self._regions[idx:]:
            if r.base >= hi:
                break
            r_end = r.base + r.size if r.size > 0 else r.base
            if r_end > lo and r.base < hi:
                out.append(r)
        return out
