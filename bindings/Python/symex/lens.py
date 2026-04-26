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
