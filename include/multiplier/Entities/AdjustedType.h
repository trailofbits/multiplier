// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Type.h"

namespace mx {
class EntityProvider;
class Index;
class AdjustedType;
class DecayedType;
class Token;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AdjustedType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<AdjustedType> in(const Fragment &frag);
  static gap::generator<AdjustedType> in(const File &file);
  static gap::generator<AdjustedType> in(const Index &index);
  static gap::generator<AdjustedType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AdjustedType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::ADJUSTED;
  }

  static std::optional<AdjustedType> from(const Type &parent);

  inline static std::optional<AdjustedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return AdjustedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AdjustedType> from(const Reference &r);
  static std::optional<AdjustedType> from(const TokenContext &t);

  Type desugar(void) const;
  Type resolved_type(void) const;
  Type original_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(AdjustedType) == sizeof(Type));

#endif
} // namespace mx
