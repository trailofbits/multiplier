# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Shared type-check constants and leaf-level enums.

Leaf module — no imports from the symex package so any file can import
these without triggering circular-import issues.
"""

from enum import StrEnum

# Pre-built type tuples for isinstance checks.
_BYTES_TYPES = (bytes, bytearray, memoryview)
_INT_TYPES   = (int, bool)
_SEQ_TYPES   = (list, tuple)


class Endian(StrEnum):
    """Byte order for Python-side memory helpers (`to_bytes` / `from_bytes`).

    The string values match Python's `int.to_bytes(..., byteorder=...)`
    argument so they can be passed through directly.
    """
    LITTLE = "little"
    BIG = "big"
