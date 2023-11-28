// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/Unsupported/Type.h>

#include <multiplier/IR/Attribute.h>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Unsupported/UnsupportedTypes.hpp>

namespace mx::ir::unsup {
std::optional<Type> Type::from(const ::mx::ir::Type &that) {
  switch (that.kind()) {
    default: return std::nullopt;
    case mx::ir::TypeKind::UNSUP_UNSUPPORTED:
      return reinterpret_cast<const Type &>(that);
  }
}

std::optional<UnsupportedType> UnsupportedType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::UNSUP_UNSUPPORTED) {
    return reinterpret_cast<const UnsupportedType &>(that);
  }
  return std::nullopt;
}

::vast::unsup::UnsupportedType UnsupportedType::underlying_repr(void) const noexcept {
  return ::vast::unsup::UnsupportedType(this->::mx::ir::Type::type_);
}

std::string_view UnsupportedType::origin_name(void) const {
  auto val = underlying_repr().getOriginName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::unsup
