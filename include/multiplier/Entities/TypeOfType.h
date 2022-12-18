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
class Type;
class TypeOfType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TypeOfTypeRange = DerivedEntityRange<TypeIterator, TypeOfType>;
using TypeOfTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypeOfType>;
class TypeOfType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static TypeOfTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypeOfTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : TypeOfType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::TYPE_OF;
  }

  static std::optional<TypeOfType> from(const TokenContext &c);
  static std::optional<TypeOfType> from(const Type &parent);

  inline static std::optional<TypeOfType> from(const std::optional<Type> &parent) {
    if (parent) {
      return TypeOfType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Type underlying_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(TypeOfType) == sizeof(Type));

#endif
} // namespace mx
