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
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class DependentAddressSpaceType;
class Expr;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DependentAddressSpaceTypeRange = DerivedEntityRange<TypeIterator, DependentAddressSpaceType>;
using DependentAddressSpaceTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, DependentAddressSpaceType>;
class DependentAddressSpaceType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static DependentAddressSpaceTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DependentAddressSpaceTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : DependentAddressSpaceType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_ADDRESS_SPACE;
  }

  static std::optional<DependentAddressSpaceType> from(const TokenContext &c);
  static std::optional<DependentAddressSpaceType> from(const Type &parent);

  inline static std::optional<DependentAddressSpaceType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DependentAddressSpaceType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Expr address_space_expression(void) const;
  Token attribute_token(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(DependentAddressSpaceType) == sizeof(Type));

#endif
} // namespace mx
