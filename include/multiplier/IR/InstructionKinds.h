// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Instruction.h"
#include "OpCode.h"
#include "Block.h"
#include "Object.h"
#include "../AST/Decl.h"
#include "../AST/Type.h"

namespace mx {

class FunctionDecl;
class FieldDecl;
class VarDecl;

// Helper macro for derived instruction classes.
#define MX_DECLARE_IR_INSTRUCTION(ClassName) \
  explicit ClassName(IRInstructionImplPtr impl_) \
      : IRInstruction(std::move(impl_)) {} \
  static std::optional<ClassName> from(const IRInstruction &inst);

// ---------------------------------------------------------------------------
// Constants
// ---------------------------------------------------------------------------

class MX_EXPORT ConstIntInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ConstIntInst)
  int64_t signed_value(void) const;
  uint64_t unsigned_value(void) const;
  uint8_t width(void) const;
  std::optional<Type> type(void) const;
};

class MX_EXPORT ConstFloatInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ConstFloatInst)
  double value(void) const;
  uint8_t width(void) const;
  std::optional<Type> type(void) const;
};

class MX_EXPORT ConstNullInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ConstNullInst)
  std::optional<Type> type(void) const;
};

// ---------------------------------------------------------------------------
// Memory
// ---------------------------------------------------------------------------

class MX_EXPORT AllocaInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(AllocaInst)
  std::optional<Type> allocated_type(void) const;
  IRObject object(void) const;
};

class MX_EXPORT LoadInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(LoadInst)
  IRInstruction address(void) const;
  std::optional<Type> loaded_type(void) const;
};

class MX_EXPORT StoreInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(StoreInst)
  IRInstruction address(void) const;
  IRInstruction stored_value(void) const;
};

class MX_EXPORT AddressOfInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(AddressOfInst)
  std::optional<Type> type(void) const;
  IRObject object(void) const;
};

// ---------------------------------------------------------------------------
// Field / Pointer access
// ---------------------------------------------------------------------------

class MX_EXPORT GEPFieldInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(GEPFieldInst)
  IRInstruction base(void) const;
  std::optional<Type> result_type(void) const;
  std::optional<FieldDecl> field(void) const;
  int64_t byte_offset(void) const;
};

class MX_EXPORT PtrAddInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(PtrAddInst)
  IRInstruction base(void) const;
  IRInstruction index(void) const;
  std::optional<Type> result_type(void) const;
  std::optional<Type> element_type(void) const;
  int64_t element_size(void) const;
};

// ---------------------------------------------------------------------------
// Binary / Comparison / Unary
// ---------------------------------------------------------------------------

class MX_EXPORT BinaryInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(BinaryInst)
  IRInstruction lhs(void) const;
  IRInstruction rhs(void) const;
  std::optional<Type> result_type(void) const;
};

class MX_EXPORT ComparisonInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ComparisonInst)
  IRInstruction lhs(void) const;
  IRInstruction rhs(void) const;
  std::optional<Type> result_type(void) const;
};

class MX_EXPORT UnaryInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(UnaryInst)
  IRInstruction operand(void) const;
  std::optional<Type> result_type(void) const;
};

// ---------------------------------------------------------------------------
// Cast
// ---------------------------------------------------------------------------

class MX_EXPORT CastInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(CastInst)
  IRInstruction operand(void) const;
  std::optional<Type> result_type(void) const;
};

// ---------------------------------------------------------------------------
// Sizeof
// ---------------------------------------------------------------------------

class MX_EXPORT SizeOfInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(SizeOfInst)
  std::optional<Type> measured_type(void) const;
  std::optional<Type> result_type(void) const;
  int64_t static_size(void) const;
};

// ---------------------------------------------------------------------------
// Call
// ---------------------------------------------------------------------------

class MX_EXPORT CallInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(CallInst)
  std::optional<Type> result_type(void) const;
  std::optional<FunctionDecl> target(void) const;
  bool is_indirect(void) const;
  gap::generator<IRInstruction> arguments(void) const &;
};

// ---------------------------------------------------------------------------
// Compound operations
// ---------------------------------------------------------------------------

class MX_EXPORT IncDecInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(IncDecInst)
  IRInstruction address(void) const;
  std::optional<Type> result_type(void) const;
  bool is_increment(void) const;
  bool is_prefix(void) const;
  int64_t pointer_element_size(void) const;
};

class MX_EXPORT CompoundAssignInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(CompoundAssignInst)
  IRInstruction address(void) const;
  IRInstruction value(void) const;
  std::optional<Type> result_type(void) const;
  ir::OpCode underlying_op(void) const;
};

// ---------------------------------------------------------------------------
// Misc
// ---------------------------------------------------------------------------

class MX_EXPORT SelectInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(SelectInst)
  IRInstruction condition(void) const;
  IRInstruction true_value(void) const;
  IRInstruction false_value(void) const;
  std::optional<Type> result_type(void) const;
};

class MX_EXPORT CopyInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(CopyInst)
  IRInstruction source(void) const;
  std::optional<Type> result_type(void) const;
};

class MX_EXPORT InitListInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(InitListInst)
  gap::generator<IRInstruction> elements(void) const &;
  std::optional<Type> result_type(void) const;
};

// ---------------------------------------------------------------------------
// Terminators
// ---------------------------------------------------------------------------

class MX_EXPORT RetInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(RetInst)
  std::optional<IRInstruction> return_value(void) const;
};

class MX_EXPORT BranchInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(BranchInst)
  IRBlock target_block(void) const;
};

class MX_EXPORT CondBranchInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(CondBranchInst)
  IRInstruction condition(void) const;
  IRBlock true_block(void) const;
  IRBlock false_block(void) const;
};

class MX_EXPORT SwitchInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(SwitchInst)
  IRInstruction selector(void) const;
  gap::generator<std::pair<int64_t, IRBlock>> cases(void) const &;
  std::optional<IRBlock> default_block(void) const;
};

class MX_EXPORT UnreachableInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(UnreachableInst)
};

class MX_EXPORT UnknownInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(UnknownInst)
};

#undef MX_DECLARE_IR_INSTRUCTION

}  // namespace mx
