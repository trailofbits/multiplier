// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Block.h>
#include <multiplier/IR/Instruction.h>

#include "Impl.h"
#include "../Fragment.h"

namespace mx {

EntityId IRBlock::id(void) const {
  if (!impl) return {};
  IRBlockId bid;
  bid.fragment_id = impl->fragment_id;
  bid.offset = impl->offset;
  bid.block_kind = static_cast<uint8_t>(kind());
  return EntityId(bid);
}

ir::BlockKind IRBlock::kind(void) const {
  if (!impl) return ir::BlockKind::GENERIC;
  return static_cast<ir::BlockKind>(impl->reader().getKind());
}

gap::generator<IRInstruction> IRBlock::all_instructions(void) const & {
  if (!impl) co_return;
  auto r = impl->reader();
  for (auto eid : r.getInstructions()) {
    auto vid = EntityId(eid).Unpack();
    if (auto *iid = std::get_if<IRInstructionId>(&vid)) {
      co_yield IRInstruction(std::make_shared<IRInstructionImpl>(
          impl->frag, iid->offset, impl->fragment_id));
    }
  }
}

gap::generator<IRInstruction> IRBlock::instructions(void) const & {
  if (!impl) co_return;
  auto r = impl->reader();
  auto insts = r.getInstructions();
  auto all_insts = impl->frag->reader.getIrInstructions();
  for (auto eid : insts) {
    auto vid = EntityId(eid).Unpack();
    if (auto *iid = std::get_if<IRInstructionId>(&vid)) {
      // Only yield top-level instructions (parentOffset == 0).
      if (all_insts[iid->offset].getParentOffset() == 0) {
        co_yield IRInstruction(std::make_shared<IRInstructionImpl>(
            impl->frag, iid->offset, impl->fragment_id));
      }
    }
  }
}

static IRBlock BlockFromEid(const FragmentImplPtr &frag,
                             RawEntityId fragment_id, RawEntityId eid) {
  auto vid = EntityId(eid).Unpack();
  if (auto *bid = std::get_if<IRBlockId>(&vid)) {
    return IRBlock(std::make_shared<IRBlockImpl>(frag, bid->offset,
                                                  fragment_id));
  }
  return {};
}

gap::generator<IRBlock> IRBlock::successors(void) const & {
  if (!impl) co_return;
  for (auto eid : impl->reader().getSuccessors()) {
    auto b = BlockFromEid(impl->frag, impl->fragment_id, eid);
    if (b) co_yield b;
  }
}

gap::generator<IRBlock> IRBlock::predecessors(void) const & {
  if (!impl) co_return;
  for (auto eid : impl->reader().getPredecessors()) {
    auto b = BlockFromEid(impl->frag, impl->fragment_id, eid);
    if (b) co_yield b;
  }
}

std::optional<IRBlock> IRBlock::immediate_dominator(void) const {
  if (!impl) return std::nullopt;
  auto eid = impl->reader().getImmediateDominator();
  if (eid == 0) return std::nullopt;
  auto b = BlockFromEid(impl->frag, impl->fragment_id, eid);
  if (b) return b;
  return std::nullopt;
}

std::optional<IRBlock> IRBlock::immediate_post_dominator(void) const {
  if (!impl) return std::nullopt;
  auto eid = impl->reader().getImmediatePostDominator();
  if (eid == 0) return std::nullopt;
  auto b = BlockFromEid(impl->frag, impl->fragment_id, eid);
  if (b) return b;
  return std::nullopt;
}

gap::generator<IRBlock> IRBlock::dominators(void) const & {
  if (!impl) co_return;
  for (auto eid : impl->reader().getDominators()) {
    auto b = BlockFromEid(impl->frag, impl->fragment_id, eid);
    if (b) co_yield b;
  }
}

gap::generator<IRBlock> IRBlock::post_dominators(void) const & {
  if (!impl) co_return;
  for (auto eid : impl->reader().getPostDominators()) {
    auto b = BlockFromEid(impl->frag, impl->fragment_id, eid);
    if (b) co_yield b;
  }
}

bool IRBlock::dominates(const IRBlock &other) const {
  if (!impl || !other.impl) return false;
  auto my_id = id().Pack();
  for (auto eid : other.impl->reader().getDominators()) {
    if (eid == my_id) return true;
  }
  return false;
}

}  // namespace mx
