// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::unsup {
class UnsupportedDecl;
}  // namespace vast::unsup
namespace mx::ir::unsup {
class UnsupportedDecl final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::UNSUP_DECL;
  }

  static std::optional<UnsupportedDecl> from(const ::mx::ir::Operation &that);
  static std::optional<UnsupportedDecl> producing(const ::mx::ir::Value &val);

  ::vast::unsup::UnsupportedDecl underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(UnsupportedDecl) == sizeof(Operation));

}  // namespace mx::ir::unsup
