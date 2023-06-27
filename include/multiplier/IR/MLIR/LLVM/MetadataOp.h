// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class MetadataOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class MetadataOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_METADATA;
  }

  static std::optional<MetadataOp> from(const ::mx::ir::Operation &that);
  static std::optional<MetadataOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::MetadataOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  std::string_view sym_name(void) const;
};
static_assert(sizeof(MetadataOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
