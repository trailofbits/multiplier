// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class InlineAsmOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class InlineAsmOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INLINE_ASM;
  }

  static std::optional<InlineAsmOp> from(const ::mx::ir::Operation &that);
  static std::optional<InlineAsmOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::InlineAsmOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::mlir::Operation::operand_range operands(void) const;
  ::mx::ir::Value res(void) const;
  std::string_view asm_string(void) const;
  std::string_view constraints(void) const;
  bool has_side_effects(void) const;
  bool is_align_stack(void) const;
  //::std::optional<::mlir::LLVM::AsmDialect> asm_dialect(void) const;
  //::std::optional<::mlir::ArrayAttr> operand_attrs(void) const;
};
static_assert(sizeof(InlineAsmOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
