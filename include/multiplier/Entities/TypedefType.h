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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class Type;
class TypedefNameDecl;
class TypedefType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypedefType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<TypedefType> in(const Fragment &frag);
  static gap::generator<TypedefType> in(const Index &index);
  static gap::generator<TypedefType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypedefType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::TYPEDEF;
  }

  inline static std::optional<TypedefType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<TypedefType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<TypedefType> from(const Type &parent);

  inline static std::optional<TypedefType> from(const std::optional<Type> &parent) {
    if (parent) {
      return TypedefType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  TypedefNameDecl declaration(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(TypedefType) == sizeof(Type));

#endif
} // namespace mx
