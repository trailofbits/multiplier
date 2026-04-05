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
 protected:
  friend class EntityProvider;
  friend class Index;
  friend class IRBlock;
  friend class IRFunction;
  IRInstructionImplPtr impl;

 public:
  // For derived instruction classes.
  const IRInstructionImplPtr &impl_ptr(void) const { return impl; }

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

  // Use-def: who uses this instruction's value as an operand.
  gap::generator<IRInstruction> users(void) const &;
  unsigned num_users(void) const;

  // AST provenance.
  std::optional<Stmt> source_statement(void) const;
  RawEntityId source_entity_id(void) const;

  // Block.
  IRBlock parent_block(void) const;

  // Terminator queries.
  bool is_terminator(void) const;

  // Conditional execution.
  bool is_conditionally_executed(void) const;

};

}  // namespace mx
