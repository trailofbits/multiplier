// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Type.h"

namespace vast::core {
class FunctionType;
}  // namespace vast::core
namespace mx::ir::core {

class MX_EXPORT Type : public ::mx::ir::Type {
 public:
  static std::optional<Type> from(const ::mx::ir::Type &);
};
static_assert(sizeof(Type) == sizeof(::mx::ir::Type));

class MX_EXPORT FunctionType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::CORE_FUNCTION;
  }

  static std::optional<FunctionType> from(const ::mx::ir::Type &that);
  ::vast::core::FunctionType underlying_repr(void) const noexcept;

  // Imported methods:
  bool is_var_arg(void) const;
  //unsignedint num_inputs(void) const;
  //unsignedint num_results(void) const;
  //::llvm::ArrayRef<Type> inputs(void) const;
  //::llvm::ArrayRef<Type> results(void) const;
  bool var_arg(void) const;
};
static_assert(sizeof(FunctionType) == sizeof(Type));

}  // namespace mx::ir::core
