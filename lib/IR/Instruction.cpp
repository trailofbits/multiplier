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

// Pool layout per instruction:
//   Position 0: parentBlockOrInstruction (IRBlockId for roots, IRInstructionId for sub-exprs)
//   Position 1: sourceEntityId
//   Position 2 (value-producing only): resultType
//   After that: operands, then opcode-specific extras

static capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader
GetEntityPool(const IRInstructionImpl &impl) {
  return impl.frag->reader.getIrEntityPool();
}

static capnp::List<int64_t, capnp::Kind::PRIMITIVE>::Reader
GetIntPool(const IRInstructionImpl &impl) {
  return impl.frag->reader.getIrIntPool();
}

// Does this opcode produce a typed value (has result type at position 2)?
static bool HasResultType(ir::OpCode op) {
  return !ir::IsTerminator(op) &&
         op != ir::OpCode::VA_START &&
         op != ir::OpCode::VA_END &&
         op != ir::OpCode::VA_COPY &&
         op != ir::OpCode::UNKNOWN;
}

// Starting pool offset of operands for this instruction.
static uint32_t OperandBase(const IRInstructionImpl &impl) {
  auto r = impl.reader();
  auto op = static_cast<ir::OpCode>(r.getOpcode());
  bool has_type = HasResultType(op);
  if (has_type && op == ir::OpCode::MEMORY) {
    auto int_pool = GetIntPool(impl);
    auto mop = static_cast<ir::MemOp>(int_pool[r.getConstOffset()]);
    if (ir::IsDirectLoadStore(mop) && ir::IsAnyStore(mop)) has_type = false;
  }
  return r.getEntityOffset() + 2 + (has_type ? 1 : 0);
}

EntityId IRInstruction::id(void) const {
  if (!impl) return {};
  IRInstructionId iid;
  iid.fragment_id = impl->fragment_id;
  iid.offset = impl->offset;
  iid.opcode = opcode();
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
  uint32_t base = OperandBase(*impl);
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
  auto eid = pool[OperandBase(*impl) + n];
  auto vid = EntityId(eid).Unpack();
  if (auto *iid = std::get_if<IRInstructionId>(&vid)) {
    return IRInstruction(std::make_shared<IRInstructionImpl>(
        impl->frag, iid->offset, impl->fragment_id));
  }
  return {};
}

std::optional<IRInstruction> IRInstruction::parent_instruction(void) const {
  if (!impl) return std::nullopt;
  auto pool = GetEntityPool(*impl);
  auto parent_eid = pool[impl->reader().getEntityOffset()];  // position 0
  auto vid = EntityId(parent_eid).Unpack();
  // If position 0 is an instruction ID, that's the parent instruction.
  if (auto *iid = std::get_if<IRInstructionId>(&vid)) {
    return IRInstruction(std::make_shared<IRInstructionImpl>(
        impl->frag, iid->offset, impl->fragment_id));
  }
  // It's a block ID -- this is a root, no parent instruction.
  return std::nullopt;
}

bool IRInstruction::is_root(void) const {
  if (!impl) return false;
  auto pool = GetEntityPool(*impl);
  auto parent_eid = pool[impl->reader().getEntityOffset()];
  auto vid = EntityId(parent_eid).Unpack();
  return std::holds_alternative<IRBlockId>(vid);
}

std::optional<Stmt> IRInstruction::source_statement(void) const {
  if (!impl) return std::nullopt;
  auto pool = GetEntityPool(*impl);
  auto eid = pool[impl->reader().getEntityOffset() + 1];  // position 1
  if (eid == kInvalidEntityId) return std::nullopt;
  // source_entity_id can be a DeclId, StmtId, or other entity kind.
  // Only try StmtFor if it's actually a Stmt entity.
  auto vid = EntityId(eid).Unpack();
  if (!std::holds_alternative<StmtId>(vid)) return std::nullopt;
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
  auto parent_eid = pool[impl->reader().getEntityOffset()];  // position 0
  auto vid = EntityId(parent_eid).Unpack();
  // If position 0 is a block ID, return it directly.
  if (auto *bid = std::get_if<IRBlockId>(&vid)) {
    return IRBlock(std::make_shared<IRBlockImpl>(
        impl->frag, bid->offset, impl->fragment_id));
  }
  // Walk up the parent chain to find the block.
  if (auto *iid = std::get_if<IRInstructionId>(&vid)) {
    auto parent = IRInstruction(std::make_shared<IRInstructionImpl>(
        impl->frag, iid->offset, impl->fragment_id));
    return parent.parent_block();
  }
  return {};
}

gap::generator<IRInstruction> IRInstruction::users(void) const & {
  if (!impl) co_return;
  for (auto eid : impl->reader().getUsers()) {
    auto vid = EntityId(eid).Unpack();
    if (auto *iid = std::get_if<IRInstructionId>(&vid)) {
      co_yield IRInstruction(std::make_shared<IRInstructionImpl>(
          impl->frag, iid->offset, impl->fragment_id));
    }
  }
}

unsigned IRInstruction::num_users(void) const {
  if (!impl) return 0;
  return impl->reader().getUsers().size();
}

bool IRInstruction::is_terminator(void) const {
  return ir::IsTerminator(opcode());
}

bool IRInstruction::is_conditionally_executed(void) const {
  if (!impl) return false;
  return (impl->reader().getFlags() & 0x4) != 0;
}

}  // namespace mx
