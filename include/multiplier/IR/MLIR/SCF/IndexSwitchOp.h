// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::scf {
class IndexSwitchOp;
}  // namespace mlir::scf
namespace mx::ir::scf {
class IndexSwitchOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::SCF_INDEX_SWITCH;
  }

  static std::optional<IndexSwitchOp> from(const ::mx::ir::Operation &that);
  static std::optional<IndexSwitchOp> producing(const ::mx::ir::Value &val);

  mlir::scf::IndexSwitchOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IndexType> arg(void) const;
  //::mlir::Operation::result_range results(void) const;
  ::mx::ir::Region default_region(void) const;
  //::mlir::MutableArrayRef<::mlir::Region> case_regions(void) const;
  //::llvm::ArrayRef<int64_t> cases(void) const;
  //unsignedint num_cases(void) const;
  //Block& default_block(void) const;
};
static_assert(sizeof(IndexSwitchOp) == sizeof(Operation));

}  // namespace mx::ir::scf
