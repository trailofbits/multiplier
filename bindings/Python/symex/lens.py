# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Memory and argument lenses for hook bodies.

Phase 1 ships read/write lenses over a ConcreteMemory. The same shape
will gain `read_struct`, `as_pointer_to`, etc. in Phase 2.
"""


class MemView:
    def __init__(self, memory):
        self._memory = memory

    @property
    def memory(self):
        return self._memory

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


class ArgsView:
    def __init__(self, mem_view, param_ptrs, param_sizes=None):
        self._mem = mem_view
        self._ptrs = list(param_ptrs)
        self._sizes = list(param_sizes) if param_sizes else [None] * len(self._ptrs)

    def __len__(self):
        return len(self._ptrs)

    def __getitem__(self, i):
        return self._ptrs[i]

    def read_int(self, i, size=None, signed=False):
        sz = size if size is not None else self._sizes[i]
        if sz is None:
            raise ValueError(
                f"ArgsView.read_int requires a size for arg {i} "
                "(no type info available)")
        return self._mem.read_int(self._ptrs[i], sz, signed=signed)

    def read_str(self, i, max=4096, encoding="utf-8"):
        return self._mem.read_str(self._ptrs[i], max=max, encoding=encoding)
