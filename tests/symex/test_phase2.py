"""Phase 2 — analyst-facing hook layer (intercept + observe).

Catalog (matches docs/symex-vision.md lines 544–612):

P2.1  intercept.memory_read addr_range gating
P2.2  intercept.memory_read returns SymExpr → downstream forks
P2.3  intercept.memory_write returns None (no next_hook) → write dropped
P2.4  intercept.call by name fires; default policy never sees the call
P2.5  intercept.call lens writes through a pointer argument
P2.6  intercept.indirect_call fires on a function-pointer call site
P2.7  intercept.call returns ctx.default() → caller sees default value
P2.8  intercept chain forwards through next_hook
P2.9  intercept.memory_read pre-writes via lens, forwards to next_hook,
       chain bottom returns the pre-written value
P2.10 observe.memory_read records to path.events; baseline output
P2.11 observe.call counts invocations; output unchanged
P2.12 intercept and observe coexist on the same event
P2.13 observer exception is swallowed and logged
P2.14 libc model pack registers all listed entries

`SymExpr` substitutes for `z3.BitVec` in P2.2 — Phase 4 lands the z3
plumbing; the behavioral assertion (symbolic flows through compare,
forks at branch) is the same.
"""

import pytest

from symex import (
    Layout,
    SymExEngine,
    ExploreUntil,
    SymExpr,
    InterceptorPolicy,
    models,
)
from symex.dispatch import extract_addr


# --- P2.1 ----------------------------------------------------------------

def test_p2_1_intercept_memory_read_addr_range(index):
    # outside-the-range half: handler does not fire.
    engine_a = SymExEngine(index)
    fired_a = []

    @engine_a.intercept.memory_read(addr_range=(0x1, 0x100))
    def hook_a(ctx, addr, size, next_hook):
        fired_a.append(addr)
        return 0xDEAD

    paths_a = engine_a.explore("symbolic_test_add_i32", args=[2, 3])
    assert paths_a[0].return_value == 5
    assert fired_a == [], "handler fired despite empty addr_range"

    # wide-range half: handler fires; forwards to next_hook.
    engine_b = SymExEngine(index)
    fired_b = []

    @engine_b.intercept.memory_read(addr_range=(0, 1 << 63))
    def hook_b(ctx, addr, size, next_hook):
        fired_b.append(addr)
        return next_hook(ctx, addr, size)

    paths_b = engine_b.explore("symbolic_test_add_i32", args=[2, 3])
    assert paths_b[0].return_value == 5
    assert len(fired_b) > 0, "handler did not fire over wide range"


# --- P2.2 ----------------------------------------------------------------

def test_p2_2_intercept_memory_read_returns_symbolic(index):
    # First read is replaced with a SymExpr; downstream comparison goes
    # symbolic and the substrate forks.
    engine = SymExEngine(index)
    fired = []

    @engine.intercept.memory_read
    def hook(ctx, addr, size, next_hook):
        if not fired:
            fired.append(addr)
            return SymExpr("user_idx", (addr,))
        return next_hook(ctx, addr, size)

    paths = engine.explore(
        "factorial",
        args=[5],
        until=ExploreUntil.path_count(2),
        slice_steps=400,
    )
    assert len(paths) >= 2, f"expected fork, got {len(paths)} path(s)"
    branch_events = [e for p in paths for e in p.events if e.get("kind") ==
                     "branch"]
    assert branch_events, "no branch event recorded — substrate did not fork"


# --- P2.3 ----------------------------------------------------------------

def test_p2_3_intercept_memory_write_drops_write(index):
    """Direct dispatch test: a handler that doesn't call next_hook and
    returns None drops the write — the chain bottom never runs, so
    memory is unchanged. The InterceptorPolicy here is invoked directly
    so we can verify dispatch semantics in isolation; the matching IR-
    driven scenario rides P2.9 / P2.5."""
    engine = SymExEngine(index)
    layout = Layout()
    layout.place_global("buf", 0x20000, 8, init=42)
    engine.layout = layout

    @engine.intercept.memory_write(addr_range=("buf", 8))
    def hook(ctx, addr, val, size, next_hook):
        # Drop the write: don't forward.
        return None

    policy = InterceptorPolicy(engine, _StubPath(), layout=layout,
                                memory=layout.memory)
    rv = policy.mem_write(("ptr", 0x20000), 99, 4, False)
    assert rv is None  # treated-as-handled
    assert layout.memory.read_bytes(0x20000, 4) == \
        (42).to_bytes(4, "little")  # unchanged


# --- P2.4 ----------------------------------------------------------------

