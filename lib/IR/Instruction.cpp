// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Instruction.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/OpCode.h>

#include "Impl.h"
#include "../Fragment.h"
#include "../EntityProvider.h"

namespace mx {

// Entity pool layout per instruction:
//   [parentBlockId, sourceEntityId, op0..opN, ...extras]
// Position 0 = parentBlockId
// Position 1 = sourceEntityId
// Positions 2..2+numOperands-1 = data-flow operands

static capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader
GetEntityPool(const IRInstructionImpl &impl) {
  return impl.frag->reader.getIrEntityPool();
}

EntityId IRInstruction::id(void) const {
  if (!impl) return {};
  IRInstructionId iid;
  iid.fragment_id = impl->fragment_id;
  iid.offset = impl->offset;
  iid.opcode = static_cast<uint8_t>(opcode());
  return EntityId(iid);
}

ir::OpCode IRInstruction::opcode(void) const {
  if (!impl) return ir::OpCode::UNKNOWN;
  return static_cast<ir::OpCode>(impl->reader().getOpcode());
}

gap::generator<IRInstruction> IRInstruction::operands(void) const & {
  if (!impl) co_return;
  auto r = impl->reader();
  auto pool = GetEntityPool(*impl);
  uint32_t base = r.getEntityOffset() + 2;  // skip parentBlockId, sourceEntityId
  uint8_t n = r.getNumOperands();
  for (uint8_t i = 0; i < n; ++i) {
    auto eid = pool[base + i];
    auto vid = EntityId(eid).Unpack();
    if (auto *iid = std::get_if<IRInstructionId>(&vid)) {
      co_yield IRInstruction(std::make_shared<IRInstructionImpl>(
          impl->frag, iid->offset, impl->fragment_id));
    }
  }
}

unsigned IRInstruction::num_operands(void) const {
  if (!impl) return 0;
  return impl->reader().getNumOperands();
}

IRInstruction IRInstruction::nth_operand(unsigned n) const {
  if (!impl) return {};
  auto r = impl->reader();
  if (n >= r.getNumOperands()) return {};
  auto pool = GetEntityPool(*impl);
  auto eid = pool[r.getEntityOffset() + 2 + n];
  auto vid = EntityId(eid).Unpack();
  if (auto *iid = std::get_if<IRInstructionId>(&vid)) {
    return IRInstruction(std::make_shared<IRInstructionImpl>(
        impl->frag, iid->offset, impl->fragment_id));
  }
  return {};
}

std::optional<IRInstruction> IRInstruction::parent_instruction(void) const {
  if (!impl) return std::nullopt;
  auto po = impl->reader().getParentOffset();
  if (po == 0) return std::nullopt;
  return IRInstruction(std::make_shared<IRInstructionImpl>(
      impl->frag, impl->offset + po, impl->fragment_id));
}

bool IRInstruction::is_root(void) const {
  if (!impl) return false;
  return impl->reader().getParentOffset() == 0;
}

std::optional<Stmt> IRInstruction::source_statement(void) const {
  if (!impl) return std::nullopt;
  auto pool = GetEntityPool(*impl);
  auto eid = pool[impl->reader().getEntityOffset() + 1];  // position 1
  if (eid == kInvalidEntityId) return std::nullopt;
  if (auto ptr = impl->frag->ep->StmtFor(impl->frag->ep, eid)) {
    return Stmt(std::move(ptr));
  }
  return std::nullopt;
}

RawEntityId IRInstruction::source_entity_id(void) const {
  if (!impl) return kInvalidEntityId;
  auto pool = GetEntityPool(*impl);
  return pool[impl->reader().getEntityOffset() + 1];
}

IRBlock IRInstruction::parent_block(void) const {
  if (!impl) return {};
  auto pool = GetEntityPool(*impl);
  auto eid = pool[impl->reader().getEntityOffset()];  // position 0
  auto vid = EntityId(eid).Unpack();
  if (auto *bid = std::get_if<IRBlockId>(&vid)) {
    return IRBlock(std::make_shared<IRBlockImpl>(
        impl->frag, bid->offset, impl->fragment_id));
  }
  return {};
}

bool IRInstruction::is_terminator(void) const {
  return ir::IsTerminator(opcode());
}

bool IRInstruction::is_conditionally_executed(void) const {
  if (!impl) return false;
  return (impl->reader().getFlags() & 0x4) != 0;
}

}  // namespace mx
