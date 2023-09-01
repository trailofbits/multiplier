// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/Builtin/Operation.h>

namespace mx::ir::builtin {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  switch (that.kind()) {
    default: return std::nullopt;
    case mx::ir::OperationKind::BUILTIN_MODULE:
    case mx::ir::OperationKind::BUILTIN_UNREALIZED_CONVERSION_CAST:
      return reinterpret_cast<const Operation &>(that);
  }
}

}  // namespace mx::ir::builtin
