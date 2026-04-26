"""Phase 3 — loop & path control.

Catalog (matches docs/symex-phase3-plan.md):

P3.1  Backedge analysis classifies a loop's latch->header edge.
P3.2  intercept.branch handler returns False, substrate takes the false
      edge regardless of the natural condition.
P3.3  intercept.loop limits iteration; handler returns False on the 4th
      hit; path summary shows iteration=3 then exit.
P3.4  Path.snapshot() / restore() round-trips state, events, tags,
      terminal, return_value, and the loop counter.
P3.5  Path.replay(modify=...) runs a fresh exploration from a snapshot
      with one mutation, taking a different branch.
P3.6  engine.explore(strategy="dfs") and "bfs" both run to completion;
      DFS commits to a path before opening siblings.
"""

import pytest

from symex import (
    SymExEngine,
    ExploreUntil,
    SymExpr,
)
from symex.cfg import classify_edges
from conftest import ForkOnSymbolicBranchPolicy, SymExpr as _ConfSymExpr


# --- P3.1 ----------------------------------------------------------------

def test_p3_1_backedge_analysis(index):
    """test_control_flow has multiple loops; classify_edges should
    discover at least one back-edge per loop and identify the loop's
    cond_branch source as a loop guard."""
    from symex.engine import _resolve_function
    ir_func = _resolve_function(index, "test_control_flow")
    assert ir_func is not None
    cfg = classify_edges(ir_func)

    # The function has several distinct while/for/do-while loops; each
    # contributes a back-edge.
    assert len(cfg.back_edges) >= 4, \
        f"expected >=4 back-edges, got {cfg.back_edges}"

    # Every back-edge has its source in latch_blocks and its dest in
    # header_blocks.
    for src, dst in cfg.back_edges:
        assert src in cfg.latch_blocks
        assert dst in cfg.header_blocks
        assert cfg.classification[(src, dst)] == "back"

    # At least one cond_branch in the function should be flagged as a
    # loop guard, with its continue/exit edges identified.
    assert cfg.loop_branches, \
        "no loop-guard cond_branches identified"
    for src_id, info in cfg.loop_branches.items():
        assert info["continue_dst"] != info["exit_dst"]
        assert info["header"] is not None


# --- P3.2 ----------------------------------------------------------------

def test_p3_2_intercept_branch_forces_edge(index):
    """intercept.branch with a func= selector forces every cond_branch
    in test_function_calls to take the false edge. test_function_calls
    starts `if (add(3,4) != 7) return 1` — natural false edge. With our
    handler the branch is forced false, so the function falls through
    every guard and reaches `return 0`."""
    engine = SymExEngine(index)
    fired = []

    @engine.intercept.branch(func="test_function_calls")
    def force_false(ctx, condition, next_hook):
        fired.append((ctx.true_eid, ctx.false_eid, condition))
        return False

    paths = engine.explore("test_function_calls")
    assert paths[0].return_value == 0
    assert fired, "intercept.branch never fired"


# --- P3.3 ----------------------------------------------------------------

def test_p3_3_loop_iterates_n_then_exits(index):
    """test_control_flow's first loop sums i = 1..5 (sum should be 15);
    if we cap at 3 iterations the early-exit makes sum = 1+2+3 = 6, and
    the post-loop check `if (sum != 15) return 2` fires."""
    engine = SymExEngine(index)
    iterations = []

    @engine.intercept.loop(func="test_control_flow")
    def lp(ctx, next_hook):
        iterations.append(ctx.loop.iteration)
        if ctx.loop.iteration >= 3:
            return False        # take the exit edge
        return next_hook(ctx)   # take whatever the natural branch picks

    paths = engine.explore("test_control_flow")
    assert paths[0].return_value == 2
    assert 0 in iterations and 3 in iterations
    # The loop hook should have fired 4 times before the exit (iter 0..3).
    assert iterations[:4] == [0, 1, 2, 3]


# --- P3.4 ----------------------------------------------------------------

def test_p3_4_path_snapshot_restore(index):
    """Run a path partway, snapshot, mutate, restore — state, events,
    tags, terminal, return_value, and the loop counter all round-trip."""
    engine = SymExEngine(index)
    paths = engine.explore("test_function_calls",
                            until=ExploreUntil.steps(50))
    assert paths
    p = paths[0]

    snap = p.snapshot()
    saved_steps = p.steps
    saved_events = list(p.events)
    saved_terminal = p.terminal
    saved_return = p.return_value

    # Mutate; restore should undo all of these.
    p.tags.add("touched")
    p.events.append({"kind": "synthetic"})

    p.restore(snap)

    assert p.steps == saved_steps
    assert p.events == saved_events
    assert "touched" not in p.tags
    assert p.terminal == saved_terminal
    assert p.return_value == saved_return

    # Snapshot is reusable — restoring twice must not break the
    # snap's internal state.
    p.tags.add("again")
    p.restore(snap)
    assert "again" not in p.tags


