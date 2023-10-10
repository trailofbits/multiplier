// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class AliasScopeDomainMetadataOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class AliasScopeDomainMetadataOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_ALIAS_SCOPE_DOMAIN;
  }

  static std::optional<AliasScopeDomainMetadataOp> from(const ::mx::ir::Operation &that);
  static std::optional<AliasScopeDomainMetadataOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AliasScopeDomainMetadataOp underlying_op(void) const noexcept;

  // Imported methods:
  std::string_view sym_name(void) const;
  std::optional<std::string_view> description(void) const;
};
static_assert(sizeof(AliasScopeDomainMetadataOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
