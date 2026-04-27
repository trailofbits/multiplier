# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""`engine.intercept.<event>(**selector)` decorator namespace.

Each attribute on `InterceptDispatcher` is a per-event decorator. The
decorator stores `(selector, handler)` in the engine's `_intercepts`
registry. At dispatch time the matching handlers compose into a chain
where each handler receives `next_hook` as its last positional
argument; calling `next_hook(...)` forwards down the chain. A handler
that returns without calling `next_hook` short-circuits.

`intercept.loop` is sugar over `intercept.branch`: at registration time
the named function's CFG is analyzed, the loop-guard branches are
identified, and the user fn is wrapped into a branch handler that
fires only on those sites with a `LoopContext` attached to `ctx.loop`.
"""

from .dispatch import make_selector, _FORK
from .events import ALL_EVENTS, BRANCH, LOOP
from .loop import LoopContext, _bump_path_counter


class InterceptDispatcher:
    """Built once per `SymExEngine` and exposed as `engine.intercept`."""

    def __init__(self, engine):
        self._engine = engine

    def __getattr__(self, name):
        if name == LOOP:
            return _LoopDecorator(self._engine)
        if name not in ALL_EVENTS:
            raise AttributeError(
                f"unknown intercept event: {name!r} "
                f"(known: {sorted(ALL_EVENTS)})")
        return _EventDecorator(self._engine, name)


class _EventDecorator:
    """The thing returned by `engine.intercept.memory_read` etc.

    Two call shapes are supported so analysts can omit selectors:

      @engine.intercept.memory_read
      def handler(ctx, addr, size): ...

      @engine.intercept.memory_read(addr_range=("g", 8))
      def handler(ctx, addr, size): ...
    """

    def __init__(self, engine, event):
        self._engine = engine
        self._event = event

    def __call__(self, *args, **kwargs):
        # Bare-decorator form: @engine.intercept.memory_read
        if args and not kwargs and callable(args[0]) and len(args) == 1:
            return self._register(args[0], {})
        # Parameterized form: @engine.intercept.memory_read(name=...)
        def deco(fn):
            return self._register(fn, kwargs)
        return deco

    def _register(self, fn, selector_kwargs):
        # If the analyst gates an intercept.branch on a function name,
        # eagerly analyze the function's CFG so the dispatcher can match
        # the source block / func id when this branch fires.
        if self._event == BRANCH and "func" in selector_kwargs:
            ir_func = self._engine.resolve_function(selector_kwargs["func"])
            if ir_func is not None:
                self._engine._get_cfg(ir_func)
                # Replace the func= value with the function id so the
                # selector can match against the int we stash on ctx.
                selector_kwargs = dict(selector_kwargs)
                selector_kwargs["func"] = int(ir_func.id)
        selector = make_selector(self._engine.layout, **selector_kwargs)
        self._engine._intercepts.register(self._event, selector, fn)
        return fn


class _LoopDecorator:
    """`engine.intercept.loop(func=…, header_block=…)`.

    Sugar over `intercept.branch`: at registration time the named
    function's CFG is analyzed and the user fn is wrapped into a branch
    handler that only fires on the function's loop-guard cond_branches.
    The wrapper bumps the per-path back-edge counter, attaches a
    `LoopContext` to `ctx.loop`, and translates the handler's
    "continue / exit" return semantics back to "true_edge / false_edge"
    that the dispatcher consumes.
    """

    def __init__(self, engine):
        self._engine = engine

    def __call__(self, *args, **kwargs):
        # Always parameterized: intercept.loop requires func=.
        if args and not kwargs and callable(args[0]) and len(args) == 1:
            raise ValueError("intercept.loop requires func=…")
        def deco(fn):
            return self._register(fn, kwargs)
        return deco

    def _register(self, fn, kwargs):
        func_spec = kwargs.get("func")
        if func_spec is None:
            raise ValueError("intercept.loop requires func=…")
        ir_func = self._engine.resolve_function(func_spec)
        if ir_func is None:
            raise ValueError(f"intercept.loop: unknown function {func_spec!r}")
        cfg = self._engine._get_cfg(ir_func)
        header_filter = kwargs.get("header_block")

        # Map (true_eid, false_eid) -> loop info for the loop-guard
        # branches we care about. Built once at registration; the
        # wrapper just dict-looks-up at dispatch.
        block_by_id = {b.id: b for b in ir_func.blocks}
        loop_keys = {}
        for src_id, info in cfg.loop_branches.items():
            if (header_filter is not None and
                    info["header"] != header_filter):
                continue
            block = block_by_id.get(src_id)
            if block is None:
                continue
            succs = list(block.successors)
            if len(succs) != 2:
                continue
            t_id, f_id = succs[0].id, succs[1].id
            loop_keys[(t_id, f_id)] = info

        if not loop_keys:
            raise ValueError(
                "intercept.loop: no loop-guard cond_branches found in "
                f"{func_spec!r}"
                + (f" with header_block={header_filter}"
                   if header_filter is not None else ""))

        wrapper = _make_loop_wrapper(fn, loop_keys)
        selector = make_selector(self._engine.layout,
                                  func=int(ir_func.id))
        self._engine._intercepts.register(BRANCH, selector, wrapper)
        return fn


def _make_loop_wrapper(user_fn, loop_keys):
    """Build the branch-event handler that drives `intercept.loop`.

    Closure inputs:
      user_fn     — the analyst's `(ctx, next_hook)` callable.
      loop_keys   — {(true_eid, false_eid): loop_info_dict}.

    The wrapper signature is `(ctx, condition, next_hook)`, matching
    the BRANCH chain. If the firing isn't on a tracked loop-guard, it
    just forwards. Otherwise it bumps the path's iteration counter,
    attaches a fresh `LoopContext`, and translates the user's
    continue / exit return into the underlying true / false edge.
    """
    def wrapper(ctx, condition, next_hook):
        key = (ctx.true_eid, ctx.false_eid)
        info = loop_keys.get(key)
        if info is None:
            return next_hook(ctx, condition)

        latch = info["latch"]
        header = info["header"]
        is_continue_on_true = (info["continue_dst"] == ctx.true_eid)

        iteration = _bump_path_counter(ctx.path, latch, header)
        ctx.loop = LoopContext(
            iteration=iteration,
            header_block=header,
            latch_block=latch,
            is_continue_on_true=is_continue_on_true,
            condition=condition,
        )

        def user_next(c=ctx):
            raw = next_hook(c, condition)
            if raw is _FORK:
                return _FORK
            if raw is True or raw is False:
                # Translate "true_edge / false_edge" → "continue / exit".
                return raw if is_continue_on_true else (not raw)
            return raw

        result = user_fn(ctx, user_next)
        if result is _FORK:
            return _FORK
        if result is True or result is False:
            # Translate back: "continue / exit" → "true_edge / false_edge".
            return result if is_continue_on_true else (not result)
        return result
    return wrapper
