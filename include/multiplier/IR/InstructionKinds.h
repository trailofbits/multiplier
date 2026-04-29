// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Instruction.h"
#include "OpCode.h"
#include "Block.h"
#include "Object.h"
#include "StructureKinds.h"
#include "../AST/Decl.h"
#include "../AST/Type.h"

namespace mx {

class FunctionDecl;
class FieldDecl;
class VarDecl;
class IRStructure;

// Helper macro for derived instruction classes.
#define MX_DECLARE_IR_INSTRUCTION(ClassName) \
  explicit ClassName(IRInstructionImplPtr impl_) \
      : IRInstruction(std::move(impl_)) {} \
  static std::optional<ClassName> from(const IRInstruction &inst);

// ---------------------------------------------------------------------------
// Constants (unified CONST opcode with ConstOp sub-opcode)
// ---------------------------------------------------------------------------

class MX_EXPORT ConstInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ConstInst)
  ir::ConstOp sub_opcode(void) const;
  int64_t signed_value(void) const;
  uint64_t unsigned_value(void) const;
  double float_value(void) const;
  Type type(void) const;
};

// ---------------------------------------------------------------------------
// Memory
// ---------------------------------------------------------------------------

class MX_EXPORT AllocaInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(AllocaInst)
  ir::AllocaKind alloca_kind(void) const;
  Type allocated_type(void) const;
  IRObject object(void) const;
  uint32_t size_bytes(void) const;   // from the object
  uint32_t align_bytes(void) const;  // from the object
};

// LOCAL alloca: regular local variable.
class MX_EXPORT LocalAllocaInst : public AllocaInst {
 public:
  explicit LocalAllocaInst(IRInstructionImplPtr impl_)
      : AllocaInst(std::move(impl_)) {}
  static std::optional<LocalAllocaInst> from(const IRInstruction &inst);
};

// ARG alloca: argument passing storage in EXPRESSION_SCOPE.
class MX_EXPORT ArgAllocaInst : public AllocaInst {
 public:
  explicit ArgAllocaInst(IRInstructionImplPtr impl_)
      : AllocaInst(std::move(impl_)) {}
  static std::optional<ArgAllocaInst> from(const IRInstruction &inst);
};

// RETURN alloca: return value storage in EXPRESSION_SCOPE.
class MX_EXPORT ReturnAllocaInst : public AllocaInst {
 public:
  explicit ReturnAllocaInst(IRInstructionImplPtr impl_)
      : AllocaInst(std::move(impl_)) {}
  static std::optional<ReturnAllocaInst> from(const IRInstruction &inst);
};

// DYNAMIC alloca: runtime-sized (VLA, alloca()).
class MX_EXPORT DynamicAllocaInst : public AllocaInst {
 public:
  explicit DynamicAllocaInst(IRInstructionImplPtr impl_)
      : AllocaInst(std::move(impl_)) {}
  static std::optional<DynamicAllocaInst> from(const IRInstruction &inst);
  IRInstruction size(void) const;        // op[0] = size in bytes (runtime value)
};

class MX_EXPORT MemoryInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(MemoryInst)
  ir::MemOp sub_opcode(void) const;
  IRInstruction address(void) const;        // op[0] for all
  IRInstruction stored_value(void) const;   // op[1] for stores / BIT_WRITE value
  Type result_type(void) const;             // for loads / BIT_READ
  // BIT_READ/BIT_WRITE: bit-level access parameters (from int pool).
  uint32_t bit_offset(void) const;          // bit offset from address
  uint32_t bit_width(void) const;           // number of bits
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

class MX_EXPORT PtrDiffInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(PtrDiffInst)
  IRInstruction lhs(void) const;
  IRInstruction rhs(void) const;
  Type result_type(void) const;
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
  ir::CastOp sub_opcode(void) const;
  IRInstruction operand(void) const;
  Type result_type(void) const;
};

// ---------------------------------------------------------------------------
// Sizeof
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// Call
// ---------------------------------------------------------------------------

class MX_EXPORT CallInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(CallInst)
  std::optional<Type> result_type(void) const;  // nullopt for void calls
  std::optional<FunctionDecl> target(void) const;
  bool is_indirect(void) const;
  bool has_return_value(void) const;
  std::optional<AllocaInst> return_alloca(void) const;  // ALLOCA/RETURN in caller's EXPRESSION_SCOPE
  gap::generator<IRInstruction> arguments(void) const &;
};

// ---------------------------------------------------------------------------
// Read-modify-write
// ---------------------------------------------------------------------------

