// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class TBAARootMetadataOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class TBAARootMetadataOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_TBAA_ROOT;
  }

  static std::optional<TBAARootMetadataOp> from(const ::mx::ir::Operation &that);
  static std::optional<TBAARootMetadataOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::TBAARootMetadataOp underlying_op(void) const noexcept;

  // Imported methods:
  std::string_view sym_name(void) const;
  std::string_view identity(void) const;
};
static_assert(sizeof(TBAARootMetadataOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
