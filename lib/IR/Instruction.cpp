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
  for (auto eid : r.getOperands()) {
    auto vid = EntityId(eid).Unpack();
    if (auto *iid = std::get_if<IRInstructionId>(&vid)) {
      co_yield IRInstruction(std::make_shared<IRInstructionImpl>(
          impl->frag, iid->offset, impl->fragment_id));
    }
  }
}

unsigned IRInstruction::num_operands(void) const {
  if (!impl) return 0;
  return impl->reader().getOperands().size();
}

IRInstruction IRInstruction::nth_operand(unsigned n) const {
  if (!impl) return {};
  auto ops = impl->reader().getOperands();
  if (n >= ops.size()) return {};
  auto vid = EntityId(ops[n]).Unpack();
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
  auto eid = impl->reader().getSourceEntityId();
  if (eid == kInvalidEntityId) return std::nullopt;
  // Resolve through entity provider.
  if (auto ptr = impl->frag->ep->StmtFor(impl->frag->ep, eid)) {
    return Stmt(std::move(ptr));
  }
  return std::nullopt;
}

RawEntityId IRInstruction::source_entity_id(void) const {
  if (!impl) return kInvalidEntityId;
  return impl->reader().getSourceEntityId();
}

IRBlock IRInstruction::parent_block(void) const {
  if (!impl) return {};
  auto block_eid = impl->reader().getParentBlockId();
  auto vid = EntityId(block_eid).Unpack();
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

RawEntityId IRInstruction::target_entity_id(void) const {
  if (!impl) return kInvalidEntityId;
  return impl->reader().getTargetEntityId();
}

RawEntityId IRInstruction::type_entity_id(void) const {
  if (!impl) return kInvalidEntityId;
  return impl->reader().getTypeEntityId();
}

RawEntityId IRInstruction::object_entity_id(void) const {
  if (!impl) return kInvalidEntityId;
  return impl->reader().getObjectId();
}

int64_t IRInstruction::int_value(void) const {
  if (!impl) return 0;
  return impl->reader().getIntValue();
}

uint64_t IRInstruction::uint_value(void) const {
  if (!impl) return 0;
  return impl->reader().getUintValue();
}

double IRInstruction::float_value(void) const {
  if (!impl) return 0.0;
  return impl->reader().getFloatValue();
}

uint8_t IRInstruction::width(void) const {
  if (!impl) return 0;
  return impl->reader().getWidth();
}

uint32_t IRInstruction::size_bytes(void) const {
  if (!impl) return 0;
  return impl->reader().getSizeBytes();
}

uint8_t IRInstruction::flags(void) const {
  if (!impl) return 0;
  return impl->reader().getFlags();
}

ir::OpCode IRInstruction::compound_op(void) const {
  if (!impl) return ir::OpCode::UNKNOWN;
  return static_cast<ir::OpCode>(impl->reader().getCompoundOp());
}

}  // namespace mx
