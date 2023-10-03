// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::ll {
class FuncOp;
}  // namespace vast::ll
namespace mx::ir::ll {
class FuncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LL_FUNC;
  }

  static std::optional<FuncOp> from(const ::mx::ir::Operation &that);
  static std::optional<FuncOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::FuncOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  std::string_view sym_name(void) const;
  //::mlir::FunctionType function_type(void) const;
  //::vast::core::GlobalLinkageKind linkage(void) const;
  std::optional<std::string_view> sym_visibility(void) const;
  //::std::optional<::mlir::ArrayAttr> arg_attrs(void) const;
  //::std::optional<::mlir::ArrayAttr> res_attrs(void) const;
  //::mlir::Region* callable_region(void) const;
  //llvm::ArrayRef<Type> callable_results(void) const;
  //llvm::ArrayRef<Type> argument_types(void) const;
  //llvm::ArrayRef<Type> result_types(void) const;
  bool is_declaration(void) const;
};
static_assert(sizeof(FuncOp) == sizeof(Operation));

}  // namespace mx::ir::ll
