// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "TypeWithKeyword.h"

namespace mx {
class EntityProvider;
class Index;
class ElaboratedType;
class TagDecl;
class Token;
class Type;
class TypeWithKeyword;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ElaboratedType : public TypeWithKeyword {
 private:
  friend class FragmentImpl;
  friend class TypeWithKeyword;
  friend class Type;
 public:
  static gap::generator<ElaboratedType> in(const Fragment &frag);
  static gap::generator<ElaboratedType> in(const File &file);
  static gap::generator<ElaboratedType> in(const Index &index);
  static gap::generator<ElaboratedType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ElaboratedType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::ELABORATED;
  }

  static std::optional<ElaboratedType> from(const Type &parent);

  inline static std::optional<ElaboratedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ElaboratedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ElaboratedType> from(const Reference &r);
  static std::optional<ElaboratedType> from(const TokenContext &t);

  Type desugar(void) const;
  Type named_type(void) const;
  std::optional<TagDecl> owned_tag_declaration(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(ElaboratedType) == sizeof(TypeWithKeyword));

#endif
} // namespace mx
