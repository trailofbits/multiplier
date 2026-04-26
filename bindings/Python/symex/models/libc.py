# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Reference interceptors for a small slice of libc.

Phase 2 covers strlen, memcpy, memset, read, malloc, free. Each is a
plain function; `register(engine)` wires them as
`engine.intercept.call(name="...")` handlers.

The handlers use the analyst-facing lens API exclusively — no direct
substrate calls — so this file doubles as a reference for hook
authors. Each takes `next_hook` as its last positional argument and
forwards by calling it; if the handler can't model the call (e.g.,
because a pointer arg is symbolic), it forwards so the substrate
inlines the body.

`read` returns a `SymExpr("read_buf", ...)` to mark the buffer as
symbolic without depending on z3 (which lands in Phase 4). Analysts
who want to override an entry should register their own handler
*before* `engine.use(models.libc)` so it sits earlier in the chain
(outermost / first-to-run); they can permissively delegate to libc by
forwarding via `next_hook(ctx)`.
"""

from ..dispatch import SymExpr


def _strlen(ctx, next_hook):
    return len(ctx.args.read_str(0))


def _memcpy(ctx, next_hook):
    dst = ctx.args.addr(0)
    src = ctx.args.addr(1)
    size = ctx.args.read_int(2, size=8)
    if dst is None or src is None:
        return next_hook(ctx)
    ctx.mem.write_bytes(dst, ctx.mem.read_bytes(src, size))
    return ("ptr", dst)


def _memset(ctx, next_hook):
    dst = ctx.args.addr(0)
    if dst is None:
        return next_hook(ctx)
    byte = ctx.args.read_int(1, size=4) & 0xFF
    size = ctx.args.read_int(2, size=8)
    ctx.mem.write_bytes(dst, bytes([byte]) * int(size))
    return ("ptr", dst)


def _read(ctx, next_hook):
    """Stub `read(fd, buf, n)`: writes a placeholder buffer and returns
    a SymExpr for the byte count. Phase 4 will swap in a real symbolic
    array."""
    buf = ctx.args.addr(1)
    n = ctx.args.read_int(2, size=8)
    if buf is not None:
        for i in range(int(n)):
            ctx.mem.write_bytes(buf + i, b"\x00")
    return SymExpr("read_buf", (n,))


def _malloc(ctx, next_hook):
    size = ctx.args.read_int(0, size=8)
    return ("ptr", ctx.layout.memory.allocate(int(size), 8))


def _free(ctx, next_hook):
    return None


_HANDLERS = {
    "strlen": _strlen,
    "memcpy": _memcpy,
    "memset": _memset,
    "read": _read,
    "malloc": _malloc,
    "free": _free,
}


def register(engine):
    """Install all libc interceptors on `engine`.

    Composition makes registration order matter: the first-registered
    handler is outermost (runs first) in the chain. Override a libc
    entry by registering your own handler *before* this call.
    """
    for name, fn in _HANDLERS.items():
        engine.intercept.call(name=name)(fn)
    return engine


__all__ = ["register"]
