// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::abi {
class WrapFuncOp;
}  // namespace vast::abi
namespace mx::ir::abi {
class WrapFuncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_WRAP_FN;
  }

  static std::optional<WrapFuncOp> from(const ::mx::ir::Operation &that);
  static std::optional<WrapFuncOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::WrapFuncOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  std::string_view sym_name(void) const;
  //::vast::core::FunctionType function_type(void) const;
  //::vast::core::GlobalLinkageKind linkage(void) const;
  std::optional<std::string_view> sym_visibility(void) const;
  //::std::optional<::mlir::ArrayAttr> arg_attrs(void) const;
  //::std::optional<::mlir::ArrayAttr> res_attrs(void) const;
  bool is_var_arg(void) const;
  //::mlir::Region* callable_region(void) const;
  //llvm::ArrayRef<Type> callable_results(void) const;
  //::mlir::ArrayAttr callable_arg_attrs(void) const;
  //::mlir::ArrayAttr callable_res_attrs(void) const;
  //llvm::ArrayRef<Type> argument_types(void) const;
  //llvm::ArrayRef<Type> result_types(void) const;
  bool is_declaration(void) const;
};
static_assert(sizeof(WrapFuncOp) == sizeof(Operation));

}  // namespace mx::ir::abi
