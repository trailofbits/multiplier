// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class GlobalOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class GlobalOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_GLOBAL;
  }

  static std::optional<GlobalOp> from(const ::mx::ir::Operation &that);
  static std::optional<GlobalOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::GlobalOp underlying_op(void) const noexcept;

  // Imported methods:
  std::string_view sym_name(void) const;
  std::optional<std::string_view> sym_visibility(void) const;
  //::mlir::MemRefType type(void) const;
  //::std::optional<::mlir::Attribute> initial_value(void) const;
  bool constant(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  bool is_external(void) const;
  bool is_uninitialized(void) const;
  //ElementsAttr constant_init_value(void) const;
};
static_assert(sizeof(GlobalOp) == sizeof(Operation));

}  // namespace mx::ir::memref
