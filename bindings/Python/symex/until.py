# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Termination predicates for SymExEngine.explore.

A predicate is a callable invoked with an ExploreState that exposes:

    .paths           — all paths created so far (live + terminal)
    .live_paths      — paths still being stepped
    .total_steps     — sum of `path.steps` across all paths created

Predicates compose with `|` (logical or — first to fire wins) and `&`
(logical and — all must fire).
"""

import time as _time


class _Predicate:
    def __init__(self, fn, repr_str):
        self._fn = fn
        self._repr = repr_str

    def __call__(self, state):
        return bool(self._fn(state))

    def __or__(self, other):
        if not isinstance(other, _Predicate):
            return NotImplemented
        return _Predicate(
            lambda s: self(s) or other(s),
            f"({self._repr} | {other._repr})")

    def __and__(self, other):
        if not isinstance(other, _Predicate):
            return NotImplemented
        return _Predicate(
            lambda s: self(s) and other(s),
            f"({self._repr} & {other._repr})")

    def __repr__(self):
        return f"ExploreUntil{self._repr}"


class ExploreUntil:
    @staticmethod
    def path_count(n):
        return _Predicate(lambda s: len(s.paths) >= n,
                          f".path_count({n})")

    @staticmethod
    def steps(n):
        return _Predicate(lambda s: s.total_steps >= n,
                          f".steps({n})")

    @staticmethod
    def time(seconds):
        deadline = [None]

        def check(state):
            if deadline[0] is None:
                deadline[0] = _time.monotonic() + seconds
            return _time.monotonic() >= deadline[0]
        return _Predicate(check, f".time({seconds})")

    @staticmethod
    def never():
        return _Predicate(lambda s: False, ".never()")