def test_p2_4_intercept_call_by_name(index):
    engine = SymExEngine(index)
    fired = []

    @engine.intercept.call(name="factorial")
    def hook(ctx, next_hook):
        fired.append(("factorial",))
        # Return a sentinel value the caller will see in place of 120.
        return 999

    paths = engine.explore("test_function_calls")
    assert len(paths) == 1
    # test_function_calls returns 2 when factorial(5) != 120.
    assert paths[0].return_value == 2
    assert fired, "intercept.call(name=factorial) did not fire"


# --- P2.5 ----------------------------------------------------------------

def test_p2_5_intercept_call_lens_writes_through_pointer(index):
    """Intercept fill_array, write the buffer through the lens, then
    verify the bytes landed at the captured address. Earlier corpus
    calls (sum_array's array-initializer) misbehave at the substrate
    level, so we short-circuit them with a sentinel intercept so
    fill_array actually fires."""
    engine = SymExEngine(index)
    layout = Layout()
    engine.layout = layout

    @engine.intercept.call(name="sum_array")
    def stub_sum(ctx, next_hook):
        return 150  # let test_array_decay proceed past the first check

    @engine.intercept.call(name="first_element")
    def stub_first(ctx, next_hook):
        return 10

    captured = {}

    @engine.intercept.call(name="fill_array")
    def fill_hook(ctx, next_hook):
        dst = ctx.args.addr(0)
        val = ctx.args.read_int(1, size=4)
        n = ctx.args.read_int(2, size=4)
        for i in range(n):
            ctx.mem.write(dst + i * 4, val, size=4)
        captured["dst"] = dst
        captured["val"] = val
        captured["n"] = n
        return ctx.default()

    engine.explore("test_array_decay")

    assert captured, "fill_array intercept did not fire"
    assert captured["val"] == 42
    assert captured["n"] == 3
    addr = captured["dst"]
    data = layout.memory.read_bytes(addr, 12)
    assert int.from_bytes(data[0:4], "little") == 42
    assert int.from_bytes(data[4:8], "little") == 42
    assert int.from_bytes(data[8:12], "little") == 42


# --- P2.6 ----------------------------------------------------------------

def test_p2_6_intercept_indirect_call_resolution(index):
    """`apply(add, 10, 20)` is an indirect call. The intercept fires
    and short-circuits with a sentinel return; verify dispatch."""
    engine = SymExEngine(index)
    fired = []

    @engine.intercept.indirect_call
    def hook(ctx, next_hook):
        fired.append(True)
        return 4242  # sentinel return

    paths = engine.explore("test_function_calls")
    assert fired, "indirect_call intercept did not fire"
    # apply(add, 5, 6) == 4242 != 11 → test_function_calls returns 4.
    # Earlier checks: add(3,4)==7 ✓, factorial(5)==120 ✓ (no intercept),
    # then `int (*fp)(int,int) = add; fp(10, 20) != 30` is also indirect
    # and returns 4242 → returns 3.
    assert paths[0].return_value == 3


# --- P2.7 ----------------------------------------------------------------

def test_p2_7_intercept_call_default_returns_default(index):
    engine = SymExEngine(index)

    @engine.intercept.call(name="add")
    def hook(ctx, next_hook):
        return ctx.default()

    paths = engine.explore("test_function_calls")
    # add(3, 4) returns the default (None) → 0 != 7 → return 1.
    assert paths[0].return_value == 1


# --- P2.8 ----------------------------------------------------------------

def test_p2_8_chain_forwards_through_next_hook(index):
    """Direct dispatch test: two handlers on overlapping ranges.
    `hook_a` forwards through `next_hook`; `hook_b` short-circuits with
    a value. `hook_a` propagates `hook_b`'s return."""
    engine = SymExEngine(index)
    layout = Layout()
    layout.place_global("buf", 0x20000, 16)
    engine.layout = layout

    order = []

    @engine.intercept.memory_read(addr_range=("buf", 16))
    def hook_a(ctx, addr, size, next_hook):
        order.append("a")
        return next_hook(ctx, addr, size)

    @engine.intercept.memory_read(addr_range=("buf", 16))
    def hook_b(ctx, addr, size, next_hook):
        order.append("b")
        return 0xBEEF

    policy = InterceptorPolicy(engine, _StubPath(), layout=layout,
                                memory=layout.memory)
    rv = policy.mem_read(("ptr", 0x20000), 4, False)
    assert rv == 0xBEEF
    assert order == ["a", "b"]


# --- P2.9 ----------------------------------------------------------------

