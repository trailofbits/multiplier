# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Reference model packs for common library surfaces.

Pass a pack to `engine.use(...)`:

    from symex import SymExEngine, models
    engine = SymExEngine(idx)
    engine.use(models.libc)

Each pack is a singleton with a `register(engine)` method that
installs interceptors on `engine.intercept.call`. Analysts can subclass
to override individual functions.
"""

from . import libc

__all__ = ["libc"]
