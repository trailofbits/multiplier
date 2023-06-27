// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir {
class UnrealizedConversionCastOp;
}  // namespace mlir
namespace mx::ir::builtin {
class UnrealizedConversionCastOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::BUILTIN_UNREALIZED_CONVERSION_CAST;
  }

  static std::optional<UnrealizedConversionCastOp> from(const ::mx::ir::Operation &that);
  static std::optional<UnrealizedConversionCastOp> producing(const ::mx::ir::Value &val);

  mlir::UnrealizedConversionCastOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::Operation::operand_range inputs(void) const;
  //::mlir::Operation::result_range outputs(void) const;
};
static_assert(sizeof(UnrealizedConversionCastOp) == sizeof(Operation));

}  // namespace mx::ir::builtin
