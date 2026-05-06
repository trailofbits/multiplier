# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Service locator handed to hook bodies.

A `Ctx` instance is constructed fresh per dispatched event and is the
sole argument every intercept / observe handler receives (alongside the
event-specific args and `next_hook`). It exposes the path, memory
lens, args lens (for call events), layout, and solver.

Hooks compose by calling `next_hook(...)` to forward to the rest of
the chain. To short-circuit a call hook with `None` as the return
value (the common "stub this function" case), just `return None`.
`ctx.default()` is the typed equivalent. To fall through to the
substrate's own resolver (e.g., let an IR function inline), return
`NotImplemented`. To stop the entire path cleanly, call
`ctx.stop_path()` and then return any value.
"""

from .events import Terminal, StopNow


class Ctx:
    """Per-event service locator.

    Holds references to the path, memory lens, args lens (for call
    events), layout, and solver. Hook bodies receive a freshly
    constructed Ctx for each event; mutating it after the event is a
    no-op as the engine drops it.
    """

    def __init__(self, *, path, mem, args=None, layout=None, solver=None):
        self.path = path
        self.mem = mem
        self.args = args
        self.layout = layout
        self.solver = solver

    def default(self):
        """The substrate's "natural default" for the current event.

        Equivalent to `return None` from a call handler — the call is
        skipped with `None` as the return value. Returns `Skip()` (a
        typed marker the substrate unwraps) so this is also safe in
        any future hook surface that might re-disambiguate `None`.
        """
        from .events import Skip
        return Skip()

    def stop_path(self):
        """Mark the current path as stopped.

        The engine reads `path.terminal` between steps; setting it
        here ends the path cleanly. This does NOT short-circuit the
        ongoing chain — finish the handler by returning a value (often
        `ctx.default()`).
        """
        if self.path is not None:
            self.path.terminal = Terminal.STOPPED

    def stop_now(self, terminal=Terminal.STOPPED):
        """Halt the current interpreter slice immediately.

        Sets `path.terminal` to `terminal` and raises `StopNow`, which
        the C++ interpreter catches to clear the work stack.  The engine
        driver intercepts `StopNow` after `_interp.step()` returns and
        treats the path as stopped — no further slices are taken.

        Works from any hook type (intercept or observe).  Unlike
        `stop_path()`, execution does not continue to the end of the
        current slice.
        """
        if self.path is not None:
            self.path.terminal = terminal
        raise StopNow()
