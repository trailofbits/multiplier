# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Canonical names for intercept / observe events.

Used as dict keys in the engine's `_intercepts` and `_observers`
registries. Keep these strings stable — analysts may write
`@engine.intercept.memory_read(...)` and the dispatcher looks the
attribute up at registration time.
"""

MEMORY_READ = "memory_read"
MEMORY_WRITE = "memory_write"
GLOBAL_READ = "global_read"
GLOBAL_WRITE = "global_write"
CALL = "call"
INDIRECT_CALL = "indirect_call"
BRANCH = "branch"
LOOP = "loop"
CONCRETIZE = "concretize"

ALL_EVENTS = frozenset({
    MEMORY_READ, MEMORY_WRITE,
    GLOBAL_READ, GLOBAL_WRITE,
    CALL, INDIRECT_CALL,
    BRANCH, LOOP, CONCRETIZE,
})
