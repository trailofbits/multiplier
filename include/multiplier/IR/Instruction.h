// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../Compiler.h"
#include "../Types.h"
#include "OpCode.h"
#include <memory>
#include <optional>
#include <gap/coro/generator.hpp>

namespace mx {

class IRBlock;
class IRObject;
class IRInstructionImpl;
class Stmt;
class FunctionDecl;
class FieldDecl;
class Type;
using IRInstructionImplPtr = std::shared_ptr<const IRInstructionImpl>;

class MX_EXPORT IRInstruction {
 private:
  friend class EntityProvider;
  friend class Index;
  friend class IRBlock;
  friend class IRFunction;
  IRInstructionImplPtr impl;

 public:
  IRInstruction(void) = default;
  explicit IRInstruction(IRInstructionImplPtr impl_)
      : impl(std::move(impl_)) {}

  // Identity.
  EntityId id(void) const;
  ir::OpCode opcode(void) const;

  // Expression tree (top-down: follow operands into children).
  gap::generator<IRInstruction> operands(void) const &;
  unsigned num_operands(void) const;
  IRInstruction nth_operand(unsigned n) const;

  // Expression tree (bottom-up: follow parent).
  std::optional<IRInstruction> parent_instruction(void) const;
  bool is_root(void) const;

  // AST provenance.
  std::optional<Stmt> source_statement(void) const;
  RawEntityId source_entity_id(void) const;

  // Block.
  IRBlock parent_block(void) const;

  // Terminator queries.
  bool is_terminator(void) const;

  // Conditional execution.
  bool is_conditionally_executed(void) const;

  // Raw field access (for derived classes / advanced usage).
  RawEntityId target_entity_id(void) const;
  RawEntityId type_entity_id(void) const;
  RawEntityId object_entity_id(void) const;
  int64_t int_value(void) const;
  uint64_t uint_value(void) const;
  double float_value(void) const;
  uint8_t width(void) const;
  uint32_t size_bytes(void) const;
  uint8_t flags(void) const;
  ir::OpCode compound_op(void) const;

  inline operator bool(void) const { return !!impl; }
};

}  // namespace mx