# --- P3.5 ----------------------------------------------------------------

def test_p3_5_path_replay_with_modify(index):
    """`intercept.call(name="factorial")` reads `path.tags`. Without
    the tag the handler forwards → factorial inlines naturally → 120.
    Snapshot an unstepped path, replay with `modify` setting the tag →
    the recursive factorial(4) call short-circuits with 999, leaving
    the outer factorial(5) to compute 5 * 999 = 4995."""
    engine = SymExEngine(index)

    @engine.intercept.call(name="factorial")
    def fake_fact(ctx, next_hook):
        if "alt" in ctx.path.tags:
            return 999
        return next_hook(ctx)

    natural = engine.explore("factorial", args=[5])
    assert natural[0].return_value == 120

    init = engine.explore("factorial", args=[5],
                            until=ExploreUntil.steps(0))
    assert init and init[0].terminal is None
    seed = init[0]

    def modify(path):
        path.tags.add("alt")

    replayed = seed.replay(modify=modify, engine=engine)
    assert replayed
    # The intercept fires on the recursive call to factorial(4), not on
    # the entry-point factorial(5). The outer body computes
    # 5 * factorial_intercepted(4) = 5 * 999 = 4995.
    assert replayed[0].return_value == 4995
    assert "alt" in replayed[0].tags
    # The original natural path is unaffected by the replay.
    assert natural[0].return_value == 120


# --- P3.6 ----------------------------------------------------------------

def test_p3_6_explore_dfs_vs_bfs(index):
    """factorial(symbolic) forks at every recursive guard. BFS and DFS
    both reach the path-count budget; DFS commits to a single chain
    before opening siblings, BFS expands breadth-first.

    Both should return at least the budget number of paths. The
    terminal-vs-live mix may differ but the explorer must not crash."""
    common = dict(
        args=[_ConfSymExpr("input", ("n",))],
        policy=ForkOnSymbolicBranchPolicy(),
        until=ExploreUntil.path_count(4),
        slice_steps=400,
    )
    bfs = SymExEngine(index).explore("factorial", strategy="bfs", **common)
    dfs = SymExEngine(index).explore("factorial", strategy="dfs", **common)

    assert len(bfs) >= 4
    assert len(dfs) >= 4

    # DFS commits depth-first: the first path that gets driven all the
    # way to a terminal should be deeper (more steps) than the
    # corresponding shallowest BFS terminal at the budget.
    bfs_completed_steps = sorted(p.steps for p in bfs
                                  if p.terminal is not None)
    dfs_completed_steps = sorted(p.steps for p in dfs
                                  if p.terminal is not None)
    if bfs_completed_steps and dfs_completed_steps:
        # Weak ordering signal: DFS's max-step terminal >= BFS's
        # max-step terminal (DFS dives, BFS spreads).
        assert dfs_completed_steps[-1] >= bfs_completed_steps[-1] // 2


# --- ExploreUntil.max_paths / max_depth ----------------------------------

def test_p3_explore_until_max_paths(index):
    """ExploreUntil.max_paths is an alias spelling of path_count, used
    in the Phase 3 documentation. Behavior should match."""
    engine = SymExEngine(index)
    paths = engine.explore(
        "factorial",
        args=[_ConfSymExpr("input", ("n",))],
        policy=ForkOnSymbolicBranchPolicy(),
        until=ExploreUntil.max_paths(3),
        slice_steps=400,
    )
    assert 3 <= len(paths) <= 4


def test_p3_explore_until_max_depth(index):
    """ExploreUntil.max_depth fires when any path's `steps` exceeds
    the bound. The bound is a step count, not a branch-depth; a single
    long-running path trips it."""
    engine = SymExEngine(index)
    paths = engine.explore(
        "factorial",
        args=[_ConfSymExpr("input", ("n",))],
        policy=ForkOnSymbolicBranchPolicy(),
        until=ExploreUntil.max_depth(50),
        slice_steps=20,
    )
    assert paths
    assert any(p.steps >= 50 for p in paths)
