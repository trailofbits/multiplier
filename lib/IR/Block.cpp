// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Block.h>
#include <multiplier/IR/Function.h>
#include <multiplier/IR/Instruction.h>
#include <multiplier/IR/Structure.h>

#include "Impl.h"
#include "../Fragment.h"

namespace mx {

// Entity pool layout per block (starting at entityOffset):
//   [inst0..instN, succ0..succN, pred0..predN,
//    idom, dom0..domN, ipdom, pdom0..pdomN]

static capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader
GetEntityPool(const IRBlockImpl &impl) {
  return impl.frag->reader.getIrEntityPool();
}

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

std::optional<IRStructure> IRBlock::parent_structure(void) const {
  if (!impl) return std::nullopt;
  auto eid = impl->reader().getParentStructureId();
  if (eid == kInvalidEntityId) return std::nullopt;
  auto vid = EntityId(eid).Unpack();
  if (auto *sid = std::get_if<IRStructureId>(&vid)) {
    return IRStructure(std::make_shared<IRStructureImpl>(
        impl->frag, sid->offset, impl->fragment_id));
  }
  return std::nullopt;
}

std::optional<IRFunction> IRBlock::parent_function(void) const {
  auto s = parent_structure();
  while (s) {
    if (auto f = s->parent_function()) return f;
    s = s->parent_structure();
  }
  return std::nullopt;
}

gap::generator<IRInstruction> IRBlock::all_instructions(void) const & {
  if (!impl) co_return;
  auto r = impl->reader();
  auto pool = GetEntityPool(*impl);
  uint32_t base = r.getEntityOffset();
  uint16_t n = r.getNumInstructions();
  for (uint16_t i = 0; i < n; ++i) {
    auto eid = pool[base + i];
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
  auto pool = GetEntityPool(*impl);
  auto all_insts = impl->frag->reader.getIrInstructions();
  auto full_pool = impl->frag->reader.getIrEntityPool();
  uint32_t base = r.getEntityOffset();
  uint16_t n = r.getNumInstructions();
  for (uint16_t i = 0; i < n; ++i) {
    auto eid = pool[base + i];
    auto vid = EntityId(eid).Unpack();
    if (auto *iid = std::get_if<IRInstructionId>(&vid)) {
      // Root instructions have an IRBlockId at their pool position 0.
      auto parent_eid = full_pool[all_insts[iid->offset].getEntityOffset()];
      if (std::holds_alternative<IRBlockId>(EntityId(parent_eid).Unpack())) {
        co_yield IRInstruction(std::make_shared<IRInstructionImpl>(
            impl->frag, iid->offset, impl->fragment_id));
      }
    }
  }
}

// Helper to read a block from a pool entity ID.
static std::optional<IRBlock> BlockFromPoolEid(
    const FragmentImplPtr &frag, RawEntityId fragment_id, uint64_t eid) {
  auto vid = EntityId(eid).Unpack();
  if (auto *bid = std::get_if<IRBlockId>(&vid)) {
    return IRBlock(std::make_shared<IRBlockImpl>(frag, bid->offset, fragment_id));
  }
  return std::nullopt;
}

gap::generator<IRBlock> IRBlock::successors(void) const & {
  if (!impl) co_return;
  auto r = impl->reader();
  auto pool = GetEntityPool(*impl);
  uint32_t base = r.getEntityOffset() + r.getNumInstructions();
  for (uint16_t i = 0; i < r.getNumSuccessors(); ++i) {
    if (auto b = BlockFromPoolEid(impl->frag, impl->fragment_id, pool[base + i])) {
      co_yield *b;
    }
  }
}

gap::generator<IRBlock> IRBlock::predecessors(void) const & {
  if (!impl) co_return;
  auto r = impl->reader();
  auto pool = GetEntityPool(*impl);
  uint32_t base = r.getEntityOffset() + r.getNumInstructions() + r.getNumSuccessors();
  for (uint16_t i = 0; i < r.getNumPredecessors(); ++i) {
    if (auto b = BlockFromPoolEid(impl->frag, impl->fragment_id, pool[base + i])) {
      co_yield *b;
    }
  }
}

std::optional<IRBlock> IRBlock::immediate_dominator(void) const {
  if (!impl) return std::nullopt;
  auto r = impl->reader();
  if (r.getNumDominators() == 0) return std::nullopt;
  auto pool = GetEntityPool(*impl);
  uint32_t base = r.getEntityOffset() + r.getNumInstructions()
      + r.getNumSuccessors() + r.getNumPredecessors();
  return BlockFromPoolEid(impl->frag, impl->fragment_id, pool[base]);
}

std::optional<IRBlock> IRBlock::immediate_post_dominator(void) const {
  if (!impl) return std::nullopt;
  auto r = impl->reader();
  if (r.getNumPostDominators() == 0) return std::nullopt;
  auto pool = GetEntityPool(*impl);
  uint32_t base = r.getEntityOffset() + r.getNumInstructions()
      + r.getNumSuccessors() + r.getNumPredecessors() + r.getNumDominators();
  return BlockFromPoolEid(impl->frag, impl->fragment_id, pool[base]);
}

gap::generator<IRBlock> IRBlock::dominators(void) const & {
  if (!impl) co_return;
  auto r = impl->reader();
  auto pool = GetEntityPool(*impl);
  uint32_t base = r.getEntityOffset() + r.getNumInstructions()
      + r.getNumSuccessors() + r.getNumPredecessors();
  for (uint16_t i = 0; i < r.getNumDominators(); ++i) {
    if (auto b = BlockFromPoolEid(impl->frag, impl->fragment_id, pool[base + i])) {
      co_yield *b;
    }
  }
}

gap::generator<IRBlock> IRBlock::post_dominators(void) const & {
  if (!impl) co_return;
  auto r = impl->reader();
  auto pool = GetEntityPool(*impl);
  uint32_t base = r.getEntityOffset() + r.getNumInstructions()
      + r.getNumSuccessors() + r.getNumPredecessors() + r.getNumDominators();
  for (uint16_t i = 0; i < r.getNumPostDominators(); ++i) {
    if (auto b = BlockFromPoolEid(impl->frag, impl->fragment_id, pool[base + i])) {
      co_yield *b;
    }
  }
}

bool IRBlock::dominates(const IRBlock &other) const {
  if (!impl || !other.impl) return false;
  auto my_id = id().Pack();
  auto r = other.impl->reader();
  auto pool = GetEntityPool(*other.impl);
  uint32_t base = r.getEntityOffset() + r.getNumInstructions()
      + r.getNumSuccessors() + r.getNumPredecessors();
  for (uint16_t i = 0; i < r.getNumDominators(); ++i) {
    if (pool[base + i] == my_id) return true;
  }
  return false;
}

}  // namespace mx
