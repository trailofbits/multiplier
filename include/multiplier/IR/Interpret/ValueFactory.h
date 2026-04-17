// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Value.h"
#include <multiplier/IR/OpCode.h>
#include <optional>
#include <vector>

namespace mx::ir::interpret {

// Abstract factory for value operations. The interpreter never performs
// arithmetic directly — it delegates to the factory. This enables:
//   - ConcreteValueFactory: direct computation
//   - SymbolicValueFactory: builds expression trees
//   - TaintValueFactory: wraps inner factory with provenance tracking
//
// Factories compose: Taint(Symbolic(Concrete)).
class ValueFactory {
 public:
  virtual ~ValueFactory(void) = default;

  // Arithmetic.
  virtual Value BinaryOp(OpCode op, const Value &lhs, const Value &rhs) = 0;
  virtual Value UnaryOp(OpCode op, const Value &operand) = 0;
  virtual Value Compare(OpCode op, const Value &lhs, const Value &rhs) = 0;

  // Cast.
  virtual Value Cast(CastOp op, const Value &operand) = 0;

  // Constants.
  virtual Value MakeConst(ConstOp op, int64_t signed_val,
                          uint64_t unsigned_val) = 0;
  virtual Value MakeNullPtr(void) = 0;

  // Pointer arithmetic.
  virtual Value PtrAdd(const Value &base, const Value &index,
                       int64_t element_size) = 0;
  virtual Value PtrDiff(const Value &lhs, const Value &rhs,
                        int64_t element_size) = 0;

  // Truth test: returns true/false for concrete, nullopt for symbolic.
  virtual std::optional<bool> IsTrue(const Value &val) = 0;

  // Select (ternary).
  virtual Value Select(const Value &cond, const Value &if_true,
                       const Value &if_false) = 0;

  // Bitwise intrinsics (BSWAP, POPCOUNT, CLZ, CTZ, FFS, PARITY, ROTL, ROTR).
  // The width opcode (BITWISE_8/16/32/64) determines operand width.
  virtual Value BitwiseIntrinsic(OpCode width_op, BitwiseOp sub,
                                 const Value &val,
                                 const Value &val2) = 0;

  // Float intrinsics (math functions, special values, classification).
  virtual Value FloatIntrinsic(FloatOp sub,
                               const std::vector<Value> &operands) = 0;
};

}  // namespace mx::ir::interpret
