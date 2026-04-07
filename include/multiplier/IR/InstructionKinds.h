// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Instruction.h"
#include "OpCode.h"
#include "Block.h"
#include "Object.h"
#include "SwitchCase.h"
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
  Type type(void) const;
};

class MX_EXPORT ConstFloatInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ConstFloatInst)
  double value(void) const;
  uint8_t width(void) const;
  Type type(void) const;
};

class MX_EXPORT ConstNullInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ConstNullInst)
  Type type(void) const;
};

// ---------------------------------------------------------------------------
// Memory
// ---------------------------------------------------------------------------

class MX_EXPORT AllocaInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(AllocaInst)
  Type allocated_type(void) const;
  IRObject object(void) const;
};

class MX_EXPORT LoadInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(LoadInst)
  IRInstruction address(void) const;
  Type loaded_type(void) const;
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
  Type type(void) const;
  IRObject object(void) const;
};

// ---------------------------------------------------------------------------
// Field / Pointer access
// ---------------------------------------------------------------------------

class MX_EXPORT GEPFieldInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(GEPFieldInst)
  IRInstruction base(void) const;
  Type result_type(void) const;
  FieldDecl field(void) const;
  int64_t byte_offset(void) const;
};

class MX_EXPORT PtrAddInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(PtrAddInst)
  IRInstruction base(void) const;
  IRInstruction index(void) const;
  Type result_type(void) const;
  Type element_type(void) const;
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
  Type result_type(void) const;
};

class MX_EXPORT ComparisonInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ComparisonInst)
  IRInstruction lhs(void) const;
  IRInstruction rhs(void) const;
  Type result_type(void) const;
};

class MX_EXPORT UnaryInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(UnaryInst)
  IRInstruction operand(void) const;
  Type result_type(void) const;
};

// ---------------------------------------------------------------------------
// Cast
// ---------------------------------------------------------------------------

class MX_EXPORT CastInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(CastInst)
  IRInstruction operand(void) const;
  Type result_type(void) const;
};

// ---------------------------------------------------------------------------
// Sizeof
// ---------------------------------------------------------------------------

class MX_EXPORT SizeOfInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(SizeOfInst)
  Type measured_type(void) const;
  Type result_type(void) const;
  int64_t static_size(void) const;
};

// ---------------------------------------------------------------------------
// Call
// ---------------------------------------------------------------------------

class MX_EXPORT CallInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(CallInst)
  std::optional<Type> result_type(void) const;  // nullopt for void calls
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
  Type result_type(void) const;
  bool is_increment(void) const;
  bool is_prefix(void) const;
  int64_t pointer_element_size(void) const;
};

class MX_EXPORT CompoundAssignInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(CompoundAssignInst)
  IRInstruction address(void) const;
  IRInstruction value(void) const;
  Type result_type(void) const;
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
  Type result_type(void) const;
};

class MX_EXPORT CopyInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(CopyInst)
  IRInstruction source(void) const;
  Type result_type(void) const;
};

class MX_EXPORT InitListInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(InitListInst)
  gap::generator<IRInstruction> elements(void) const &;
  Type result_type(void) const;
};

// ---------------------------------------------------------------------------
// Parameter read
// ---------------------------------------------------------------------------

class MX_EXPORT ParamReadInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ParamReadInst)
  uint32_t parameter_index(void) const;
  Type parameter_type(void) const;
  IRObject object(void) const;
};

// ---------------------------------------------------------------------------
// Memory operations
// ---------------------------------------------------------------------------

class MX_EXPORT MemsetInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(MemsetInst)
  IRInstruction dest(void) const;       // op[0]
  IRInstruction byte_value(void) const; // op[1]
  IRInstruction size(void) const;       // op[2]
};

class MX_EXPORT MemcpyInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(MemcpyInst)
  IRInstruction dest(void) const;       // op[0]
  IRInstruction src(void) const;        // op[1]
  IRInstruction size(void) const;       // op[2]
};

// ---------------------------------------------------------------------------
// Variadic
// ---------------------------------------------------------------------------

class MX_EXPORT VAStartInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(VAStartInst)
  IRInstruction va_list_operand(void) const;
};

class MX_EXPORT VAEndInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(VAEndInst)
  IRInstruction va_list_operand(void) const;
};

class MX_EXPORT VACopyInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(VACopyInst)
  IRInstruction dest(void) const;
  IRInstruction src(void) const;
};

class MX_EXPORT VAArgInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(VAArgInst)
  IRInstruction va_list_operand(void) const;
  Type result_type(void) const;
};

class MX_EXPORT VAPackInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(VAPackInst)
  gap::generator<IRInstruction> arguments(void) const &;
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
  std::optional<Type> case_type(void) const;
  gap::generator<IRSwitchCase> cases(void) const &;
  unsigned num_cases(void) const;
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
