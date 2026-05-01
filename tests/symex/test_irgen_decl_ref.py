# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Regression tests for IRGen DeclRefExpr lowering.

A `DeclRefExpr` to an `EnumConstantDecl` is an rvalue — it must lower
to a `CONST` instruction holding the enumerator's integer value. The
old code routed every `DeclRefExpr` through the lvalue fallback, which
turned an enum constant reference into `MEMORY/LOAD_LE_* [%0]` (a load
from instruction 0, the entry block's IMPLICIT_GOTO).

These tests pin the corpus added at the bottom of
`tests/symex/c/symex_integration.c`. Without the IRGen fix every
function below produces at least one MEMORY instruction whose
source_statement is a DeclRefExpr to an EnumConstantDecl; with the fix
those references all produce CONST.
"""

import pytest

import multiplier as mx

from conftest import find_ir_function


def _walk_instructions(ir_func):
    """Yield every IRInstruction in `ir_func`, including nested sub-
    instruction operands. `IRBlock.all_instructions` only enumerates
    the block's root instructions; CONST nodes that materialise
    EnumConstantDecl values live as operands of stores/calls/comparisons,
    so the walk has to descend through `nth_operand`.
    """
    if ir_func is None:
        return
    seen = set()

    def walk(inst):
        if inst is None:
            return
        key = inst.id
        if key in seen:
            return
        seen.add(key)
        yield inst
        for i in range(inst.num_operands):
            child = inst.nth_operand(i)
            if child is None:
                continue
            yield from walk(child)

    for block in ir_func.blocks:
        for root in block.all_instructions:
            yield from walk(root)


def _is_decl_ref_to_enum_constant(stmt):
    if not isinstance(stmt, mx.ast.DeclRefExpr):
        return False
    return isinstance(stmt.declaration, mx.ast.EnumConstantDecl)


def _enum_const_refs(ir_func):
    """All instructions whose source_statement is a DeclRefExpr to an
    EnumConstantDecl, paired with the referenced enumerator name."""
    for inst in _walk_instructions(ir_func):
        stmt = inst.source_statement
        if _is_decl_ref_to_enum_constant(stmt):
            yield inst, str(stmt.declaration.name)


def _find_var_decl(index, name):
    for vd in mx.ast.VarDecl.IN(index):
        if str(vd.name) == name:
            return vd
    return None


# ---------------------------------------------------------------------------
# Functional uses of EnumConstantDecl
# ---------------------------------------------------------------------------

def _is_load(inst):
    """True if `inst` is a MEMORY load. The bug shape is a LOAD whose
    source_statement is a DeclRefExpr→EnumConstantDecl; wrapping STOREs
    (e.g. into an argument alloca) legitimately inherit the same source
    statement and are not part of the bug."""
    if inst.opcode != mx.ir.OpCode.MEMORY:
        return False
    s = inst.to_string
    return "LOAD_" in s


@pytest.mark.parametrize("func_name,expected_names", [
    ("si_enum_return", {"si_red"}),
    ("si_enum_cmp",    {"si_blue"}),
    ("si_enum_arg",    {"si_green"}),
])
def test_enum_constant_ref_emits_const(symex_index, func_name, expected_names):
    """Every DeclRefExpr→EnumConstantDecl in `func_name` materialises as a
    CONST, never as a MEMORY/LOAD."""
    ir = find_ir_function(symex_index, func_name)
    assert ir is not None, f"{func_name} missing from index"

    const_names = set()
    for inst, enum_name in _enum_const_refs(ir):
        # The bug shape: a LOAD whose source statement is the
        # DeclRefExpr to the EnumConstantDecl (no storage exists, so any
        # LOAD is malformed by definition).
        assert not _is_load(inst), (
            f"{func_name}: DeclRefExpr to EnumConstantDecl {enum_name!r} "
            f"lowered to a load: {inst.to_string!r}"
        )
        if inst.opcode == mx.ir.OpCode.CONST:
            const_names.add(enum_name)

    # Every expected enumerator must materialise as a CONST somewhere
    # in the function. (Wrapping STOREs that propagate the source
    # statement are fine; the value sub-instruction must be a CONST.)
    assert expected_names <= const_names, (
        f"{func_name}: expected CONST emissions for {expected_names}, "
        f"saw {const_names}"
    )


# ---------------------------------------------------------------------------
# Aggregate initializer at file scope.
# ---------------------------------------------------------------------------

def test_enum_constant_ref_in_global_aggregate(symex_index):
    """`si_color_table`'s initializer references si_red/si_green/si_blue —
    each must be a CONST, not a MEMORY load."""
    vd = _find_var_decl(symex_index, "si_color_table")
    assert vd is not None, "si_color_table missing from index"

    ir = mx.ir.IRFunction.FROM(vd)
    assert ir is not None, (
        "no global initializer IR for si_color_table — IRGen failed to emit "
        "GenerateGlobalInit() output for the aggregate"
    )

    const_names = set()
    for inst, enum_name in _enum_const_refs(ir):
        assert not _is_load(inst), (
            f"si_color_table init: DeclRefExpr to {enum_name!r} lowered "
            f"to a load: {inst.to_string!r}"
        )
        if inst.opcode == mx.ir.OpCode.CONST:
            const_names.add(enum_name)

    assert {"si_red", "si_green", "si_blue"} <= const_names, (
        f"expected CONSTs for si_red/si_green/si_blue in initializer, "
        f"saw {const_names}"
    )


# ---------------------------------------------------------------------------
# Negative shape check: no instruction in the corpus has %0 as a
# value-producing operand. (`%0` is always the entry IMPLICIT_GOTO; a
# load/store/etc. that consumes it is the malformed shape we're guarding
# against.)
# ---------------------------------------------------------------------------

@pytest.mark.parametrize("func_name", [
    "si_enum_return", "si_enum_cmp", "si_enum_arg", "si_enum_table_name",
])
def test_no_value_consumer_of_entry_goto(symex_index, func_name):
    ir = find_ir_function(symex_index, func_name)
    assert ir is not None, f"{func_name} missing from index"

    for inst in _walk_instructions(ir):
        if inst.is_terminator:
            continue
        for op_idx in range(inst.num_operands):
            operand = inst.nth_operand(op_idx)
            if operand is None:
                continue
            assert not operand.is_terminator, (
                f"{func_name}: instruction {inst.to_string!r} consumes a "
                f"terminator ({operand.to_string!r}) as operand {op_idx}"
            )
