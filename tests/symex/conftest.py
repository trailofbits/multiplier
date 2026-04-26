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


def find_ir_function(index, name):
    for frag in mx.Fragment.IN(index):
        for decl in mx.ast.Decl.IN(frag):
            fd = mx.ast.FunctionDecl.FROM(decl)
            if fd and str(fd.name) == name:
                ir = mx.ir.IRFunction.FROM(fd)
                if ir is not None:
                    return ir
    return None


def make_func_resolver(index):
    def resolve(eid):
        entity = index.entity(eid)
        if isinstance(entity, mx.ast.Decl):
            fd = mx.ast.FunctionDecl.FROM(entity)
            if fd is not None:
                return mx.ir.IRFunction.FROM(fd)
        if isinstance(entity, mx.ast.Stmt):
            dre = mx.ast.DeclRefExpr.FROM(entity)
            if dre is not None:
                fd = mx.ast.FunctionDecl.FROM(dre.declaration)
                if fd is not None:
                    return mx.ir.IRFunction.FROM(fd)
        return None
    return resolve


def make_global_resolver(index):
    def resolve(eid):
        entity = index.entity(eid)
        vd = None
        if isinstance(entity, mx.ast.Decl):
            vd = mx.ast.VarDecl.FROM(entity)
        elif isinstance(entity, mx.ast.Stmt):
            dre = mx.ast.DeclRefExpr.FROM(entity)
            if dre is not None:
                vd = mx.ast.VarDecl.FROM(dre.declaration)
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


@pytest.fixture(scope="session")
def index():
    db_path = os.environ.get("MX_INDEX_DB", _default_db_path())
    if not os.path.exists(db_path):
        pytest.skip(f"index database not found at {db_path}; "
                    f"set MX_INDEX_DB or build tests/InterpretIR/mx-index.db")
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

    Returns the final ``result`` tuple from the last step dict.
    """
    while state.steps < max_total_steps:
        out = interp.step(state, mem, policy, slice_steps,
                          func_resolver, global_resolver)
        result = out.get("result")
        if result is None:
            return None
        status = result[0]
        if status in ("completed", "error", "suspended"):
            return result
        if status == "budget":
            continue
        return result
    return None
