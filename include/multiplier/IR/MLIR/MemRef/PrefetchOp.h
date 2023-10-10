// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class PrefetchOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class PrefetchOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_PREFETCH;
  }

  static std::optional<PrefetchOp> from(const ::mx::ir::Operation &that);
  static std::optional<PrefetchOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::PrefetchOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::MemRefType> memref(void) const;
  gap::generator<::mx::ir::Operand> indices(void) const;
  bool is_write(void) const;
  uint32_t locality_hint(void) const;
  bool is_data_cache(void) const;
  //MemRefType mem_ref_type(void) const;
  //StringRef locality_hint_attr_str_name(void) const;
  //StringRef is_write_attr_str_name(void) const;
  //StringRef is_data_cache_attr_str_name(void) const;
};
static_assert(sizeof(PrefetchOp) == sizeof(Operation));

}  // namespace mx::ir::memref
