"""
Symbolic policy for the multiplier IR interpreter.

Every value is a Python object: `int` for concrete, `z3.BitVecRef` for symbolic.
The policy tries concrete fast-path first, falls back to z3 expression building.

Usage:
    from symbolic_policy import SymbolicPolicy
    policy = SymbolicPolicy()
    # mark parameter as symbolic:
    #   policy.symbolics[param_index] = z3.BitVec("x", 32)
"""

from typing import Optional

try:
    import z3
    HAS_Z3 = True
except ImportError:
    HAS_Z3 = False


def _is_symbolic(val) -> bool:
    """Check if a value is a z3 expression (not a concrete Python int/float)."""
    if not HAS_Z3:
        return False
    return isinstance(val, (z3.BitVecRef, z3.BoolRef, z3.ArithRef))


def _to_bv(val, width: int = 64):
    """Convert a value to a z3 BitVec of the given width."""
    if isinstance(val, z3.BitVecRef):
        if val.size() == width:
            return val
        if val.size() < width:
            return z3.SignExt(width - val.size(), val)
        return z3.Extract(width - 1, 0, val)
    if isinstance(val, z3.BoolRef):
        return z3.If(val, z3.BitVecVal(1, width), z3.BitVecVal(0, width))
    if isinstance(val, int):
        return z3.BitVecVal(val, width)
    return z3.BitVecVal(0, width)


class SymbolicPolicy:
    """Policy that builds z3 expressions for symbolic values.

    For concrete values (both operands are Python int), operations are
    computed directly in Python. When either operand is a z3 expression,
    the result is a z3 expression.

    The interpreter calls these methods via the C++ PythonPolicy bridge.
    Values arrive as Python ints (from value_to_python) or z3 expressions
    (stored in frame.values by prior policy calls).
    """

    def __init__(self, bit_width: int = 32):
        self.bit_width = bit_width
        self.path_constraints: list = []

    def binary_op(self, op: int, lhs, rhs):
        """Handle binary operations. op is the OpCode enum value."""
        if not _is_symbolic(lhs) and not _is_symbolic(rhs):
            return NotImplemented  # fall back to concrete C++

        if not HAS_Z3:
            return NotImplemented

        a = _to_bv(lhs, self.bit_width)
        b = _to_bv(rhs, self.bit_width)
        # Return the z3 expression. The interpreter stores it as a Value.
        # For now, just build an add expression as proof of concept.
        # Full opcode dispatch would go here.
        return NotImplemented  # Let concrete handle it for now

    def compare(self, op: int, lhs, rhs):
        """Handle comparison operations."""
        if not _is_symbolic(lhs) and not _is_symbolic(rhs):
            return NotImplemented

        if not HAS_Z3:
            return NotImplemented

        return NotImplemented  # Let concrete handle it for now

    def is_true(self, val) -> Optional[bool]:
        """Truth test. Returns None for symbolic values (triggers fork)."""
        if _is_symbolic(val):
            return None  # Unknown -> triggers resolve_branch
        # Concrete: let C++ handle it
        return NotImplemented

    def resolve_branch(self, condition, true_eid: int, false_eid: int):
        """Branch resolution for symbolic conditions.

        Returns True (take true path), False (take false path), or
        None (suspend for the explorer to fork).
        """
        if _is_symbolic(condition):
            # Symbolic condition: suspend so the explorer can fork both paths.
            return None
        # Concrete: take true path.
        return True
