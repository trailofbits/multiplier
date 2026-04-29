# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""`engine.observe.<event>(**selector)` decorator namespace.

Mirrors `intercept.py` but registers observers (listen-only handlers).
Defaults to the `after` phase — a use-case-driven choice: by the time
an observer runs, the chosen value is known, so most analysts want to
see the resolved decision. Use `engine.observe.before.<event>` for the
narrower pre-dispatch window.

Observer dispatch is "fire all in registration order". An exception in
one observer does NOT propagate; the dispatcher records it as an
`observer_error` entry on `path.events` and continues with the next
observer (and the rest of execution).
"""

from .dispatch import make_selector
from .events import ALL_EVENTS, Phase


class _PhaseDispatcher:
    """`engine.observe.before.<event>` / `engine.observe.after.<event>`.

    Returns event-specific decorators bound to the named phase.
    """

    def __init__(self, engine, phase):
        self._engine = engine
        self._phase = phase

    def __getattr__(self, name):
        if name not in ALL_EVENTS:
            raise AttributeError(
                f"unknown observe event: {name!r} "
                f"(known: {sorted(ALL_EVENTS)})")
        return _ObserveDecorator(self._engine, name, self._phase)


class ObserveDispatcher:
    """Built once per `SymExEngine` and exposed as `engine.observe`.

    Top-level calls (`engine.observe.<event>`) default to `after`. Use
    `engine.observe.before.<event>` to register a pre-dispatch
    observer.
    """

    def __init__(self, engine):
        self._engine = engine
        self.before = _PhaseDispatcher(engine, Phase.BEFORE)
        self.after = _PhaseDispatcher(engine, Phase.AFTER)

    def __getattr__(self, name):
        if name not in ALL_EVENTS:
            raise AttributeError(
                f"unknown observe event: {name!r} "
                f"(known: {sorted(ALL_EVENTS)})")
        return _ObserveDecorator(self._engine, name, Phase.AFTER)


class _ObserveDecorator:
    """Returned by `engine.observe.<event>` (or its phase namespaces).

    Same call-shape ergonomics as the intercept decorators.
    """

    def __init__(self, engine, event, phase):
        self._engine = engine
        self._event = event
        self._phase = phase

    def __call__(self, *args, **kwargs):
        if args and not kwargs and callable(args[0]) and len(args) == 1:
            return self._register(args[0], {})

        def deco(fn):
            return self._register(fn, kwargs)
        return deco

    def _register(self, fn, selector_kwargs):
        selector = make_selector(self._engine.layout, **selector_kwargs)
        self._engine._observers.register(
            (self._event, self._phase), selector, fn)
        return fn
