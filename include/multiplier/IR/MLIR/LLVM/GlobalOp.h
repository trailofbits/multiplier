// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class GlobalOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class GlobalOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MLIR_GLOBAL;
  }

  static std::optional<GlobalOp> from(const ::mx::ir::Operation &that);
  static std::optional<GlobalOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::GlobalOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region initializer(void) const;
  //::mlir::Type global_type(void) const;
  bool constant(void) const;
  std::string_view sym_name(void) const;
  //::mlir::LLVM::Linkage linkage(void) const;
  bool dso_local(void) const;
  bool thread_local__(void) const;
  //::std::optional<::mlir::Attribute> value(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  uint32_t addr_space(void) const;
  //::std::optional<::mlir::LLVM::UnnamedAddr> unnamed_addr(void) const;
  std::optional<std::string_view> section(void) const;
  //::std::optional<::mlir::SymbolRefAttr> comdat(void) const;
  //::mlir::LLVM::Visibility visibility__(void) const;
  //Type type(void) const;
  //Attribute value_or_null(void) const;
  //Region& initializer_region(void) const;
  //Block* initializer_block(void) const;
};
static_assert(sizeof(GlobalOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
