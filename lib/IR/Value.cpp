// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Value.h>

#include <mlir/IR/Block.h>
#include <mlir/IR/Operation.h>
#include <mlir/IR/OperationSupport.h>
#include <mlir/IR/Value.h>
#include <multiplier/IR/Operation.h>
#include <multiplier/IR/Type.h>

namespace mx::ir {

MX_EXPORT const char *EnumeratorName(ValueKind kind) {
  switch (kind) {
    case ValueKind::OPERATION_RESULT: return "OPERATION_RESULT";
    case ValueKind::BLOCK_ARGUMENT: return "BLOCK_ARGUMENT";
    default: return "<invalid>";
  }
}

ValueKind Value::kind(void) const noexcept {
  switch (impl_.value->getKind()) {
    case mlir::detail::ValueImpl::Kind::InlineOpResult:
    case mlir::detail::ValueImpl::Kind::OutOfLineOpResult:
      return ValueKind::OPERATION_RESULT;
    case mlir::detail::ValueImpl::Kind::BlockArgument:
      return ValueKind::BLOCK_ARGUMENT;
  }
}

Type Value::type(void) const noexcept {
  mlir::Value val = mlir::Value::getFromOpaquePointer(impl_.opaque);
  return Type(
      val.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          val.getType().getAsOpaquePointer()));
}

// Generate the uses of this value.
gap::generator<Operand> Value::uses(void) const & noexcept {
  for (mlir::OpOperand &use : mlir::Value(impl_.value).getUses()) {
    co_yield Operand(module_, &use);
  }
}

}  // namespace mx::ir
