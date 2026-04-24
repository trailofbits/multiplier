#!/usr/bin/env python3
"""
Symbolic execution explorer for the multiplier IR interpreter.

Drives the C++ interpreter via the sym_init_state/sym_step Python API,
using a SymbolicPolicy that can fork on symbolic branch conditions.

Usage:
    python3 explorer.py <db_path> <function_name> [arg0 arg1 ...]

Example:
    python3 explorer.py tests/InterpretIR/mx-index.db test_control_flow

The explorer runs the function through the concrete interpreter via the
symbolic policy bridge. When a branch condition is symbolic (is_true
returns None), the explorer forks execution into two paths.
"""

import sys
from dataclasses import dataclass, field
from typing import Optional, List, Tuple, Any

import multiplier as mx

interp = mx.ir.interpret


@dataclass
class ExplorationResult:
    """Result of exploring a single path."""
    status: str           # "completed", "error", "budget"
    return_value: Any     # The return value (if completed)
    path_decisions: list  # Branch decisions taken [(condition, took_true), ...]
    steps: int            # Total instruction steps


@dataclass
class ExplorationState:
    """A pending state in the worklist."""
    branch_decisions: list = field(default_factory=list)
    # List of (branch_index, take_true) tuples that replay branch history


class Explorer:
    """DFS explorer that forks on symbolic branches.

    Strategy: run to completion with a BranchReplayPolicy that records/replays
    branch decisions. On the first unknown branch, pick True and queue False
    for later exploration.
    """

    def __init__(self, idx: mx.Index, func_name: str,
                 args: Optional[List[int]] = None,
                 max_steps: int = 100000, max_paths: int = 100):
        self.idx = idx
        self.func_name = func_name
        self.args = args or []
        self.max_steps = max_steps
        self.max_paths = max_paths

        self.ir_func = self._find_function()
        if not self.ir_func:
            raise ValueError(f"Function '{func_name}' not found in database")

        self.func_resolver = self._make_func_resolver()
        self.global_resolver = self._make_global_resolver()
        self.results: List[ExplorationResult] = []

    def _find_function(self) -> Optional[mx.ir.IRFunction]:
        for frag in mx.Fragment.IN(self.idx):
            for decl in mx.ast.Decl.IN(frag):
                fd = mx.ast.FunctionDecl.FROM(decl)
                if fd and str(fd.name) == self.func_name:
                    ir = mx.ir.IRFunction.FROM(fd)
                    if ir:
                        return ir
        return None

    def _make_func_resolver(self):
        idx = self.idx
        def resolver(eid):
            entity = mx.Entity.FROM(idx, eid)
            if entity:
                fd = mx.ast.FunctionDecl.FROM(entity)
                if fd:
                    return mx.ir.IRFunction.FROM(fd)
            return None
        return resolver

    def _make_global_resolver(self):
        idx = self.idx
        def resolver(eid):
            entity = mx.Entity.FROM(idx, eid)
            if not entity:
                return None
            vd = mx.ast.VarDecl.FROM(entity)
            if not vd:
                return None
            vt = vd.type
            size = 0
            if hasattr(vt, 'size_in_bits'):
                bits = vt.size_in_bits
                if bits:
                    size = (bits + 7) // 8
            if size == 0:
                size = 8
            align = 8
            canonical = eid
            initializer = None
            ir = mx.ir.IRFunction.FROM(vd)
            if ir:
                initializer = ir
            return (canonical, size, align, initializer)
        return resolver

    def explore(self) -> List[ExplorationResult]:
        """Run DFS exploration. Returns list of path results."""
        worklist: List[ExplorationState] = [ExplorationState()]

        while worklist and len(self.results) < self.max_paths:
            state = worklist.pop()
            result, new_states = self._run_path(state)
            if result:
                self.results.append(result)
            worklist.extend(new_states)

        return self.results

    def _run_path(self, exploration_state: ExplorationState
                  ) -> Tuple[Optional[ExplorationResult], List[ExplorationState]]:
        """Run a single path. Returns (result, new_worklist_entries)."""

        branch_history = list(exploration_state.branch_decisions)
        branch_index = [0]  # mutable counter for the policy closure
        new_branches: list = []

        class ReplayPolicy:
            """Policy that replays recorded branch decisions and records new ones."""

            def is_true(self_policy, val):
                return NotImplemented  # Let C++ concrete handle it

            def resolve_branch(self_policy, condition, true_eid, false_eid):
                idx = branch_index[0]
                branch_index[0] += 1

                if idx < len(branch_history):
                    # Replay a previously recorded decision.
                    return branch_history[idx]
                else:
                    # New branch: take True, queue False for later.
                    new_branches.append((idx, True))
                    return True

        mem = interp.ConcreteMemory()
        istate = interp.InterpreterState()
        policy = ReplayPolicy()

        py_args = [a for a in self.args]
        interp.sym_init_state(istate, mem, policy, self.ir_func, py_args,
                              self.func_resolver, self.global_resolver)
        result = interp.sym_step(istate, mem, policy, self.max_steps,
                                 self.func_resolver, self.global_resolver)

        res_tuple = result.get("result")
        if not res_tuple:
            return None, []

        status = res_tuple[0] if isinstance(res_tuple, tuple) else str(res_tuple)
        ret_val = res_tuple[1] if isinstance(res_tuple, tuple) and len(res_tuple) > 1 else None

        exploration_result = ExplorationResult(
            status=status,
            return_value=ret_val,
            path_decisions=branch_history + [(True,) for _ in new_branches],
            steps=istate.steps,
        )

        # Queue the alternative path for each new branch.
        new_states = []
        for branch_idx, took_true in new_branches:
            alt_decisions = list(branch_history)
            # Pad with True for branches before this one.
            while len(alt_decisions) < branch_idx:
                alt_decisions.append(True)
            alt_decisions.append(False)  # Take the other path.
            new_states.append(ExplorationState(branch_decisions=alt_decisions))

        return exploration_result, new_states


def main():
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <db_path> <function_name> [args...]",
              file=sys.stderr)
        sys.exit(1)

    db_path = sys.argv[1]
    func_name = sys.argv[2]
    args = [int(a) for a in sys.argv[3:]]

    idx = mx.Index.from_database(db_path)
    explorer = Explorer(idx, func_name, args, max_steps=100000, max_paths=50)
    results = explorer.explore()

    print(f"Explored {len(results)} paths for {func_name}:")
    for i, r in enumerate(results):
        print(f"  Path {i}: status={r.status}, return={r.return_value}, "
              f"steps={r.steps}, decisions={len(r.path_decisions)}")


if __name__ == "__main__":
    main()
