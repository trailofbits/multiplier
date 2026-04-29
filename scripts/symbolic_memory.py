"""
Symbolic memory overlay for the multiplier IR interpreter.

Concrete backing via ConcreteMemory (most reads/writes never touch Python).
Symbolic overlay: dict[int, z3_expr] for addresses with symbolic content.
COW fork: shallow copy of overlay, share concrete backing.
"""

from typing import Optional, Dict, Any

try:
    import z3
    HAS_Z3 = True
except ImportError:
    HAS_Z3 = False


class SymbolicMemory:
    """Symbolic overlay on top of ConcreteMemory.

    The ConcreteMemory handles all address allocation and concrete reads/writes.
    This overlay tracks addresses that hold symbolic values.

    For the initial version, the overlay is a simple dict. Symbolic store
    overwrites the overlay entry; concrete store clears it. Reads check the
    overlay first, then fall through to ConcreteMemory.
    """

    def __init__(self):
        self._overlay: Dict[int, Any] = {}  # addr -> z3 expression

    def store_symbolic(self, addr: int, value) -> None:
        """Mark an address as holding a symbolic value."""
        self._overlay[addr] = value

    def load_symbolic(self, addr: int) -> Optional[Any]:
        """Check if an address has a symbolic value. Returns None for concrete."""
        return self._overlay.get(addr)

    def clear(self, addr: int) -> None:
        """Clear symbolic overlay for an address (concrete store happened)."""
        self._overlay.pop(addr, None)

    def fork(self) -> "SymbolicMemory":
        """Create a COW copy for path forking."""
        new = SymbolicMemory()
        new._overlay = dict(self._overlay)
        return new

    def has_symbolic(self, addr: int) -> bool:
        return addr in self._overlay
