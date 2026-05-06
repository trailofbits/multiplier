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

import multiplier as mx

from .ctx import Ctx
from .events import (
    MEMORY_READ, MEMORY_WRITE,
    SYMBOLIC_LOAD, SYMBOLIC_STORE,
    GLOBAL_READ, GLOBAL_WRITE, GLOBAL_INITIALIZED,
    CALL, INDIRECT_CALL,
    BRANCH, LOOP, CONCRETIZE,
    BLOCK_ENTER, INSTRUCTION,
    ADDRESS_FOR, ADDRESS_RESOLVED,
    BULK_MEMORY,
    EventKind, Phase,
)
from .lens import MemView, ArgsView

_OP = mx.ir.OpCode


def _op_range(lo_name, hi_name):
    """Build an `(int, int)` inclusive range from two `mx.ir.OpCode`
    enum names. Anchoring to the enum (rather than hardcoded numeric
    boundaries) means ranges track OpCode.h automatically — adding a
    new opcode in the gap between two width-grouped opcodes would
    surface as a Python error rather than silently shifting the lookup.
    """
    return (int(getattr(_OP, lo_name)), int(getattr(_OP, hi_name)))


class SymExpr:
    """Default symbolic-value sentinel produced by InterceptorPolicy.

    A class (not an int) so the substrate's bare-int address heuristic
    cannot mistake a symbolic value for a concrete pointer. The
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


def _concrete_int(v):
    """Return a Python ``int`` if ``v`` is concretely an integer.

    Accepts Python ``int`` (rejecting ``bool`` — booleans come through
    only when a hook returned ``True``/``False`` and aren't valid
    pointers / numeric operands), and z3 BitVec values. For z3 values
    that aren't already a ``BitVecVal`` (e.g. ``Concat(BVV, BVV) + 0``
    after a multi-byte concrete load through the shadow), one
    ``z3.simplify`` is enough to collapse the structural shape to a
    value when the expression is provably constant. Returns ``None``
    when the value is genuinely symbolic.
    """
    if isinstance(v, bool):
        return None
    if isinstance(v, int):
        return v
    z3 = _z3_module()
    if z3 is None or not isinstance(v, z3.ExprRef):
        return None
    if z3.is_bv_value(v):
        return v.as_long()
    s = z3.simplify(v)
    if z3.is_bv_value(s):
        return s.as_long()
    return None


def _concrete_bool(v):
    """Return Python ``bool`` if ``v`` is concretely truthy or falsy.

    Mirrors ``_concrete_int`` for branch / is_true sites. ``None``
    means "still symbolic, fork".
    """
    if isinstance(v, bool):
        return v
    if isinstance(v, int):
        return v != 0
    z3 = _z3_module()
    if z3 is None or not isinstance(v, z3.ExprRef):
        return None
    if z3.is_true(v):
        return True
    if z3.is_false(v):
        return False
    if z3.is_bv_value(v):
        return v.as_long() != 0
    s = z3.simplify(v)
    if z3.is_true(s):
        return True
    if z3.is_false(s):
        return False
    if z3.is_bv_value(s):
        return s.as_long() != 0
    return None


def extract_addr(addr):
    """Pull a concrete address out of the substrate's value form.

    Pointers come through as bare ints (the common case) or as z3
    BitVec values that may be structurally non-trivial (e.g. a
    ``Concat(BVV, …) + 0`` produced by the shadow-driven load of a
    pointer global). ``_concrete_int`` collapses both shapes to an
    ``int``; symbolic addresses yield ``None`` so the substrate
    emits a ``MemAddrContinuation``.
    """
    return _concrete_int(addr)


# Back-compat alias — `_coerce_int` used to be its own thing for
# bulk-op operands; keep the name working while everything points
# at the unified helper.
_coerce_int = _concrete_int


def _memop_name(op):
    """Return the analyst-facing name for an IR `MemOp` sub-opcode.

    Derived from the `mx.ir.MemOp` enum so the name list stays in
    lock-step with the C++ enum automatically — adding a new bulk op
    in `OpCode.h` becomes available here without a separate edit.
    Returns the lower-cased member name (e.g. ``"memcpy"``).
    """
    return mx.ir.MemOp(int(op)).name.lower()


class _Selector:
    """Compiled selector. Stored once per registration; matched at
    dispatch time in constant-ish time.

    Selectors carry every attribute the analyst can pass; matching
    against an event filters by the attributes the event provides.
    Empty / `None` attributes match anything.
    """

    __slots__ = ("addr_range", "name", "eid", "func", "block", "region",
                 "_layout", "_resolved_range", "kind", "target_kind", "decl",
                 "op")

    def __init__(self, addr_range=None, name=None, eid=None, func=None,
                 block=None, region=None, layout=None,
                 kind=None, target_kind=None, decl=None, op=None):
        self.addr_range = addr_range
        self.name = name
        # Allow `decl=<NamedDecl>` to substitute for both name and eid:
        # we extract them up front so matches_name / matches_eid still
        # do their cheap equality checks at dispatch time.
        if decl is not None:
            try:
                if name is None:
                    self.name = str(decl.name) if decl.name else None
            except (AttributeError, TypeError):
                pass
            if eid is None:
                try:
                    eid = int(decl.id)
                except (AttributeError, TypeError):
                    eid = None
        self.eid = eid
        self.decl = decl
        self.func = func
        self.block = block
        self.region = region
        self._layout = layout
        self._resolved_range = None
        # Phase 9 axes
        self.kind = kind
        self.target_kind = target_kind
        # Bulk-memory selector — matches "memcpy", "memset", … against
        # the IR sub-opcode name, mirroring the `kind=` axis used by
        # the address-resolution events.
        self.op = op

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

    def matches_region(self, candidate):
        if self.region is None:
            return True
        return candidate is not None and candidate == self.region

    def matches_kind(self, candidate):
        """Match the entity kind: "function", "global", "thread_local"."""
        if self.kind is None:
            return True
        return candidate is not None and candidate == self.kind

    def matches_target_kind(self, candidate):
        """Match the indirect-call target kind: "concrete" or "symbolic"."""
        if self.target_kind is None:
            return True
        return candidate is not None and candidate == self.target_kind

    def matches_op(self, candidate):
        """Match the bulk-memory op name: "memcpy", "memset", …."""
        if self.op is None:
            return True
        return candidate is not None and candidate == self.op

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
        decl=kwargs.get("decl"),
        func=kwargs.get("func"),
        block=kwargs.get("block"),
        region=kwargs.get("region"),
        layout=layout,
        kind=kwargs.get("kind"),
        target_kind=kwargs.get("target_kind"),
        op=kwargs.get("op"),
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

from ._types import _BYTES_TYPES, _INT_TYPES, _SEQ_TYPES, Endian

# Pre-built zero-fill byte strings indexed by size (0-16).
_ZERO_BYTES = tuple(bytes(n) for n in range(17))


def _shadow_write(shadow, addr, val, size):
    """Decompose a z3 value into per-byte shadow entries (little-endian).

    Each ``shadow[addr + i]`` slot holds a ``BitVec(8)`` extract of ``val``
    (or, when ``val.size() == 8``, ``val`` itself — avoids accumulating
    nested ``Extract(7, 0, ...)`` layers when a symbolic byte is
    read-and-rewritten).

    Concrete writes erase covered shadow slots (``ConcreteMemory`` is the
    source of truth for concrete bytes); the caller is responsible for
    writing the actual bytes to ``ConcreteMemory``. Partial overlap is
    handled naturally — only touched positions are updated.
    """
    z3 = _z3_module()
    if z3 is not None and _is_z3(val):
        # Structural Concat-fold before per-byte decomposition: when
        # ``val`` was built by re-concatenating bytes earlier read from
        # the shadow (the load-modify-store round-trip), the fold
        # collapses ``Concat(Extract(31,24,X),Extract(23,16,X),...)``
        # back to ``X`` (or a single Extract) so the per-byte
        # decomposition below stores raw ``Extract(8i+7, 8i, X)``
        # entries. Using the structural fold here instead of
        # ``z3.simplify`` avoids the asymmetric-byte-arith collapse
        # that would otherwise produce ``212 + 255*b`` for the low
        # byte of ``1492 - zext_32(b)`` and lose the parent identity
        # for future loads.
        val = _z3_concat_fold(z3, val)
        i = 0
        while i < size:
            shadow[addr + i] = _z3_byte_at(val, i)
            i += 1
    else:
        i = 0
        while i < size:
            shadow.pop(addr + i, None)
            i += 1


def _shadow_read(shadow, addr, size, data, buf):
    """Reconstruct a symbolic value from the byte-granular shadow.

    ``data`` is the already-read concrete bytes for ``[addr, addr+size)``.
    Returns ``None`` immediately when no shadow entry overlaps the range
    (zero dict lookups beyond the in-check on the fast path).

    For each covered position: shadow-dict hit → ``z3.BitVec(8)`` extract;
    miss → ``BitVecVal`` of the concrete byte.  ``buf`` is a pre-allocated
    list (held on ``Path``) reused across calls.  ``z3.simplify`` collapses
    a same-width read of a single symbolic write back to the original
    variable.
    """
    # Fast path: check whether any byte in the range is shadowed. Sparse
    # paths see a non-shadowed range and return immediately, so this is
    # the no-symbolic-data hot path.
    found = False
    i = 0
    while i < size:
        if (addr + i) in shadow:
            found = True
            break
        i += 1
    if not found:
        return None

    z3 = _z3_module()

    while len(buf) < size:
        buf.append(None)

    i = 0
    while i < size:
        entry = shadow.get(addr + i)
        buf[i] = entry if entry is not None else z3.BitVecVal(data[i], 8)
        i += 1

    if size == 1:
        return buf[0]

    # Concat is MSB-first; little-endian layout means buf[size-1] is the MSB.
    result = buf[size - 1]
    j = size - 2
    while j >= 0:
        result = z3.Concat(result, buf[j])
        j -= 1
    # Structural fold only — collapses consecutive Extracts of the
    # same parent back to the parent (or a single Extract). Avoids
    # ``z3.simplify`` here on purpose: simplify folds the low byte
    # through byte arith asymmetrically and prevents the parent from
    # being recovered. A consumer op (compare, branch, cast) is the
    # right place to run a full simplify.
    return _z3_concat_fold(z3, result)


def _shadow_range_is_concrete(z3, shadow, addr, size):
    """True iff no byte in [addr, addr+size) carries a symbolic-shaped
    shadow entry. Missing entries (``None``) are concrete — they're
    filled from ``ctx.mem.read_bytes`` data by ``_shadow_read``.
    ``BitVecVal`` entries (concrete IR-side stores) are also concrete.
    Only symbolic shapes (``Extract``, region-overlay selects, …)
    return False so the read preserves the symbolic shape."""
    i = 0
    while i < size:
        entry = shadow.get(addr + i)
        if entry is not None and not z3.is_bv_value(entry):
            return False
        i += 1
    return True


def _make_default_mem_read(is_float, shadow=None, buf=None,
                           byte_order=Endian.LITTLE):
    """Return the chain bottom for a memory_read event.

    Reads baseline bytes from ``ConcreteMemory`` first (always needed as
    fallback), then defers to ``_shadow_read`` which checks the per-path
    shadow dict.  Shadow entries shadow the baseline; any range with no
    shadow entry goes straight to the concrete fallback.  Falls back to
    zero-fill on a read failure so OOB sinks still fire.

    Concrete IR-side stores land in the shadow as ``BitVecVal`` bytes
    (so sibling forks see their own writes through CoW). When the read
    range is covered entirely by ``BitVecVal`` entries, collapse back
    to a Python ``int`` (or float) so downstream comparisons stay
    concrete — without this a round-tripped concrete value would
    surface as a z3 expression and a later compare would fork or
    produce a ``BoolRef`` the substrate can't store. Symbolic-shaped
    entries (``Extract``, ``Concat``, region-overlay selects, …) are
    preserved as-is, even when they happen to simplify to a constant
    — analyst code relies on the *shape* signaling symbolic-ness.
    """
    _buf = buf if buf is not None else []

    def default(ctx, addr, size):
        try:
            data = ctx.mem.read_bytes(addr, size)
        except RuntimeError:
            data = _ZERO_BYTES[size] if size < len(_ZERO_BYTES) else bytes(size)
        if shadow is not None:
            sym = _shadow_read(shadow, addr, size, data, _buf)
            if sym is not None:
                z3 = _z3_module()
                if z3 is not None and _shadow_range_is_concrete(
                        z3, shadow, addr, size):
                    val = z3.simplify(sym).as_long()
                    if is_float and size in (4, 8):
                        # Shadow assembly is always little-endian
                        # (`_shadow_read` puts byte-at-addr in the
                        # LSB), so the int we get out is the LE
                        # representation. Repacking LE matches.
                        fmt = "<f" if size == 4 else "<d"
                        return _struct.unpack(
                            fmt, val.to_bytes(size, Endian.LITTLE))[0]
                    return val
                return sym
        if is_float and size in (4, 8):
            prefix = "<" if byte_order == Endian.LITTLE else ">"
            fmt = f"{prefix}f" if size == 4 else f"{prefix}d"
            return _struct.unpack(fmt, data)[0]
        return int.from_bytes(data, byte_order, signed=False)
    return default


def _make_default_mem_write(is_float, shadow=None, byte_order=Endian.LITTLE):
    """Return the chain bottom for a memory_write event.

    Concrete values land in BOTH the per-path shadow (as ``BitVecVal``
    bytes, little-endian internal layout) and ``ConcreteMemory``. The
    shadow gives sibling forks per-path read isolation through the
    dispatcher; ``ConcreteMemory`` keeps direct ``path.mem.read_bytes``
    inspection working as before. Symbolic (z3) values land in the
    shadow only — there's no concrete byte representation for them.

    Without a shadow (test paths, substrate-only callers) the fallback
    is just the ``ConcreteMemory`` write; symbolic writes have nowhere
    to go and are silently dropped (matches prior behavior).
    """
    def default(ctx, addr, val, size):
        if isinstance(val, bool):
            val = int(val)
        # ``BitVecVal(7, 32)`` IS a concrete int; route it through the
        # int path so the write round-trips as a Python int rather
        # than as Extract-of-BitVecVal bytes in the shadow. The check
        # is intentionally strict (``is_bv_value`` only — no simplify)
        # because a symbolic-shaped expression that *evaluates* to a
        # constant (e.g. a region-overlay select that the test wants
        # to surface as z3) should still take the symbolic path.
        z3 = _z3_module()
        if z3 is not None and isinstance(val, z3.ExprRef) \
                and z3.is_bv_value(val):
            val = val.as_long()

        # Genuinely symbolic values: shadow only. No concrete
        # representation, so nothing meaningful to put in ConcreteMemory.
        if _is_z3(val):
            if shadow is not None:
                _shadow_write(shadow, addr, val, size)
            return None

        # Concrete values: bytes for ConcreteMemory + matching
        # BitVecVal entries in the shadow (when z3 is available).
        if isinstance(val, int):
            packed = val.to_bytes(size, byte_order, signed=(val < 0))
        elif isinstance(val, _BYTES_TYPES):
            packed = bytes(val)
        elif isinstance(val, float):
            prefix = "<" if byte_order == Endian.LITTLE else ">"
            fmt = f"{prefix}f" if size == 4 else f"{prefix}d"
            packed = _struct.pack(fmt, val)
        else:
            return None

        ctx.mem.write_bytes(addr, packed)

        if shadow is not None:
            z3 = _z3_module()
            if z3 is not None:
                # Shadow stores byte-at-addr in slot[addr], which
                # `_shadow_read` reassembles LSB-first. Re-layout
                # `packed` as LE so the shadow round-trips concrete
                # writes correctly regardless of the requested
                # ``byte_order`` for the concrete-mem write above.
                if byte_order == Endian.LITTLE or len(packed) == 1:
                    bytes_le = packed
                else:
                    bytes_le = packed[::-1]
                i = 0
                for b in bytes_le:
                    shadow[addr + i] = z3.BitVecVal(b, 8)
                    i += 1
        return None
    return default


def _default_call(ctx):
    """Chain bottom for a call event — defer to substrate inline."""
    return _DEFER


def _default_indirect_call(ctx, target_addr):
    """Chain bottom for an indirect_call event — defer to substrate inline.

    Indirect-call hooks receive `target_addr` as a positional argument
    (per the design doc); the chain bottom accepts and ignores it so
    handlers that forward via `next_hook(ctx, target_addr)` reach a
    concrete sentinel.
    """
    return _DEFER


def _default_branch(ctx, condition):
    """Chain bottom for a branch event.

    Concrete conditions resolve to True / False naturally; symbolic
    conditions return `_FORK`, telling the InterceptorPolicy to hand
    control back to the substrate so it can enumerate edges via a
    BranchContinuation. A z3 expression that simplifies to a concrete
    ``True``/``False`` resolves concretely too — without this, an
    ``Eq(BVV(0), BVV(0))``-shaped condition would force a needless
    fork.
    """
    decided = _concrete_bool(condition)
    if decided is not None:
        return decided
    return _FORK


# ---- z3 helpers (lazy-imported, then cached so non-z3 analysts pay
#      one import lookup ever and z3 analysts pay zero per IR op) ----

_Z3 = None  # cached `z3` module; `False` = import attempted and failed.


def _z3_module():
    """Return the `z3` module, or None if it isn't installed.

    The module reference is cached so the per-IR-op `_is_z3` check
    isn't paying for `try: import z3` (and especially not paying for an
    `ImportError` raise+catch when z3 isn't installed) on every call.
    """
    global _Z3
    if _Z3 is None:
        try:
            import z3 as _module
            _Z3 = _module
        except ImportError:
            _Z3 = False
    return _Z3 if _Z3 is not False else None


def _is_z3(value):
    """Return True if `value` is a z3 expression (BitVec or Bool)."""
    z3 = _z3_module()
    return z3 is not None and isinstance(value, z3.ExprRef)


def _z3_bool(value):
    """Coerce a z3 value to a z3 boolean.

    BitVecs become `value != 0`; bools pass through. Anything else
    returns None — callers treat None as "can't represent this
    symbolically; defer to substrate fork".
    """
    z3 = _z3_module()
    if z3 is None:
        return None
    if isinstance(value, z3.BoolRef):
        return value
    if isinstance(value, z3.BitVecRef):
        return value != 0
    return None


def _z3_coerce(v, sample):
    """Coerce concrete `v` into z3 form, sized like `sample` if it's a
    BitVec. Already-z3 inputs pass through."""
    z3 = _z3_module()
    if z3 is None:
        return None
    if isinstance(v, z3.ExprRef):
        return v
    if isinstance(v, bool):
        v = int(v)
    if isinstance(v, int):
        if isinstance(sample, z3.BitVecRef):
            return z3.BitVecVal(v, sample.size())
        return z3.BitVecVal(v, 64)
    return None


def _z3_resize(val, target_bits, signed=False):
    """Return a z3 BitVec of exactly ``target_bits`` derived from ``val``.

    If ``val`` is already that wide, returned unchanged — z3 doesn't
    auto-simplify ``Extract(N-1, 0, BitVec(N))`` or ``ZeroExt(0, …)`` /
    ``SignExt(0, …)`` to identity, so wrapping a same-width value in those
    ops just bloats every downstream expression. Avoiding the wrap keeps
    expressions canonical across repeated read-modify-write cycles.
    """
    cur = val.size()
    if cur == target_bits:
        return val
    z3 = _z3_module()
    if cur > target_bits:
        return z3.Extract(target_bits - 1, 0, val)
    return z3.SignExt(target_bits - cur, val) if signed \
        else z3.ZeroExt(target_bits - cur, val)


def _z3_byte_at(val, i):
    """Extract the i-th byte (8 bits, little-endian) of ``val``.

    Skips the wrap when ``val`` is already exactly one byte wide and
    we're asking for byte 0 — the common case for byte-granular shadow
    writes of an already-extracted symbolic byte.
    """
    if val.size() == 8 and i == 0:
        return val
    z3 = _z3_module()
    return z3.Extract(8 * (i + 1) - 1, 8 * i, val)


def _z3_concat_fold(z3, expr):
    """Structural fold for Concat-of-consecutive-Extracts-of-same-parent.

    Pure structure rewrite — never folds Extract through arithmetic.
    `z3.simplify` would do that asymmetrically (the low byte of a
    subtraction has no incoming borrow, so it folds into byte arith,
    while high bytes don't), producing shapes like
    `Concat(Extract(31, 8, X), 212 + 255*b)` where the low byte's
    parent identity has been lost and the round-trip back to X is
    impossible to recover.

    Steps:

      1. Flatten nested Concats — z3 stores n-ary Concat as a
         left-associated chain of binary applications, so
         `Concat(a, b, c, d)` is `Concat(Concat(Concat(a, b), c), d)`
         under the hood. The fold has to see it as a flat MSB→LSB
         sequence to merge consecutive Extracts.
      2. Merge consecutive Extracts of the same parent at adjacent
         bit ranges into a single Extract.
      3. If a single Extract spans the parent's full width, return
         the parent itself.

    Rules 2 + 3 together recover the original parent expression on a
    full-width round trip: store a 32-bit value as four byte shadows,
    load all four, and the result is the original 32-bit term — no
    z3.simplify required, and (more importantly) no asymmetric
    arithmetic folding to the low byte.
    """
    if not z3.is_app(expr) or expr.decl().kind() != z3.Z3_OP_CONCAT:
        return expr

    # Step 1: flatten nested Concats into a single MSB→LSB list.
    parts = []
    stack = [expr]
    while stack:
        node = stack.pop()
        if z3.is_app(node) and node.decl().kind() == z3.Z3_OP_CONCAT:
            # Children are MSB→LSB; push in reverse so the pop order
            # walks them MSB-first.
            kids = node.children()
            for k in reversed(kids):
                stack.append(k)
        else:
            parts.append(node)

    if len(parts) == 1:
        return parts[0]

    # Step 2: left-to-right merge of adjacent same-parent Extracts.
    out = []
    for p in parts:
        if (out and
                z3.is_app(p) and p.decl().kind() == z3.Z3_OP_EXTRACT and
                z3.is_app(out[-1]) and
                out[-1].decl().kind() == z3.Z3_OP_EXTRACT and
                p.arg(0).eq(out[-1].arg(0))):
            top_hi, top_lo = out[-1].params()
            bot_hi, bot_lo = p.params()
            if top_lo == bot_hi + 1:
                out[-1] = z3.Extract(top_hi, bot_lo, p.arg(0))
                continue
        out.append(p)

    if len(out) == 1:
        only = out[0]
        # Step 3: full-width Extract collapses to its parent.
        if z3.is_app(only) and only.decl().kind() == z3.Z3_OP_EXTRACT:
            hi, lo = only.params()
            parent = only.arg(0)
            if lo == 0 and hi == parent.size() - 1:
                return parent
        return only
    return z3.Concat(*out)


# Per-arity dispatch tables: each entry is `(opcode_range, builder)`.
# Builders for ops that need a z3 module function take (z3, a[, b]) so
# the cached `_z3_module()` reference flows through; the rest are pure
# operator overloads. Anchoring the ranges to `mx.ir.OpCode` keeps the
# tables in lockstep with the C++ enum.
_COMPARE_TABLE = [
    (_op_range("CMP_EQ_8",  "CMP_EQ_64"),  lambda z3, a, b: a == b),
    (_op_range("CMP_NE_8",  "CMP_NE_64"),  lambda z3, a, b: a != b),
    (_op_range("CMP_LT_8",  "CMP_LT_64"),  lambda z3, a, b: a <  b),
    (_op_range("CMP_LE_8",  "CMP_LE_64"),  lambda z3, a, b: a <= b),
    (_op_range("CMP_GT_8",  "CMP_GT_64"),  lambda z3, a, b: a >  b),
    (_op_range("CMP_GE_8",  "CMP_GE_64"),  lambda z3, a, b: a >= b),
    (_op_range("UCMP_LT_8", "UCMP_LT_64"), lambda z3, a, b: z3.ULT(a, b)),
    (_op_range("UCMP_LE_8", "UCMP_LE_64"), lambda z3, a, b: z3.ULE(a, b)),
    (_op_range("UCMP_GT_8", "UCMP_GT_64"), lambda z3, a, b: z3.UGT(a, b)),
    (_op_range("UCMP_GE_8", "UCMP_GE_64"), lambda z3, a, b: z3.UGE(a, b)),
]

_BINARY_TABLE = [
    (_op_range("ADD_8",     "ADD_64"),     lambda z3, a, b: a + b),
    (_op_range("SUB_8",     "SUB_64"),     lambda z3, a, b: a - b),
    (_op_range("MUL_8",     "MUL_64"),     lambda z3, a, b: a * b),
    (_op_range("DIV_8",     "DIV_64"),     lambda z3, a, b: a / b),
    (_op_range("REM_8",     "REM_64"),     lambda z3, a, b: z3.SRem(a, b)),
    (_op_range("UDIV_8",    "UDIV_64"),    lambda z3, a, b: z3.UDiv(a, b)),
    (_op_range("UREM_8",    "UREM_64"),    lambda z3, a, b: z3.URem(a, b)),
    (_op_range("USHR_8",    "USHR_64"),    lambda z3, a, b: z3.LShR(a, b)),
    (_op_range("BIT_AND_8", "BIT_AND_64"), lambda z3, a, b: a & b),
    (_op_range("BIT_OR_8",  "BIT_OR_64"),  lambda z3, a, b: a | b),
    (_op_range("BIT_XOR_8", "BIT_XOR_64"), lambda z3, a, b: a ^ b),
    (_op_range("SHL_8",     "SHL_64"),     lambda z3, a, b: a << b),
    (_op_range("SHR_8",     "SHR_64"),     lambda z3, a, b: a >> b),  # arith
]

_UNARY_TABLE = [
    (_op_range("NEG_8",     "NEG_64"),     lambda z3, a: -a),
    (_op_range("BIT_NOT_8", "BIT_NOT_64"), lambda z3, a: ~a),
    (_op_range("ABS_8",     "ABS_64"),
        lambda z3, a: z3.If(a < 0, -a, a)),
]


def _dispatch_op(table, op):
    for lo_hi, builder in table:
        if lo_hi[0] <= op <= lo_hi[1]:
            return builder
    return None


def _dispatch_op_sized(table, op):
    """Like ``_dispatch_op`` but also returns the operand width in bits.

    Assumes the entry has _8/_16/_32/_64 variants in that order (so a
    range of size 4). Used by integer binary/unary dispatch so a
    width-mismatched operand pair is reconciled before reaching z3.
    """
    for lo_hi, builder in table:
        if lo_hi[0] <= op <= lo_hi[1]:
            return builder, 8 << (op - lo_hi[0])
    return None


def _z3_compare(op, lhs, rhs):
    """Build a z3 boolean from a comparison opcode and two operands.

    For BitVec operands, both are resized to a matching width (the
    larger of the two) before the op is built — z3 sort-checks
    aggressively and an upstream cast may have left the pair mismatched.
    FP operands fall through unchanged (already same-width by construction).

    Returns None if the opcode isn't recognised. Result is simplified.
    """
    z3 = _z3_module()
    builder = _dispatch_op(_COMPARE_TABLE, op)
    if z3 is None or builder is None:
        return None
    sample = lhs if _is_z3(lhs) else rhs
    a = _z3_coerce(lhs, sample)
    b = _z3_coerce(rhs, sample)
    if a is None or b is None:
        return None
    if isinstance(a, z3.BitVecRef) and isinstance(b, z3.BitVecRef) \
            and a.size() != b.size():
        target = max(a.size(), b.size())
        a = _z3_resize(a, target)
        b = _z3_resize(b, target)
    return z3.simplify(builder(z3, a, b))


def _z3_binary(op, lhs, rhs):
    """Build a z3 BitVec from a binary opcode. None on unsupported.

    Both operands are coerced to the opcode's declared width before the
    op is built — without this, an upstream cast that left an operand
    wider/narrower than its companion (or wider/narrower than the
    opcode's width) crashes z3 with a sort-mismatch.
    Result is simplified so each step in a chain of arithmetic ops stays
    canonical.
    """
    z3 = _z3_module()
    sized = _dispatch_op_sized(_BINARY_TABLE, op)
    if z3 is None or sized is None:
        return None
    builder, bits = sized
    sample = lhs if _is_z3(lhs) else rhs
    a = _z3_coerce(lhs, sample)
    b = _z3_coerce(rhs, sample)
    if a is None or b is None:
        return None
    a = _z3_resize(a, bits)
    b = _z3_resize(b, bits)
    return z3.simplify(builder(z3, a, b))


def _z3_unary(op, operand):
    if not _is_z3(operand):
        return None
    z3 = _z3_module()
    sized = _dispatch_op_sized(_UNARY_TABLE, op)
    if z3 is None or sized is None:
        return None
    builder, bits = sized
    return z3.simplify(builder(z3, _z3_resize(operand, bits)))


def _z3_cast(op, operand):
    """Lower a CastOp to z3 ops so symbolic values flow through casts.

    Returns None for casts we don't model symbolically (float ↔ int,
    F32_TO_F64, etc.); the caller falls back to a SymExpr placeholder
    in that case, which keeps the value visible but blocks z3 reasoning
    until those casts are wired up.
    """
    z3 = _z3_module()
    if z3 is None or not isinstance(operand, z3.ExprRef):
        return None
    name = mx.ir.CastOp(int(op)).name

    # Each cast result is z3.simplify'd — `_z3_resize` may emit a fresh
    # Extract/SignExt/ZeroExt node that the simplifier can immediately
    # collapse against an existing one (common when a SEXT feeds into a
    # TRUNC on the same value).
    if name.startswith("SEXT_I") or name.startswith("ZEXT_I"):
        # SEXT_I{src}_I{tgt} or ZEXT_I{src}_I{tgt}. Use the operand's
        # actual width (not src) — earlier casts may already have
        # widened or narrowed it past what the opcode claims.
        prefix = "SEXT_I" if name.startswith("SEXT_I") else "ZEXT_I"
        parts = name[len(prefix):].split("_I")
        _, tgt = int(parts[0]), int(parts[1])
        return z3.simplify(_z3_resize(operand, tgt, signed=(prefix == "SEXT_I")))
    if name.startswith("TRUNC_I"):
        # TRUNC_I{src}_I{tgt}.
        parts = name[len("TRUNC_I"):].split("_I")
        _, tgt = int(parts[0]), int(parts[1])
        return z3.simplify(_z3_resize(operand, tgt))
    if name in ("BITCAST", "IDENTITY"):
        return operand
    if name in ("PTR_TO_I64", "I64_TO_PTR"):
        return z3.simplify(_z3_resize(operand, 64))
    if name == "PTR_TO_I32":
        return z3.simplify(_z3_resize(operand, 32))
    if name == "I32_TO_PTR":
        return z3.simplify(_z3_resize(operand, 64))
    return None  # float casts unhandled; caller produces a SymExpr


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
        self._mem_view = (MemView(self._memory, endian=engine.endian)
                          if self._memory else None)
        # Phase 8c: shadow map for symbolic values written to concrete
        # substrate-allocated addresses. Held as a shared reference to
        # the path's dict so writes and reads survive across steps
        # (policy is fresh per step; path is durable). Test paths with
        # `path is None` (or stub paths without the attr) get a
        # per-policy ephemeral dict.
        self._shadow = getattr(path, "_symbolic_shadow", None)
        if self._shadow is None:
            self._shadow = {}
        self._shadow_buf = getattr(path, "_shadow_buf", None)
        if self._shadow_buf is None:
            self._shadow_buf = []

    # ------------------------------------------------------------------
    # Hook entry points (lookup_method on PyPolicy fires these)
    # ------------------------------------------------------------------

    def mem_read(self, addr, size, is_float):
        addr_int = extract_addr(addr)
        if addr_int is None:
            return NotImplemented
        ctx = self._make_ctx()
        size_i = int(size)
        region_name = self._region_name_for(addr_int)

        self._fire_observers(MEMORY_READ, Phase.BEFORE, ctx,
                             addr=addr_int, size=size_i,
                             is_float=bool(is_float),
                             region=region_name)

        handlers = self._matching_handlers(
            MEMORY_READ, lambda sel: sel.matches_addr(addr_int))
        chain = _build_chain(handlers,
                             _make_default_mem_read(bool(is_float),
                                                    self._shadow,
                                                    self._shadow_buf,
                                                    byte_order=self._engine.endian))
        value = chain(ctx, addr_int, size_i)

        self._fire_observers(MEMORY_READ, Phase.AFTER, ctx,
                             addr=addr_int, size=size_i,
                             is_float=bool(is_float), value=value,
                             handled=True, region=region_name)
        self._record_memory_event(ctx, MEMORY_READ, addr_int, size_i,
                                  region_name, value=value,
                                  is_float=bool(is_float))
        self._fire_sinks(MEMORY_READ, ctx,
                         {"addr": addr_int, "size": size_i,
                          "value": value, "region": region_name,
                          "is_float": bool(is_float)})
        self._fire_global_event_if_applicable(
            ctx, addr=addr_int, size=size_i, value=value,
            region_name=region_name, is_float=bool(is_float),
            is_write=False)
        return value

    def mem_write(self, addr, val, size, is_float):
        addr_int = extract_addr(addr)
        if addr_int is None:
            return NotImplemented
        ctx = self._make_ctx()
        size_i = int(size)
        region_name = self._region_name_for(addr_int)

        self._fire_observers(MEMORY_WRITE, Phase.BEFORE, ctx,
                             addr=addr_int, size=size_i,
                             value=val, is_float=bool(is_float),
                             region=region_name)

        handlers = self._matching_handlers(
            MEMORY_WRITE, lambda sel: sel.matches_addr(addr_int))
        chain = _build_chain(handlers,
                             _make_default_mem_write(bool(is_float),
                                                     self._shadow,
                                                     byte_order=self._engine.endian))
        chain(ctx, addr_int, val, size_i)

        # Phase 6 invariant: when the region's overlay has been
        # materialized (some prior symbolic access forced its
        # creation), mirror each concrete byte into the overlay so
        # later symbolic-offset reads see the written value. Regions
        # without an overlay pay zero — the cost is opt-in via earlier
        # symbolic touches.
        if region_name is not None and not bool(is_float):
            self._mirror_concrete_write_to_overlay(
                addr_int, val, size_i, region_name)

        self._fire_observers(MEMORY_WRITE, Phase.AFTER, ctx,
                             addr=addr_int, size=size_i,
                             value=val, is_float=bool(is_float),
                             handled=True, region=region_name)
        self._record_memory_event(ctx, MEMORY_WRITE, addr_int, size_i,
                                  region_name, value=val,
                                  is_float=bool(is_float))
        self._fire_sinks(MEMORY_WRITE, ctx,
                         {"addr": addr_int, "size": size_i,
                          "value": val, "region": region_name,
                          "is_float": bool(is_float)})
        self._fire_global_event_if_applicable(
            ctx, addr=addr_int, size=size_i, value=val,
            region_name=region_name, is_float=bool(is_float),
            is_write=True)
        # InterceptorPolicy claims the write — chain decided whether
        # to actually mutate memory. Tell the substrate not to redo it.
        return None

    # ------------------------------------------------------------------
    # Phase 8a: symbolic-address LOAD / STORE
    # ------------------------------------------------------------------
    #
    # Called by the substrate's `with_address`-equivalent path *before*
    # suspension when the address didn't extract to ("ptr", N). When the
    # current path was forked via `SplitByRegion` it carries
    # `_region_at_suspension`; we read/write through that region's z3
    # Array overlay so subsequent ops keep propagating symbolically.
    # Returning NotImplemented falls back to the substrate's existing
    # suspension path — the right answer when no region context is
    # available (so analyst mistakes surface as suspension rather than
    # silently collapsing to default-zero reads).

    def symbolic_load(self, addr, size, is_float):
        if not _is_z3(addr):
            return NotImplemented
        z3 = _z3_module()
        if z3 is None:
            return NotImplemented
        path = self._path
        region_name = getattr(path, "_region_at_suspension", None)
        size_i = int(size)
        layout = self._layout

        ctx = self._make_ctx()
        ctx.region = region_name
        self._fire_observers(SYMBOLIC_LOAD, Phase.BEFORE, ctx,
                             addr=addr, size=size_i,
                             is_float=bool(is_float),
                             region=region_name)

        def _default(c, a, sz):
            # Chain bottom: read through the suspension region's
            # z3-Array overlay. NotImplemented when no region context
            # is attached — preserves the pre-Phase-8d fallback so
            # the substrate's existing suspension path keeps firing.
            if region_name is None or layout is None:
                return NotImplemented
            region = layout.region_for_name(region_name)
            if region is None:
                return NotImplemented
            bytes_z = [region.select_byte(a + i) for i in range(sz)]
            if sz == 1:
                return bytes_z[0]
            # z3.Concat is MSB-first; little-endian means byte 0 is the
            # low byte, hence reversed().
            return z3.Concat(*reversed(bytes_z))

        handlers = self._matching_handlers(
            SYMBOLIC_LOAD,
            lambda sel: (sel.matches_region(region_name) and
                         sel.matches_name(region_name)))
        chain = _build_chain(handlers, _default)
        result = chain(ctx, addr, size_i)

        if result is NotImplemented:
            return NotImplemented

        self._fire_observers(SYMBOLIC_LOAD, Phase.AFTER, ctx,
                             addr=addr, size=size_i,
                             is_float=bool(is_float), value=result,
                             handled=True, region=region_name)
        # Mirror the read into the canonical MEMORY_READ stream so
        # observers keyed on memory_read still see symbolic accesses.
        self._fire_observers(MEMORY_READ, Phase.BEFORE, ctx,
                             addr=addr, size=size_i,
                             is_float=bool(is_float),
                             region=region_name)
        self._fire_observers(MEMORY_READ, Phase.AFTER, ctx,
                             addr=addr, size=size_i,
                             is_float=bool(is_float), value=result,
                             handled=True, region=region_name)
        self._record_memory_event(ctx, MEMORY_READ, addr, size_i,
                                  region_name, value=result,
                                  is_float=bool(is_float))
        self._fire_sinks(MEMORY_READ, ctx,
                         {"addr": addr, "size": size_i,
                          "value": result, "region": region_name,
                          "is_float": bool(is_float)})
        self._fire_global_event_if_applicable(
            ctx, addr=addr, size=size_i, value=result,
            region_name=region_name, is_float=bool(is_float),
            is_write=False)
        return result

    def symbolic_store(self, addr, val, size, is_float):
        if not _is_z3(addr):
            return NotImplemented
        z3 = _z3_module()
        if z3 is None:
            return NotImplemented
        path = self._path
        region_name = getattr(path, "_region_at_suspension", None)
        size_i = int(size)
        layout = self._layout

        ctx = self._make_ctx()
        ctx.region = region_name
        self._fire_observers(SYMBOLIC_STORE, Phase.BEFORE, ctx,
                             addr=addr, size=size_i,
                             value=val, is_float=bool(is_float),
                             region=region_name)

        coerce = self._coerce_store_value

        def _default(c, a, v, sz):
            if region_name is None or layout is None:
                return NotImplemented
            region = layout.region_for_name(region_name)
            if region is None:
                return NotImplemented
            val_z = coerce(v, sz, z3)
            if val_z is None:
                return NotImplemented
            for i in range(sz):
                region.store_byte(a + i, _z3_byte_at(val_z, i))
            return True

        handlers = self._matching_handlers(
            SYMBOLIC_STORE,
            lambda sel: (sel.matches_region(region_name) and
                         sel.matches_name(region_name)))
        chain = _build_chain(handlers, _default)
        result = chain(ctx, addr, val, size_i)

        if result is NotImplemented:
            return NotImplemented

        self._fire_observers(SYMBOLIC_STORE, Phase.AFTER, ctx,
                             addr=addr, size=size_i,
                             value=val, is_float=bool(is_float),
                             handled=True, region=region_name)
        self._fire_observers(MEMORY_WRITE, Phase.BEFORE, ctx,
                             addr=addr, size=size_i,
                             value=val, is_float=bool(is_float),
                             region=region_name)
        self._fire_observers(MEMORY_WRITE, Phase.AFTER, ctx,
                             addr=addr, size=size_i,
                             value=val, is_float=bool(is_float),
                             handled=True, region=region_name)
        self._record_memory_event(ctx, MEMORY_WRITE, addr, size_i,
                                  region_name, value=val,
                                  is_float=bool(is_float))
        self._fire_sinks(MEMORY_WRITE, ctx,
                         {"addr": addr, "size": size_i,
                          "value": val, "region": region_name,
                          "is_float": bool(is_float)})
        self._fire_global_event_if_applicable(
            ctx, addr=addr, size=size_i, value=val,
            region_name=region_name, is_float=bool(is_float),
            is_write=True)
        return True

    def _coerce_store_value(self, val, size, z3):
        """Lift a substrate-shaped store value to a z3 BitVec of `8*size`
        bits. Accepts ints, bools, Python floats, and z3 BitVecs.
        Floats pack via the IEEE byte pattern (size 4 → f32, size 8 →
        f64); the resulting BitVec is the bit pattern of the float,
        matching how concrete float stores land on the substrate's
        byte buffer. Returns None for shapes the overlay can't
        represent."""
        bits = 8 * int(size)
        if isinstance(val, bool):
            return z3.BitVecVal(int(val), bits)
        if isinstance(val, int):
            return z3.BitVecVal(val & ((1 << bits) - 1), bits)
        if isinstance(val, float):
            byte_order = self._engine.endian
            prefix = "<" if byte_order == Endian.LITTLE else ">"
            if int(size) == 4:
                packed = _struct.pack(f"{prefix}f", val)
            elif int(size) == 8:
                packed = _struct.pack(f"{prefix}d", val)
            else:
                return None
            return z3.BitVecVal(int.from_bytes(packed, byte_order), bits)
        if isinstance(val, z3.BitVecRef):
            return _z3_resize(val, bits)
        return None

    def resolve_call(self, call_inst=None, target_eid=0, indirect_eid=0,
                     target_addr=0, args_list=(), is_indirect=False):
        # Args land as a Python list of raw values (ints, SymExprs, z3
        # expressions, …). Build an ArgsView over them so hooks have a
        # consistent lens API.
        args = list(args_list)
        ctx = self._make_ctx(args=args)
        ctx.inst = call_inst

        target_name = self._lookup_name(target_eid)
        indirect_name = self._lookup_name(indirect_eid)

        event = INDIRECT_CALL if is_indirect else CALL
        target_for_match = (indirect_eid if is_indirect and indirect_eid
                            else target_eid)
        candidate_name = (indirect_name if is_indirect and indirect_name
                          else target_name)

        self._fire_observers(event, Phase.BEFORE, ctx,
                             target_eid=target_for_match,
                             name=candidate_name, args=args,
                             target_addr=target_addr,
                             is_indirect=is_indirect)

        this_target_kind = "concrete" if is_indirect else None

        def _match(sel):
            if not sel.matches_name(candidate_name):
                return False
            if not sel.matches_eid(target_for_match):
                return False
            if not sel.matches_target_kind(this_target_kind):
                return False
            return True

        handlers = self._matching_handlers(event, _match)
        # Indirect-call hooks expect `(ctx, target_addr, next_hook)` per
        # the design doc; direct-call hooks expect `(ctx, next_hook)`.
        if is_indirect:
            chain = _build_chain(handlers, _default_indirect_call)
            chosen = chain(ctx, int(target_addr))
        else:
            chain = _build_chain(handlers, _default_call)
            chosen = chain(ctx)

        if chosen is _DEFER:
            self._fire_observers(event, Phase.AFTER, ctx,
                                 target_eid=target_for_match,
                                 name=candidate_name, args=args,
                                 target_addr=target_addr,
                                 is_indirect=is_indirect, return_value=None,
                                 handled=False)
            # No handler claimed the call: tell the substrate to fall
            # through to its own resolver. NotImplemented (matching
            # mem_read / mem_write and the pure ops) is the
            # fall-through signal; None is now a real "stub with None".
            return NotImplemented

        self._fire_observers(event, Phase.AFTER, ctx,
                             target_eid=target_for_match,
                             name=candidate_name, args=args,
                             target_addr=target_addr,
                             is_indirect=is_indirect, return_value=chosen,
                             handled=True)
        # Handlers return their replacement value directly; the
        # substrate treats any non-NotImplemented return as a skip with
        # that value (None included — that's the stub-with-None case).
        return chosen

    # ----- pure ops: propagate symbolic values, else fall through -----

    def compare(self, op, lhs, rhs):
        if _is_concrete(lhs) and _is_concrete(rhs):
            return NotImplemented
        if _is_z3(lhs) or _is_z3(rhs):
            z = _z3_compare(op, lhs, rhs)
            if z is not None:
                return z
        return SymExpr("cmp", (op, lhs, rhs))

    def binary_op(self, op, lhs, rhs):
        sinks = getattr(self._engine, "sinks", None)
        if sinks is not None and len(sinks):
            ctx = self._make_ctx()
            self._fire_sinks(EventKind.BINARY_OP, ctx,
                             {"op": int(op), "lhs": lhs, "rhs": rhs})
        if _is_concrete(lhs) and _is_concrete(rhs):
            return NotImplemented
        if _is_z3(lhs) or _is_z3(rhs):
            z = _z3_binary(op, lhs, rhs)
            if z is not None:
                return z
        return SymExpr("bin", (op, lhs, rhs))

    def unary_op(self, op, operand):
        if _is_concrete(operand):
            return NotImplemented
        if _is_z3(operand):
            z = _z3_unary(op, operand)
            if z is not None:
                return z
        return SymExpr("un", (op, operand))

    def cast(self, op, operand):
        if _is_concrete(operand):
            return NotImplemented
        if _is_z3(operand):
            z = _z3_cast(op, operand)
            if z is not None:
                return z
        return SymExpr("cast", (op, operand))

    # ----- pointer arithmetic: lower symbolic operands to z3 BitVec(64) -----

    def ptr_add(self, base, index, element_size):
        if _is_concrete(base) and _is_concrete(index):
            return NotImplemented
        z3 = _z3_module()
        if z3 is None:
            return SymExpr("ptr_add", (base, index, element_size))
        base_z = self._addr_as_z3(base, z3)
        idx_z = self._addr_as_z3(index, z3)
        if base_z is None or idx_z is None:
            return SymExpr("ptr_add", (base, index, element_size))
        base_z = _z3_resize(base_z, 64)
        idx_z = _z3_resize(idx_z, 64, signed=True)
        return z3.simplify(base_z + idx_z * z3.BitVecVal(int(element_size), 64))

    def ptr_diff(self, lhs, rhs, element_size):
        if _is_concrete(lhs) and _is_concrete(rhs):
            return NotImplemented
        z3 = _z3_module()
        if z3 is None:
            return SymExpr("ptr_diff", (lhs, rhs, element_size))
        l = self._addr_as_z3(lhs, z3)
        r = self._addr_as_z3(rhs, z3)
        if l is None or r is None:
            return SymExpr("ptr_diff", (lhs, rhs, element_size))
        diff = l - r
        if int(element_size) > 1:
            diff = z3.UDiv(diff, z3.BitVecVal(int(element_size), 64))
        return diff

    def ptr_offset(self, base, byte_offset):
        if _is_concrete(base):
            return NotImplemented
        z3 = _z3_module()
        if z3 is None:
            return SymExpr("ptr_offset", (base, byte_offset))
        base_z = self._addr_as_z3(base, z3)
        if base_z is None:
            return SymExpr("ptr_offset", (base, byte_offset))
        return base_z + z3.BitVecVal(int(byte_offset), 64)

    def _addr_as_z3(self, value, z3):
        """Normalize a substrate address-shaped value to a z3 BitVec.

        Accepts: a z3 ExprRef (passes through) or a Python int / bool
        (concrete pointer — wrap as a 64-bit BitVecVal). Anything else
        returns None so callers can fall back to a SymExpr.
        """
        if isinstance(value, z3.ExprRef):
            return value
        if isinstance(value, bool):
            return z3.BitVecVal(int(value), 64)
        if isinstance(value, int):
            return z3.BitVecVal(int(value), 64)
        return None

    # ----- Phase 8d: per-block-enter event ---------------------------

    def on_enter_block(self, block_id):
        """Fired by the substrate at the top of every `enter_block`.
        Fans out to `engine.observe.block_enter` and appends a
        structured `block_enter` entry to `path.events` so renderers
        like `path.dot_cfg` can walk every visited block (not just
        branch transitions)."""
        ctx = self._make_ctx()
        ctx.block = int(block_id)
        self._fire_observers(BLOCK_ENTER, Phase.AFTER, ctx,
                             block=int(block_id))
        # _fire_observers auto-records the event when an observer was
        # registered; otherwise we still want the event on path.events
        # so dot_cfg can render block visits without requiring the
        # analyst to register a no-op observer.
        path = self._path
        if path is None:
            return
        if self._engine._observers.lookup((BLOCK_ENTER, Phase.AFTER)):
            return
        path.events.append({
            "kind": BLOCK_ENTER,
            "phase": Phase.AFTER,
            "block": int(block_id),
            "step": getattr(path, "steps", 0),
        })

    # ----- Phase: per-instruction observe hook ----------------------

    def on_instruction(self, inst):
        """Fired by the substrate before every non-trivial instruction.
        Fans out to `engine.observe.instruction` observers."""
        if not self._engine._observers.lookup((INSTRUCTION, Phase.AFTER)):
            return
        ctx = self._make_ctx()
        ctx.inst = inst
        self._fire_observers(INSTRUCTION, Phase.AFTER, ctx, inst=inst)

    def on_global_initialized(self, init_func, addr):
        """Fired by the substrate when a GLOBAL_INITIALIZER /
        THREAD_LOCAL_INITIALIZER frame returns — i.e. the global's IR
        initializer has finished executing. Fans out to
        `engine.observe.global_initialized` observers.

        `init_func` is the initializer IRFunction; `init_func.source_declaration`
        is the VarDecl. `addr` is the global's virtual address (int)."""
        if not self._engine._observers.lookup(
                (GLOBAL_INITIALIZED, Phase.AFTER)):
            return
        decl = init_func.source_declaration if init_func is not None else None
        name = None
        eid = 0
        if decl is not None:
            try:
                name = str(decl.name) if decl.name else None
            except Exception:
                name = None
            try:
                eid = int(decl.id)
            except (AttributeError, TypeError):
                eid = 0
        ctx = self._make_ctx()
        self._fire_observers(GLOBAL_INITIALIZED, Phase.AFTER, ctx,
                             init_func=init_func, decl=decl,
                             name=name, eid=eid, addr=int(addr))

    # ----- bulk memory ops (memcpy / memset / strlen / …) ----------
    #
    # The C++ substrate calls this for every IR MEMORY op whose
    # sub-opcode is in the bulk range (32..56). Returning
    # `NotImplemented` falls back to the substrate's concrete impl
    # (raw `ConcreteMemory::memcpy/memset/read` — bypasses every
    # hook); returning anything else is the IR result of the bulk op.
    #
    # The chain bottom (`_make_bulk_default`) decomposes supported ops
    # into per-byte `mem_read` / `mem_write` calls so analyst hooks
    # registered for `memory_read` / `memory_write` fire correctly.

    def mem_bulk_op(self, op, ops):
        try:
            op_name = _memop_name(op)
        except ValueError:
            # Op value outside the MemOp enum (shouldn't happen, but
            # don't crash the substrate if it does).
            return NotImplemented
        ctx = self._make_ctx()
        ctx.op = op_name

        handlers = self._matching_handlers(
            BULK_MEMORY, lambda sel: sel.matches_op(op_name))
        default = self._make_bulk_default(op_name)
        if default is None and not handlers:
            return NotImplemented
        if default is None:
            # Op kind has no built-in decomposer but at least one
            # analyst handler is registered. Bottom of the chain
            # signals "fall through to concrete" if every handler
            # delegates downstream.
            def default(*_args, **_kwargs):
                return NotImplemented

        chain = _build_chain(handlers, default)
        return chain(ctx, *list(ops))

    def _make_bulk_default(self, op_name):
        if op_name in ("memcpy", "memmove"):
            return self._default_memcpy_like
        if op_name == "memset":
            return self._default_memset
        if op_name == "bzero":
            return self._default_bzero
        if op_name == "memcmp":
            return self._default_memcmp
        if op_name == "memchr":
            return self._default_memchr
        if op_name == "strlen":
            return self._default_strlen
        if op_name == "strnlen":
            return self._default_strnlen
        if op_name == "strcmp":
            return self._default_strcmp
        if op_name == "strncmp":
            return self._default_strncmp
        if op_name == "strchr":
            return self._default_strchr
        if op_name == "strrchr":
            return self._default_strrchr
        if op_name in ("strcpy", "stpcpy"):
            return self._make_strcpy_like(op_name == "stpcpy")
        if op_name in ("strncpy", "stpncpy"):
            return self._make_strncpy_like(op_name == "stpncpy")
        if op_name == "strcat":
            return self._default_strcat
        if op_name == "strncat":
            return self._default_strncat
        return None

    # Per-op default decomposers. Each returns NotImplemented when an
    # operand or a byte read is non-concrete and the op's semantics
    # depend on the concrete value (e.g., a symbolic length, a
    # symbolic null-terminator). Falling back to concrete preserves
    # pre-existing behavior for those cases — analysts who want
    # symbolic modelling intercept the bulk op themselves.

    def _default_memcpy_like(self, ctx, dst, src, n):
        n_int = _coerce_int(n)
        dst_int = _coerce_int(dst)
        src_int = _coerce_int(src)
        if n_int is None or dst_int is None or src_int is None:
            return NotImplemented
        # Probe `src` for backing memory. The IR uses MEMCPY for
        # struct-return-by-value: when the struct fits in a register
        # the "src" value isn't a pointer, it's the raw u64 bit
        # pattern of the struct. The C++ concrete fallback distinguishes
        # those by trying a 1-byte probe; we mirror that here so the
        # decomposition only handles real pointer-to-pointer copies.
        if src_int == 0 or self._memory is None:
            return NotImplemented
        try:
            self._memory.read_bytes(src_int, 1)
        except RuntimeError:
            return NotImplemented
        for i in range(n_int):
            byte = self.mem_read(src_int + i, 1, False)
            if byte is NotImplemented:
                return NotImplemented
            self.mem_write(dst_int + i, byte, 1, False)
        return dst

    def _default_memset(self, ctx, dst, byte_val, n):
        n_int = _coerce_int(n)
        dst_int = _coerce_int(dst)
        if n_int is None or dst_int is None:
            return NotImplemented
        b_int = _coerce_int(byte_val)
        masked = (b_int & 0xFF) if b_int is not None else byte_val
        for i in range(n_int):
            self.mem_write(dst_int + i, masked, 1, False)
        return dst

    def _default_bzero(self, ctx, dst, n):
        n_int = _coerce_int(n)
        dst_int = _coerce_int(dst)
        if n_int is None or dst_int is None:
            return NotImplemented
        for i in range(n_int):
            self.mem_write(dst_int + i, 0, 1, False)
        return dst

    def _default_memcmp(self, ctx, a, b, n):
        n_int = _coerce_int(n)
        a_int = _coerce_int(a)
        b_int = _coerce_int(b)
        if n_int is None or a_int is None or b_int is None:
            return NotImplemented
        for i in range(n_int):
            ba = _coerce_int(self.mem_read(a_int + i, 1, False))
            bb = _coerce_int(self.mem_read(b_int + i, 1, False))
            if ba is None or bb is None:
                return NotImplemented
            if ba != bb:
                return -1 if ba < bb else 1
        return 0

    def _default_memchr(self, ctx, addr, byte, n):
        n_int = _coerce_int(n)
        addr_int = _coerce_int(addr)
        b_int = _coerce_int(byte)
        if n_int is None or addr_int is None or b_int is None:
            return NotImplemented
        needle = b_int & 0xFF
        for i in range(n_int):
            byte_val = _coerce_int(self.mem_read(addr_int + i, 1, False))
            if byte_val is None:
                return NotImplemented
            if byte_val == needle:
                return addr_int + i
        return 0  # null pointer

    def _default_strlen(self, ctx, addr):
        addr_int = _coerce_int(addr)
        if addr_int is None:
            return NotImplemented
        i = 0
        while True:
            byte = _coerce_int(self.mem_read(addr_int + i, 1, False))
            if byte is None:
                return NotImplemented
            if byte == 0:
                return i
            i += 1

    def _default_strnlen(self, ctx, addr, max_len):
        addr_int = _coerce_int(addr)
        max_int = _coerce_int(max_len)
        if addr_int is None or max_int is None:
            return NotImplemented
        for i in range(max_int):
            byte = _coerce_int(self.mem_read(addr_int + i, 1, False))
            if byte is None:
                return NotImplemented
            if byte == 0:
                return i
        return max_int

    def _default_strcmp(self, ctx, a, b):
        a_int = _coerce_int(a)
        b_int = _coerce_int(b)
        if a_int is None or b_int is None:
            return NotImplemented
        i = 0
        while True:
            ba = _coerce_int(self.mem_read(a_int + i, 1, False))
            bb = _coerce_int(self.mem_read(b_int + i, 1, False))
            if ba is None or bb is None:
                return NotImplemented
            if ba != bb:
                return -1 if ba < bb else 1
            if ba == 0:
                return 0
            i += 1

    def _default_strncmp(self, ctx, a, b, n):
        n_int = _coerce_int(n)
        a_int = _coerce_int(a)
        b_int = _coerce_int(b)
        if n_int is None or a_int is None or b_int is None:
            return NotImplemented
        for i in range(n_int):
            ba = _coerce_int(self.mem_read(a_int + i, 1, False))
            bb = _coerce_int(self.mem_read(b_int + i, 1, False))
            if ba is None or bb is None:
                return NotImplemented
            if ba != bb:
                return -1 if ba < bb else 1
            if ba == 0:
                return 0
        return 0

    def _default_strchr(self, ctx, addr, byte):
        addr_int = _coerce_int(addr)
        b_int = _coerce_int(byte)
        if addr_int is None or b_int is None:
            return NotImplemented
        needle = b_int & 0xFF
        i = 0
        while True:
            byte_val = _coerce_int(self.mem_read(addr_int + i, 1, False))
            if byte_val is None:
                return NotImplemented
            if byte_val == needle:
                return addr_int + i
            if byte_val == 0:
                return addr_int + i if needle == 0 else 0
            i += 1

    def _default_strrchr(self, ctx, addr, byte):
        addr_int = _coerce_int(addr)
        b_int = _coerce_int(byte)
        if addr_int is None or b_int is None:
            return NotImplemented
        needle = b_int & 0xFF
        last = -1
        i = 0
        while True:
            byte_val = _coerce_int(self.mem_read(addr_int + i, 1, False))
            if byte_val is None:
                return NotImplemented
            if byte_val == needle:
                last = i
            if byte_val == 0:
                break
            i += 1
        return (addr_int + last) if last >= 0 else 0

    def _make_strcpy_like(self, return_end):
        """`strcpy` (return_end=False) and `stpcpy` (return_end=True)
        share a body: walk src copying bytes (including the null
        terminator) into dst. `stpcpy` returns a pointer to the
        copied null; `strcpy` returns dst."""
        def default(ctx, dst, src):
            dst_int = _coerce_int(dst)
            src_int = _coerce_int(src)
            if dst_int is None or src_int is None:
                return NotImplemented
            i = 0
            while True:
                byte = self.mem_read(src_int + i, 1, False)
                b_int = _coerce_int(byte)
                if b_int is None:
                    return NotImplemented
                self.mem_write(dst_int + i, byte, 1, False)
                if b_int == 0:
                    return (dst_int + i) if return_end else dst
                i += 1
        return default

    def _make_strncpy_like(self, return_end):
        """`strncpy` (return_end=False) and `stpncpy` (return_end=True).
        Copy at most n bytes of src to dst; if src is shorter than n,
        the remaining dst bytes are zero-filled. `stpncpy` returns a
        pointer to the byte AFTER the last non-null byte copied (or
        dst+n if no null was found in the first n)."""
        def default(ctx, dst, src, n):
            n_int = _coerce_int(n)
            dst_int = _coerce_int(dst)
            src_int = _coerce_int(src)
            if n_int is None or dst_int is None or src_int is None:
                return NotImplemented
            hit_null_at = -1
            for i in range(n_int):
                byte = self.mem_read(src_int + i, 1, False)
                b_int = _coerce_int(byte)
                if b_int is None:
                    return NotImplemented
                if hit_null_at >= 0:
                    self.mem_write(dst_int + i, 0, 1, False)
                else:
                    self.mem_write(dst_int + i, byte, 1, False)
                    if b_int == 0:
                        hit_null_at = i
            if return_end:
                return (dst_int + hit_null_at) if hit_null_at >= 0 \
                    else (dst_int + n_int)
            return dst
        return default

    def _default_strcat(self, ctx, dst, src):
        dst_int = _coerce_int(dst)
        src_int = _coerce_int(src)
        if dst_int is None or src_int is None:
            return NotImplemented
        # Find end of dst.
        end = 0
        while True:
            byte = _coerce_int(self.mem_read(dst_int + end, 1, False))
            if byte is None:
                return NotImplemented
            if byte == 0:
                break
            end += 1
        # Copy src (including null) to dst+end.
        i = 0
        while True:
            byte = self.mem_read(src_int + i, 1, False)
            b_int = _coerce_int(byte)
            if b_int is None:
                return NotImplemented
            self.mem_write(dst_int + end + i, byte, 1, False)
            if b_int == 0:
                return dst
            i += 1

    def _default_strncat(self, ctx, dst, src, n):
        n_int = _coerce_int(n)
        dst_int = _coerce_int(dst)
        src_int = _coerce_int(src)
        if n_int is None or dst_int is None or src_int is None:
            return NotImplemented
        end = 0
        while True:
            byte = _coerce_int(self.mem_read(dst_int + end, 1, False))
            if byte is None:
                return NotImplemented
            if byte == 0:
                break
            end += 1
        copied = 0
        while copied < n_int:
            byte = self.mem_read(src_int + copied, 1, False)
            b_int = _coerce_int(byte)
            if b_int is None:
                return NotImplemented
            self.mem_write(dst_int + end + copied, byte, 1, False)
            if b_int == 0:
                return dst
            copied += 1
        # No null in first n bytes; append a terminator.
        self.mem_write(dst_int + end + copied, 0, 1, False)
        return dst

    # ----- truth + branch resolution: fork on non-concrete -----

    def is_true(self, val):
        # If the analyst registered any BRANCH handlers, fall through to
        # `resolve_branch` (where we have the target eids) so they get a
        # chance to fire. The Phase 2 fast path only applies when no
        # handler is interested.
        if self._engine._intercepts.lookup(BRANCH):
            return None
        # Genuinely symbolic truths force a fork. Concrete-shaped z3
        # (e.g. an ``Eq`` of two ``BitVecVal``s that simplifies to
        # True/False) resolves concretely so the substrate doesn't
        # explode the path set on a known-determined branch.
        decided = _concrete_bool(val)
        if decided is None:
            return None
        return decided

    def resolve_branch(self, branch_inst, condition, true_eid, false_eid):
        ctx = self._make_ctx()
        ctx.inst = branch_inst
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
        if not handlers:
            # Phase 2 fast path: resolve concretely when we can.
            # Covers Python ints AND z3 expressions that simplify to
            # a concrete bool, so a determinate branch on lifted-from-
            # memory pointers doesn't force a fork.
            decided = _concrete_bool(condition)
            if decided is not None:
                return decided
            return None  # genuinely symbolic — let substrate fork

        chain = _build_chain(handlers, _default_branch)
        chosen = chain(ctx, condition)

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

    def _fire_sinks(self, event_kind, ctx, payload):
        sinks = getattr(self._engine, "sinks", None)
        if sinks is None or len(sinks) == 0:
            return
        sinks.fire(event_kind, ctx, payload)

    def _record_memory_event(self, ctx, kind, addr, size, region_name,
                              **extra):
        """Append a memory event to `path.events` regardless of whether
        an observer was registered. The event drives
        `path.regions_touched()` and the events-based filters used by
        sinks and analyst queries. Skipped if `ctx.path is None`
        (synthesized/test contexts that don't carry a Path)."""
        path = ctx.path
        if path is None:
            return
        # If an observer for this event also fired (auto-record path),
        # avoid duplicating the entry.
        if self._engine._observers.lookup((kind, Phase.AFTER)):
            return
        entry = {"kind": kind, "phase": Phase.AFTER,
                 "addr": addr, "size": size, "region": region_name,
                 "handled": True}
        entry.update(extra)
        path.events.append(entry)

    def _region_name_for(self, addr):
        layout = self._layout
        if layout is None:
            return None
        region = layout.region_containing(addr)
        return region.name if region is not None else None

    def _fire_global_event_if_applicable(self, ctx, *, addr, size, value,
                                          region_name, is_float, is_write):
        """Fan a `mem_read` / `mem_write` (or its symbolic peer) out to
        `GLOBAL_READ` / `GLOBAL_WRITE` observers when the access lands
        in a `kind == "global"` region. Lazy / function-placement
        regions don't qualify — they aren't analyst-named globals.

        Observer-only fan-out: analysts who want to *change* what a
        global read returns already use
        `intercept.memory_read(addr_range=("name", N))` — the
        named-region selector routes correctly there. When the access
        path went through `symbolic_load` / `symbolic_store`, `addr`
        and (for reads) `value` are z3 expressions; observer hooks
        that expect ints must guard accordingly."""
        if region_name is None or self._layout is None:
            return
        region = self._layout.region_for_name(region_name)
        if region is None or region.kind != "global":
            return
        global_event = GLOBAL_WRITE if is_write else GLOBAL_READ
        self._fire_observers(global_event, Phase.AFTER, ctx,
                             name=region_name, addr=addr,
                             size=size, value=value,
                             is_float=is_float)

    def _mirror_concrete_write_to_overlay(self, addr, val, size, region_name):
        layout = self._layout
        if layout is None:
            return
        region = layout.region_for_name(region_name)
        if region is None or not region.has_overlay():
            return
        # Convert the value into an integer bit pattern, then store
        # one byte at a time into the overlay. Pointer-typed values
        # are written as their address bits; bytes/bytearray writes
        # are spelled out byte-wise.
        if isinstance(val, bool):
            int_val = int(val)
        elif isinstance(val, int):
            int_val = val
        elif isinstance(val, _BYTES_TYPES):
            i = 0
            for b in val:
                region.store_byte(addr + i, int(b) & 0xFF)
                i += 1
            return
        else:
            # Unhandled value shape (z3 expr written through concrete
            # addr, etc.) — skip mirroring; next symbolic read sees
            # the prior overlay state, which is the conservative
            # answer.
            return
        if int_val < 0:
            int_val &= (1 << (size * 8)) - 1
        for i in range(size):
            byte = (int_val >> (8 * i)) & 0xFF
            region.store_byte(addr + i, byte)

    def _fire_observers(self, event, phase, ctx, **payload):
        registry = self._engine._observers
        key = (event, phase)
        for selector, handler in registry.lookup(key):
            if not _selector_matches_payload(selector, event, payload):
                continue
            handler(ctx, **payload)
            self._auto_record_event(ctx, event, phase, payload)

    def _auto_record_event(self, ctx, event, phase, payload):
        """Append a structured entry to path.events after each observer
        run. Branches are recorded by the driver itself; suppress here
        to avoid duplicates."""
        if event == BRANCH:
            return
        if phase != Phase.AFTER:
            return
        path = ctx.path
        if path is None:
            return
        entry = {"kind": event, "phase": phase}
        for k, v in payload.items():
            entry[k] = v
        path.events.append(entry)

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
    policy help: ints, bools, None."""
    if value is None:
        return True
    if isinstance(value, _INT_TYPES):
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
    if event == GLOBAL_INITIALIZED:
        if not selector.matches_name(payload.get("name")):
            return False
        if not selector.matches_eid(payload.get("eid")):
            return False
        addr = payload.get("addr")
        if addr is not None and not selector.matches_addr(addr):
            return False
        return True
    # Phase 9: address_for / address_resolved filter on kind= / name= / eid=
    if event in (ADDRESS_FOR, ADDRESS_RESOLVED):
        if not selector.matches_kind(payload.get("kind")):
            return False
        if not selector.matches_name(payload.get("name")):
            return False
        if not selector.matches_eid(payload.get("eid")):
            return False
        return True
    return True
