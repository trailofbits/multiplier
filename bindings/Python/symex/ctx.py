# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Service locator handed to hook bodies.

Phase 1 has no hooks, so Ctx is a passive container. Phase 2 populates
the control verbs (PASS / SKIP / STOP) and registers it for hook
dispatch.
"""


class Ctx:
    def __init__(self, *, path, mem, args=None, layout=None, solver=None):
        self.path = path
        self.mem = mem
        self.args = args
        self.layout = layout
        self.solver = solver
