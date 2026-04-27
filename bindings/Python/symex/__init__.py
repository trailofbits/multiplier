# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Symbolic execution facade for Multiplier.

Phase 1 ships the analyst-facing skeleton: Layout, SymExEngine, Path,
Ctx, MemView, ArgsView, and ExploreUntil. Phase 2 adds the hook layer
(`engine.intercept.<event>` and `engine.observe.<event>`) and a small
libc model pack.
"""

from .layout import Layout
from .lens import MemView, ArgsView
from .ctx import Ctx
from .path import Path
from .events import EventLog
from .until import ExploreUntil
from .engine import SymExEngine, PathSet
from .dispatch import InterceptorPolicy, SymExpr
from . import models

__all__ = [
    "Layout",
    "MemView",
    "ArgsView",
    "Ctx",
    "Path",
    "EventLog",
    "PathSet",
    "ExploreUntil",
    "SymExEngine",
    "InterceptorPolicy",
    "SymExpr",
    "models",
]
