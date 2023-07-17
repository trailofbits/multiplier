// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir {
class ModuleOp;
}  // namespace mlir
namespace mx::ir::builtin {
class ModuleOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::BUILTIN_MODULE;
  }

  static std::optional<ModuleOp> from(const ::mx::ir::Operation &that);
  static std::optional<ModuleOp> producing(const ::mx::ir::Value &val);

  ::mlir::ModuleOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body_region(void) const;
  std::optional<std::string_view> sym_name(void) const;
  std::optional<std::string_view> sym_visibility(void) const;
  std::optional<std::string_view> name(void) const;
  bool is_optional_symbol(void) const;
  //DataLayoutSpecInterface data_layout_spec(void) const;
  std::string_view default_dialect(void) const;
};
static_assert(sizeof(ModuleOp) == sizeof(Operation));

}  // namespace mx::ir::builtin
