// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/Core/Operation.h>

namespace mx::ir::core {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  switch (that.kind()) {
    default: return std::nullopt;
    case mx::ir::OperationKind::CORE_BIN_LAND:
    case mx::ir::OperationKind::CORE_BIN_LOR:
    case mx::ir::OperationKind::CORE_LAZY_OP:
    case mx::ir::OperationKind::CORE_SELECT:
    case mx::ir::OperationKind::CORE_SCOPE:
      return reinterpret_cast<const Operation &>(that);
  }
}

}  // namespace mx::ir::core
