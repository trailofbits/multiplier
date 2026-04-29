import os
import pytest
import multiplier as mx

interp = mx.ir.interpret

_ir_func_cache = {}


class _PassthroughPolicy:
    """Empty policy -- all operations fall back to concrete interpreter."""
    pass


def find_ir_function(index, name):
    """Find IRFunction by name (cached)."""
    if name in _ir_func_cache:
        return _ir_func_cache[name]
    for fd in mx.ast.FunctionDecl.IN(index):
        if str(fd.name) == name:
            ir = mx.ir.IRFunction.FROM(fd)
            if ir:
                _ir_func_cache[name] = ir
                return ir
    _ir_func_cache[name] = None
    return None


def run_ir_function(ir_func, args, func_resolver, global_resolver,
                    max_steps=100000):
    """Run a pre-resolved IRFunction via the symbolic executor.

    Uses the unified init_state/step with ConcreteMemory as the second
    argument to trigger the symbolic (Python policy) dispatch path.

    Returns the result value on success.  Raises AssertionError on failure.
    """
    mem = interp.ConcreteMemory()
    state = interp.InterpreterState()
    policy = _PassthroughPolicy()
    interp.init_state(state, mem, policy, ir_func,
                      list(args), func_resolver, global_resolver)
    result = interp.step(state, mem, policy, max_steps,
                         func_resolver, global_resolver)
    res = result.get("result")
    assert res is not None and res[0] == "completed", \
        f"Interpreter failed for args={args}: {res}"
    return res[1]


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


def _make_func_resolver(index):
    def resolve(eid):
        fd = _func_decl_for(index.entity(eid))
        if fd is None:
            return None
        return mx.ir.IRFunction.FROM(fd)
    return resolve


def _make_global_resolver(index):
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


# ---- pytest fixtures ----

@pytest.fixture(scope="session")
def index():
    db_path = os.environ.get("MX_INDEX_DB", "mx-index.db")
    return mx.Index.from_database(db_path)


@pytest.fixture(scope="session")
def func_resolver(index):
    return _make_func_resolver(index)


@pytest.fixture(scope="session")
def global_resolver(index):
    return _make_global_resolver(index)
