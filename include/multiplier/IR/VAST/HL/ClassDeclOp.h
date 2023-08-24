// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class ClassDeclOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class ClassDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_CLASS;
  }

  static std::optional<ClassDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<ClassDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::ClassDeclOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region bases(void) const;
  ::mx::ir::Region fields(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(ClassDeclOp) == sizeof(Operation));

}  // namespace mx::ir::hl