// RMW(address, rhs_operands...) — reads from address, applies underlying
// opcode(loaded_value, rhs_operands...), writes back.
// flags bit 0: 1 = returns new value (pre-increment), 0 = old value (post).
class MX_EXPORT ReadModifyWriteInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ReadModifyWriteInst)
  IRInstruction address(void) const;
  ir::OpCode underlying_op(void) const;
  int64_t element_size(void) const;  // for PTR_ADD, 0 otherwise
  bool is_big_endian(void) const;    // int_pool[2]: target endianness
  bool is_atomic(void) const;        // true if underlying op is ATOMIC_*
  bool returns_new_value(void) const;
  Type result_type(void) const;
  // RHS operands (everything after address).
  gap::generator<IRInstruction> rhs_operands(void) const &;
};

// ---------------------------------------------------------------------------
// Misc
// ---------------------------------------------------------------------------

// Evaluates all operands in order, returns the last one's value.
// Used for comma operator (a, b) and other sequence-point patterns.
class MX_EXPORT LastValueInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(LastValueInst)
  IRInstruction last(void) const;  // The last operand (the value returned).
  Type result_type(void) const;
};

class MX_EXPORT SelectInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(SelectInst)
  IRInstruction condition(void) const;
  IRInstruction true_value(void) const;
  IRInstruction false_value(void) const;
  Type result_type(void) const;
};

// CopyInst removed: use CastInst with CastOp::IDENTITY instead.

// ---------------------------------------------------------------------------
// Parameter pointer
// ---------------------------------------------------------------------------

// Returns a pointer to the Nth function parameter. The storage lives
// in the caller's EXPRESSION_SCOPE.
class MX_EXPORT ParamPtrInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ParamPtrInst)
  uint32_t parameter_index(void) const;
  Type parameter_type(void) const;
};

// ---------------------------------------------------------------------------
// Global/function address
// ---------------------------------------------------------------------------

class MX_EXPORT GlobalPtrInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(GlobalPtrInst)
  std::optional<VarDecl> variable(void) const;
};

class MX_EXPORT ThreadLocalPtrInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ThreadLocalPtrInst)
  std::optional<VarDecl> variable(void) const;
};

class MX_EXPORT FuncPtrInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(FuncPtrInst)
  std::optional<FunctionDecl> function(void) const;
};

// ---------------------------------------------------------------------------
// Return value pointer (callee-side)
// ---------------------------------------------------------------------------

// Pointer to the caller's ALLOCA/RETURN storage. No operands.
// Used inside the callee to write the return value before RET.
class MX_EXPORT ReturnPtrInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ReturnPtrInst)
  Type return_type(void) const;
};

// ---------------------------------------------------------------------------
// Bitwise/intrinsic operations
// ---------------------------------------------------------------------------

class MX_EXPORT BitwiseOpInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(BitwiseOpInst)
  ir::BitwiseOp sub_opcode(void) const;
  Type result_type(void) const;
};

// ---------------------------------------------------------------------------
// Floating-point operations (FLOAT)
// ---------------------------------------------------------------------------

class MX_EXPORT FloatOpInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(FloatOpInst)
  ir::FloatOp sub_opcode(void) const;
  Type result_type(void) const;
};

// ---------------------------------------------------------------------------
// Frame/return address intrinsics
// ---------------------------------------------------------------------------

class MX_EXPORT FramePtrInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(FramePtrInst)
  IRInstruction level(void) const;       // op[0]
  Type result_type(void) const;
};

class MX_EXPORT ReturnAddressInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ReturnAddressInst)
  IRInstruction level(void) const;       // op[0]
  Type result_type(void) const;
};

// ---------------------------------------------------------------------------
// Undefined/poison value
// ---------------------------------------------------------------------------

class MX_EXPORT UndefinedInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(UndefinedInst)
  Type result_type(void) const;
};

// ---------------------------------------------------------------------------
// Scope entry/exit
// ---------------------------------------------------------------------------

class MX_EXPORT EnterScopeInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(EnterScopeInst)
  IRStructure scope(void) const;
};

class MX_EXPORT ExitScopeInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ExitScopeInst)
  IRStructure scope(void) const;
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

// ConsumeVAParam: reads the next variadic argument from va_list, memcpys
// it from the caller's EXPRESSION_SCOPE, increments the va_list index.
// This is a MemOp sub-opcode (CONSUME_VA_PARAM) but gets a dedicated class
// for ergonomic access.
class MX_EXPORT ConsumeVAParamInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(ConsumeVAParamInst)
  IRInstruction va_list_operand(void) const;
  Type result_type(void) const;
};

// ---------------------------------------------------------------------------
// Terminators
// ---------------------------------------------------------------------------

class MX_EXPORT RetInst : public IRInstruction {
 public:
  MX_DECLARE_IR_INSTRUCTION(RetInst)
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
  gap::generator<IRSwitchCaseStructure> cases(void) const &;
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
