# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""A Path is one execution trace.

In Phase 3 the path wraps an InterpreterState plus the engine-managed
event log, tag set, per-path solver placeholder, and per-path back-edge
counter (`_loop_iters`). `snapshot()` captures everything an analyst
might want to roll back to (including a fresh state clone) and
`restore()` re-clones from the snapshot so the snap stays reusable.
`replay(modify=…)` runs the engine forward from a snapshot with one
mutation applied.
"""

import multiplier as mx

_interp = mx.ir.interpret


_id_counter = [0]


def _next_id():
    _id_counter[0] += 1
    return _id_counter[0]


class Path:
    def __init__(self, state, mem, *, parent_id=None):
        self.id = _next_id()
        self._state = state
        self._mem = mem
        self._parent_id = parent_id
        self.events = []
        self.tags = set()
        self.solver = None
        self.terminal = None
        self.return_value = None
        self.error_kind = None
        self.suspended = None
        # Per-path back-edge counter; keyed by (latch_id, header_id).
        # Mutated by the dispatcher each time intercept.loop fires.
        self._loop_iters = {}

    @property
    def state(self):
        return self._state

    @property
    def mem(self):
        return self._mem

    @property
    def steps(self):
        return self._state.steps

    def clone(self):
        cloned_state = _interp.clone_state(self._state)
        new_path = Path(cloned_state, self._mem, parent_id=self.id)
        new_path.events = list(self.events)
        new_path.tags = set(self.tags)
        new_path.solver = self.solver
        new_path._loop_iters = dict(self._loop_iters)
        return new_path

    def snapshot(self):
        """Capture full path state — interpreter state, events, tags,
        terminal, return_value, loop counter — into a reusable snapshot.

        The snapshot owns a fresh clone of the interpreter state, so
        further stepping on the path doesn't affect it.
        """
        return _Snapshot(
            state=_interp.clone_state(self._state),
            events=list(self.events),
            tags=set(self.tags),
            terminal=self.terminal,
            return_value=self.return_value,
            error_kind=self.error_kind,
            loop_iters=dict(self._loop_iters),
        )

    def restore(self, snap):
        """Roll the path back to `snap`. Re-clones the snapshot's state
        so the snapshot remains reusable."""
        self._state = _interp.clone_state(snap.state)
        self.events = list(snap.events)
        self.tags = set(snap.tags)
        self.terminal = snap.terminal
        self.return_value = snap.return_value
        self.error_kind = snap.error_kind
        self._loop_iters = dict(snap.loop_iters)

    def replay(self, *, modify, engine, slice_steps=1024,
               concretize=None, until=None):
        """Run a fresh exploration starting from a clone of this path,
        with `modify(path)` applied once before resuming.

        Returns the list of paths produced by the resumed exploration.
        Doesn't mutate `self`. The `modify` callback receives the
        cloned Path; it can use `path.mem`, `path.solver`, or directly
        write through the interpreter state.
        """
        snap = self.snapshot()
        return engine.resume_from(snap, modify=modify,
                                  slice_steps=slice_steps,
                                  concretize=concretize,
                                  parent_id=self.id,
                                  until=until)


class _Snapshot:
    """Reusable point-in-time capture of a Path's full state."""

    __slots__ = ("state", "events", "tags", "terminal", "return_value",
                 "error_kind", "loop_iters")

    def __init__(self, *, state, events, tags, terminal, return_value,
                 error_kind, loop_iters):
        self.state = state
        self.events = events
        self.tags = tags
        self.terminal = terminal
        self.return_value = return_value
        self.error_kind = error_kind
        self.loop_iters = loop_iters
