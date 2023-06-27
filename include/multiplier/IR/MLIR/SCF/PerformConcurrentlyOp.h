// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::scf {
class PerformConcurrentlyOp;
}  // namespace mlir::scf
namespace mx::ir::scf {
class PerformConcurrentlyOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::SCF_FOREACH_THREAD_PERFORM_CONCURRENTLY;
  }

  static std::optional<PerformConcurrentlyOp> from(const ::mx::ir::Operation &that);
  static std::optional<PerformConcurrentlyOp> producing(const ::mx::ir::Value &val);

  mlir::scf::PerformConcurrentlyOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region region(void) const;
  //::llvm::SmallVector<::mlir::BlockArgument> dests(void) const;
  //::llvm::iterator_range<::mlir::Block::iterator> yielding_ops(void) const;
};
static_assert(sizeof(PerformConcurrentlyOp) == sizeof(Operation));

}  // namespace mx::ir::scf
