# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Address-strategy plumbing for symbolic-address suspensions.

The substrate raises a `MemAddrContinuation` whenever a load or store
hits a symbolic address. The engine asks an `AddressStrategy` for one
or more `Decision`s; today the only Decision variant is `ConcretizeTo`,
but the type is the seam Phase 6 widens with `SplitByRegion` and
`ConstrainTo`.

`ConcretizeViaSolver` attaches `addr_var == k` as `extra_constraint`
when picking `k` from a model so the child path's solver agrees with
the executed address — without that the path's constraint set silently
diverges from the substrate's chosen address.
"""

from abc import ABC, abstractmethod
from dataclasses import dataclass
from typing import Iterable, Optional


@dataclass(frozen=True)
class Decision:
    """Base for what an `AddressStrategy.next_decisions(...)` returns.

    Today only `ConcretizeTo` exists; Phase 6 will add `SplitByRegion`
    and `ConstrainTo` as sibling dataclasses (not tagged-union fields)
    so the engine's `isinstance` ladder in `_handle_suspension` is the
    place where new variants gain semantics — and an unhandled variant
    fails loudly rather than silently returning nothing.
    """


@dataclass(frozen=True)
class ConcretizeTo(Decision):
    """Resume the suspension with `addr` as the concrete value.

    `extra_constraint`, when set, is asserted on the child path's
    `path_condition` (and the path's solver invalidated) so the path's
    view of the address remains consistent with the chosen int. The
    solver-driven strategy uses this to attach `addr_var == k`.
    """
    addr: int
    extra_constraint: Optional[object] = None  # z3.BoolRef when set


class Suspension:
    """Read-only view over the substrate's MemAddrContinuation fork
    entry, surfaced to strategies. Mirrors today's dict but with named
    attributes so strategy code reads naturally."""

    __slots__ = ("address_expr", "address_eid", "size", "is_write",
                 "path", "layout", "solver")

    def __init__(self, *, address_expr, address_eid, size, is_write,
                 path, layout, solver):
        self.address_expr = address_expr
        self.address_eid = address_eid
        self.size = size
        self.is_write = is_write
        self.path = path
        self.layout = layout
        self.solver = solver


class AddressStrategy(ABC):
    """One method: pick decisions for a single suspension.

    Decisions must be returned in a stable order — the engine forks
    paths in that order, and `docs/symex-vision.md` requires "same
    input ⇒ same path order." When `max_models` is set, the strategy
    itself caps its own output; the engine treats `len(out) >=
    max_models` as the truncation signal.
    """

    max_models: Optional[int] = None

    @abstractmethod
    def next_decisions(self, suspension: "Suspension") -> Iterable[Decision]:
        ...


class ConcretizeFinite(AddressStrategy):
    """Explicit list of concrete addresses to fork on."""

    def __init__(self, addrs):
        self._addrs = [int(a) for a in addrs]

    def next_decisions(self, _suspension):
        return [ConcretizeTo(a) for a in self._addrs]


class ConcretizePointerSet(AddressStrategy):
    """Resolve named globals/functions through a layout.

    Pass an explicit `names` list, or use `.functions(layout)` /
    `.globals(layout)` to take everything of a kind. Names that don't
    resolve are silently skipped — a layout that doesn't know a name
    isn't an error, it's just a candidate that won't fire.
    """

    def __init__(self, names, *, layout=None):
        self._names = list(names)
        self._layout = layout

    @classmethod
    def functions(cls, layout):
        return cls(list(layout.functions().keys()), layout=layout)

    @classmethod
    def globals(cls, layout):
        return cls(list(layout.globals().keys()), layout=layout)

    def next_decisions(self, suspension):
        layout = self._layout if self._layout is not None else suspension.layout
        if layout is None:
            return []
        out = []
        for name in self._names:
            try:
                out.append(ConcretizeTo(int(layout[name])))
            except KeyError:
                continue
        return out


class ConcretizeByRegion(AddressStrategy):
    """Fork one path per overlapping layout region.

    Phase 5 ships the "constrain to region base" form — emits
    `ConcretizeTo(base)` per region in deterministic order. Phase 6
    will widen the Decision to `SplitByRegion` so the in-region offset
    stays symbolic.
    """

    def __init__(self, layout, *, max_models=None):
        self._layout = layout
        self.max_models = max_models

    def next_decisions(self, _suspension):
        regions = sorted(self._layout.globals().items())
        out = []
        for _name, (base, _size) in regions:
            out.append(ConcretizeTo(int(base)))
            if self.max_models is not None and len(out) >= self.max_models:
                break
        return out


class ConcretizeViaSolver(AddressStrategy):
    """Enumerate up to `max_models` distinct satisfying addresses by
    asking a fresh z3 solver for models, blocking each result before
    asking for the next.

    A *fresh* solver is used (not `path.solver`) so the model-blocking
    constraints don't leak into the path. Each `ConcretizeTo(k)` carries
    `addr_var == k` as `extra_constraint`; the engine appends that to
    the child path's path_condition so the path's view of the address
    stays consistent with the executed value.
    """

    def __init__(self, *, max_models=8):
        self.max_models = int(max_models)

    def next_decisions(self, suspension):
        addr_expr = suspension.address_expr
        if addr_expr is None:
            return []
        try:
            import z3
        except ImportError:
            return []
        if not isinstance(addr_expr, z3.ExprRef):
            return []
        s = z3.Solver()
        for c in suspension.path.path_condition:
            s.add(c)
        out = []
        remaining = self.max_models
        while remaining > 0:
            if s.check() != z3.sat:
                break
            m = s.model()
            try:
                v = m.eval(addr_expr, model_completion=True).as_long()
            except Exception:  # noqa: BLE001
                break
            out.append(v)
            s.add(addr_expr != v)
            remaining -= 1
        out.sort()
        return [ConcretizeTo(v, extra_constraint=(addr_expr == v))
                for v in out]


class _CallableStrategy(AddressStrategy):
    """Wrap a legacy `concretize=lambda fork: [...]` callable so the
    rest of the engine can speak Decisions uniformly."""

    def __init__(self, fn):
        self._fn = fn

    def next_decisions(self, suspension):
        addrs = self._fn({
            "state": None,
            "address": suspension.address_expr,
            "address_eid": suspension.address_eid,
            "size": suspension.size,
            "is_write": suspension.is_write,
        })
        return [ConcretizeTo(int(a)) for a in addrs]


def _coerce_strategy(thing):
    if isinstance(thing, AddressStrategy):
        return thing
    if callable(thing):
        return _CallableStrategy(thing)
    raise TypeError(f"unrecognized address strategy: {thing!r}")
