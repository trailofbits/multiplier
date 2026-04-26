# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""A Path is one execution trace.

In Phase 1 the path wraps an InterpreterState plus the engine-managed
event log, tag set, and per-path solver placeholder. clone uses the
substrate's clone_state. snapshot/restore are stubs until Phase 3.
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
        return new_path

    def snapshot(self):
        return _PathSnapshot(self.id, list(self.events), set(self.tags))

    def restore(self, snap):
        self.events = list(snap.events)
        self.tags = set(snap.tags)


class _PathSnapshot:
    __slots__ = ("path_id", "events", "tags")

    def __init__(self, path_id, events, tags):
        self.path_id = path_id
        self.events = events
        self.tags = tags
