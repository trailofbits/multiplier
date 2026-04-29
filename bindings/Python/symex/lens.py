# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Memory and argument lenses for hook bodies.

Phase 1 shipped read/write byte access. Phase 2 adds:
  - MemView.read_struct / write_struct over a (name, offset, size,
    signed) layout.
  - ArgsView constructed from raw call args (ints, ("ptr", N) tuples,
    arbitrary symbolic objects). `args[i]` returns the raw value;
    typed accessors do the obvious thing.
  - ArgsView.as_string(i) / as_pointer_to(i, type=...) for pointer
    arguments.
"""

import struct as _struct

import multiplier as mx


def _coerce_addr(value):
    """Pull an integer address out of a raw arg or pointer tuple."""
    if isinstance(value, tuple) and len(value) == 2 and value[0] == "ptr":
        return int(value[1])
    if isinstance(value, int) and not isinstance(value, bool):
        return int(value)
    return None


class MemView:
    """Read/write lens over a `ConcreteMemory`.

    Hook bodies receive a MemView via `ctx.mem`. The view is shape-
    only — it never copies the underlying memory.
    """

    def __init__(self, memory):
        self._memory = memory

    @property
    def memory(self):
        return self._memory

    # ---- read primitives ----------------------------------------------

    def __getitem__(self, key):
        if isinstance(key, slice):
            if key.step not in (None, 1):
                raise ValueError("MemView slice step must be 1")
            start = key.start
            stop = key.stop
            if start is None or stop is None:
                raise ValueError("MemView slice must specify start and stop")
            return self._memory.read_bytes(start, stop - start)
        raise TypeError(f"MemView indexing requires a slice, got {type(key)}")

    def read_bytes(self, addr, size):
        return self._memory.read_bytes(addr, size)

    def read_int(self, addr, size, signed=False):
        data = self._memory.read_bytes(addr, size)
        return int.from_bytes(data, "little", signed=signed)

    def read_str(self, addr, max=4096, encoding="utf-8"):
        out = bytearray()
        for off in range(max):
            b = self._memory.read_bytes(addr + off, 1)
            if not b or b[0] == 0:
                break
            out.append(b[0])
        return out.decode(encoding, errors="replace")

    # ---- write primitives ---------------------------------------------

    def write(self, addr, value, size=None):
        if isinstance(value, (bytes, bytearray)):
            self._memory.write_bytes(addr, bytes(value))
            return
        if isinstance(value, bool):
            value = int(value)
        if isinstance(value, int):
            if size is None:
                raise ValueError("size required when writing an integer")
            self._memory.write_bytes(
                addr, value.to_bytes(size, "little", signed=(value < 0)))
            return
        raise TypeError(
            f"MemView.write does not yet handle values of type {type(value)}")

    def write_bytes(self, addr, data):
        try:
            import z3 as _z3
            if isinstance(data, _z3.ExprRef):
                raise TypeError(
                    "ctx.mem.write_bytes() does not accept z3 expressions — "
                    "ConcreteMemory stores bytes, not symbolic values. "
                    "To plant symbolic data in a buffer so reads return "
                    "symbolic values, use engine.intercept.memory_read("
                    "addr_range=...) to return a fresh z3 variable per "
                    "load site, or write concrete placeholder bytes and "
                    "constrain them via path.solver.")
        except ImportError:
            pass
        self._memory.write_bytes(addr, bytes(data))

    # ---- struct lens (Phase 2) ----------------------------------------

    def read_struct(self, addr, layout):
        """Read fields described by a list of `(name, offset, size,
        signed)` tuples. Returns a dict.

        The 4-tuple form is the simplest layout the analyst can name;
        type-driven layouts arrive in Phase 4/6.
        """
        out = {}
        for name, offset, size, signed in layout:
            out[name] = self.read_int(addr + offset, size, signed=signed)
        return out

    def write_struct(self, addr, layout, **fields):
        """Write the named fields. Layout entries not present in
        `fields` are left untouched."""
        for name, offset, size, signed in layout:
            if name not in fields:
                continue
            value = fields[name]
            if isinstance(value, bool):
                value = int(value)
            self._memory.write_bytes(
                addr + offset,
                int(value).to_bytes(size, "little", signed=signed))


class ArgsView:
    """Lens over a call's argument list.

    Phase 2 unifies the previous mid-block-entry helper with the call-
    hook view. Constructed from a list of raw arg values; `args[i]`
    returns the raw value (an int, a `("ptr", addr)` tuple, or an
    arbitrary symbolic object). Typed accessors operate over either
    the literal value or the pointed-to memory.
    """

    def __init__(self, mem_view, raw_args, sizes=None):
        self._mem = mem_view
        self._raw = list(raw_args) if raw_args is not None else []
        self._sizes = (list(sizes) if sizes is not None
                       else [None] * len(self._raw))

    def __len__(self):
        return len(self._raw)

    def __getitem__(self, i):
        return self._raw[i]

    def __iter__(self):
        return iter(self._raw)

    def addr(self, i):
        """Concrete address for arg `i`, if it's pointer-shaped."""
        return _coerce_addr(self._raw[i])

    def read_int(self, i, size=None, signed=False):
        v = self._raw[i]
        if isinstance(v, bool):
            return int(v)
        if isinstance(v, int):
            return v
        # Pointer-shaped — read through it.
        a = _coerce_addr(v)
        if a is None:
            raise TypeError(
                f"ArgsView.read_int: arg {i} is not int or pointer-shaped")
        sz = size if size is not None else self._sizes[i]
        if sz is None:
            raise ValueError(
                f"ArgsView.read_int requires a size for arg {i}")
        return self._mem.read_int(a, sz, signed=signed)

    def read_str(self, i, max=4096, encoding="utf-8"):
        a = _coerce_addr(self._raw[i])
        if a is None:
            raise TypeError(
                f"ArgsView.read_str: arg {i} is not pointer-shaped")
        return self._mem.read_str(a, max=max, encoding=encoding)

    def as_string(self, i, max=4096, encoding="utf-8"):
        """Alias for read_str — reads a NUL-terminated C string at
        the address held by arg `i`."""
        return self.read_str(i, max=max, encoding=encoding)

    def as_pointer_to(self, i, type=None):
        """Return a `_PointerLens` based at args[i] for read/write
        access through the pointer.

        `type` is reserved for Phase 4/6 type-driven layouts; Phase 2
        accepts and ignores it.
        """
        a = _coerce_addr(self._raw[i])
        if a is None:
            raise TypeError(
                f"ArgsView.as_pointer_to: arg {i} is not pointer-shaped")
        return _PointerLens(self._mem, a)


