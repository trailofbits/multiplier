# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""LoopContext — the per-firing payload attached to `ctx.loop`.

Built lazily by the dispatcher whenever a cond_branch is at the source
of a back-edge or at the header of one. Carries iteration metadata so
loop policies can decide when to short-circuit. The per-path counter
itself lives on `Path._loop_iters`; LoopContext is rebuilt fresh per
dispatch and reads / mutates that dict.
"""


class LoopContext:
    """Snapshot of the loop state visible to a loop / branch hook.

    `iteration` counts how many times this loop's gating cond_branch has
    already fired on the current path (0 on the first call, 1 on the
    second, etc.). The dispatcher bumps the counter *after* building
    the LoopContext so a hook that returns False on iteration == 3 has
    seen three prior firings.
    """

    __slots__ = ("iteration", "header_block", "latch_block",
                 "_is_continue_on_true", "_condition")

    def __init__(self, iteration, header_block, latch_block,
                 is_continue_on_true, condition):
        self.iteration = int(iteration)
        self.header_block = header_block
        self.latch_block = latch_block
        self._is_continue_on_true = bool(is_continue_on_true)
        self._condition = condition

    @property
    def would_exit(self):
        """Best-effort: True if the substrate's natural concrete answer
        would take the exit edge (i.e., leave the loop), False if it
        would re-enter the loop, None if the condition is symbolic.
        """
        cond = self._condition
        if isinstance(cond, bool):
            concrete_true = cond
        elif isinstance(cond, int):
            concrete_true = cond != 0
        else:
            return None
        # exit = the non-continue edge.
        if self._is_continue_on_true:
            return not concrete_true
        return concrete_true

    def __repr__(self):
        return (f"LoopContext(iteration={self.iteration}, "
                f"header={self.header_block}, latch={self.latch_block})")


def _bump_path_counter(path, latch, header):
    """Increment `path._loop_iters[(latch, header)]` and return the
    pre-increment value (i.e., the iteration index for the firing about
    to happen). Tolerates a path that doesn't yet have the dict."""
    iters = getattr(path, "_loop_iters", None)
    if iters is None:
        iters = {}
        path._loop_iters = iters
    key = (latch, header)
    n = iters.get(key, 0)
    iters[key] = n + 1
    return n
