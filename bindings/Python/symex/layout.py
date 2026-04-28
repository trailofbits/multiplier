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
    # Reserved address ranges (non-overlapping).
    #   TLS segment:      0x6000_0000_0000_0000 upward (per-entity offsets)
    #   Function alloc:   0x4000_0000_0000_0000 upward (next_function_address)
    #   Lazy regions:     0x7000_0000_0000_0000 upward (declare_lazy)

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
        # Phase 9: function-address allocator (for next_function_address).
        self._func_base_cursor: int = 0x4000_0000_0000_0000
        # Phase 9: TLS segment. tls_offset(eid) allocates a slot per entity.
        self._tls_base: int = 0x6000_0000_0000_0000
        self._tls_cursor: int = 0
        self._tls_offsets: dict[int, int] = {}  # canonical_eid -> offset

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

    def name_for(self, addr) -> str:
        """Return the name of the global, function, or region that
        contains `addr`, or None if the address is not mapped.

        Wraps `region_containing` for the common case where the analyst
        just wants a name string rather than the full Region object.
        """
        region = self.region_containing(addr)
        if region is None:
            return None
        return region.name

    def regions_overlapping(self, lo, hi):
        """Return regions whose extent intersects `[lo, hi)`."""
        return self._regions.overlapping(int(lo), int(hi))

    # ---- Phase 9 bulk / TLS API -------------------------------------

    @property
    def tls_base(self) -> int:
        """Fixed base address for the TLS segment. All paths share this
        address; per-path isolation comes from path._tls_shadow."""
        return self._tls_base

    def tls_offset(self, eid) -> int:
        """Return the fixed byte offset of TLS entity `eid` within the
        TLS segment. Allocates a new slot on first call; subsequent
        calls for the same eid return the same offset.

        The absolute address for any path is `layout.tls_base + tls_offset(eid)`.
        """
        key = int(eid)
        cached = self._tls_offsets.get(key)
        if cached is not None:
            return cached
        offset = self._tls_cursor
        # Allocate 8 bytes per TLS slot (conservative default; callers
        # that know the real size can adjust by calling tls_offset and
        # tracking the result themselves).
        self._tls_cursor += 8
        self._tls_offsets[key] = offset
        return offset

    def next_function_address(self, *, align: int = 4) -> int:
        """Allocate the next unused address from the function-placement
        window. Consecutive calls return non-overlapping addresses."""
        cursor = self._func_base_cursor
        # Align up
        if align > 1:
            cursor = (cursor + align - 1) & ~(align - 1)
        self._func_base_cursor = cursor + align  # advance by at least align
        return cursor

    def place_functions(self, mapping: dict):
        """Bulk-place functions from a `{name: addr}` dict.

        Atomic: if any placement would fail (collision or duplicate
        name), the entire call rolls back and raises ValueError.
        """
        # Validate all entries first.
        for name, addr in mapping.items():
            if name in self._by_name:
                raise ValueError(
                    f"place_functions: layout name already in use: {name!r}")
            if addr in self._function_addrs:
                raise ValueError(
                    f"place_functions: address 0x{addr:x} already bound to "
                    f"{self._function_addrs[addr]!r}")
        # Commit.
        for name, addr in mapping.items():
            region = Region(name=name, base=addr, size=0, kind="function")
            self._regions.add(region)
            self._by_name[name] = region
            self._function_addrs[addr] = name

    def place_globals(self, entries):
        """Bulk-place globals. Each entry is (name, addr, size) or
        (name, addr, size, init).

        Atomic: if any entry would fail, the whole call rolls back.
        """
        parsed = []
        for entry in entries:
            if len(entry) == 3:
                name, addr, size = entry
                init = None
            elif len(entry) == 4:
                name, addr, size, init = entry
            else:
                raise ValueError(
                    f"place_globals: entry must be (name, addr, size) or "
                    f"(name, addr, size, init), got {entry!r}")
            if name in self._by_name:
                raise ValueError(
                    f"place_globals: layout name already in use: {name!r}")
            parsed.append((name, addr, size, init))

        # Pre-validate memory placement (no rollback on ConcreteMemory,
        # so we do a two-pass: check then commit).
        for name, addr, size, init in parsed:
            if name in self._by_name:
                raise ValueError(
                    f"place_globals: duplicate name {name!r}")
        # Commit.
        for name, addr, size, init in parsed:
            self.place_global(name, addr, size, init=init)

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
