// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class CxxBaseSpecifierOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class CxxBaseSpecifierOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BASE;
  }

  static std::optional<CxxBaseSpecifierOp> from(const ::mx::ir::Operation &that);
  static std::optional<CxxBaseSpecifierOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::CxxBaseSpecifierOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::Type type(void) const;
  //::vast::hl::AccessSpecifier access(void) const;
  bool is_virtual(void) const;
};
static_assert(sizeof(CxxBaseSpecifierOp) == sizeof(Operation));

}  // namespace mx::ir::hl
