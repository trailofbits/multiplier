// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::ll {
class StructGEPOp;
}  // namespace vast::ll
namespace mx::ir::ll {
class StructGEPOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LL_GEP;
  }

  static std::optional<StructGEPOp> from(const ::mx::ir::Operation &that);
  static std::optional<StructGEPOp> producing(const ::mx::ir::Value &val);

  vast::ll::StructGEPOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value record(void) const;
  ::mx::ir::Value element(void) const;
  uint32_t idx(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(StructGEPOp) == sizeof(Operation));

}  // namespace mx::ir::ll
