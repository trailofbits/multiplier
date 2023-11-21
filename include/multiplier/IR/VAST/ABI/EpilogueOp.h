// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::abi {
class EpilogueOp;
}  // namespace vast::abi
namespace mx::ir::abi {
class EpilogueOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_EPILOGUE;
  }

  static std::optional<EpilogueOp> from(const ::mx::ir::Operation &that);
  static std::optional<EpilogueOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::EpilogueOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Result> results(void) const;
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(EpilogueOp) == sizeof(Operation));

}  // namespace mx::ir::abi
