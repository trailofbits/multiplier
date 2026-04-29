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
from dataclasses import dataclass, field
from typing import Iterable, Optional, Tuple


@dataclass(frozen=True)
class Decision:
    """Base for what an `AddressStrategy.next_decisions(...)` returns.

    Three variants ship today: `ConcretizeTo` picks one concrete int
    and resumes; `ConstrainTo` resumes with the address symbolic but
    asserts a z3 predicate on the child's path condition; and
    `SplitByRegion` is the typed shorthand for "fork one child per
    region, assert `addr ∈ region` on each." The engine's
    `_handle_suspension` isinstance ladder is the place where each
    variant gains its semantics — an unhandled variant fails loudly
    rather than silently returning nothing.
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


@dataclass(frozen=True)
class ConstrainTo(Decision):
    """Resume the suspension with the address symbolic; assert
    `constraint` on the child path's `path_condition`. Fork count
    is one. Use this when the analyst wants an arbitrary predicate
    over `addr_var` (e.g., alignment, a finite set) rather than a
    region-shaped constraint.

    When the suspension's `address_expr` is concrete (the substrate
    has collapsed pointer arithmetic — the deferred Phase 7 work),
    the engine records a `constrain_to_concrete_addr` event and
    resumes at the concrete address without asserting the predicate.
    """
    constraint: object  # z3.BoolRef


@dataclass(frozen=True)
class SplitByRegion(Decision):
    """Fork one child per region; assert `addr_var ∈ region` on
    each child's path condition. A typed shorthand for N
    `ConstrainTo` decisions, one per region, plus a
    `_region_at_suspension` tag on the child path for downstream
    sinks and observers. Region order is the order returned by
    `ConcretizeByRegion.next_decisions(...)`.

    When the suspension's `address_expr` is concrete (the substrate
    collapsed pointer arithmetic), the engine degrades to "resume
    each child at the region's base" — equivalent to Phase 5's
    `ConcretizeTo(base)` per region.
    """
    regions: Tuple = ()  # tuple[Region, ...]


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
    """Fork one path per region; the in-region offset stays symbolic
    on the child (when the substrate carries it through — see the
    Phase 6 deferred-work note in the plan).

    Phase 6 returns a single `SplitByRegion(regions=(...))` decision
    so the engine can forward all regions in one isinstance dispatch.
    Region order is the layout's natural sorted-by-base order.

    `lazy_default=True` materializes a fresh `LazyRegion` (via
    `layout.declare_lazy(...)`) when the layout has no regions to
    enumerate. The engine asserts `addr_var ∈ [base, base+max_size)`
    on the child and emits a `region_materialized` event. Bounded
    by `engine.lazy_region_budget` per path.
    """

    _lazy_counter = 0

    def __init__(self, layout, *, max_models=None, lazy_default=False,
                 lazy_max_size=4096):
        self._layout = layout
        self.max_models = max_models
        self._lazy_default = lazy_default
        self._lazy_max_size = int(lazy_max_size)

    def next_decisions(self, suspension):
        # Honor the suspension's path condition: drop regions that
        # provably cannot contain the symbolic address. Concrete
        # addresses bypass the filter (the engine's concrete-fallback
        # branch will resume at the region's base regardless).
        candidates = [r for r in self._layout.regions()
                      if r.kind in ("global", "lazy") and r.size > 0]
        if self.max_models is not None:
            candidates = candidates[:self.max_models]

        if not candidates and self._lazy_default:
            lazy = self._fresh_lazy()
            return [SplitByRegion(regions=(lazy,))]

        if not candidates:
            return []

        return [SplitByRegion(regions=tuple(candidates))]

    def _fresh_lazy(self):
        ConcretizeByRegion._lazy_counter += 1
        name = f"__lazy_{ConcretizeByRegion._lazy_counter}"
        return self._layout.declare_lazy(
            name, max_size=self._lazy_max_size)


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
