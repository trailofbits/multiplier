// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class LLVMFuncOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class LLVMFuncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FUNC;
  }

  static std::optional<LLVMFuncOp> from(const ::mx::ir::Operation &that);
  static std::optional<LLVMFuncOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LLVMFuncOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  std::string_view sym_name(void) const;
  //::mlir::LLVM::LLVMFunctionType function_type(void) const;
  //::mlir::LLVM::Linkage linkage(void) const;
  bool dso_local(void) const;
  //::mlir::LLVM::cconv::CConv c_conv(void) const;
  std::optional<std::string_view> personality(void) const;
  std::optional<std::string_view> garbage_collector(void) const;
  //::std::optional<::mlir::ArrayAttr> passthrough(void) const;
  //::std::optional<::mlir::ArrayAttr> arg_attrs(void) const;
  //::std::optional<::mlir::ArrayAttr> res_attrs(void) const;
  //::std::optional<uint64_t> function_entry_count(void) const;
  //::std::optional<::mlir::LLVM::MemoryEffectsAttr> memory(void) const;
  //Block* add_entry_block(void) const;
  bool is_var_arg(void) const;
  //ArrayRef<Type> argument_types(void) const;
  //ArrayRef<Type> result_types(void) const;
  //Region* callable_region(void) const;
  //ArrayRef<Type> callable_results(void) const;
};
static_assert(sizeof(LLVMFuncOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
