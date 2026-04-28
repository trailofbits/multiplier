# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""SymExEngine — orchestrates symbolic exploration over the IR
interpreter.

Phase 1 enumerated paths through the C++ symbolic substrate. Phase 2
adds the analyst-facing hook layer:

  * `engine.intercept.<event>` — composable handlers; each receives
    `next_hook` as its last positional arg and forwards by calling it.
  * `engine.observe.<event>` — listener handlers; auto-recorded to
    `path.events`.

When the analyst supplies neither a custom policy nor a base policy,
the engine instantiates an `InterceptorPolicy` per step that consults
the registries and propagates symbolic values across pure operations.
"""

import re

import multiplier as mx

from .layout import Layout
from .lens import MemView, ArgsView
from .path import Path
from .events import (
    EventLog, EventKind, BRANCH, BranchDirection, Terminal,
    StepResultKind, Strategy, _FilterableList,
)
from .until import ExploreUntil
from .dispatch import (
    InterceptorPolicy, _Registry, SymExpr, _is_z3, _z3_bool, _z3_module,
    make_selector,
)
from .intercept import InterceptDispatcher
from .observe import ObserveDispatcher
from .concretize import (
    AddressStrategy, ConcretizeFinite, ConcretizeTo, ConstrainTo,
    SplitByRegion, Suspension,
    _coerce_strategy,
)
from .region import LazyRegion
from .sinks import SinkRegistry

_interp = mx.ir.interpret


class _ExploreState:
    """Snapshot handed to ExploreUntil predicates each tick."""
    def __init__(self, paths, total_steps):
        self.paths = paths
        self.live_paths = [p for p in paths if p.terminal is None]
        self.total_steps = total_steps


def _resolve_function(index, name):
    for fd in mx.ast.FunctionDecl.IN(index):
        if str(fd.name) == name:
            ir = mx.ir.IRFunction.FROM(fd)
            if ir is not None:
                return ir
    return None


def _func_decl_for(entity):
    """Pull a FunctionDecl out of either a direct decl or a DeclRefExpr."""
    if isinstance(entity, mx.ast.FunctionDecl):
        return entity
    if isinstance(entity, mx.ast.DeclRefExpr):
        decl = entity.declaration
        if isinstance(decl, mx.ast.FunctionDecl):
            return decl
    return None


def _var_decl_for(entity):
    """Pull a VarDecl out of either a direct decl or a DeclRefExpr."""
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


def _make_func_name_resolver(index):
    """Resolve a function entity id to its declared name.

    Used by InterceptorPolicy to filter `intercept.call(name=...)`
    selectors. Returns None on miss; the caller treats that as
    "selectors with `name=` cannot match".
    """
    def resolve(eid):
        try:
            entity = index.entity(eid)
        except Exception:
            return None
        fd = _func_decl_for(entity)
        if fd is None:
            return None
        try:
            return str(fd.name)
        except Exception:
            return None
    return resolve


def _make_global_resolver(index):
    def resolve(eid):
        vd = _var_decl_for(index.entity(eid))
        if vd is None:
            return None
        ty = vd.type
        bits = ty.size_in_bits
        size = (bits + 7) // 8 if bits is not None else 0
        align_bits = ty.alignment
        align = align_bits // 8 if align_bits is not None else 8
        if align == 0:
            align = 8
        initializer = mx.ir.IRFunction.FROM(vd)
        return (vd.id, size, align, initializer)
    return resolve


_DEFAULT_SLICE_STEPS = 1024


class PathSet(_FilterableList):
    """List subclass with predicate queries over the paths an
    `engine.explore(...)` produced.

    Filters are kwargs. Path-level keys (`terminal`, `return_value`,
    `id`) match exact equality; `tags__contains=t` checks `t in
    path.tags`; `events__contains_kind=k` matches paths whose event log
    contains an entry with that kind; `events__contains_addr=a` matches
    paths whose event log contains an entry with that exact address.
    """

    def _match(self, path, filters):
        for key, target in filters.items():
            if not _path_match_one(path, key, target):
                return False
        return True

    def by_entry(self):
        """Group paths by `entry_func`, preserving insertion order.

        Useful after `engine.explore_many(...)` for per-entry queries
        (e.g. "did the `on_*_event` exploration ever trip the OOB
        sink?"). Paths whose `entry_func` is `None` (single-entry
        `explore` results pre-Phase 8f, or paths constructed directly)
        are grouped under the `None` key.
        """
        groups = {}
        for p in self:
            ef = getattr(p, "entry_func", None)
            groups.setdefault(ef, []).append(p)
        return {k: PathSet(v) for k, v in groups.items()}


def _path_match_one(path, key, target):
    if key == "tags__contains":
        return target in path.tags
    if key == "events__contains_kind":
        return path.events.first(kind=target) is not None
    if key == "events__contains_addr":
        return path.events.first(addr=target) is not None
    if key == "terminal":
        return path.terminal == target
    if key == "return_value":
        return path.return_value == target
    if key == "id":
        return path.id == target
    if key == "func":
        return path._func_name == target
    raise ValueError(f"unknown PathSet filter: {key!r}")


class SymExEngine:
    def __init__(self, index):
        self._index = index
        self.layout = None
        self._func_resolver = _make_func_resolver(index)
        self._global_resolver = _make_global_resolver(index)
        self._func_name_resolver = _make_func_name_resolver(index)
        self._intercepts = _Registry()
        self._observers = _Registry()
        # Lazy-populated CFGInfo per function id (Phase 3).
        self._cfg_cache = {}
        # (true_eid, false_eid) -> {"src_id": …, "func_id": …}; populated
        # when a function's CFG is analyzed for an intercept.branch /
        # intercept.loop registration.
        self._branch_sites = {}
        self.intercept = InterceptDispatcher(self)
        self.observe = ObserveDispatcher(self)
        # Default address strategy: concretize every symbolic-address
        # suspension to 0. Analysts override per-engine
        # (`engine.address_strategy = ...`), per-call (`explore(...,
        # concretize=...)`), or per-site (`engine.concretize_at(...)`).
        self.address_strategy = ConcretizeFinite([0])
        # Per-site overrides: list of `(selector, strategy)` pairs.
        # First match wins, identical to the intercept registry.
        self._strategy_overrides = []
        # Phase 6: per-engine sink registry. Sinks fire after policy
        # events in the same dispatcher pass as observers.
        self.sinks = SinkRegistry()
        # Phase 6: cap on LazyRegion materializations charged to a
        # single path. Once exceeded, ConcretizeByRegion(lazy_default
        # =True) is forced to refuse, terminating the path with
        # Terminal.CONCRETIZATION_REFUSED + a lazy_budget_exhausted
        # event.
        self.lazy_region_budget = 8

    def _get_cfg(self, ir_func):
        """Return the cached CFGInfo for `ir_func`, computing it on
        first call. Also populates `_branch_sites` so the
        InterceptorPolicy can resolve a (true_eid, false_eid) pair
        back to its source block and function id."""
        from .cfg import classify_edges
        fid = int(ir_func.id)
        cached = self._cfg_cache.get(fid)
        if cached is not None:
            return cached
        cfg = classify_edges(ir_func)
        self._cfg_cache[fid] = cfg
        # Update the global branch site index. Each (true, false) tuple
        # maps to its source block and function id; on collision we keep
        # the first one (deterministic via DFS visit order in CFGInfo).
        for key, src_ids in cfg.branch_to_src.items():
            if key in self._branch_sites:
                continue
            self._branch_sites[key] = {
                "src_id": src_ids[0],
                "func_id": fid,
            }
        return cfg

    def resolve_function(self, spec):
        """Resolve a function spec (name string or IRFunction) to an
        IRFunction. Public so decorator helpers can share the path."""
        return self._resolve_start(spec)

    # ------------------------------------------------------------------
    # Public API
    # ------------------------------------------------------------------

    def use(self, model):
        """Install a model pack. The pack is either a callable (called
        with `engine`) or an object with a `register(engine)` method.

        `engine.use(symex.models.libc)` registers all libc handlers in
        one call.
        """
        if hasattr(model, "register"):
            model.register(self)
        elif callable(model):
            model(self)
        else:
            raise TypeError(
                f"engine.use(): {model!r} is not callable and lacks "
                "register(engine)")
        return self

    def concretize_at(self, strategy, **selector_kwargs):
        """Register a strategy for suspensions whose payload matches the
        selector. Selector vocabulary is identical to `@intercept.*` /
        `@observe.*` — `addr_range=`, `name=`, `eid=`, `func=`,
        `block=`. First registration wins on overlap.

        Note: `eid=` keys on the *value's* eid (the symbolic value being
        resolved), not the load instruction's use-site eid; that's what
        the substrate's `MemAddrContinuation` reports.
        """
        selector = make_selector(self.layout, **selector_kwargs)
        self._strategy_overrides.append(
            (selector, _coerce_strategy(strategy)))

    def explore(self, start_func, *, start_block=None, args=None, seed=None,
                policy=None, until=None, slice_steps=_DEFAULT_SLICE_STEPS,
                concretize=None, strategy=Strategy.BFS):
        ir_func = self._resolve_start(start_func)
        if ir_func is None:
            raise ValueError(f"start_func {start_func!r} not found in index")

        if seed is not None and start_block is None:
            raise ValueError(
                "value seed requires start_block (mid-block entry; Phase 3)")

        if strategy not in (Strategy.BFS, Strategy.DFS):
            raise ValueError(f"unknown explore strategy {strategy!r}")

        until_pred = until if until is not None else ExploreUntil.never()
        # Per-call override of the default address strategy. None means
        # "use engine.address_strategy"; a callable is wrapped for
        # back-compat; an AddressStrategy is used directly.
        strategy_obj = (_coerce_strategy(concretize)
                        if concretize is not None else self.address_strategy)

        use_interceptor = policy is None
        if self.layout is None:
            # Pin a layout the first time `explore` runs so subsequent
            # calls (and `resume_from` / `Path.replay`) see the same
            # address space — otherwise a freshly minted Layout() per
            # call would diverge from the one whose addresses are baked
            # into a previously-cloned state.
            self.layout = Layout()
        layout = self.layout
        memory = layout.memory

        init_policy = (InterceptorPolicy(self, None, layout=layout,
                                         memory=memory)
                       if use_interceptor else policy)
        initial_path = self._init_path(
            ir_func, memory, init_policy, args=args,
            start_block=start_block, value_seed=seed)

        return PathSet(self._drive(
            [initial_path], memory, layout, policy,
            use_interceptor, until_pred, slice_steps,
            strategy_obj, strategy))

    def explore_many(self, start_funcs, *, args=None, until=None,
                     strategy=Strategy.BFS, concretize=None,
                     slice_steps=_DEFAULT_SLICE_STEPS):
        """Drive symbolic exploration over multiple entry functions.

        `start_funcs` accepts:
          * a list of names / IRFunctions (mixed allowed),
          * a compiled `re.Pattern` matched against function names, or
          * a callable `name -> bool` predicate.

        The engine drives entries sequentially under a shared `until`
        predicate and one shared `Layout` (matching `explore`'s
        layout-pinning behavior). The user-supplied `until` sees the
        cumulative state — `paths` is every path produced so far across
        every entry. An entry that pushes the cumulative state past
        `until` short-circuits the remaining entries; those entries
        are not initialized (so they leave no zero-step paths in the
        result).

        Empty resolution (no functions match) raises `ValueError` —
        almost always a typo. `args=None` is forwarded verbatim to
        each entry; per-entry args mapping is deferred.

        Returns a `PathSet`. Each path carries `entry_func` (the
        IRFunction it started in); `paths.by_entry()` groups by entry
        in resolution order.
        """
        entries = self._resolve_start_many(start_funcs)
        if not entries:
            raise ValueError(
                "explore_many: start_funcs resolved to zero functions; "
                "check the names, regex, or predicate")

        if strategy not in (Strategy.BFS, Strategy.DFS):
            raise ValueError(f"unknown explore strategy {strategy!r}")

        if self.layout is None:
            self.layout = Layout()
        layout = self.layout
        memory = layout.memory

        raw_until = until if until is not None else ExploreUntil.never()
        strategy_obj = (_coerce_strategy(concretize)
                        if concretize is not None else self.address_strategy)

        aggregate = []  # paths from every entry explored so far

        def cumulative_until(state):
            # Wrap the user predicate so it sees aggregate + the
            # in-flight entry's paths in one ExploreState.
            full_paths = aggregate + list(state.paths)
            total = sum(p.steps for p in full_paths)
            return raw_until(_ExploreState(full_paths, total))

        for ir_func in entries:
            # Cross-entry short-circuit: if the user's `until` already
            # fires on the aggregate from prior entries, skip the rest.
            if cumulative_until(_ExploreState([], 0)):
                break
            init_policy = InterceptorPolicy(self, None, layout=layout,
                                            memory=memory)
            init_path = self._init_path(
                ir_func, memory, init_policy, args=args,
                start_block=None, value_seed=None)
            entry_paths = self._drive(
                [init_path], memory, layout, None, True,
                cumulative_until, slice_steps, strategy_obj, strategy)
            aggregate.extend(entry_paths)

        return PathSet(aggregate)

    def _resolve_start_many(self, start_funcs):
        """Resolve the explore_many `start_funcs` argument into a
        de-duplicated list of IRFunctions in resolution order.

        Accepts a `re.Pattern`, a callable `name -> bool`, or a list /
        tuple of `str` and / or pre-resolved IRFunctions. Pattern and
        callable forms iterate `mx.ast.FunctionDecl.IN(index)` and
        emit each matching function once (deduplicated by IRFunction
        id, so multiple FunctionDecl entries for the same definition
        across translation units don't double up).
        """
        if isinstance(start_funcs, re.Pattern):
            return self._resolve_by_predicate(
                lambda n: start_funcs.search(n) is not None)
        if isinstance(start_funcs, str):
            raise TypeError(
                "explore_many: start_funcs is a bare string; pass a "
                "list (e.g. [name]) or a regex / predicate")
        if isinstance(start_funcs, (list, tuple)):
            return self._resolve_explicit_list(start_funcs)
        if callable(start_funcs):
            return self._resolve_by_predicate(start_funcs)
        raise TypeError(
            f"explore_many: start_funcs has unexpected type "
            f"{type(start_funcs).__name__}; expected list, "
            f"re.Pattern, or callable")

    def _resolve_explicit_list(self, items):
        out = []
        seen = set()
        for item in items:
            if isinstance(item, str):
                ir = _resolve_function(self._index, item)
                if ir is None:
                    raise ValueError(
                        f"explore_many: function name {item!r} "
                        f"not found in index")
            else:
                ir = item
            try:
                fid = int(ir.id)
            except (AttributeError, TypeError) as exc:
                raise TypeError(
                    f"explore_many: list entry {item!r} is neither "
                    f"a name nor an IRFunction") from exc
            if fid in seen:
                continue
            seen.add(fid)
            out.append(ir)
        return out

    def _resolve_by_predicate(self, pred):
        out = []
        seen = set()
        for fd in mx.ast.FunctionDecl.IN(self._index):
            try:
                name = str(fd.name)
            except Exception:
                continue
            if not pred(name):
                continue
            ir = mx.ir.IRFunction.FROM(fd)
            if ir is None:
                continue
            fid = int(ir.id)
            if fid in seen:
                continue
            seen.add(fid)
            out.append(ir)
        return out

    def _drive(self, initial_paths, memory, layout, policy,
               use_interceptor, until_pred, slice_steps, concretize,
               strategy):
        if strategy == Strategy.DFS:
            return self._drive_dfs(initial_paths, memory, layout, policy,
                                   use_interceptor, until_pred, slice_steps,
                                   concretize)
        return self._drive_bfs(initial_paths, memory, layout, policy,
                               use_interceptor, until_pred, slice_steps,
                               concretize)

    def _drive_bfs(self, initial_paths, memory, layout, policy,
                   use_interceptor, until_pred, slice_steps, concretize):
        paths = list(initial_paths)
        while True:
            live = [p for p in paths if p.terminal is None]
            if not live:
                break
            total_steps = sum(p.steps for p in paths)
            if until_pred(_ExploreState(paths, total_steps)):
                break

            new_paths = []
            for path in paths:
                if path.terminal is not None:
                    new_paths.append(path)
                    continue
                step_policy = (InterceptorPolicy(self, path, layout=layout,
                                                  memory=memory)
                                if use_interceptor else policy)
                children = self._step_one(
                    path, memory, step_policy, slice_steps, concretize)
                new_paths.extend(children)
                if until_pred(_ExploreState(new_paths +
                                            [p for p in paths
                                             if p not in new_paths and
                                             p.terminal is not None],
                                            sum(p.steps for p in new_paths))):
                    break

            paths = new_paths
            if not any(p.terminal is None for p in paths):
                break

        return paths

    def _drive_dfs(self, initial_paths, memory, layout, policy,
                   use_interceptor, until_pred, slice_steps, concretize):
        """DFS: take one live path off the top of the stack, step it
        until it forks (fork → push children, deepest first) or
        terminates. The terminal-path order in the result is "deepest
        completes first," in contrast to BFS's "shallowest first."
        """
        all_paths = list(initial_paths)
        stack = [p for p in initial_paths if p.terminal is None]

        while stack:
            total_steps = sum(p.steps for p in all_paths)
            if until_pred(_ExploreState(all_paths, total_steps)):
                break

            path = stack.pop()
            if path.terminal is not None:
                continue

            step_policy = (InterceptorPolicy(self, path, layout=layout,
                                              memory=memory)
                            if use_interceptor else policy)
            children = self._step_one(
                path, memory, step_policy, slice_steps, concretize)

            if len(children) == 1 and children[0] is path:
                # Path stepped without forking; keep driving it.
                if path.terminal is None:
                    stack.append(path)
                continue

            # Fork: replace `path` in `all_paths` with the children, push
            # in reverse order so the lowest-id child is processed first.
            try:
                idx = all_paths.index(path)
                all_paths[idx:idx + 1] = children
            except ValueError:
                all_paths.extend(children)
            for child in reversed(children):
                if child.terminal is None:
                    stack.append(child)

        return all_paths

    def resume_from(self, snapshot, *, modify=None,
                    slice_steps=_DEFAULT_SLICE_STEPS, concretize=None,
                    parent_id=None, until=None, strategy=Strategy.BFS):
        """Build a fresh `Path` from a `_Snapshot` (re-cloning its
        state so the snapshot stays reusable), apply `modify(path)`
        once, and resume exploration through the engine driver.

        Returns the list of paths produced. Used by `Path.replay`.
        """
        layout = self.layout if self.layout is not None else Layout()
        memory = layout.memory
        strategy_obj = (_coerce_strategy(concretize)
                        if concretize is not None else self.address_strategy)
        until_pred = until if until is not None else ExploreUntil.never()

        fresh_state = _interp.clone_state(snapshot.state)
        path = Path(fresh_state, memory, parent_id=parent_id)
        path.events = EventLog(snapshot.events)
        path.tags = set(snapshot.tags)
        path.path_condition = list(snapshot.path_condition)
        path._loop_iters = dict(snapshot.loop_iters)
        path._func_name = snapshot.func_name
        path._layout = layout
        path.solver.adopt_fresh_vars(snapshot.fresh_vars)
        path.terminal = snapshot.terminal
        path.return_value = snapshot.return_value
        path.error_kind = snapshot.error_kind

        if modify is not None:
            modify(path)

        # If the snapshot was taken at a terminal point and modify
        # didn't reset it, return the path as-is.
        if path.terminal is not None:
            return PathSet([path])

        return PathSet(self._drive(
            [path], memory, layout, None, True,
            until_pred, slice_steps, strategy_obj, strategy))

    # ------------------------------------------------------------------
    # internals
    # ------------------------------------------------------------------

    def _resolve_start(self, start_func):
        if isinstance(start_func, str):
            return _resolve_function(self._index, start_func)
        return start_func

    def _init_path(self, ir_func, memory, policy, *, args, start_block,
                   value_seed):
        state = _interp.InterpreterState()
        if args is None:
            args = []

        if start_block is None:
            _interp.init_state(state, memory, policy, ir_func, list(args),
                               self._func_resolver, self._global_resolver)
        else:
            block = self._resolve_block(ir_func, start_block)
            param_addrs = self._allocate_param_slots(ir_func, memory, args)
            seed_dict = {int(k): v for k, v in (value_seed or {}).items()}
            _interp.init_state_at(
                state, memory, policy, ir_func, block,
                param_addrs, None, seed_dict,
                self._func_resolver, self._global_resolver)
        path = Path(state, memory)
        path._func_name = self._function_name(ir_func)
        path._layout = self.layout
        path.entry_func = ir_func
        # Init-time z3 args land in the init-policy's ephemeral shadow
        # (path didn't exist yet). Migrate them to the path's durable
        # shadow so subsequent steps see the symbolic param values.
        init_shadow = getattr(policy, "_shadow", None)
        if init_shadow:
            path._symbolic_shadow.update(init_shadow)
        return path

    def _function_name(self, ir_func):
        fd = ir_func.declaration
        if fd is None:
            return None
        return str(fd.name)

    def _resolve_block(self, ir_func, start_block):
        if not isinstance(start_block, int):
            return start_block
        for b in ir_func.blocks:
            if b.id == start_block:
                return b
        raise ValueError(f"block id {start_block} not found in function")

    def _allocate_param_slots(self, ir_func, memory, args):
        addrs = []
        fd = ir_func.declaration
        if fd is None:
            return addrs
        for i, p in enumerate(fd.parameters):
            ty = p.type
            bits = ty.size_in_bits
            size = max(1, (bits + 7) // 8) if bits is not None else 8
            align_bits = ty.alignment
            align = max(1, align_bits // 8) if align_bits is not None else 8
            addr = memory.allocate(size, align)
            addrs.append(addr)
            if i < len(args):
                val = args[i]
                if isinstance(val, bool):
                    val = int(val)
                if isinstance(val, int):
                    memory.write_bytes(
                        addr, val.to_bytes(size, "little",
                                           signed=(val < 0)))
        return addrs

    def _step_one(self, path, memory, policy, slice_steps, concretize):
        out = _interp.step(path.state, memory, policy, slice_steps,
                           self._func_resolver, self._global_resolver)
        result = out.get("result")
        forks = out.get("forks") or []

        if path.terminal is not None:
            # An intercept called ctx.stop_path() and short-circuited.
            return [path]

        if result is None:
            return [path]

        kind = result[0]
        if kind == StepResultKind.COMPLETED:
            path.terminal = Terminal.COMPLETED
            path.return_value = result[1]
            return [path]
        if kind == StepResultKind.ERROR:
            path.terminal = Terminal.ERROR
            path.error_kind = result[1]
            return [path]
        if kind == StepResultKind.BUDGET:
            return [path]
        if kind == StepResultKind.BRANCH:
            return self._handle_branch_forks(path, result, forks)
        if kind == StepResultKind.SUSPENDED:
            return self._handle_suspension(path, result, forks, concretize)

        path.terminal = Terminal.UNKNOWN
        return [path]

    def _handle_branch_forks(self, path, result, forks):
        _, cond, t_eid, f_eid = result
        if not forks:
            path.terminal = Terminal.STUCK_BRANCH
            return [path]

        cond_z3 = _z3_bool(cond) if _is_z3(cond) else None

        children = []
        for entry in forks:
            child_state = entry["state"]
            direction = entry.get("direction", BranchDirection.UNKNOWN)
            child = self._fork_child(path, child_state)
            if cond_z3 is not None:
                if direction == BranchDirection.TRUE:
                    child.path_condition.append(cond_z3)
                elif direction == BranchDirection.FALSE:
                    z3 = _z3_module()
                    child.path_condition.append(z3.Not(cond_z3))
                child.solver.invalidate()
            child.events.append({
                "kind": BRANCH,
                "direction": direction,
                "true_block": t_eid,
                "false_block": f_eid,
                "step": path.steps,
            })
            children.append(child)
        return children

    def _handle_suspension(self, path, result, forks, strategy):
        if not forks:
            path.suspended = result
            path.terminal = Terminal.STUCK_SUSPENSION
            return [path]

        fork_entry = forks[0]
        suspension = Suspension(
            address_expr=fork_entry.get("address"),
            address_eid=int(fork_entry.get("address_eid") or 0),
            size=fork_entry.get("size"),
            is_write=fork_entry.get("is_write"),
            path=path,
            layout=self.layout,
            solver=path.solver,
        )

        chosen = self._match_override(suspension)
        if chosen is None:
            chosen = strategy

        decisions = list(chosen.next_decisions(suspension))
        truncated = (chosen.max_models is not None
                     and len(decisions) >= chosen.max_models)

        if not decisions:
            path.suspended = result
            path.terminal = Terminal.CONCRETIZATION_REFUSED
            return [path]

        children = []
        # Track which fork-entry state has been "claimed" without a
        # clone yet. The first ConcretizeTo / SplitByRegion-region
        # consumes the original; subsequent forks clone.
        first_state_used = [False]

        def _take_state():
            if not first_state_used[0]:
                first_state_used[0] = True
                return fork_entry["state"]
            return _interp.clone_state(fork_entry["state"])

        for d in decisions:
            if isinstance(d, ConcretizeTo):
                self._dispatch_concretize_to(
                    path, suspension, d, _take_state, children, truncated,
                    chosen)
            elif isinstance(d, ConstrainTo):
                self._dispatch_constrain_to(
                    path, suspension, d, _take_state, children)
            elif isinstance(d, SplitByRegion):
                self._dispatch_split_by_region(
                    path, suspension, d, _take_state, children)
            else:
                raise NotImplementedError(
                    f"unknown Decision variant: {type(d).__name__}")

        if not children:
            # Every candidate was infeasible.
            path.suspended = result
            path.terminal = Terminal.CONCRETIZATION_REFUSED
            return [path]
        return children

    def _dispatch_concretize_to(self, path, suspension, d, take_state,
                                 children, truncated, chosen):
        if not self._addr_feasible(path, suspension, d):
            path.events.append({
                "kind": EventKind.CONCRETIZATION_INFEASIBLE,
                "address": d.addr,
                "address_eid": suspension.address_eid,
                "step": path.steps,
            })
            return
        child_state = take_state()
        _interp.resume_addr(child_state, suspension.address_eid, d.addr)
        child = self._fork_child(path, child_state)

        if d.extra_constraint is not None:
            child.path_condition.append(d.extra_constraint)
            child.solver.invalidate()

        child.events.append({
            "kind": EventKind.MEMADDR_CONCRETIZE,
            "address": d.addr,
            "address_eid": suspension.address_eid,
            "size": suspension.size,
            "is_write": suspension.is_write,
            "step": path.steps,
        })
        if truncated:
            child.events.append({
                "kind": EventKind.CONCRETIZATION_TRUNCATED,
                "address_eid": suspension.address_eid,
                "max_models": chosen.max_models,
                "step": path.steps,
            })
        children.append(child)

    def _dispatch_constrain_to(self, path, suspension, d, take_state,
                                children):
        addr_expr = suspension.address_expr
        addr_is_symbolic = self._is_z3_expr(addr_expr)
        child_state = take_state()
        if addr_is_symbolic:
            _interp.resume_addr_symbolic(
                child_state, suspension.address_eid, addr_expr)
            child = self._fork_child(path, child_state)
            child.path_condition.append(d.constraint)
            child.solver.invalidate()
        else:
            # Concrete-addr fallback: the substrate has collapsed
            # ptr_add (Phase 7 deferred). The constraint over a
            # single concrete value would be vacuous against the
            # sole satisfying assignment, so we record the situation
            # and resume at the existing concrete address without
            # asserting it.
            self._record_constrain_to_concrete_addr(path, suspension)
            try:
                concrete = int(addr_expr) if addr_expr is not None else 0
            except (TypeError, ValueError):
                concrete = 0
            _interp.resume_addr(
                child_state, suspension.address_eid, concrete)
            child = self._fork_child(path, child_state)
        children.append(child)

    def _dispatch_split_by_region(self, path, suspension, d, take_state,
                                   children):
        addr_expr = suspension.address_expr
        addr_is_symbolic = self._is_z3_expr(addr_expr)

        regions_emitted = []
        for region in d.regions:
            if isinstance(region, LazyRegion):
                # Charge the materialization budget to the path; if
                # the budget is exhausted, refuse this region.
                if path._lazy_regions_used >= self._engine_lazy_budget():
                    path.events.append({
                        "kind": EventKind.LAZY_BUDGET_EXHAUSTED,
                        "region": region.name,
                        "address_eid": suspension.address_eid,
                        "step": path.steps,
                    })
                    continue
                self._record_region_materialized(path, region)
                path._lazy_regions_used += 1

            child_state = take_state()
            if addr_is_symbolic:
                _interp.resume_addr_symbolic(
                    child_state, suspension.address_eid, addr_expr)
                z3 = _z3_module()
                in_region = z3.And(
                    z3.UGE(addr_expr, region.base),
                    z3.ULT(addr_expr, region.base + region.size))
                child = self._fork_child(path, child_state)
                child.path_condition.append(in_region)
                child.solver.invalidate()
            else:
                # Concrete-addr fallback: degrade to "resume at the
                # region's base." Mirrors Phase 5's
                # ConcretizeByRegion(layout) semantics.
                _interp.resume_addr(
                    child_state, suspension.address_eid, region.base)
                child = self._fork_child(path, child_state)
            child._region_at_suspension = region.name
            child.events.append({
                "kind": EventKind.SPLIT_BY_REGION,
                "region": region.name,
                "region_base": region.base,
                "region_size": region.size,
                "address_eid": suspension.address_eid,
                "is_write": suspension.is_write,
                "step": path.steps,
            })
            children.append(child)
            regions_emitted.append(region.name)

        if not regions_emitted:
            # Every region in the split was rejected (lazy budget
            # exhausted etc.). The caller will mark
            # CONCRETIZATION_REFUSED.
            return

    def _engine_lazy_budget(self):
        return int(getattr(self, "lazy_region_budget", 8))

    @staticmethod
    def _is_z3_expr(value):
        if value is None:
            return False
        z3 = _z3_module()
        return z3 is not None and isinstance(value, z3.ExprRef)

    def _record_region_materialized(self, path, region):
        path.events.append({
            "kind": EventKind.REGION_MATERIALIZED,
            "region": region.name,
            "region_base": region.base,
            "region_size": region.size,
            "step": path.steps,
        })

    def _record_constrain_to_concrete_addr(self, path, suspension):
        path.events.append({
            "kind": EventKind.CONSTRAIN_TO_CONCRETE_ADDR,
            "address_eid": suspension.address_eid,
            "size": suspension.size,
            "is_write": suspension.is_write,
            "step": path.steps,
        })

    def _match_override(self, suspension):
        """Walk per-site overrides in registration order. Selector
        axes:
          - `eid=` matches the value's eid (what the substrate reports).
          - `addr_range=` matches when a concrete address lands in
            range, or the symbolic address can land in range under
            the path's accumulated condition.
          - `name=` (without `addr_range=`) routes through the
            layout: a function's zero-size range matches concrete
            equality; a global's range matches like `addr_range=`.
        Empty axes match anything."""
        addr_int = self._extract_concrete_addr(suspension.address_expr)
        for selector, strategy in self._strategy_overrides:
            if not selector.matches_eid(suspension.address_eid):
                continue
            if selector.addr_range is not None:
                lo, hi = selector._compute_range()
                if not self._addr_range_matches(suspension, addr_int, lo, hi):
                    continue
            elif selector.name is not None:
                if not self._addr_name_matches(suspension, addr_int,
                                                selector.name):
                    continue
            return strategy
        return None

    def _addr_range_matches(self, suspension, addr_int, lo, hi):
        if addr_int is not None:
            return lo <= addr_int < hi
        return self._symbolic_in_range(suspension, lo, hi)

    def _addr_name_matches(self, suspension, addr_int, name):
        if self.layout is None:
            return False
        try:
            lo, hi = self.layout.address_range(name)
        except KeyError:
            return False
        if lo == hi:  # function placement: zero-size, exact match
            return addr_int is not None and addr_int == lo
        return self._addr_range_matches(suspension, addr_int, lo, hi)

    @staticmethod
    def _symbolic_in_range(suspension, lo, hi):
        addr_expr = suspension.address_expr
        if addr_expr is None:
            return False
        z3 = _z3_module()
        if z3 is None or not isinstance(addr_expr, z3.ExprRef):
            return False
        s = z3.Solver()
        for c in suspension.path.path_condition:
            s.add(c)
        s.add(z3.UGE(addr_expr, lo))
        s.add(z3.ULT(addr_expr, hi))
        return s.check() == z3.sat

    @staticmethod
    def _extract_concrete_addr(addr_expr):
        if addr_expr is None:
            return None
        if isinstance(addr_expr, bool):
            return None
        if isinstance(addr_expr, int):
            return addr_expr
        return None

    def _addr_feasible(self, path, suspension, decision):
        """Cheap feasibility check: `path_condition ∧ (addr_var == k)`
        must be sat for `k` to be a viable concrete address. When
        `address_expr` is concrete or there are no constraints, no
        solver call is needed."""
        if not path.path_condition or suspension.address_expr is None:
            return True
        z3 = _z3_module()
        if z3 is None:
            return True
        if not isinstance(suspension.address_expr, z3.ExprRef):
            return True
        s = z3.Solver()
        for c in path.path_condition:
            s.add(c)
        s.add(suspension.address_expr == decision.addr)
        return s.check() == z3.sat

    def _fork_child(self, parent, child_state):
        """Build a fresh Path that inherits everything from `parent`
        except its interpreter state. Used by branch and suspension
        fork handling so the propagation rules stay in one place."""
        child = Path(child_state, parent.mem, parent_id=parent.id)
        child.events = EventLog(parent.events)
        child.tags = set(parent.tags)
        child.path_condition = list(parent.path_condition)
        child._loop_iters = dict(parent._loop_iters)
        child._func_name = parent._func_name
        child._layout = parent._layout
        child.entry_func = parent.entry_func
        child.solver.adopt_fresh_vars(parent.solver._fresh_vars)
        return child
