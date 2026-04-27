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
)
from .intercept import InterceptDispatcher
from .observe import ObserveDispatcher

_interp = mx.ir.interpret


class _ExploreState:
    """Snapshot handed to ExploreUntil predicates each tick."""
    def __init__(self, paths, total_steps):
        self.paths = paths
        self.live_paths = [p for p in paths if p.terminal is None]
        self.total_steps = total_steps


def _resolve_function(index, name):
    for frag in mx.Fragment.IN(index):
        for decl in mx.ast.Decl.IN(frag):
            fd = mx.ast.FunctionDecl.FROM(decl)
            if fd and str(fd.name) == name:
                ir = mx.ir.IRFunction.FROM(fd)
                if ir is not None:
                    return ir
    return None


def _make_func_resolver(index):
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
        fd = None
        if isinstance(entity, mx.ast.Decl):
            fd = mx.ast.FunctionDecl.FROM(entity)
        elif isinstance(entity, mx.ast.Stmt):
            dre = mx.ast.DeclRefExpr.FROM(entity)
            if dre is not None:
                fd = mx.ast.FunctionDecl.FROM(dre.declaration)
        if fd is None:
            return None
        try:
            return str(fd.name)
        except Exception:
            return None
    return resolve


def _make_global_resolver(index):
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
        if concretize is None:
            concretize = lambda fork: [0]

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
            concretize, strategy))

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
        if concretize is None:
            concretize = lambda fork: [0]
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
            until_pred, slice_steps, concretize, strategy))

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
        return path

    def _function_name(self, ir_func):
        decl = ir_func.source_declaration
        if decl is None:
            return None
        fd = mx.ast.FunctionDecl.FROM(decl)
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
        decl = ir_func.source_declaration
        if decl is None:
            return addrs
        fd = mx.ast.FunctionDecl.FROM(decl)
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

    def _handle_suspension(self, path, result, forks, concretize):
        if not forks:
            path.suspended = result
            path.terminal = Terminal.STUCK_SUSPENSION
            return [path]

        fork_entry = forks[0]
        addresses = list(concretize(fork_entry))
        if not addresses:
            path.suspended = result
            path.terminal = Terminal.STUCK_SUSPENSION
            return [path]

        children = []
        size = fork_entry.get("size")
        is_write = fork_entry.get("is_write")
        for addr in addresses:
            child_state = (fork_entry["state"]
                           if addr is addresses[0]
                           else _interp.clone_state(fork_entry["state"]))
            _interp.resume_addr(child_state, fork_entry["address_eid"], addr)
            child = self._fork_child(path, child_state)
            child.events.append({
                "kind": EventKind.MEMADDR_CONCRETIZE,
                "address": addr,
                "size": size,
                "is_write": is_write,
                "step": path.steps,
            })
            children.append(child)
        return children

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
        child.solver.adopt_fresh_vars(parent.solver._fresh_vars)
        return child
