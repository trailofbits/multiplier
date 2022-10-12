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

#include "AdjustedType.h"
#include "TypeKind.h"

namespace mx {
class AdjustedType;
class DecayedType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DecayedTypeRange = DerivedEntityRange<TypeIterator, DecayedType>;
using DecayedTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, DecayedType>;
class DecayedType : public AdjustedType {
 private:
  friend class FragmentImpl;
  friend class AdjustedType;
  friend class Type;
 public:
  inline static DecayedTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DecayedTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : DecayedType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DECAYED;
  }

  static std::optional<DecayedType> from(const TokenContext &c);
  static std::optional<DecayedType> from(const AdjustedType &parent);

  inline static std::optional<DecayedType> from(const std::optional<AdjustedType> &parent) {
    if (parent) {
      return DecayedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DecayedType> from(const Type &parent);

  inline static std::optional<DecayedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DecayedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(DecayedType) == sizeof(AdjustedType));

#endif
} // namespace mx
