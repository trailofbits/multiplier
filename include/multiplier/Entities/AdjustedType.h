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
class AdjustedType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AdjustedTypeRange = DerivedEntityRange<TypeIterator, AdjustedType>;
using AdjustedTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, AdjustedType>;
class AdjustedType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static AdjustedTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AdjustedTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : AdjustedType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::ADJUSTED;
  }

  static std::optional<AdjustedType> from(const TokenContext &c);
  static std::optional<AdjustedType> from(const Type &parent);

  inline static std::optional<AdjustedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return AdjustedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Type resolved_type(void) const;
  Type original_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(AdjustedType) == sizeof(Type));

#endif
} // namespace mx
