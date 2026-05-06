# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Sink oracles for the symbolic-execution engine.

A `Sink` consumes a policy event (after-phase) and decides whether the
event constitutes a `Finding` — a reproducible bug witness recorded
on the path. Three built-ins ship in Phase 6:

- `OOBSink`        — out-of-bounds reads and writes.
- `NullDerefSink`  — null-pointer reads and writes.
- `DivByZeroSink`  — udiv/sdiv/urem/srem with a zero divisor.

Each sink has two modes:

- **concrete**: the relevant value (address, divisor) is a Python int
  at the event. The sink does a simple numeric check; no solver call.
  Concrete-mode is what fires end-to-end in Phase 6 because the
  substrate's `ptr_add` / `ptr_diff` / `ptr_offset` collapse
  symbolic indices before they reach a memory event (deferred to
  Phase 7).
- **symbolic**: the relevant value is a z3 expression. The sink asks
  `path_condition ∧ <bad>` for sat and records the model as the
  witness. Symbolic-mode for memory ops fires only on synthesized
  fixtures in Phase 6; for `DivByZeroSink` it fires organically when
  an intercept produces a symbolic divisor (binary_op already
  dispatches through Python).

Sinks fire after the policy event in the same dispatcher pass as
observers — observers see the event, then sinks see the event, then
control returns to the substrate. A sink registered with
`fatal=True` terminates the path on a hit; default is non-fatal so
all reachable sinks are surfaced from one entry.
"""

from abc import ABC, abstractmethod
from dataclasses import dataclass, field
from typing import Optional

from .dispatch import _z3_module
from .events import (
    EventKind, MEMORY_READ, MEMORY_WRITE, Terminal,
)


@dataclass
class Finding:
    """One sink hit: a reproducible bug witness on a path.

    `kind` is a short string: "oob_read", "oob_write", "null_read",
    "null_write", "div_by_zero", "rem_by_zero".
    `addr_eid` is the operand entity-id whose value triggered the sink.
    `step` is `path.steps` at fire time.
    `witness` is `{name: int}` from a z3 model in symbolic-addr mode;
    empty dict in concrete-addr mode (the strategy's enumerated
    address is itself the witness).
    `region` is the layout region's name, or None when the access
    landed outside any layout region.
    `mode` is "concrete" or "symbolic".
    """

    kind: str
    addr_eid: Optional[int]
    step: int
    witness: dict = field(default_factory=dict)
    region: Optional[str] = None
    mode: str = "concrete"


class Sink(ABC):
    """Sinks fire after the policy event (same timing as observers).
    Returning a `Finding` records it on `ctx.path.findings`; returning
    `None` does nothing.

    Each sink declares which event kinds it cares about; the registry
    only invokes `check(...)` when the dispatched event matches.
    """

    @property
    @abstractmethod
    def event_kinds(self) -> tuple:
        """Tuple of event kinds (strings) this sink subscribes to."""

    @abstractmethod
    def check(self, event_kind, ctx, payload) -> Optional[Finding]:
        ...


class OOBSink(Sink):
    """Out-of-bounds memory access detector.

    Concrete-addr mode: `ctx.layout.region_containing(addr)` finds the
    region; if no region claims the address, or the access extends
    past the region's end, it's OOB.

    Symbolic-addr mode: when `addr` is a z3 expression and the path
    has a `_region_at_suspension` set (from `SplitByRegion`),
    `path_condition ∧ ¬(addr ∈ region)` is asked for sat. A model
    constitutes the witness.
    """

    @property
    def event_kinds(self) -> tuple:
        return (MEMORY_READ, MEMORY_WRITE)

    def check(self, event_kind, ctx, payload):
        addr = payload.get("addr")
        size = int(payload.get("size", 1) or 1)
        kind = ("oob_write" if event_kind == MEMORY_WRITE else "oob_read")

        if isinstance(addr, int) and not isinstance(addr, bool):
            return self._check_concrete(ctx, payload, addr, size, kind)

        z3 = _z3_module()
        if z3 is None or not isinstance(addr, z3.ExprRef):
            return None
        return self._check_symbolic(ctx, payload, addr, size, kind, z3)

    @staticmethod
    def _check_concrete(ctx, payload, addr, size, kind):
        layout = ctx.layout
        if layout is None:
            return None
        region = layout.region_containing(addr)
        addr_eid = payload.get("addr_eid")
        path = ctx.path
        step = path.steps if path is not None else 0
        if region is not None:
            end = region.base + region.size
            if addr + size > end or addr < region.base:
                return Finding(kind=kind, addr_eid=addr_eid, step=step,
                                witness={}, region=region.name,
                                mode="concrete")
            return None
        # Address sits outside every layout region. To distinguish a
        # real buffer-overflow (the strategy resolved a suspension to
        # an OOB address) from a substrate-internal access (parameter
        # slot, return slot, etc., outside the analyst's layout), only
        # fire when the path has a MEMADDR_CONCRETIZE event for this
        # exact address — i.e., this access *is* the resolution of a
        # symbolic-address suspension. The matching region is the one
        # closest before `addr` (the one the analyst presumably
        # intended).
        if path is None or not OOBSink._is_resolved_suspension(path, addr):
            return None
        prev = OOBSink._region_just_before(layout, addr)
        return Finding(kind=kind, addr_eid=addr_eid, step=step,
                        witness={}, region=(prev.name if prev else None),
                        mode="concrete")

    @staticmethod
    def _is_resolved_suspension(path, addr):
        """True iff path.events contains a MEMADDR_CONCRETIZE entry
        whose `address` equals `addr` — i.e., this memory access is
        the resolution of a strategy-driven suspension, not a
        substrate-internal access."""
        from .events import EventKind
        for entry in path.events:
            if entry.get("kind") == EventKind.MEMADDR_CONCRETIZE \
                    and entry.get("address") == addr:
                return True
        return False

    @staticmethod
    def _region_just_before(layout, addr):
        """Find the highest-base region whose end is at or before
        `addr`, within `max(region.size, 64)` of `addr`. None if no
        such region (likely a substrate-internal access)."""
        candidate = None
        for r in layout.regions():
            if r.kind not in ("global", "lazy"):
                continue
            r_end = r.base + r.size
            if r_end > addr:
                continue
            spill = max(r.size, 64)
            if (addr - r_end) > spill:
                continue
            if candidate is None or r.base > candidate.base:
                candidate = r
        return candidate

    @staticmethod
    def _check_symbolic(ctx, payload, addr, size, kind, z3):
        path = ctx.path
        if path is None:
            return None
        layout = ctx.layout
        region_name = getattr(path, "_region_at_suspension", None)
        region = (layout.region_for_name(region_name)
                  if (region_name is not None and layout is not None)
                  else None)
        if region is None:
            return None
        out_of_bounds = z3.Or(
            z3.ULT(addr, region.base),
            z3.UGT(addr + size, region.base + region.size))
        s = z3.Solver()
        for c in path.path_condition:
            s.add(c)
        s.add(out_of_bounds)
        if s.check() != z3.sat:
            return None
        m = s.model()
        return Finding(
            kind=kind, addr_eid=payload.get("addr_eid"),
            step=path.steps,
            witness=_model_to_witness(m),
            region=region.name, mode="symbolic")


class NullDerefSink(Sink):
    """Null-pointer dereference detector. Concrete: `addr == 0`.
    Symbolic: `path_condition ∧ (addr == 0)` sat."""

    @property
    def event_kinds(self) -> tuple:
        return (MEMORY_READ, MEMORY_WRITE)

    def check(self, event_kind, ctx, payload):
        addr = payload.get("addr")
        kind = ("null_write" if event_kind == MEMORY_WRITE else "null_read")
        addr_eid = payload.get("addr_eid")
        path = ctx.path

        if isinstance(addr, int) and not isinstance(addr, bool):
            if addr != 0:
                return None
            step = path.steps if path is not None else 0
            return Finding(kind=kind, addr_eid=addr_eid, step=step,
                            witness={}, region=None, mode="concrete")

        z3 = _z3_module()
        if z3 is None or not isinstance(addr, z3.ExprRef):
            return None
        if path is None:
            return None
        s = z3.Solver()
        for c in path.path_condition:
            s.add(c)
        s.add(addr == 0)
        if s.check() != z3.sat:
            return None
        m = s.model()
        return Finding(
            kind=kind, addr_eid=addr_eid, step=path.steps,
            witness=_model_to_witness(m),
            region=getattr(path, "_region_at_suspension", None),
            mode="symbolic")


def _is_div_or_rem(op):
    """Return ("div"|"rem", is_signed) if `op` is a divide or remainder
    opcode of any width, else None.

    Drives off `mx.ir.OpCode(int(op)).name` so this stays in
    lock-step with the C++ enum (no hand-maintained int table).
    """
    import multiplier as mx
    try:
        name = mx.ir.OpCode(int(op)).name
    except ValueError:
        return None
    if name.startswith("UDIV_"): return ("div", False)
    if name.startswith("DIV_"):  return ("div", True)
    if name.startswith("UREM_"): return ("rem", False)
    if name.startswith("REM_"):  return ("rem", True)
    return None


class DivByZeroSink(Sink):
    """Division-by-zero detector. Fires on `binary_op` events for
    udiv/sdiv/urem/srem. Concrete: `divisor == 0`. Symbolic:
    `path_condition ∧ (divisor == 0)` sat.

    Note: `binary_op` is dispatched through Python (Phase 4 wired
    this), so a divisor reaching the binary_op event can be a
    z3 expression organically — this is the one Phase 6 sink that
    fires symbolic-mode end-to-end.
    """

    @property
    def event_kinds(self) -> tuple:
        return (EventKind.BINARY_OP,)

    def check(self, event_kind, ctx, payload):
        if event_kind != EventKind.BINARY_OP:
            return None
        op = payload.get("op")
        if op is None:
            return None
        info = _is_div_or_rem(op)
        if info is None:
            return None
        kind_word, _signed = info
        rhs = payload.get("rhs")
        path = ctx.path
        addr_eid = payload.get("rhs_eid")

        if isinstance(rhs, int) and not isinstance(rhs, bool):
            if rhs != 0:
                return None
            step = path.steps if path is not None else 0
            return Finding(
                kind=("div_by_zero" if kind_word == "div"
                      else "rem_by_zero"),
                addr_eid=addr_eid, step=step,
                witness={}, region=None, mode="concrete")

        z3 = _z3_module()
        if z3 is None or not isinstance(rhs, z3.ExprRef):
            return None
        if path is None:
            return None
        s = z3.Solver()
        for c in path.path_condition:
            s.add(c)
        s.add(rhs == 0)
        if s.check() != z3.sat:
            return None
        m = s.model()
        return Finding(
            kind=("div_by_zero" if kind_word == "div" else "rem_by_zero"),
            addr_eid=addr_eid, step=path.steps,
            witness=_model_to_witness(m),
            region=None, mode="symbolic")


def _model_to_witness(model):
    """Adapt a z3 `model` into a plain `{name: int}` dict.
    Non-numeric models drop their entry; the witness still records
    every name that *did* extract."""
    out = {}
    for d in model.decls():
        try:
            v = model[d]
            if v is None:
                continue
            out[d.name()] = v.as_long()
        except Exception:  # noqa: BLE001
            continue
    return out


class SinkRegistry:
    """Per-engine registry of sinks. Add via
    `engine.sinks.add(OOBSink())` (non-fatal) or
    `engine.sinks.add(OOBSink(), fatal=True)` (terminates the path
    on hit with `Terminal.SINK_HIT`).

    Sinks fire after the policy event in dispatch order. Findings are
    appended to `ctx.path.findings` and tag the path with
    `f"sink:{kind}"`.
    """

    def __init__(self):
        self._sinks: list[tuple[Sink, bool]] = []

    def add(self, sink: Sink, *, fatal: bool = False) -> None:
        self._sinks.append((sink, bool(fatal)))

    def __len__(self):
        return len(self._sinks)

    def __iter__(self):
        return iter(self._sinks)

    def fire(self, event_kind, ctx, payload):
        """Run every sink that subscribes to `event_kind`. Returns
        the number of findings recorded."""
        if not self._sinks:
            return 0
        path = ctx.path
        n = 0
        for sink, fatal in self._sinks:
            if event_kind not in sink.event_kinds:
                continue
            try:
                f = sink.check(event_kind, ctx, payload)
            except Exception:  # noqa: BLE001
                continue
            if f is None:
                continue
            if path is not None:
                path.findings.append(f)
                path.tags.add(f"sink:{f.kind}")
                path.events.append({
                    "kind": EventKind.SINK_FIRED,
                    "sink_kind": f.kind,
                    "addr_eid": f.addr_eid,
                    "region": f.region,
                    "mode": f.mode,
                    "step": f.step,
                })
            n += 1
            if fatal and path is not None:
                path.terminal = Terminal.SINK_HIT
        return n
