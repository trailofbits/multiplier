# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""SymExEngine — orchestrates symbolic exploration over the IR
interpreter.

Phase 1 scope: enumerate paths through the existing C++ symbolic
substrate. Forks come in two flavors:

  * BranchContinuation — the policy returned `is_true is None` for a
    COND_BRANCH cond. The substrate's `step` already enumerates the two
    edges into `forks`; the driver adds one path per edge.

  * MemAddrContinuation — the policy returned a non-`("ptr", ...)`
    value for a memory-op address. Phase 1 falls back to
    ConcretizeFinite([0]); each candidate becomes a path via
    `resume_addr`. Phase 5 swaps strategies in.

The driver does NOT dispatch hooks (Phase 2) and does NOT integrate z3
(Phase 4). It does record one structured `branch` event per fork so
P1.4 has something to query.
"""

import multiplier as mx

from .layout import Layout
from .lens import MemView, ArgsView
from .path import Path
from .until import ExploreUntil

_interp = mx.ir.interpret


class _PassthroughPolicy:
    """Default policy when the analyst hasn't supplied one.

    No method overrides — the C++ side falls back to concrete semantics
    everywhere.
    """


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


class SymExEngine:
    def __init__(self, index):
        self._index = index
        self.layout = None
        self._func_resolver = _make_func_resolver(index)
        self._global_resolver = _make_global_resolver(index)

    def explore(self, start_func, *, start_block=None, args=None, seed=None,
                policy=None, until=None, slice_steps=_DEFAULT_SLICE_STEPS,
                concretize=None):
        ir_func = self._resolve_start(start_func)
        if ir_func is None:
            raise ValueError(f"start_func {start_func!r} not found in index")

        if seed is not None and start_block is None:
            # seed maps eid -> python value; mid-block entry is Phase 3.
            raise ValueError(
                "value seed requires start_block (mid-block entry; Phase 3)")

        until_pred = until if until is not None else ExploreUntil.never()
        if concretize is None:
            concretize = lambda fork: [0]

        active_policy = policy if policy is not None else _PassthroughPolicy()
        layout = self.layout if self.layout is not None else Layout()
        memory = layout.memory

        initial_path = self._init_path(
            ir_func, memory, active_policy, args=args,
            start_block=start_block, value_seed=seed)

        paths = [initial_path]

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
                children = self._step_one(
                    path, memory, active_policy, slice_steps, concretize)
                new_paths.extend(children)
                if until_pred(_ExploreState(new_paths +
                                            [p for p in paths
                                             if p not in new_paths and
                                             p.terminal is not None],
                                            sum(p.steps for p in new_paths))):
                    # Predicate fired mid-tick; capture and break out.
                    break

            paths = new_paths
            if not any(p.terminal is None for p in paths):
                break

        return paths

    # -- internals ---------------------------------------------------------

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
        return Path(state, memory)

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

        if result is None:
            # Pre-CRDT idle tick — treat as live, no progress.
            return [path]

        kind = result[0]
        if kind == "completed":
            path.terminal = "completed"
            path.return_value = result[1]
            return [path]
        if kind == "error":
            path.terminal = "error"
            path.error_kind = result[1]
            return [path]
        if kind == "budget":
            # Slice exhausted; same path continues next tick.
            return [path]
        if kind == "branch":
            return self._handle_branch_forks(path, result, forks)
        if kind == "suspended":
            return self._handle_suspension(path, result, forks, concretize)

        path.terminal = "unknown"
        return [path]

    def _handle_branch_forks(self, path, result, forks):
        _, cond, t_eid, f_eid = result
        if not forks:
            path.terminal = "stuck-branch"
            return [path]

        children = []
        for entry in forks:
            child_state = entry["state"]
            direction = entry.get("direction", "?")
            child = Path(child_state, path.mem, parent_id=path.id)
            child.events = list(path.events)
            child.tags = set(path.tags)
            child.solver = path.solver
            child.events.append({
                "kind": "branch",
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
            path.terminal = "stuck-suspension"
            return [path]

        fork_entry = forks[0]
        addresses = list(concretize(fork_entry))
        if not addresses:
            path.suspended = result
            path.terminal = "stuck-suspension"
            return [path]

        children = []
        size = fork_entry.get("size")
        is_write = fork_entry.get("is_write")
        for addr in addresses:
            child_state = (fork_entry["state"]
                           if addr is addresses[0]
                           else _interp.clone_state(fork_entry["state"]))
            _interp.resume_addr(child_state, fork_entry["address_eid"], addr)
            child = Path(child_state, path.mem, parent_id=path.id)
            child.events = list(path.events)
            child.tags = set(path.tags)
            child.solver = path.solver
            child.events.append({
                "kind": "memaddr_concretize",
                "address": addr,
                "size": size,
                "is_write": is_write,
                "step": path.steps,
            })
            children.append(child)
        return children
