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

// Generate the uses of this value.
gap::generator<Operand> Value::uses(void) const & noexcept {
  for (mlir::OpOperand &use : mlir::Value(impl_.value).getUses()) {
    co_yield Operand(module_, &use);
  }
}

}  // namespace mx::ir
