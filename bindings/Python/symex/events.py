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

from enum import StrEnum


class EventKind(StrEnum):
    MEMORY_READ = "memory_read"
    MEMORY_WRITE = "memory_write"
    SYMBOLIC_LOAD = "symbolic_load"
    SYMBOLIC_STORE = "symbolic_store"
    GLOBAL_READ = "global_read"
    GLOBAL_WRITE = "global_write"
    CALL = "call"
    INDIRECT_CALL = "indirect_call"
    BRANCH = "branch"
    LOOP = "loop"
    CONCRETIZE = "concretize"
    BINARY_OP = "binary_op"
    MEMADDR_CONCRETIZE = "memaddr_concretize"
    CONCRETIZATION_TRUNCATED = "concretization_truncated"
    CONCRETIZATION_INFEASIBLE = "concretization_infeasible"
    OBSERVER_ERROR = "observer_error"
    INTERCEPT_ERROR = "intercept_error"
    REGION_MATERIALIZED = "region_materialized"
    LAZY_BUDGET_EXHAUSTED = "lazy_budget_exhausted"
    CONSTRAIN_TO_CONCRETE_ADDR = "constrain_to_concrete_addr"
    SPLIT_BY_REGION = "split_by_region"
    SINK_FIRED = "sink_fired"
    BLOCK_ENTER = "block_enter"
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
CALL = EventKind.CALL
INDIRECT_CALL = EventKind.INDIRECT_CALL
BRANCH = EventKind.BRANCH
LOOP = EventKind.LOOP
CONCRETIZE = EventKind.CONCRETIZE
BLOCK_ENTER = EventKind.BLOCK_ENTER
ADDRESS_FOR = EventKind.ADDRESS_FOR
ADDRESS_RESOLVED = EventKind.ADDRESS_RESOLVED
INDIRECT_CALL_RESOLVED = EventKind.INDIRECT_CALL_RESOLVED


ALL_EVENTS = frozenset({
    MEMORY_READ, MEMORY_WRITE,
    SYMBOLIC_LOAD, SYMBOLIC_STORE,
    GLOBAL_READ, GLOBAL_WRITE,
    CALL, INDIRECT_CALL,
    BRANCH, LOOP, CONCRETIZE,
    BLOCK_ENTER,
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
    # Cosmetic placeholder used only by `path.summary()` when the path
    # is still live (`path.terminal is None`) — never actually written
    # to a Path.
    LIVE = "live"


class StepResultKind(StrEnum):
    """Kinds the C++ substrate returns in the `result` tuple."""
    COMPLETED = "completed"
    ERROR = "error"
    BUDGET = "budget"
    BRANCH = "branch"
    SUSPENDED = "suspended"


class Strategy(StrEnum):
    BFS = "bfs"
    DFS = "dfs"


class CallAction(StrEnum):
    """Substrate-facing tag for the second slot of resolve_call's
    return tuple: ("skip", value) replaces the call with `value`;
    ("model", value) is reserved for future modeled-call shapes."""
    SKIP = "skip"
    MODEL = "model"


# Wire-protocol tag for "this Python value is a pointer to address N".
# The C++ substrate inspects 2-tuples of shape `(VALUE_TAG_PTR, N)` to
# recognise live pointers; keep this string stable.
VALUE_TAG_PTR = "ptr"


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
