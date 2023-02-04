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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "TypeKind.h"
#include "TypeWithKeyword.h"

namespace mx {
class ElaboratedType;
class TagDecl;
class Type;
class TypeWithKeyword;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ElaboratedType : public TypeWithKeyword {
 private:
  friend class FragmentImpl;
  friend class TypeWithKeyword;
  friend class Type;
 public:
  static gap::generator<ElaboratedType> in(const Fragment &frag);
  static gap::generator<ElaboratedType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::ELABORATED;
  }

  inline static std::optional<ElaboratedType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<ElaboratedType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<ElaboratedType> from(const TypeWithKeyword &parent);

  inline static std::optional<ElaboratedType> from(const std::optional<TypeWithKeyword> &parent) {
    if (parent) {
      return ElaboratedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ElaboratedType> from(const Type &parent);

  inline static std::optional<ElaboratedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ElaboratedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Type named_type(void) const;
  std::optional<TagDecl> owned_tag_declaration(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(ElaboratedType) == sizeof(TypeWithKeyword));

#endif
} // namespace mx
