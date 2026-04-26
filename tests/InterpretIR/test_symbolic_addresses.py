"""Symbolic-address forking through the suspension API.

A Python policy that lets the interpreter compute a non-`("ptr", ...)`
value for a load address (e.g. an integer-arithmetic-derived pointer)
will trigger `with_address` to emit a `MemAddrContinuation`.  The driver
picks one or more concrete addresses, calls `resume_addr`, and continues
stepping — once per chosen address.

These tests exercise the full suspension/resumption cycle.
"""

import struct

import pytest

import multiplier as mx
from conftest import find_ir_function

interp = mx.ir.interpret


class _PassthroughPolicy:
    """Empty policy — all hooks fall back to concrete semantics."""
    pass


def _step_until_suspension(state, mem, policy, max_iter=20):
    """Step until the run reaches a suspended/completed/error/budget terminal."""
    for _ in range(max_iter):
        r = interp.step(state, mem, policy, 10000, None, None)
        if r is None:
            return None
        res = r.get("result")
        if res is not None:
            return r
    raise AssertionError("step loop did not terminate")


def test_indirect_load_suspends_on_int_address(index):
    """A pointer arg passed as a Python int triggers a load-addr suspension."""
    ir = find_ir_function(index, "symbolic_test_ptr_add")
    if ir is None:
        pytest.skip("symbolic_test_ptr_add not in index")

    mem = interp.ConcreteMemory()
    buf = mem.allocate(64, 8)
    mem.write_bytes(buf, struct.pack("<iii", 42, 1337, 999))

    policy = _PassthroughPolicy()
    state = interp.InterpreterState()
    interp.init_state(state, mem, policy, ir, [buf, 0], None, None)

    r = _step_until_suspension(state, mem, policy)
    res = r["result"]
    assert res[0] == "suspended"
    assert res[1] == "load-addr"
    assert res[2] == buf
    assert res[4] == 4
    assert res[5] is False

    forks = r["forks"]
    assert len(forks) == 1
    fork = forks[0]
    assert fork["kind"] == "load-addr"
    assert fork["address"] == buf
    assert fork["size"] == 4
    assert fork["is_write"] is False


def test_resume_addr_completes_load(index):
    """resume_addr binds the chosen pointer; step then returns the loaded value."""
    ir = find_ir_function(index, "symbolic_test_ptr_add")
    if ir is None:
        pytest.skip("symbolic_test_ptr_add not in index")

    mem = interp.ConcreteMemory()
    buf = mem.allocate(64, 8)
    mem.write_bytes(buf, struct.pack("<iii", 42, 1337, 999))

    policy = _PassthroughPolicy()
    state = interp.InterpreterState()
    interp.init_state(state, mem, policy, ir, [buf, 0], None, None)

    r = _step_until_suspension(state, mem, policy)
    fork = r["forks"][0]
    forked = fork["state"]
    interp.resume_addr(forked, fork["address_eid"], buf)

    r2 = _step_until_suspension(forked, mem, policy)
    assert r2["result"][0] == "completed"
    assert r2["result"][1] == 42


def test_resume_addr_different_choices_diverge(index):
    """Cloning the snapshot lets the driver explore distinct addresses."""
    ir = find_ir_function(index, "symbolic_test_ptr_add")
    if ir is None:
        pytest.skip("symbolic_test_ptr_add not in index")

    mem = interp.ConcreteMemory()
    buf = mem.allocate(64, 8)
    values = (42, 1337, 999)
    mem.write_bytes(buf, struct.pack("<iii", *values))

    policy = _PassthroughPolicy()
    state = interp.InterpreterState()
    interp.init_state(state, mem, policy, ir, [buf, 0], None, None)

    r = _step_until_suspension(state, mem, policy)
    snap_state = r["forks"][0]["state"]
    addr_eid = r["forks"][0]["address_eid"]

    seen = []
    for offset, expected in enumerate(values):
        clone = interp.clone_state(snap_state)
        interp.resume_addr(clone, addr_eid, buf + offset * 4)
        r2 = _step_until_suspension(clone, mem, policy)
        assert r2["result"][0] == "completed"
        seen.append(r2["result"][1])

    assert tuple(seen) == values


class _OneShotSuspendingPolicy:
    """First `is_true` + `resolve_branch` pair returns None (forces a
    branch suspension); subsequent calls fall through to concrete.

    Lets a single COND_BRANCH suspend; the resumed forks each run their
    bound condition through `is_true` (now concrete) and complete normally.
    """

    def __init__(self):
        self.suspended_once = False

    def is_true(self, val):
        if not self.suspended_once:
            return None
        return bool(val) if isinstance(val, int) else None

    def resolve_branch(self, cond, true_eid, false_eid):
        if not self.suspended_once:
            self.suspended_once = True
            return None  # tell the C++ side to suspend
        return bool(cond) if isinstance(cond, int) else True


def test_branch_next_walks_both_directions(index):
    """`BranchContinuation::next()` enumerates {false, true} forks.

    With one branch suspended, the result dict carries two forks — one
    per direction. Each fork's state has the cond_eid bound to the
    matching literal int and the DECIDE_COND_BRANCH work item re-pushed,
    so stepping it dispatches the correct edge.
    """
    ir = find_ir_function(index, "test_control_flow")
    if ir is None:
        pytest.skip("test_control_flow not in index")

    mem = interp.ConcreteMemory()
    policy = _OneShotSuspendingPolicy()
    state = interp.InterpreterState()
    interp.init_state(state, mem, policy, ir, [], None, None)

    r = _step_until_suspension(state, mem, policy)
    assert r is not None
    forks = r["forks"]
    assert len(forks) == 2

    directions = sorted(f["direction"] for f in forks)
    assert directions == ["false", "true"]

    for fork in forks:
        r2 = _step_until_suspension(fork["state"], mem, policy)
        assert r2 is not None
        assert r2["result"][0] == "completed"


def test_invalid_eid_does_not_suspend(index):
    """`with_address` callsites that pass kInvalidEntityId silently skip
    instead of suspending — the run continues without a fork.

    `read_return_value` and the init-time bulk copies use kInvalidEntityId,
    so a function that returns a small scalar doesn't trip a suspension
    even when no return alloca is wired up.
    """
    ir = find_ir_function(index, "symbolic_test_add_i32")
    if ir is None:
        pytest.skip("symbolic_test_add_i32 not in index")

    mem = interp.ConcreteMemory()
    policy = _PassthroughPolicy()
    state = interp.InterpreterState()
    interp.init_state(state, mem, policy, ir, [3, 4], None, None)

    r = _step_until_suspension(state, mem, policy)
    assert r["result"][0] == "completed"
    assert r["result"][1] == 7
