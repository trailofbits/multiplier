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
class Token;
class Type;
class UsingShadowDecl;
class UsingType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UsingType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<UsingType> in(const Fragment &frag);
  static gap::generator<UsingType> in(const File &file);
  static gap::generator<UsingType> in(const Index &index);
  static gap::generator<UsingType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UsingType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::USING;
  }

  static std::optional<UsingType> from(const Type &parent);

  inline static std::optional<UsingType> from(const std::optional<Type> &parent) {
    if (parent) {
      return UsingType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingType> from(const Reference &r);
  static std::optional<UsingType> from(const TokenContext &t);

  Type desugar(void) const;
  UsingShadowDecl found_declaration(void) const;
  Type underlying_type(void) const;
  bool is_sugared(void) const;
  bool type_matches_declaration(void) const;
};

static_assert(sizeof(UsingType) == sizeof(Type));

#endif
} // namespace mx
