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
class PointerType;
class Token;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PointerType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<PointerType> in(const Fragment &frag);
  static gap::generator<PointerType> in(const File &file);
  static gap::generator<PointerType> in(const Index &index);
  static gap::generator<PointerType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PointerType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::POINTER;
  }

  static std::optional<PointerType> from(const Type &parent);

  inline static std::optional<PointerType> from(const std::optional<Type> &parent) {
    if (parent) {
      return PointerType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PointerType> from(const Reference &r);
  static std::optional<PointerType> from(const TokenContext &t);

  Type desugar(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(PointerType) == sizeof(Type));

#endif
} // namespace mx
