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
the chain. To short-circuit with the substrate's natural default
(e.g., "let the call return None / 0 instead of inlining"), use
`ctx.default()`. To stop the entire path cleanly, call
`ctx.stop_path()` and then return `ctx.default()` (or any value).
"""

from .events import Terminal


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

        Phase 2 returns `None` for every event; per-event typed
        defaults (e.g., width-correct zero for memory reads) can land
        in Phase 3 if a use-case demands it. Use this when you want to
        short-circuit a call or write without inlining.
        """
        return None

    def stop_path(self):
        """Mark the current path as stopped.

        The engine reads `path.terminal` between steps; setting it
        here ends the path cleanly. This does NOT short-circuit the
        ongoing chain — finish the handler by returning a value (often
        `ctx.default()`).
        """
        if self.path is not None:
            self.path.terminal = Terminal.STOPPED