def test_p2_9_intercept_struct_field_pre_write(index):
    """Direct dispatch test: handler writes a value via the lens, then
    forwards to next_hook so the chain bottom's concrete read fires;
    the natural read returns the pre-written value."""
    engine = SymExEngine(index)
    layout = Layout()
    layout.place_global("buf", 0x20000, 16)
    engine.layout = layout

    @engine.intercept.memory_read(addr_range=("buf", 16))
    def hook(ctx, addr, size, next_hook):
        ctx.mem.write(addr, 0xC0FFEE, size=size)
        return next_hook(ctx, addr, size)

    policy = InterceptorPolicy(engine, _StubPath(), layout=layout,
                                memory=layout.memory)
    rv = policy.mem_read(("ptr", 0x20000), 4, False)
    # Chain bottom reads concrete; the underlying memory now holds
    # 0xC0FFEE because the handler pre-wrote it.
    assert rv == 0xC0FFEE
    assert layout.memory.read_bytes(0x20000, 4) == \
        (0xC0FFEE).to_bytes(4, "little")


# --- P2.10 ---------------------------------------------------------------

def test_p2_10_observe_memory_read_records_to_path(index):
    """Memory events land in `path.events` so analyst queries (sinks,
    region tagging, regions_touched) can run over them — Phase 6
    expanded auto-recording to all paths so baseline and observer runs
    both expose memory events. Both runs return the same value; both
    record memory_read entries."""
    base = SymExEngine(index)
    base_paths = base.explore("symbolic_test_add_i32", args=[2, 3])
    assert base_paths[0].return_value == 5

    engine = SymExEngine(index)

    @engine.observe.memory_read
    def trace(ctx, **payload):
        # Observer registration is no longer required for events to
        # land — the dispatcher records them regardless; this hook
        # just exercises the observer-fired path.
        pass

    paths = engine.explore("symbolic_test_add_i32", args=[2, 3])
    assert paths[0].return_value == 5  # output identical
    mem_events = [e for e in paths[0].events if e.get("kind") ==
                  "memory_read"]
    assert mem_events, "no memory_read entries in path.events"
    base_mem = [e for e in base_paths[0].events
                if e.get("kind") == "memory_read"]
    assert base_mem, "baseline must also expose memory_read entries"
    assert len(mem_events) == len(base_mem)


# --- P2.11 ---------------------------------------------------------------

def test_p2_11_observe_call_counts_invocations(index):
    """Observer fires for every CALL the substrate dispatches; the
    program continues unaffected by the observation. Counts are bumped
    per invocation."""
    engine = SymExEngine(index)
    counter = {"add": 0, "factorial": 0, "apply": 0}

    @engine.observe.call
    def trace(ctx, **payload):
        name = payload.get("name")
        if name in counter:
            counter[name] += 1

    engine.explore("test_function_calls")
    assert counter["add"] >= 1, f"observer never saw 'add': {counter}"
    assert counter["factorial"] >= 1, \
        f"observer never saw 'factorial': {counter}"


# --- P2.12 ---------------------------------------------------------------

def test_p2_12_intercept_and_observe_coexist_on_same_event(index):
    """Intercept rewrites add()'s return; observer sees the rewritten
    return value via the `return_value` payload."""
    engine = SymExEngine(index)
    seen = []

    @engine.intercept.call(name="add")
    def rewrite(ctx, next_hook):
        return 4242

    @engine.observe.call(name="add")
    def watch(ctx, **payload):
        seen.append(payload.get("return_value"))

    paths = engine.explore("test_function_calls")
    # add(3,4)==4242 → 4242 != 7 → returns 1.
    assert paths[0].return_value == 1
    assert seen and seen[0] == 4242


# --- P2.13 ---------------------------------------------------------------

def test_p2_13_observer_exception_does_not_corrupt_path(index):
    engine = SymExEngine(index)

    @engine.observe.memory_read
    def boom(ctx, **payload):
        raise RuntimeError("test bug")

    paths = engine.explore("symbolic_test_add_i32", args=[2, 3])
    # Path completes normally despite observer raising.
    assert paths[0].return_value == 5
    errors = [e for e in paths[0].events if e.get("kind") ==
              "observer_error"]
    assert errors, "observer_error not recorded on path.events"
    assert "test bug" in errors[0]["error"]


# --- P2.14 ---------------------------------------------------------------

def test_p2_14_libc_model_pack_registers_all(index):
    engine = SymExEngine(index)
    engine.use(models.libc)
    # Every libc handler should sit under the "call" event with a
    # name= selector matching the function name.
    registered = {sel.name for sel, _ in
                  engine._intercepts.lookup("call")}
    expected = {"strlen", "memcpy", "memset", "read", "malloc", "free"}
    assert expected.issubset(registered), \
        f"missing libc handlers: {expected - registered}"


# --- helpers -------------------------------------------------------------

class _StubPath:
    """Minimal stand-in for a Path used by direct-dispatch unit tests."""
    def __init__(self):
        self.events = []
        self.tags = set()
        self.solver = None
        self.terminal = None
