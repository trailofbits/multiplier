// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::unsup {
class UnsupportedStmt;
}  // namespace vast::unsup
namespace mx::ir::unsup {
class UnsupportedStmt final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::UNSUP_STMT;
  }

  static std::optional<UnsupportedStmt> from(const ::mx::ir::Operation &that);
  static std::optional<UnsupportedStmt> producing(const ::mx::ir::Value &val);

  ::vast::unsup::UnsupportedStmt underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  //::mlir::MutableArrayRef<::mlir::Region> children(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(UnsupportedStmt) == sizeof(Operation));

}  // namespace mx::ir::unsup
