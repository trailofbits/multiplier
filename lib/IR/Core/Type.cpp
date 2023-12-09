// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/Core/Type.h>

#include <multiplier/IR/Attribute.h>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/ABI/ABIOps.hpp>

namespace mx::ir::core {
std::optional<Type> Type::from(const ::mx::ir::Type &that) {
  if (IsCoreTypeKind(that.kind())) {
    return reinterpret_cast<const Type &>(that);
  }
  return std::nullopt;
}

std::optional<FunctionType> FunctionType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::CORE_FUNCTION) {
    return reinterpret_cast<const FunctionType &>(that);
  }
  return std::nullopt;
}

::vast::core::FunctionType FunctionType::underlying_repr(void) const noexcept {
  return ::vast::core::FunctionType(this->::mx::ir::Type::type_);
}

bool FunctionType::is_var_arg(void) const {
  auto val = underlying_repr().isVarArg();
  return val;
}

bool FunctionType::var_arg(void) const {
  auto val = underlying_repr().getVarArg();
  return val;
}

}  // namespace mx::ir::core
