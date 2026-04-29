# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Per-function back-edge analysis for `intercept.loop`.

`classify_edges(ir_func)` does an iterative DFS over the function's
blocks, classifying every CFG edge as `tree`, `forward`, `cross`, or
`back`. Back-edges seed the loop machinery: their headers are the
classified loop headers, and conditional branches whose source block is
either a back-edge head or tail are flagged as "loop guards" — the
points where `intercept.loop` can fire.

For each loop-guard cond_branch we precompute which of its two outgoing
edges is the loop-continuation edge (the one that re-enters the loop
body, eventually triggering a back-edge) versus the exit edge (the one
that leaves the loop). That mapping lets `LoopContext.would_exit` give
a concrete answer for concrete branch conditions without any extra IR
walk at dispatch time.
"""

from enum import StrEnum


class EdgeKind(StrEnum):
    TREE = "tree"
    FORWARD = "forward"
    BACK = "back"


class _DfsColor(StrEnum):
    ON_STACK = "on_stack"
    VISITED = "visited"


class CFGInfo:
    """Result of `classify_edges`. All fields are immutable after the
    analysis returns; the engine caches one CFGInfo per function."""

    __slots__ = ("back_edges", "header_blocks", "latch_blocks",
                 "classification", "loop_branches", "branch_to_src")

    def __init__(self):
        self.back_edges = []
        self.header_blocks = set()
        self.latch_blocks = set()
        self.classification = {}
        # src_block_id -> dict with keys: header, latch, continue_dst,
        # exit_dst. Populated only for cond_branches that gate a loop.
        self.loop_branches = {}
        # (true_dst_id, false_dst_id) -> [src_block_id, ...]
        self.branch_to_src = {}

    def is_back_edge(self, src, dst):
        return self.classification.get((src, dst)) == EdgeKind.BACK

    def loop_info_for_branch(self, true_dst, false_dst):
        """Return the loop_branches entry for the cond_branch whose
        outgoing edges land on (true_dst, false_dst), or None.

        Multiple sources with the same (t, f) pair are exceedingly rare;
        we return the first match (deterministic via DFS visit order).
        """
        srcs = self.branch_to_src.get((true_dst, false_dst))
        if not srcs:
            return None
        for src in srcs:
            entry = self.loop_branches.get(src)
            if entry is not None:
                return entry
        return None


def classify_edges(ir_func):
    """DFS over `ir_func.blocks`, returning a populated CFGInfo.

    Successors are visited in `block.id` order so the classification is
    stable across runs. The DFS uses an explicit stack rather than
    recursion so functions with deep CFGs don't blow the Python
    recursion limit.
    """
    blocks = {}
    for b in ir_func.blocks:
        blocks[b.id] = b

    info = CFGInfo()
    if not blocks:
        return info

    entry = ir_func.entry_block
    if entry is None or entry.id not in blocks:
        # Pick the lowest-id block as entry if the IR didn't surface one.
        entry = blocks[min(blocks)]

    color = {}
    stack = []  # (node_id, sorted_succ_ids, child_index)
    color[entry.id] = _DfsColor.ON_STACK
    stack.append([entry.id,
                  sorted(s.id for s in blocks[entry.id].successors), 0])

    while stack:
        frame = stack[-1]
        node_id, succs, idx = frame
        if idx >= len(succs):
            color[node_id] = _DfsColor.VISITED
            stack.pop()
            continue
        child_id = succs[idx]
        frame[2] = idx + 1

        if child_id not in color:
            info.classification[(node_id, child_id)] = EdgeKind.TREE
            color[child_id] = _DfsColor.ON_STACK
            stack.append([child_id,
                          sorted(s.id for s in
                                 blocks.get(child_id, blocks[node_id])
                                 .successors), 0])
        elif color[child_id] == _DfsColor.ON_STACK:
            info.classification[(node_id, child_id)] = EdgeKind.BACK
            info.back_edges.append((node_id, child_id))
            info.header_blocks.add(child_id)
            info.latch_blocks.add(node_id)
        else:
            # Forward (DFS-tree descendant) or cross (sibling subtree).
            # We don't distinguish; both are non-loop edges.
            info.classification[(node_id, child_id)] = EdgeKind.FORWARD

    # Any block not reached by DFS still gets classification entries for
    # its outgoing edges (best-effort; unreachable blocks are rare in
    # well-formed IR but the analysis shouldn't crash on them).
    for block in ir_func.blocks:
        if block.id in color:
            continue
        for s in block.successors:
            info.classification.setdefault((block.id, s.id),
                                            EdgeKind.FORWARD)

    # Build the (true, false) -> src reverse map and the loop_branches
    # table. Iterate ir_func.blocks (not the dict) so deterministic.
    for block in ir_func.blocks:
        succs = list(block.successors)
        if len(succs) != 2:
            continue
        t_id, f_id = succs[0].id, succs[1].id
        info.branch_to_src.setdefault((t_id, f_id), []).append(block.id)

        is_latch = block.id in info.latch_blocks
        is_header = block.id in info.header_blocks
        if not (is_latch or is_header):
            continue

        continue_dst = exit_dst = None
        header = latch = None

        if is_latch:
            # do-while shape: src is the latch; one edge goes back to
            # the header, the other leaves.
            for src_id, hdr_id in info.back_edges:
                if src_id != block.id:
                    continue
                if t_id == hdr_id:
                    continue_dst, exit_dst = t_id, f_id
                    header, latch = hdr_id, block.id
                    break
                if f_id == hdr_id:
                    continue_dst, exit_dst = f_id, t_id
                    header, latch = hdr_id, block.id
                    break

        if continue_dst is None and is_header:
            # while/for shape: src is the header; the loop body
            # eventually reaches a latch that back-edges to src.
            latches_for_header = {src_id for src_id, hdr in info.back_edges
                                  if hdr == block.id}
            if _can_reach(blocks, t_id, latches_for_header,
                          stop=block.id):
                continue_dst, exit_dst = t_id, f_id
            elif _can_reach(blocks, f_id, latches_for_header,
                            stop=block.id):
                continue_dst, exit_dst = f_id, t_id
            if continue_dst is not None:
                header = block.id
                # Pick any latch deterministically — first by id.
                latch = min(latches_for_header) if latches_for_header \
                    else None

        if continue_dst is not None:
            info.loop_branches[block.id] = {
                "header": header,
                "latch": latch,
                "continue_dst": continue_dst,
                "exit_dst": exit_dst,
            }

    return info


def _can_reach(blocks, start_id, targets, *, stop):
    """BFS from `start_id`; return True if any block in `targets` is
    reachable without traversing through `stop` (the header). The stop
    block is excluded so we measure "lives inside the loop body".
    """
    if not targets:
        return False
    if start_id in targets:
        return True
    seen = {start_id, stop}
    queue = [start_id]
    while queue:
        node = queue.pop()
        block = blocks.get(node)
        if block is None:
            continue
        for s in block.successors:
            sid = s.id
            if sid in targets:
                return True
            if sid in seen:
                continue
            seen.add(sid)
            queue.append(sid)
    return False
