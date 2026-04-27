# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Address-space declaration for symbolic exploration.

A Layout is a name -> address book backed by a ConcreteMemory. The
analyst declares globals at chosen addresses (mimicking a process
layout) and assigns symbolic addresses to functions for indirect-call
resolution. Engine consumes the layout's memory as the execution
memory.

Phase 6 upgrades the internal representation: globals and functions
are now `Region` objects in a sorted-by-base `RegionTable`, supporting
`region_containing(addr)` / `regions_overlapping(lo, hi)` interval
queries used by the OOB sink and the per-region overlay machinery.
The legacy `globals()` / `functions()` / `address_range()` / `[name]`
API is preserved unchanged.
"""

import multiplier as mx

from .region import LazyRegion, Region, RegionTable

_interp = mx.ir.interpret


class Layout:
    def __init__(self):
        self._memory = _interp.ConcreteMemory()
        self._regions = RegionTable()
        # name -> addr fast lookup for __getitem__ / __contains__.
        self._by_name: dict[str, Region] = {}
        # function-base -> name (for back-compat function_at API).
        self._function_addrs: dict[int, str] = {}
        self._symbolic_inits: dict[str, object] = {}
        # Counter for `declare_lazy` auto-base allocation. Lazy regions
        # are placed in a high range so they don't collide with the
        # analyst's declared globals.
        self._lazy_base_cursor: int = 0x7000_0000_0000_0000
        self._lazy_count: int = 0

    @property
    def memory(self):
        return self._memory

    def place_global(self, name, addr, size, init=None, align=8):
        if name in self._by_name:
            raise ValueError(f"layout name already in use: {name!r}")
        if not self._memory.place_at(addr, size, align):
            raise ValueError(
                f"cannot place global {name!r} at 0x{addr:x} "
                f"(size={size}, align={align}): overlap or misalignment")
        region = Region(name=name, base=addr, size=size, kind="global",
                        align=align, init=init)
        self._regions.add(region)
        self._by_name[name] = region
        if init is not None:
            self._write_init(name, addr, size, init)

    def place_function(self, name, addr):
        if name in self._by_name:
            raise ValueError(f"layout name already in use: {name!r}")
        if addr in self._function_addrs:
            raise ValueError(
                f"address 0x{addr:x} already bound to function "
                f"{self._function_addrs[addr]!r}")
        region = Region(name=name, base=addr, size=0, kind="function")
        self._regions.add(region)
        self._by_name[name] = region
        self._function_addrs[addr] = name

    def declare_lazy(self, name, *, max_size=4096, base=None):
        """Materialize a `LazyRegion`. Used by `ConcretizeByRegion(...,
        lazy_default=True)` when an unbacked symbolic pointer needs
        backing storage. Returns the new region.

        `base` may be passed explicitly; otherwise an address in the
        layout's reserved high range is auto-allocated. The region is
        not backed by any concrete memory — the overlay handles all
        accesses."""
        if name in self._by_name:
            raise ValueError(f"layout name already in use: {name!r}")
        if base is None:
            base = self._lazy_base_cursor
            # Stride generously to avoid sequential lazy regions touching.
            self._lazy_base_cursor += max(max_size, 1 << 16)
        region = LazyRegion(name=name, base=base, size=max_size,
                            kind="lazy", max_size=max_size)
        self._regions.add(region)
        self._by_name[name] = region
        self._lazy_count += 1
        return region

    def __getitem__(self, name):
        region = self._by_name.get(name)
        if region is None:
            raise KeyError(name)
        return region.base

    def __contains__(self, name):
        return name in self._by_name

    def function_at(self, addr):
        return self._function_addrs.get(addr)

    def address_range(self, name):
        region = self._by_name.get(name)
        if region is None:
            raise KeyError(name)
        if region.kind == "function":
            return (region.base, region.base)
        return (region.base, region.base + region.size)

    def globals(self):
        return {r.name: (r.base, r.size)
                for r in self._regions
                if r.kind in ("global", "lazy")}

    def functions(self):
        return {r.name: r.base
                for r in self._regions if r.kind == "function"}

    def symbolic_init(self, name):
        return self._symbolic_inits.get(name)

    # ---- Phase 6 region API ------------------------------------------

    def regions(self):
        """Return all regions, sorted by base."""
        return self._regions.all()

    def region_for_name(self, name) -> Region:
        return self._by_name.get(name)

    def region_containing(self, addr):
        """Return the region whose extent covers `addr`, or None.
        Prefers non-zero-size globals/lazies over zero-size function
        placements that share a base address."""
        return self._regions.containing(int(addr))

    def regions_overlapping(self, lo, hi):
        """Return regions whose extent intersects `[lo, hi)`."""
        return self._regions.overlapping(int(lo), int(hi))

    def _write_init(self, name, addr, size, init):
        if isinstance(init, bool):
            init = int(init)
        if isinstance(init, int):
            self._memory.write_bytes(
                addr, init.to_bytes(size, "little", signed=(init < 0)))
            return
        if isinstance(init, (bytes, bytearray)):
            data = bytes(init)
            if len(data) > size:
                raise ValueError(
                    f"init bytes for {name!r} exceed size: "
                    f"{len(data)} > {size}")
            if len(data) < size:
                data = data + b"\x00" * (size - len(data))
                # Note: zero-pad is consistent with C aggregate initialization.
            self._memory.write_bytes(addr, data)
            return
        # Anything else (e.g., a z3 expression) is treated as a symbolic
        # init: recorded for later policy-driven materialization. Phase 1
        # doesn't materialize it into the program-visible memory; Phase 4
        # adds the lazy-init policy that returns the recorded value.
        self._symbolic_inits[name] = init
