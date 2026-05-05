"""Fixtures for the symbolic-execution Python test suite (Phase 0+).

Phase 0 reuses the test database under tests/InterpretIR/ — the existing
fixtures cover enough block structure for mid-block-entry tests. Later
phases will add a dedicated tests/symex/c/ corpus.
"""

import os
import pytest

import multiplier as mx

interp = mx.ir.interpret


class PassthroughPolicy:
    """Empty policy — all operations fall back to the C++ default."""
    pass


class SymExpr:
    """Opaque symbolic value used by ForkOnSymbolicBranchPolicy.

    A class (not an int) so the substrate's address-extraction
    can't mistake a symbolic compare result for a concrete pointer.
    """
    __slots__ = ("kind", "args")

    def __init__(self, kind, args):
        self.kind = kind
        self.args = args

    def __repr__(self):
        return f"SymExpr({self.kind}, {self.args})"

    def __bool__(self):
        # Truthiness is "unknown" — but we surface that via is_true.
        # If something coerces this to bool, default to true so a
        # missed instrument can be noticed in tests.
        raise TypeError(
            "SymExpr has no concrete truth value (this is a test bug)")


def _extract_addr(addr):
    """Pull a concrete address out of the substrate's value form.

    Pointers come through as bare ints; anything else (None, symbolic
    objects) yields None.
    """
    if isinstance(addr, int) and not isinstance(addr, bool):
        return addr
    return None


class ForkOnSymbolicBranchPolicy:
    """Tracks symbolic values through memory and forces forks on branches.

    Phase 1 testing aid. Real interceptor support arrives in Phase 2.
    Behavior:
      - mem_write of a non-int value records a shadow at the target
        address; mem_read returns the shadow if present.
      - compare/binary_op/cast where any operand is non-int return a
        SymExpr so symbolic-ness propagates.
      - is_true returns None for SymExpr; resolve_branch likewise.
        Together these force the substrate to emit a
        BranchContinuation that the driver enumerates.
    """

    def __init__(self):
        self._shadow = {}

    def mem_write(self, addr, val, size, is_float):
        if isinstance(val, (int, bool)):
            a = _extract_addr(addr)
            if a is not None:
                self._shadow.pop((a, int(size)), None)
            return NotImplemented
        a = _extract_addr(addr)
        if a is None:
            return NotImplemented
        self._shadow[(a, int(size))] = val
        return None

    def mem_read(self, addr, size, is_float):
        a = _extract_addr(addr)
        if a is None:
            return NotImplemented
        key = (a, int(size))
        if key in self._shadow:
            return self._shadow[key]
        return NotImplemented

    def compare(self, op, lhs, rhs):
        if isinstance(lhs, (int, bool)) and isinstance(rhs, (int, bool)):
            return NotImplemented
        return SymExpr("cmp", (op, lhs, rhs))

    def binary_op(self, op, lhs, rhs):
        if isinstance(lhs, (int, bool)) and isinstance(rhs, (int, bool)):
            return NotImplemented
        return SymExpr("bin", (op, lhs, rhs))

    def unary_op(self, op, operand):
        if isinstance(operand, (int, bool)):
            return NotImplemented
        return SymExpr("un", (op, operand))

    def cast(self, op, operand):
        if isinstance(operand, (int, bool)):
            return NotImplemented
        return SymExpr("cast", (op, operand))

    def is_true(self, val):
        if isinstance(val, SymExpr):
            return None
        if isinstance(val, (int, bool)):
            return val != 0
        return None

    def resolve_branch(self, branch_inst, condition, true_eid, false_eid):
        # Returning None signals "I can't decide" → BranchContinuation
        # is emitted and the engine driver enumerates both edges.
        if isinstance(condition, (int, bool)):
            return condition != 0
        return None


def find_ir_function(index, name):
    for fd in mx.ast.FunctionDecl.IN(index):
        if str(fd.name) == name:
            ir = mx.ir.IRFunction.FROM(fd)
            if ir is not None:
                return ir
    return None


def _func_decl_for(entity):
    if isinstance(entity, mx.ast.FunctionDecl):
        return entity
    if isinstance(entity, mx.ast.DeclRefExpr):
        decl = entity.declaration
        if isinstance(decl, mx.ast.FunctionDecl):
            return decl
    return None


def _var_decl_for(entity):
    if isinstance(entity, mx.ast.VarDecl):
        return entity
    if isinstance(entity, mx.ast.DeclRefExpr):
        decl = entity.declaration
        if isinstance(decl, mx.ast.VarDecl):
            return decl
    return None


