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

#include "ReferenceType.h"
#include "TypeKind.h"

namespace mx {
class LValueReferenceType;
class ReferenceType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using LValueReferenceTypeRange = DerivedEntityRange<TypeIterator, LValueReferenceType>;
using LValueReferenceTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, LValueReferenceType>;
class LValueReferenceType : public ReferenceType {
 private:
  friend class FragmentImpl;
  friend class ReferenceType;
  friend class Type;
 public:
  inline static LValueReferenceTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static LValueReferenceTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : LValueReferenceType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::L_VALUE_REFERENCE;
  }

  static std::optional<LValueReferenceType> from(const TokenContext &c);
  static std::optional<LValueReferenceType> from(const ReferenceType &parent);

  inline static std::optional<LValueReferenceType> from(const std::optional<ReferenceType> &parent) {
    if (parent) {
      return LValueReferenceType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<LValueReferenceType> from(const Type &parent);

  inline static std::optional<LValueReferenceType> from(const std::optional<Type> &parent) {
    if (parent) {
      return LValueReferenceType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(LValueReferenceType) == sizeof(ReferenceType));

#endif
} // namespace mx
