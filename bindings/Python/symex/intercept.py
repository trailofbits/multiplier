# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""`engine.intercept.<event>(**selector)` decorator namespace.

Each attribute on `InterceptDispatcher` is a per-event decorator. The
decorator stores `(selector, handler)` in the engine's `_intercepts`
registry. At dispatch time the matching handlers compose into a chain
where each handler receives `next_hook` as its last positional
argument; calling `next_hook(...)` forwards down the chain. A handler
that returns without calling `next_hook` short-circuits.
"""

from .dispatch import make_selector
from .events import ALL_EVENTS


class InterceptDispatcher:
    """Built once per `SymExEngine` and exposed as `engine.intercept`."""

    def __init__(self, engine):
        self._engine = engine

    def __getattr__(self, name):
        if name not in ALL_EVENTS:
            raise AttributeError(
                f"unknown intercept event: {name!r} "
                f"(known: {sorted(ALL_EVENTS)})")
        return _EventDecorator(self._engine, name)


class _EventDecorator:
    """The thing returned by `engine.intercept.memory_read` etc.

    Two call shapes are supported so analysts can omit selectors:

      @engine.intercept.memory_read
      def handler(ctx, addr, size): ...

      @engine.intercept.memory_read(addr_range=("g", 8))
      def handler(ctx, addr, size): ...
    """

    def __init__(self, engine, event):
        self._engine = engine
        self._event = event

    def __call__(self, *args, **kwargs):
        # Bare-decorator form: @engine.intercept.memory_read
        if args and not kwargs and callable(args[0]) and len(args) == 1:
            return self._register(args[0], {})
        # Parameterized form: @engine.intercept.memory_read(name=...)
        def deco(fn):
            return self._register(fn, kwargs)
        return deco

    def _register(self, fn, selector_kwargs):
        selector = make_selector(self._engine.layout, **selector_kwargs)
        self._engine._intercepts.register(self._event, selector, fn)
        return fn
