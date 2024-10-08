// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Type.h"

namespace vast::unsup {
class UnsupportedType;
}  // namespace vast::unsup
namespace mx::ir::unsup {

class MX_EXPORT Type : public ::mx::ir::Type {
 public:
  static std::optional<Type> from(const ::mx::ir::Type &);
};
static_assert(sizeof(Type) == sizeof(::mx::ir::Type));

class MX_EXPORT UnsupportedType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::UNSUP_UNSUPPORTED;
  }

  static std::optional<UnsupportedType> from(const ::mx::ir::Type &that);
  ::vast::unsup::UnsupportedType underlying_repr(void) const noexcept;

  // Imported methods:
  std::string_view origin_name(void) const;
};
static_assert(sizeof(UnsupportedType) == sizeof(Type));

}  // namespace mx::ir::unsup
