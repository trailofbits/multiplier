# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Hook dispatcher and selector compilation.

`InterceptorPolicy` is the single object passed to the C++ symbolic
substrate. It implements every hook the substrate consults
(`mem_read`, `mem_write`, `compare`, `binary_op`, `is_true`,
`resolve_branch`, `resolve_call`, etc.). Each event-dispatching method:

  1. Fires `before` observers for the event.
  2. Builds a chain from the registered handlers and a per-event
     default function. Each handler receives `next_hook` as its last
     positional argument; calling `next_hook(...)` forwards down the
     chain. Handlers compose; the dispatcher does no sentinel walking.
  3. Fires `after` observers for the event.
  4. Returns the chain's result (or `NotImplemented` to fall through
     to the C++ concrete fallback for the symbolic-address case).

`InterceptorPolicy` also propagates symbolic values across pure
operations (`compare`, `binary_op`, `unary_op`, `cast`) by emitting a
`SymExpr` whenever an operand is non-int, and forces forks on
non-concrete branch conditions by returning `None` from `is_true` and
`resolve_branch`. That keeps "the analyst's hooks produce symbolic
values; the substrate forks when one reaches a branch" working without
the analyst writing a propagation policy.
"""

import struct as _struct

from .ctx import Ctx
from .events import (
    MEMORY_READ, MEMORY_WRITE,
    GLOBAL_READ, GLOBAL_WRITE,
    CALL, INDIRECT_CALL,
    BRANCH, LOOP, CONCRETIZE,
)
from .lens import MemView, ArgsView


class SymExpr:
    """Default symbolic-value sentinel produced by InterceptorPolicy.

    The class shape (not a 2-tuple) avoids the substrate's
    `("ptr", N)` heuristic seeing a symbolic value as a pointer. The
    `kind`/`args` fields carry provenance for debugging and for Phase 4
    z3 lowering.
    """

    __slots__ = ("kind", "args")

    def __init__(self, kind, args=()):
        self.kind = kind
        self.args = args

    def __repr__(self):
        return f"SymExpr({self.kind!r}, {self.args!r})"

    def __bool__(self):
        raise TypeError(
            "SymExpr has no concrete truth value; route through is_true")


def extract_addr(addr):
    """Pull a concrete address out of the substrate's value form.

    The substrate hands the policy `("ptr", N)` for live pointers and
    bare ints occasionally; both normalize to an int. Anything else
    (e.g., SymExpr) yields None.
    """
    if isinstance(addr, tuple) and len(addr) == 2 and addr[0] == "ptr":
        return int(addr[1])
    if isinstance(addr, int) and not isinstance(addr, bool):
        return int(addr)
    return None


class _Selector:
    """Compiled selector. Stored once per registration; matched at
    dispatch time in constant-ish time.

    Selectors carry every attribute the analyst can pass; matching
    against an event filters by the attributes the event provides.
    Empty / `None` attributes match anything.
    """

    __slots__ = ("addr_range", "name", "eid", "func", "block",
                 "_layout", "_resolved_range")

    def __init__(self, addr_range=None, name=None, eid=None, func=None,
                 block=None, layout=None):
        self.addr_range = addr_range
        self.name = name
        self.eid = eid
        self.func = func
        self.block = block
        self._layout = layout
        self._resolved_range = None

    def matches_addr(self, addr):
        if self.addr_range is None:
            return True
        start, end = self._compute_range()
        return start <= addr < end

    def matches_name(self, candidate):
        if self.name is None:
            return True
        return candidate is not None and candidate == self.name

    def matches_eid(self, candidate):
        if self.eid is None:
            return True
        return candidate is not None and int(candidate) == int(self.eid)

    def matches_func(self, candidate_func):
        if self.func is None:
            return True
        if candidate_func is None:
            return False
        return self.func is candidate_func or self.func == candidate_func

    def matches_block(self, candidate_block):
        if self.block is None:
            return True
        if candidate_block is None:
            return False
        return int(self.block) == int(candidate_block)

    def _compute_range(self):
        if self._resolved_range is not None:
            return self._resolved_range
        ar = self.addr_range
        if not (isinstance(ar, tuple) and len(ar) == 2):
            raise ValueError(f"unrecognized addr_range: {ar!r}")
        a, b = ar
        if isinstance(a, str):
            if self._layout is None:
                raise ValueError(
                    "addr_range with a name requires the engine's layout")
            base = self._layout[a]
            self._resolved_range = (base, base + int(b))
        else:
            self._resolved_range = (int(a), int(b))
        return self._resolved_range


def make_selector(layout, **kwargs):
    """Compile a kwargs-style selector spec into a `_Selector` bound to
    the engine's layout. The layout is required only when an
    `addr_range` selector uses a global name."""
    return _Selector(
        addr_range=kwargs.get("addr_range"),
        name=kwargs.get("name"),
        eid=kwargs.get("eid"),
        func=kwargs.get("func"),
        block=kwargs.get("block"),
        layout=layout,
    )


class _Registry:
    """Per-event ordered list of `(selector, handler)` pairs.

    Phase 2 ships the linear-scan implementation. The shape is the same
    one Phase 6 will swap in for an interval tree; consumers must not
    depend on the underlying container.
    """

    def __init__(self):
        self._by_event = {}

    def register(self, event, selector, handler):
        self._by_event.setdefault(event, []).append((selector, handler))

    def lookup(self, event):
        return self._by_event.get(event, ())


class _Sentinel:
    __slots__ = ("_repr",)

    def __init__(self, name):
        self._repr = name

    def __repr__(self):
        return self._repr


# Private sentinels — never appear in analyst code. Returned by chain
# bottoms whose substrate translation is "let the substrate handle this
# itself" (call → inline; branch → enumerate edges).
_DEFER = _Sentinel("<defer>")
_FORK = _Sentinel("<fork>")


def _wrap(handler, downstream):
    """Bind a handler to its downstream tail.

    Defined as a named helper (not an in-loop lambda) so each iteration
    captures `handler` and `downstream` in its own closure. See the
    "closure binding" gotcha in docs/symex-phase2-compose-plan.md.
    """
    def call(*args, **kwargs):
        return handler(*args, next_hook=downstream, **kwargs)
    return call


def _build_chain(handlers, default_fn):
    """Compose `[h1, h2, h3]` over `default_fn` into a single callable.

    The chain is built right-to-left so that calling it invokes h1
    first; h1's `next_hook` is the rest of the chain (h2 → h3 →
    default_fn). Each handler decides whether to forward (call
    `next_hook(...)` and return its result) or short-circuit (return a
    value without calling `next_hook`).
    """
    chain = default_fn
    for h in reversed(handlers):
        chain = _wrap(h, chain)
    return chain


# ---- per-event default (chain bottom) functions -----------------------

def _make_default_mem_read(is_float):
    """Return the chain bottom for a memory_read event.

    Reads concrete bytes via the lens; for `is_float`, unpacks IEEE
    float32 / float64. Returns the loaded value.
    """
    def default(ctx, addr, size):
        data = ctx.mem.read_bytes(addr, size)
        if is_float and size == 4:
            return _struct.unpack("<f", data)[0]
        if is_float and size == 8:
            return _struct.unpack("<d", data)[0]
        return int.from_bytes(data, "little", signed=False)
    return default


def _make_default_mem_write(is_float):
    """Return the chain bottom for a memory_write event.

    Writes concrete bytes via the lens. Handles ints, ("ptr", N)
    pointer tuples, raw bytes, and IEEE floats. Returns None.
    """
    def default(ctx, addr, val, size):
        if isinstance(val, bool):
            val = int(val)
        if isinstance(val, int):
            ctx.mem.write_bytes(
                addr, val.to_bytes(size, "little", signed=(val < 0)))
            return None
        if isinstance(val, tuple) and len(val) == 2 and val[0] == "ptr":
            ctx.mem.write_bytes(
                addr, int(val[1]).to_bytes(size, "little", signed=False))
            return None
        if isinstance(val, (bytes, bytearray)):
            ctx.mem.write_bytes(addr, bytes(val))
            return None
        if isinstance(val, float):
            fmt = "<f" if size == 4 else "<d"
            ctx.mem.write_bytes(addr, _struct.pack(fmt, val))
            return None
        # Symbolic or otherwise unknown — drop. Phase 4 will replace
        # this with a typed write into the symbolic memory model.
        return None
    return default


def _default_call(ctx):
    """Chain bottom for a call event — defer to substrate inline."""
    return _DEFER


def _default_branch(ctx, condition):
    """Chain bottom for a branch event.

    Concrete conditions resolve to True / False naturally; symbolic
    conditions return `_FORK`, telling the InterceptorPolicy to hand
    control back to the substrate so it can enumerate edges via a
    BranchContinuation.
    """
    if isinstance(condition, (int, bool)):
        return condition != 0
    return _FORK


# -----------------------------------------------------------------------


class InterceptorPolicy:
    """Sole consumer of the C++ symbolic substrate's hook surface.

    Constructed fresh per step by the engine (because PythonPolicy
    re-binds method caches per construction). Holds a reference to the
    engine's intercept / observe registries plus the current `Path`,
    `Layout`, and concrete memory.

    Every C++ hook lands here. Each method (a) fires before observers,
    (b) builds and invokes the matching intercept chain, (c) fires
    after observers, (d) returns the chosen value or `NotImplemented`
    to fall through to concrete (only for symbolic-address reads /
    writes). For pure-arithmetic hooks, this class also propagates
    symbolic values when an operand is non-int, so analysts who don't
    write a custom symbolic policy still see forks at branches gated on
    intercept-produced symbols.
    """

    def __init__(self, engine, path, *, layout=None, memory=None):
        self._engine = engine
        self._path = path
        self._layout = layout if layout is not None else engine.layout
        self._memory = memory if memory is not None else (
            self._layout.memory if self._layout is not None else None)
        # Lazily built per-step MemView; ArgsView is per-call event.
        self._mem_view = MemView(self._memory) if self._memory else None

    # ------------------------------------------------------------------
    # Hook entry points (lookup_method on PyPolicy fires these)
    # ------------------------------------------------------------------

    def mem_read(self, addr, size, is_float):
        addr_int = extract_addr(addr)
        if addr_int is None:
            return NotImplemented
        ctx = self._make_ctx()
        size_i = int(size)

        self._fire_observers(MEMORY_READ, "before", ctx,
                             addr=addr_int, size=size_i,
                             is_float=bool(is_float))

        handlers = self._matching_handlers(
            MEMORY_READ, lambda sel: sel.matches_addr(addr_int))
        chain = _build_chain(handlers, _make_default_mem_read(bool(is_float)))
        try:
            value = chain(ctx, addr_int, size_i)
        except Exception as exc:  # noqa: BLE001
            self._record_handler_error(ctx, MEMORY_READ, exc,
                                       role="intercept")
            self._fire_observers(MEMORY_READ, "after", ctx,
                                 addr=addr_int, size=size_i,
                                 is_float=bool(is_float), value=None,
                                 handled=False)
            return NotImplemented

        self._fire_observers(MEMORY_READ, "after", ctx,
                             addr=addr_int, size=size_i,
                             is_float=bool(is_float), value=value,
                             handled=True)
        return value

    def mem_write(self, addr, val, size, is_float):
        addr_int = extract_addr(addr)
        if addr_int is None:
            return NotImplemented
        ctx = self._make_ctx()
        size_i = int(size)

        self._fire_observers(MEMORY_WRITE, "before", ctx,
                             addr=addr_int, size=size_i,
                             value=val, is_float=bool(is_float))

        handlers = self._matching_handlers(
            MEMORY_WRITE, lambda sel: sel.matches_addr(addr_int))
        chain = _build_chain(handlers, _make_default_mem_write(bool(is_float)))
        try:
            chain(ctx, addr_int, val, size_i)
        except Exception as exc:  # noqa: BLE001
            self._record_handler_error(ctx, MEMORY_WRITE, exc,
                                       role="intercept")

        self._fire_observers(MEMORY_WRITE, "after", ctx,
                             addr=addr_int, size=size_i,
                             value=val, is_float=bool(is_float),
                             handled=True)
        # InterceptorPolicy claims the write — chain decided whether
        # to actually mutate memory. Tell the substrate not to redo it.
        return None

    def resolve_call(self, target_eid, indirect_eid, args_list,
                     is_indirect):
        # Args land as a Python list of raw values (ints, ("ptr", N)
        # tuples, SymExprs, …). Build an ArgsView over them so hooks
        # have a consistent lens API.
        args = list(args_list)
        ctx = self._make_ctx(args=args)

        target_name = self._lookup_name(target_eid)
        indirect_name = self._lookup_name(indirect_eid)

        event = INDIRECT_CALL if is_indirect else CALL
        target_for_match = (indirect_eid if is_indirect and indirect_eid
                            else target_eid)
        candidate_name = (indirect_name if is_indirect and indirect_name
                          else target_name)

        self._fire_observers(event, "before", ctx,
                             target_eid=target_for_match,
                             name=candidate_name, args=args,
                             is_indirect=is_indirect)

        def _match(sel):
            if not sel.matches_name(candidate_name):
                return False
            if not sel.matches_eid(target_for_match):
                return False
            return True

        handlers = self._matching_handlers(event, _match)
        chain = _build_chain(handlers, _default_call)
        try:
            chosen = chain(ctx)
        except Exception as exc:  # noqa: BLE001
            self._record_handler_error(ctx, event, exc, role="intercept")
            chosen = _DEFER

        if chosen is _DEFER:
            self._fire_observers(event, "after", ctx,
                                 target_eid=target_for_match,
                                 name=candidate_name, args=args,
                                 is_indirect=is_indirect, return_value=None,
                                 handled=False)
            return None  # PythonPolicy treats None as "fall through".

        self._fire_observers(event, "after", ctx,
                             target_eid=target_for_match,
                             name=candidate_name, args=args,
                             is_indirect=is_indirect, return_value=chosen,
                             handled=True)
        if isinstance(chosen, tuple) and len(chosen) == 2 and \
                chosen[0] in ("skip", "model"):
            return chosen
        return ("skip", chosen)

    # ----- pure ops: propagate symbolic values, else fall through -----

    def compare(self, op, lhs, rhs):
        if _is_concrete(lhs) and _is_concrete(rhs):
            return NotImplemented
        return SymExpr("cmp", (op, lhs, rhs))

    def binary_op(self, op, lhs, rhs):
        if _is_concrete(lhs) and _is_concrete(rhs):
            return NotImplemented
        return SymExpr("bin", (op, lhs, rhs))

    def unary_op(self, op, operand):
        if _is_concrete(operand):
            return NotImplemented
        return SymExpr("un", (op, operand))

    def cast(self, op, operand):
        if _is_concrete(operand):
            return NotImplemented
        return SymExpr("cast", (op, operand))

    # ----- truth + branch resolution: fork on non-concrete -----

    def is_true(self, val):
        # If the analyst registered any BRANCH handlers, fall through to
        # `resolve_branch` (where we have the target eids) so they get a
        # chance to fire. The Phase 2 fast path only applies when no
        # handler is interested.
        if self._engine._intercepts.lookup(BRANCH):
            return None
        if isinstance(val, (int, bool)):
            return val != 0
        return None

    def resolve_branch(self, condition, true_eid, false_eid):
        ctx = self._make_ctx()
        t_eid = int(true_eid)
        f_eid = int(false_eid)
        ctx.true_eid = t_eid
        ctx.false_eid = f_eid

        # Resolve the source-block / function context — populated when
        # an `intercept.branch(func=…)` or `intercept.loop(func=…)` was
        # registered against the function containing this branch.
        site = self._engine._branch_sites.get((t_eid, f_eid))
        if site is not None:
            ctx.source_block = site["src_id"]
            ctx.func_id = site["func_id"]
        else:
            ctx.source_block = None
            ctx.func_id = None

        def _match(sel):
            if not sel.matches_func(ctx.func_id):
                return False
            if not sel.matches_block(ctx.source_block):
                return False
            return True

        handlers = self._matching_handlers(BRANCH, _match)
        if not handlers and isinstance(condition, (int, bool)):
            return condition != 0  # Phase 2 fast path
        if not handlers:
            return None  # symbolic, no handler — let substrate fork

        chain = _build_chain(handlers, _default_branch)
        try:
            chosen = chain(ctx, condition)
        except Exception as exc:  # noqa: BLE001
            self._record_handler_error(ctx, BRANCH, exc, role="intercept")
            chosen = _FORK

        if chosen is _FORK:
            return None
        return bool(chosen)

    # ------------------------------------------------------------------
    # Internal helpers
    # ------------------------------------------------------------------

    def _make_ctx(self, args=None):
        ctx = Ctx(
            path=self._path,
            mem=self._mem_view,
            args=ArgsView(self._mem_view, args) if args is not None else None,
            layout=self._layout,
            solver=getattr(self._path, "solver", None),
        )
        return ctx

    def _matching_handlers(self, event, match):
        registry = self._engine._intercepts
        return [h for sel, h in registry.lookup(event) if match(sel)]

    def _fire_observers(self, event, phase, ctx, **payload):
        registry = self._engine._observers
        key = (event, phase)
        for selector, handler in registry.lookup(key):
            if not _selector_matches_payload(selector, event, payload):
                continue
            try:
                handler(ctx, **payload)
            except Exception as exc:  # noqa: BLE001 — swallow + log
                self._record_handler_error(ctx, event, exc,
                                           role=f"observer.{phase}")
                continue
            self._auto_record_event(ctx, event, phase, payload)

    def _auto_record_event(self, ctx, event, phase, payload):
        """Append a structured entry to path.events after each observer
        run. Branches are recorded by the driver itself; suppress here
        to avoid duplicates."""
        if event == BRANCH:
            return
        if phase != "after":
            return
        path = ctx.path
        if path is None:
            return
        entry = {"kind": event, "phase": phase}
        for k, v in payload.items():
            entry[k] = v
        path.events.append(entry)

    def _record_handler_error(self, ctx, event, exc, *, role):
        path = ctx.path
        if path is None:
            return
        path.events.append({
            "kind": "observer_error" if role.startswith("observer") else
                    "intercept_error",
            "event": event,
            "role": role,
            "error": repr(exc),
        })

    def _lookup_name(self, eid):
        """Best-effort resolution of an entity id to a function name.

        The engine cached this lookup in `_func_name_resolver`; on miss
        we return None and selectors that filter by name simply don't
        match.
        """
        if eid is None or int(eid) == 0:
            return None
        resolver = getattr(self._engine, "_func_name_resolver", None)
        if resolver is None:
            return None
        return resolver(int(eid))


def _is_concrete(value):
    """A value is concrete if the substrate can interpret it without
    policy help: ints, bools, None, and ("ptr", N) tuples."""
    if value is None:
        return True
    if isinstance(value, (int, bool)):
        return True
    if isinstance(value, tuple) and len(value) == 2 and value[0] == "ptr":
        return True
    return False


def _selector_matches_payload(selector, event, payload):
    """Apply the relevant selector axes for an event's payload."""
    if event in (MEMORY_READ, MEMORY_WRITE):
        addr = payload.get("addr")
        if addr is None:
            return False
        return selector.matches_addr(addr)
    if event in (CALL, INDIRECT_CALL):
        if not selector.matches_name(payload.get("name")):
            return False
        if not selector.matches_eid(payload.get("target_eid")):
            return False
        return True
    if event in (GLOBAL_READ, GLOBAL_WRITE):
        if not selector.matches_name(payload.get("name")):
            return False
        if not selector.matches_eid(payload.get("eid")):
            return False
        return True
    return True
