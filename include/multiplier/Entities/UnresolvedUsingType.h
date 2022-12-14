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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class Type;
class UnresolvedUsingType;
class UnresolvedUsingTypenameDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UnresolvedUsingTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnresolvedUsingType>;
class UnresolvedUsingType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static gap::generator<UnresolvedUsingType> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static UnresolvedUsingTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : UnresolvedUsingType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::UNRESOLVED_USING;
  }

  static std::optional<UnresolvedUsingType> from(const TokenContext &c);
  static std::optional<UnresolvedUsingType> from(const Type &parent);

  inline static std::optional<UnresolvedUsingType> from(const std::optional<Type> &parent) {
    if (parent) {
      return UnresolvedUsingType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  UnresolvedUsingTypenameDecl declaration(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(UnresolvedUsingType) == sizeof(Type));

#endif
} // namespace mx
