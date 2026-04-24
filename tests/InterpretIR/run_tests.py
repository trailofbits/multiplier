#!/usr/bin/env python3
"""IR interpreter test runner using C++ interpreter driven from Python.

Usage: python run_tests.py /path/to/test.db [func_name]
"""

import sys

import multiplier as mx

interp = mx.ir.interpret


def find_ir_function(index, name):
    """Find an IRFunction by name in the index."""
    for frag in mx.Fragment.IN(index):
        for decl in mx.ast.Decl.IN(frag):
            fd = mx.ast.FunctionDecl.FROM(decl)
            if fd is None or fd.name != name:
                continue
            ir = mx.ir.IRFunction.FROM(fd)
            if ir is not None:
                return ir
    return None


def make_func_resolver(index):
    """Create a function resolver: entity ID -> IRFunction."""
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
    """Create a global resolver: entity ID -> (canonical_eid, size, align, init)."""
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


def interpret_function(index, ir_func):
    """Interpret an IR function using the C++ interpreter and return the result."""
    state = interp.InterpreterState()
    memory = interp.ConcreteMemory()
    policy = interp.ConcretePolicy(
        memory,
        make_func_resolver(index),
        make_global_resolver(index))

    # Build zero-initialized arguments from declaration.
    args = []
    decl = ir_func.source_declaration
    if decl is not None:
        fd = mx.ast.FunctionDecl.FROM(decl)
        if fd is not None:
            for _ in fd.parameters:
                args.append(0)

    interp.init_state(state, policy, ir_func, args)

    max_total_steps = 100000
    while state.steps < max_total_steps:
        ret = interp.step(state, policy, 1000)
        if ret is None:
            return None
        result = ret.get("result") if isinstance(ret, dict) else ret
        if result is None:
            return None
        status = result[0]
        if status == "completed":
            return result[1]
        if status == "error" or status == "suspended":
            return result[1] if len(result) > 1 else None
        if status == "budget":
            continue
        return None

    return None  # budget exhausted


TEST_FUNCS = [
    "test_arithmetic",
    "test_bitfields",
    "test_casts",
    "test_compound_assign",
    "test_control_flow",
    "test_function_calls",
    "test_globals",
    "test_goto",
    "test_init_lists",
    "test_memory_ops",
    "test_pointers",
    "test_scopes",
    "test_sizeof_alignof",
    "test_switch",
    "test_array_decay",
    "test_struct_assign",
    "test_string_literals",
    "test_variadics",
    "test_dynamic_alloca",
    "test_byvalue",
    "test_evil_goto",
    "test_conditional_exec",
    "test_unsigned",
    "test_c23",
    "test_float_compound",
    "test_unsigned_compound",
    "test_float_precision",
    "test_width_arithmetic",
    "test_width_comparisons",
    "test_float_ops",
    "test_logical_misc",
    "test_width_rmw",
    "test_overflow_exact",
    "test_cast_precision",
]


def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <db_path> [func_name]")
        sys.exit(1)

    db_path = sys.argv[1]
    index = mx.Index.from_database(db_path)

    # Single function mode.
    if len(sys.argv) >= 3:
        func_name = sys.argv[2]
        ir = find_ir_function(index, func_name)
        if ir is None:
            print(f"Could not find IR for '{func_name}'")
            sys.exit(1)
        result = interpret_function(index, ir)
        if result is None:
            print(f"Interpreter error for '{func_name}'")
            sys.exit(1)
        print(f"Return value: {result}")
        sys.exit(0)

    # Test runner mode.
    passed = 0
    failed = 0
    skipped = 0
    errors = []

    for func_name in TEST_FUNCS:
        ir = find_ir_function(index, func_name)
        if ir is None:
            print(f"SKIP   {func_name} (not found)")
            skipped += 1
            continue
        try:
            result = interpret_function(index, ir)
            if result is None:
                print(f"CRASH  {func_name}")
                errors.append(f"  {func_name}: crashed")
                failed += 1
            elif isinstance(result, int) and result == 0:
                print(f"PASS   {func_name}")
                passed += 1
            else:
                print(f"FAIL   {func_name} (returned {result})")
                errors.append(f"  {func_name}: returned {result}")
                failed += 1
        except Exception as e:
            print(f"CRASH  {func_name} ({e})")
            errors.append(f"  {func_name}: {e}")
            failed += 1

    print()
    print(f"Results: {passed} passed, {failed} failed, {skipped} skipped")
    if errors:
        print("Failures:")
        for e in errors:
            print(e)

    sys.exit(failed)


if __name__ == "__main__":
    main()
