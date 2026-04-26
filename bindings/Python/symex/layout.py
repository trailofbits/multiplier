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
"""

import multiplier as mx

_interp = mx.ir.interpret


class Layout:
    def __init__(self):
        self._memory = _interp.ConcreteMemory()
        self._globals = {}
        self._functions = {}
        self._function_addrs = {}
        self._symbolic_inits = {}

    @property
    def memory(self):
        return self._memory

    def place_global(self, name, addr, size, init=None, align=8):
        if name in self._globals or name in self._functions:
            raise ValueError(f"layout name already in use: {name!r}")
        if not self._memory.place_at(addr, size, align):
            raise ValueError(
                f"cannot place global {name!r} at 0x{addr:x} "
                f"(size={size}, align={align}): overlap or misalignment")
        self._globals[name] = (addr, size)
        if init is not None:
            self._write_init(name, addr, size, init)

    def place_function(self, name, addr):
        if name in self._globals or name in self._functions:
            raise ValueError(f"layout name already in use: {name!r}")
        if addr in self._function_addrs:
            raise ValueError(
                f"address 0x{addr:x} already bound to function "
                f"{self._function_addrs[addr]!r}")
        self._functions[name] = addr
        self._function_addrs[addr] = name

    def __getitem__(self, name):
        if name in self._globals:
            return self._globals[name][0]
        if name in self._functions:
            return self._functions[name]
        raise KeyError(name)

    def __contains__(self, name):
        return name in self._globals or name in self._functions

    def function_at(self, addr):
        return self._function_addrs.get(addr)

    def address_range(self, name):
        if name in self._globals:
            addr, size = self._globals[name]
            return (addr, addr + size)
        if name in self._functions:
            addr = self._functions[name]
            return (addr, addr)
        raise KeyError(name)

    def globals(self):
        return dict(self._globals)

    def functions(self):
        return dict(self._functions)

    def symbolic_init(self, name):
        return self._symbolic_inits.get(name)

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
