# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Canonical event / phase / direction / terminal / strategy names, plus
the queryable EventLog wrapper that backs `path.events`.

Each name is a `StrEnum` so comparisons against bare strings still work
(call-site code may look for `path.terminal == "completed"` and the
substrate hands back string-keyed result tuples), but call sites can
reference the typed members instead of repeating the literals.
"""

from dataclasses import dataclass
from enum import StrEnum
from typing import Any, Optional


class EventKind(StrEnum):
    MEMORY_READ = "memory_read"
    MEMORY_WRITE = "memory_write"
    SYMBOLIC_LOAD = "symbolic_load"
    SYMBOLIC_STORE = "symbolic_store"
    GLOBAL_READ = "global_read"
    GLOBAL_WRITE = "global_write"
    GLOBAL_INITIALIZED = "global_initialized"
    CALL = "call"
    INDIRECT_CALL = "indirect_call"
    BRANCH = "branch"
    SWITCH_CASE = "switch_case"
    SWITCH_DEFAULT = "switch_default"
    LOOP = "loop"
    CONCRETIZE = "concretize"
    BINARY_OP = "binary_op"
    MEMADDR_CONCRETIZE = "memaddr_concretize"
    CONCRETIZATION_TRUNCATED = "concretization_truncated"
    CONCRETIZATION_INFEASIBLE = "concretization_infeasible"
    REGION_MATERIALIZED = "region_materialized"
    LAZY_BUDGET_EXHAUSTED = "lazy_budget_exhausted"
    CONSTRAIN_TO_CONCRETE_ADDR = "constrain_to_concrete_addr"
    SPLIT_BY_REGION = "split_by_region"
    SINK_FIRED = "sink_fired"
    BLOCK_ENTER = "block_enter"
    INSTRUCTION = "instruction"
    # Phase 9: address-resolution telemetry
    ADDRESS_FOR = "address_for"
    ADDRESS_RESOLVED = "address_resolved"
    INDIRECT_CALL_RESOLVED = "indirect_call_resolved"


# Module-level aliases — analysts and dispatcher import these by name.
MEMORY_READ = EventKind.MEMORY_READ
MEMORY_WRITE = EventKind.MEMORY_WRITE
SYMBOLIC_LOAD = EventKind.SYMBOLIC_LOAD
SYMBOLIC_STORE = EventKind.SYMBOLIC_STORE
GLOBAL_READ = EventKind.GLOBAL_READ
GLOBAL_WRITE = EventKind.GLOBAL_WRITE
GLOBAL_INITIALIZED = EventKind.GLOBAL_INITIALIZED
CALL = EventKind.CALL
INDIRECT_CALL = EventKind.INDIRECT_CALL
BRANCH = EventKind.BRANCH
SWITCH_CASE = EventKind.SWITCH_CASE
SWITCH_DEFAULT = EventKind.SWITCH_DEFAULT
LOOP = EventKind.LOOP
CONCRETIZE = EventKind.CONCRETIZE
BLOCK_ENTER = EventKind.BLOCK_ENTER
INSTRUCTION = EventKind.INSTRUCTION
ADDRESS_FOR = EventKind.ADDRESS_FOR
ADDRESS_RESOLVED = EventKind.ADDRESS_RESOLVED
INDIRECT_CALL_RESOLVED = EventKind.INDIRECT_CALL_RESOLVED


ALL_EVENTS = frozenset({
    MEMORY_READ, MEMORY_WRITE,
    SYMBOLIC_LOAD, SYMBOLIC_STORE,
    GLOBAL_READ, GLOBAL_WRITE, GLOBAL_INITIALIZED,
    CALL, INDIRECT_CALL,
    BRANCH, SWITCH_CASE, SWITCH_DEFAULT, LOOP, CONCRETIZE,
    BLOCK_ENTER, INSTRUCTION,
    ADDRESS_FOR, ADDRESS_RESOLVED,
    INDIRECT_CALL_RESOLVED,
})


class Phase(StrEnum):
    BEFORE = "before"
    AFTER = "after"


class BranchDirection(StrEnum):
    TRUE = "true"
    FALSE = "false"
    UNKNOWN = "?"


class StopNow(BaseException):
    """Raise from any hook to halt the current slice immediately.

    The C++ interpreter catches this via the existing exception-propagation
    mechanism, clears the work stack, and surfaces it back to the Python
    driver.  `_step_one` intercepts it and treats the path as stopped.

    Prefer `ctx.stop_now(terminal=...)` over raising this directly so the
    terminal value is recorded before the interpreter halts.
    """


class Terminal(StrEnum):
    """Reasons a path stops stepping. Strings rather than ints so the
    legacy `path.terminal == "completed"` checks keep working."""
    COMPLETED = "completed"
    ERROR = "error"
    BUDGET = "budget"
    UNKNOWN = "unknown"
    STOPPED = "stopped"
    STUCK_BRANCH = "stuck-branch"
    STUCK_SUSPENSION = "stuck-suspension"
    CONCRETIZATION_REFUSED = "concretization-refused"
    INFEASIBLE = "infeasible"
    SINK_HIT = "sink-hit"
    # Phase 9: intercept.indirect_call returned None, refusing the call.
    UNRESOLVED_CALL = "unresolved-call"
    # GLOBAL_PTR suspended on an unresolved entity and the address_for
    # chain produced no answer — we can't make forward progress.
    UNRESOLVED_GLOBAL = "unresolved-global"
    # Cosmetic placeholder used only by `path.summary()` when the path
    # is still live (`path.terminal is None`) — never actually written
    # to a Path.
    LIVE = "live"


# ===========================================================================
# Step result + fork shapes
#
# The C++ substrate's `step()` call hands the Python driver one of these
# typed result objects (in the dict's "result" slot) plus a list of typed
# fork objects (in "forks"). Drivers dispatch via `isinstance`; the type
# IS the discriminator. No string tags, no positional unpacking.
# ===========================================================================

@dataclass(frozen=True)
class Completed:
    return_value: Any


@dataclass(frozen=True)
class Errored:
    error_kind: int


@dataclass(frozen=True)
class Budget:
    steps: int


@dataclass(frozen=True)
class Branch:
    condition: Any
    true_block: int
    false_block: int


@dataclass(frozen=True)
class Switch:
    selector: Any
    selector_eid: int


@dataclass(frozen=True)
class MemAddrSuspension:
    address: Any
    address_eid: int
    size: int
    is_write: bool
    is_call_target: bool


@dataclass(frozen=True)
class GlobalSuspension:
    entity_id: int
    instruction_id: int


@dataclass(frozen=True)
class Suspended:
    """Generic fallback for continuation kinds the driver doesn't
    recognize specifically — carries only a description."""
    description: str


@dataclass(frozen=True)
class Skip:
    """Explicit "skip this call, use `value` as the return slot."

    Most call handlers can return their replacement value directly —
    the substrate treats any non-None return as a skip with that
    value, since None already means "fall through to inlining."
    `Skip(value)` is the disambiguator for the rare case where the
    intent is to skip with `None` (e.g. `ctx.default()`).
    """
    value: Any = None


# ---- Fork entries (one per resumption a continuation produces) ----

@dataclass
class BranchFork:
    state: Any
    direction: "BranchDirection"


@dataclass
class SwitchFork:
    state: Any
    selector: Any
    selector_eid: int
    cases: list  # list of (low, high, target_eid, target_block)
    default_block: Any
    default_block_eid: Optional[int]


@dataclass
class MemAddrFork:
    state: Any
    address: Any
    address_eid: int
    size: int
    is_write: bool


@dataclass
class GlobalFork:
    state: Any
    entity_id: int
    instruction_id: int


class Strategy(StrEnum):
    BFS = "bfs"
    DFS = "dfs"


# Endian lives in `_types` (a leaf module) since it's a fundamental
# constant used by Layout, MemView, Path, and the engine. Re-exported
# here for back-compat with existing `from .events import Endian` users.
from ._types import Endian  # noqa: E402,F401


_MISSING = object()


def _split_suffix(key):
    if "__" in key:
        field, _, suffix = key.rpartition("__")
        return field, suffix
    return key, None


def _match_one(entry, field, suffix, target):
    actual = entry.get(field, _MISSING)
    if actual is _MISSING:
        return False
    if suffix is None:
        return actual == target
    if suffix == "in":
        return actual in target
    if suffix == "between":
        lo, hi = target
        return lo <= actual <= hi
    if suffix == "gt":
        return actual > target
    if suffix == "lt":
        return actual < target
    if suffix == "ge":
        return actual >= target
    if suffix == "le":
        return actual <= target
    if suffix == "ne":
        return actual != target
    if suffix == "contains":
        if isinstance(actual, str):
            return target in actual
        try:
            return target in actual
        except TypeError:
            return False
    raise ValueError(f"unknown filter suffix: {suffix!r}")


def _match(entry, filters):
    for key, target in filters.items():
        field, suffix = _split_suffix(key)
        if not _match_one(entry, field, suffix, target):
            return False
    return True


class _FilterableList(list):
    """List subclass that adds Django-ORM-style predicate queries.

    Subclasses provide `_match(item, filters) -> bool` and optionally
    `_get_field(item, key)` (default: `item.get(key, None)` for dict-like
    items, `getattr(item, key, None)` otherwise). This base then derives
    `where` / `first` / `last` / `count` / `groupby` / `unique` from them.
    `where` returns a new instance of the same subclass so chaining
    (`a.where(...).where(...)`) preserves the type.
    """

    def _match(self, item, filters):
        raise NotImplementedError

    def _get_field(self, item, key):
        if hasattr(item, "get"):
            return item.get(key)
        return getattr(item, key, None)

    def where(self, **filters):
        cls = type(self)
        return cls(item for item in self if self._match(item, filters))

    def first(self, **filters):
        for item in self:
            if self._match(item, filters):
                return item
        return None

    def last(self, **filters):
        """Return the last item matching `filters`, or None."""
        found = None
        for item in self:
            if self._match(item, filters):
                found = item
        return found

    def count(self, **filters):
        return sum(1 for item in self if self._match(item, filters))

    def groupby(self, field) -> dict:
        """Partition items by the value of `field`. Returns
        `{field_value: <same subclass>}` preserving insertion order."""
        groups: dict = {}
        for item in self:
            val = self._get_field(item, field)
            groups.setdefault(val, []).append(item)
        cls = type(self)
        return {k: cls(v) for k, v in groups.items()}

    def unique(self, field) -> set:
        """Return the set of distinct values for `field` across all items."""
        return {self._get_field(item, field) for item in self}


class EventLog(_FilterableList):
    """List subclass with predicate queries.

    Inherits append/iter/indexing/len from `list` so existing code
    (`path.events.append(...)`, `path.events[-1]`, `len(path.events)`)
    keeps working unchanged. Filter kwargs use Django-ORM-style suffix
    grammar: `kind="memory_read"`, `addr__between=(lo, hi)`,
    `step__gt=10`, etc.
    """

    def _match(self, entry, filters):
        return _match(entry, filters)
