// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../../Compiler.h"
#include "ValueFactory.h"

namespace mx::ir::interpret {

// Concrete implementation of ValueFactory: performs direct computation
// on ScalarValue/Pointer values. No symbolic reasoning.
class MX_EXPORT ConcreteValueFactory final : public ValueFactory {
 public:
  ~ConcreteValueFactory(void) override = default;

  Value BinaryOp(OpCode op, const Value &lhs, const Value &rhs) override;
  Value UnaryOp(OpCode op, const Value &operand) override;
  Value Compare(OpCode op, const Value &lhs, const Value &rhs) override;
  Value Cast(CastOp op, const Value &operand) override;
  Value MakeConst(ConstOp op, int64_t signed_val,
                  uint64_t unsigned_val) override;
  Value MakeNullPtr(void) override;
  Value PtrAdd(const Value &base, const Value &index,
               int64_t element_size) override;
  Value PtrDiff(const Value &lhs, const Value &rhs,
                int64_t element_size) override;
  std::optional<bool> IsTrue(const Value &val) override;
  Value Select(const Value &cond, const Value &if_true,
               const Value &if_false) override;
  Value BitwiseIntrinsic(OpCode width_op, BitwiseOp sub,
                         const Value &val, const Value &val2) override;
  Value FloatIntrinsic(FloatOp sub,
                       const std::vector<Value> &operands) override;
};

}  // namespace mx::ir::interpret