class LocalsView:
    """Debugger-style lens over a function's local variables (ALLOCAs).

    Discovers every ALLOCA in `ir_func`, allocates concrete backing memory
    for each in `layout`, and exposes them by name.  Works for both
    parameter slots (AllocaKind.ARG) and body-scoped locals (AllocaKind.LOCAL).

    Parameters
    ----------
    index:    mx.Index — needed to resolve AST entities.
    ir_func:  mx.ir.IRFunction — the function to analyse.
    layout:   Layout — address space; backing memory is used for allocation.
    kinds:    which ALLOCA categories to include.  "all" (default) covers
              both parameters and locals; "locals" skips ARG slots;
              "params" keeps only ARG slots.

    Typical use
    -----------
    ::

        lv = LocalsView(index, ir_func, layout)
        lv["i"]   = z3.BitVec("i_init", 32)  # symbolic init
        lv["ptr"] = layout["g_buf"]           # concrete address
        lv.install_hooks(engine)              # wire z3 inits as intercepts
        paths = engine.explore(ir_func, seed=lv.seed_dict)

        for p in paths:
            lv.dump(p)                  # GDB "info locals"
            val = lv.read(p, "i")      # read one variable
            lv.write(p, "i", 0)        # patch on a live path
    """

    def __init__(self, index: mx.Index, ir_func, layout, kinds: str = "all"):
        self._index   = index
        self._layout  = layout
        self._memory  = layout.memory
        # name → (inst_id, size_bytes, align_bytes, addr)
        self._locals: dict[str, tuple[int, int, int, int]] = {}
        # Symbolic initial values deferred until install_hooks().
        self._symbolic_inits: dict[str, object] = {}
        self._discover(ir_func, kinds)

    # ------------------------------------------------------------------
    # Discovery
    # ------------------------------------------------------------------

    def _discover(self, ir_func, kinds: str):
        from .dispatch import _is_z3  # local import to avoid circularity
        seen_ids: set[int] = set()
        for block in ir_func.blocks:
            for inst in block.all_instructions:
                # AllocaInst.FROM returns None for non-ALLOCA instructions,
                # so this doubles as both the isinstance check and the upcast.
                alloca = mx.ir.AllocaInst.FROM(inst)
                if alloca is None:
                    continue

                inst_id = int(alloca.id)
                if inst_id in seen_ids:
                    continue
                seen_ids.add(inst_id)

                kind_val = alloca.alloca_kind
                if kinds == "locals" and kind_val != mx.ir.AllocaKind.LOCAL:
                    continue
                if kinds == "params" and kind_val != mx.ir.AllocaKind.ARG:
                    continue
                # "all" keeps LOCAL and ARG; skip RETURN and DYNAMIC slots
                # (implementation details the analyst doesn't name).
                if kinds == "all" and kind_val not in (
                    mx.ir.AllocaKind.LOCAL, mx.ir.AllocaKind.ARG
                ):
                    continue

                name  = alloca.name or f"anon_{inst_id}"
                size  = max(1, alloca.size_bytes)
                align = max(1, alloca.align_bytes)

                addr = self._memory.allocate(size, align)
                self._locals[name] = (inst_id, size, align, addr)

    # ------------------------------------------------------------------
    # Seeding (call before explore)
    # ------------------------------------------------------------------

    def __setitem__(self, name: str, value):
        """Seed the initial value for a local before exploration.

        Concrete int/bytes are written directly to backing memory.
        A z3 expression is deferred; call `install_hooks()` afterward
        to register the intercept that serves it on first read.
        """
        from .dispatch import _is_z3
        if name not in self._locals:
            raise KeyError(f"no ALLOCA found for {name!r}; "
                           f"available: {sorted(self._locals)}")
        inst_id, size, align, addr = self._locals[name]

        if _is_z3(value):
            self._symbolic_inits[name] = value
        elif isinstance(value, (int, bool)):
            val = int(value)
            data = val.to_bytes(size, "little", signed=(val < 0))
            self._memory.write_bytes(addr, data)
        elif isinstance(value, (bytes, bytearray)):
            self._memory.write_bytes(addr, bytes(value)[:size])
        else:
            raise TypeError(
                f"value must be int, bytes, or z3 expression, got {type(value)}")

    def install_hooks(self, engine):
        """Register intercept.memory_read hooks for z3-seeded locals.

        Must be called after `build_engine()` and before `explore()`.
        Hooks are scoped to the exact (addr, size) of each slot so they
        don't affect unrelated reads.  No-op if no symbolic inits are set.
        """
        for name, z3_val in list(self._symbolic_inits.items()):
            inst_id, size, align, addr = self._locals[name]

            def _make_hook(slot_addr, slot_size, sym_val):
                @engine.intercept.memory_read(addr_range=(slot_addr, slot_size))
                def _read_slot(ctx, addr_, sz, is_float, next_hook):
                    return sym_val
            _make_hook(addr, size, z3_val)

    @property
    def seed_dict(self) -> dict[int, int]:
        """Return ``{inst_id: addr}`` for every discovered ALLOCA.

        Pass as ``seed=lv.seed_dict`` to ``engine.explore()``.  The
        interpreter uses these addresses for stack slots instead of
        allocating fresh ones, so concrete writes and symbolic hooks
        both take effect.
        """
        return {inst_id: addr
                for name, (inst_id, size, align, addr) in self._locals.items()}

    # ------------------------------------------------------------------
    # Read / write on a live or completed path (debugger style)
    # ------------------------------------------------------------------

    def read(self, path, name: str):
        """Read the current value of a local from a path.

        Checks the per-path symbolic shadow first (z3 expression wins),
        then falls back to the backing memory.  Returns a z3 expression
        or a concrete int.
        """
        from .dispatch import _is_z3
        if name not in self._locals:
            raise KeyError(f"no ALLOCA found for {name!r}")
        inst_id, size, align, addr = self._locals[name]

        sym = path._symbolic_shadow.get((addr, size))
        if sym is not None:
            return sym

        data = path.mem.read_bytes(addr, size)
        if data:
            return int.from_bytes(data, "little")
        return 0

    def write(self, path, name: str, value):
        """Write to a local on a live path (GDB ``set var`` equivalent).

        Concrete ints go to backing memory; z3 expressions go to the
        per-path symbolic shadow so the next load sees the symbolic value.
        """
        from .dispatch import _is_z3
        if name not in self._locals:
            raise KeyError(f"no ALLOCA found for {name!r}")
        inst_id, size, align, addr = self._locals[name]

        if _is_z3(value):
            path._symbolic_shadow[(addr, size)] = value
        elif isinstance(value, (int, bool)):
            val = int(value)
            path.mem.write(addr, val, size)
        else:
            raise TypeError(
                f"value must be int or z3 expression, got {type(value)}")

    # ------------------------------------------------------------------
    # Diagnostics
    # ------------------------------------------------------------------

    def names(self) -> list[str]:
        """All discovered local variable names."""
        return list(self._locals.keys())

    def __repr__(self) -> str:
        return f"LocalsView({list(self._locals)})"

    def dump(self, path=None):
        """Print a GDB-style local variable listing.

        Without a path: shows the pre-exploration address plan and any
        pending symbolic inits.  With a path: reads current runtime
        values (like GDB ``info locals``).
        """
        from .dispatch import _is_z3
        print("(locals)")
        for name, (inst_id, size, align, addr) in self._locals.items():
            if path is not None:
                val = self.read(path, name)
                val_str = str(val) if _is_z3(val) else hex(val)
                print(f"  {name:20s} = {val_str}")
            else:
                pending = self._symbolic_inits.get(name)
                if pending is not None:
                    init_str = f"<symbolic: {pending}>"
                else:
                    data = self._memory.read_bytes(addr, size)
                    init_str = hex(int.from_bytes(data, "little")) if data else "0x0"
                print(f"  {name:20s}  addr=0x{addr:016x}  "
                      f"size={size}  init={init_str}")


class _PointerLens:
    """Tiny adapter around MemView with a fixed base address.

    Returned by `ArgsView.as_pointer_to`. Forwards reads / writes
    relative to the base. Phase 4 will subclass this to add type-
    driven offsets.
    """

    def __init__(self, mem_view, base):
        self._mem = mem_view
        self._base = base

    @property
    def base(self):
        return self._base

    def read_bytes(self, offset, size):
        return self._mem.read_bytes(self._base + offset, size)

    def read_int(self, offset, size, signed=False):
        return self._mem.read_int(self._base + offset, size, signed=signed)

    def write_bytes(self, offset, data):
        self._mem.write_bytes(self._base + offset, data)

    def write_int(self, offset, value, size, signed=False):
        if isinstance(value, bool):
            value = int(value)
        self._mem.write(self._base + offset, int(value), size=size)

    def write(self, offset, value, size=None):
        self._mem.write(self._base + offset, value, size=size)
