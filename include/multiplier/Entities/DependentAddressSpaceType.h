// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Type.h"

namespace mx {
class DependentAddressSpaceType;
class Expr;
class Token;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DependentAddressSpaceType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<DependentAddressSpaceType> in(const Fragment &frag);
  static gap::generator<DependentAddressSpaceType> in(const File &file);
  static gap::generator<DependentAddressSpaceType> in(const Index &index);
  static gap::generator<DependentAddressSpaceType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DependentAddressSpaceType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_ADDRESS_SPACE;
  }

  static std::optional<DependentAddressSpaceType> from(const Type &parent);

  inline static std::optional<DependentAddressSpaceType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DependentAddressSpaceType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<DependentAddressSpaceType> from(const Reference &r) {
    return DependentAddressSpaceType::from(r.as_type());
  }

  inline static std::optional<DependentAddressSpaceType> from(const TokenContext &t) {
    return DependentAddressSpaceType::from(t.as_type());
  }

  Type desugar(void) const;
  Expr address_space_expression(void) const;
  Token attribute_token(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(DependentAddressSpaceType) == sizeof(Type));

#endif
} // namespace mx
