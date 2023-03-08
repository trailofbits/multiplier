// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ReferenceType.h"

namespace mx {
class EntityProvider;
class Index;
class RValueReferenceType;
class ReferenceType;
class Token;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class RValueReferenceType : public ReferenceType {
 private:
  friend class FragmentImpl;
  friend class ReferenceType;
  friend class Type;
 public:
  static gap::generator<RValueReferenceType> in(const Fragment &frag);
  static gap::generator<RValueReferenceType> in(const File &file);
  static gap::generator<RValueReferenceType> in(const Index &index);
  static gap::generator<RValueReferenceType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<RValueReferenceType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::R_VALUE_REFERENCE;
  }

  static std::optional<RValueReferenceType> from(const Type &parent);

  inline static std::optional<RValueReferenceType> from(const std::optional<Type> &parent) {
    if (parent) {
      return RValueReferenceType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RValueReferenceType> from(const Reference &r);
  static std::optional<RValueReferenceType> from(const TokenContext &t);

  Type desugar(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(RValueReferenceType) == sizeof(ReferenceType));

#endif
} // namespace mx
