// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::scf {
class ForeachThreadOp;
}  // namespace mlir::scf
namespace mx::ir::scf {
class ForeachThreadOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::SCF_FOREACH_THREAD;
  }

  static std::optional<ForeachThreadOp> from(const ::mx::ir::Operation &that);
  static std::optional<ForeachThreadOp> producing(const ::mx::ir::Value &val);

  ::mlir::scf::ForeachThreadOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> num_threads(void) const;
  gap::generator<::mx::ir::Operand> outputs(void) const;
  gap::generator<::mx::ir::Result> results(void) const;
  ::mx::ir::Region region(void) const;
  //::std::optional<::mlir::ArrayAttr> mapping(void) const;
  int64_t rank(void) const;
  //ArrayRef<BlockArgument> output_block_arguments(void) const;
  //::mlir::ValueRange thread_indices(void) const;
  //::mlir::mlir::Block::BlockArgListType region_out_args(void) const;
  //PerformConcurrentlyOp terminator(void) const;
};
static_assert(sizeof(ForeachThreadOp) == sizeof(Operation));

}  // namespace mx::ir::scf
