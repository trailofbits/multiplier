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
    EventKind, Phase, CallAction, VALUE_TAG_PTR,
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
    if isinstance(addr, tuple) and len(addr) == 2 and addr[0] == VALUE_TAG_PTR:
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

    __slots__ = ("addr_range", "name", "eid", "func", "block", "region",
                 "_layout", "_resolved_range", "kind", "target_kind", "decl")

    def __init__(self, addr_range=None, name=None, eid=None, func=None,
                 block=None, region=None, layout=None,
                 kind=None, target_kind=None, decl=None):
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

from ._types import _BYTES_TYPES, _INT_TYPES, _SEQ_TYPES

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
        # Simplify before per-byte decomposition: when ``val`` was
        # constructed by re-concatenating bytes earlier read from the
        # shadow (the common round-trip), z3 collapses the
        # ``Extract(i+7, i, Concat(b_n, …, b_0))`` patterns back to the
        # original byte expressions. Without this, every load-modify-store
        # cycle accumulates Concat/Extract layers around the same bytes.
        val = z3.simplify(val)
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
    return z3.simplify(result)


def _make_default_mem_read(is_float, shadow=None, buf=None, byte_order="little"):
    """Return the chain bottom for a memory_read event.

    Reads baseline bytes from ``ConcreteMemory`` first (always needed as
    fallback), then defers to ``_shadow_read`` which checks the per-path
    shadow dict.  Shadow entries shadow the baseline; any range with no
    shadow entry goes straight to the concrete fallback.  Falls back to
    zero-fill on a read failure so OOB sinks still fire.
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
                return sym
        if is_float and size == 4:
            fmt = "<f" if byte_order == "little" else ">f"
            return _struct.unpack(fmt, data)[0]
        if is_float and size == 8:
            fmt = "<d" if byte_order == "little" else ">d"
            return _struct.unpack(fmt, data)[0]
        return int.from_bytes(data, byte_order, signed=False)
    return default


def _make_default_mem_write(is_float, shadow=None, byte_order="little"):
    """Return the chain bottom for a memory_write event.

    Writes concrete bytes via the lens. Handles ints, ("ptr", N) pointer
    tuples, raw bytes, and IEEE floats. A z3 write decomposes ``val`` into
    per-byte extracts in the shadow dict; a concrete write clears any
    covered shadow slots (concrete memory is the source of truth) and
    writes the real bytes to ``ConcreteMemory``.
    """
    def default(ctx, addr, val, size):
        if isinstance(val, bool):
            val = int(val)
        if isinstance(val, int):
            if shadow is not None:
                _shadow_write(shadow, addr, val, size)
            ctx.mem.write_bytes(
                addr, val.to_bytes(size, byte_order, signed=(val < 0)))
            return None
        if isinstance(val, tuple) and len(val) == 2 and val[0] == VALUE_TAG_PTR:
            if shadow is not None:
                _shadow_write(shadow, addr, val, size)
            ctx.mem.write_bytes(
                addr, int(val[1]).to_bytes(size, byte_order, signed=False))
            return None
        if isinstance(val, _BYTES_TYPES):
            if shadow is not None:
                _shadow_write(shadow, addr, val, size)
            ctx.mem.write_bytes(addr, val)
            return None
        if isinstance(val, float):
            if shadow is not None:
                _shadow_write(shadow, addr, val, size)
            prefix = "<" if byte_order == "little" else ">"
            fmt = f"{prefix}f" if size == 4 else f"{prefix}d"
            ctx.mem.write_bytes(addr, _struct.pack(fmt, val))
            return None
        if shadow is not None and _is_z3(val):
            _shadow_write(shadow, addr, val, size)
            return None
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
    BranchContinuation.
    """
    if isinstance(condition, _INT_TYPES):
        return condition != 0
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
                                                    byte_order=str(self._engine.endian)))
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
                                                     byte_order=str(self._engine.endian)))
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
        bits. Accepts ints, bools, Python floats, `("ptr", N)` tuples,
        and z3 BitVecs. Floats pack via the IEEE byte pattern (size 4 →
        f32, size 8 → f64); the resulting BitVec is the bit pattern of
        the float, matching how concrete float stores land on the
        substrate's byte buffer. Returns None for shapes the overlay
        can't represent."""
        bits = 8 * int(size)
        if isinstance(val, bool):
            return z3.BitVecVal(int(val), bits)
        if isinstance(val, int):
            return z3.BitVecVal(val & ((1 << bits) - 1), bits)
        if isinstance(val, float):
            byte_order = str(self._engine.endian)
            prefix = "<" if byte_order == "little" else ">"
            if int(size) == 4:
                packed = _struct.pack(f"{prefix}f", val)
            elif int(size) == 8:
                packed = _struct.pack(f"{prefix}d", val)
            else:
                return None
            return z3.BitVecVal(int.from_bytes(packed, byte_order), bits)
        if isinstance(val, tuple) and len(val) == 2 and \
                val[0] == VALUE_TAG_PTR:
            return z3.BitVecVal(int(val[1]) & ((1 << bits) - 1), bits)
        if isinstance(val, z3.BitVecRef):
            return _z3_resize(val, bits)
        return None

    def resolve_call(self, call_inst=None, target_eid=0, indirect_eid=0,
                     target_addr=0, args_list=(), is_indirect=False):
        # Args land as a Python list of raw values (ints, ("ptr", N)
        # tuples, SymExprs, …). Build an ArgsView over them so hooks
        # have a consistent lens API.
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
            return None  # PythonPolicy treats None as "fall through".

        self._fire_observers(event, Phase.AFTER, ctx,
                             target_eid=target_for_match,
                             name=candidate_name, args=args,
                             target_addr=target_addr,
                             is_indirect=is_indirect, return_value=chosen,
                             handled=True)
        if isinstance(chosen, tuple) and len(chosen) == 2 and \
                chosen[0] in (CallAction.SKIP, CallAction.MODEL):
            return chosen
        return (CallAction.SKIP, chosen)

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

        Accepts: a z3 ExprRef (passes through), a `("ptr", N)` tuple
        (concrete pointer — wrap as a 64-bit BitVecVal), or a Python int
        / bool. Anything else returns None so callers can fall back to a
        SymExpr.
        """
        if isinstance(value, z3.ExprRef):
            return value
        if isinstance(value, tuple) and len(value) == 2 and \
                value[0] == VALUE_TAG_PTR:
            return z3.BitVecVal(int(value[1]), 64)
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

    # ----- truth + branch resolution: fork on non-concrete -----

    def is_true(self, val):
        # z3 truths always force a fork — the substrate enumerates
        # both edges and the branch handler accumulates the path
        # condition.
        if _is_z3(val):
            return None
        # If the analyst registered any BRANCH handlers, fall through to
        # `resolve_branch` (where we have the target eids) so they get a
        # chance to fire. The Phase 2 fast path only applies when no
        # handler is interested.
        if self._engine._intercepts.lookup(BRANCH):
            return None
        if isinstance(val, _INT_TYPES):
            return val != 0
        return None

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
        if not handlers and isinstance(condition, _INT_TYPES) and \
                not _is_z3(condition):
            return condition != 0  # Phase 2 fast path
        if not handlers:
            return None  # symbolic, no handler — let substrate fork

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
        elif (isinstance(val, tuple) and len(val) == 2
              and val[0] == VALUE_TAG_PTR):
            int_val = int(val[1])
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
    policy help: ints, bools, None, and ("ptr", N) tuples."""
    if value is None:
        return True
    if isinstance(value, _INT_TYPES):
        return True
    if isinstance(value, tuple) and len(value) == 2 and \
            value[0] == VALUE_TAG_PTR:
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