def make_func_resolver(index):
    def resolve(eid):
        fd = _func_decl_for(index.entity(eid))
        if fd is None:
            return None
        return mx.ir.IRFunction.FROM(fd)
    return resolve


def make_global_resolver(index):
    def resolve(eid):
        vd = _var_decl_for(index.entity(eid))
        if vd is None:
            return None
        canonical_eid = vd.id
        ty = vd.type
        size = 0
        bits = ty.size_in_bits
        if bits is not None:
            size = (bits + 7) // 8
        align = ty.alignment
        if align is not None:
            align = align // 8
        else:
            align = 8
        if align == 0:
            align = 8
        initializer = mx.ir.IRFunction.FROM(vd)
        return (canonical_eid, size, align, initializer)
    return resolve


def _default_db_path():
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.normpath(
        os.path.join(here, "..", "InterpretIR", "mx-index.db"))


def _default_symex_db_path():
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.normpath(os.path.join(here, "c", "mx-index.db"))


@pytest.fixture(scope="session")
def index():
    db_path = os.environ.get("MX_INDEX_DB", _default_db_path())
    if not os.path.exists(db_path):
        pytest.skip(f"index database not found at {db_path}; "
                    f"set MX_INDEX_DB or build tests/InterpretIR/mx-index.db")
    return mx.Index.from_database(db_path)


@pytest.fixture(scope="session")
def symex_index():
    """Index built from tests/symex/c/symex_integration.c (si_* functions).

    Used by integration tests for phases 9-14. Set MX_SYMEX_DB to override
    the path, or rebuild with:
        mx-index --db tests/symex/c/mx-index.db \\
                 --workspace tests/symex/c/mx-workspace \\
                 --target tests/symex/c/compile_commands.json \\
                 --fork_mode
    """
    db_path = os.environ.get("MX_SYMEX_DB", _default_symex_db_path())
    if not os.path.exists(db_path):
        pytest.skip(f"symex integration index not found at {db_path}; "
                    f"set MX_SYMEX_DB or rebuild tests/symex/c/mx-index.db")
    return mx.Index.from_database(db_path)


@pytest.fixture(scope="session")
def func_resolver(index):
    return make_func_resolver(index)


@pytest.fixture(scope="session")
def global_resolver(index):
    return make_global_resolver(index)


def run_until_terminal(state, mem, policy, func_resolver, global_resolver,
                       max_total_steps=100000, slice_steps=10000):
    """Drive the symbolic step loop until completion / error / suspended.

    Returns the final result dataclass from the last step dict.
    """
    from multiplier.symex.events import (
        Completed, Errored, Budget, Suspended,
        MemAddrSuspension, GlobalSuspension,
    )
    terminal_types = (Completed, Errored, Suspended,
                       MemAddrSuspension, GlobalSuspension)
    while state.steps < max_total_steps:
        out = interp.step(state, mem, policy, slice_steps,
                          func_resolver, global_resolver)
        result = out.get("result")
        if result is None:
            return None
        if isinstance(result, terminal_types):
            return result
        if isinstance(result, Budget):
            continue
        return result
    return None


def run_via_concrete_policy(index, name, args=None):
    """Run `name` through `interp.ConcretePolicy` (pure C++ semantics)
    and return the function's result. Used as the ground-truth reference
    for symex tests that compare `engine.explore(name)` against the
    concrete driver.

    Returns `None` if the function isn't in the index, the run errored,
    suspended, or exhausted its budget.
    """
    ir = find_ir_function(index, name)
    if ir is None:
        return None

    memory = interp.ConcreteMemory()
    policy = interp.ConcretePolicy(
        memory,
        make_func_resolver(index),
        make_global_resolver(index))

    if args is None:
        args = []
        fd = ir.declaration
        if fd is not None:
            for _ in fd.parameters:
                args.append(0)

    state = interp.InterpreterState()
    interp.init_state(state, policy, ir, args)

    from multiplier.symex.events import (
        Completed, Errored, Budget, Suspended,
        MemAddrSuspension, GlobalSuspension,
    )
    max_total_steps = 100000
    while state.steps < max_total_steps:
        out = interp.step(state, policy, 1000)
        if out is None:
            return None
        result = out.get("result") if isinstance(out, dict) else out
        if result is None:
            return None
        if isinstance(result, Completed):
            return result.return_value
        if isinstance(result, (Errored, Suspended,
                               MemAddrSuspension, GlobalSuspension)):
            return None
        if isinstance(result, Budget):
            continue
        return None
    return None
