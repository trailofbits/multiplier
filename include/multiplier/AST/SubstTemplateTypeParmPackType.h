// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Type.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class SubstTemplateTypeParmPackType;
class TemplateTypeParmDecl;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT SubstTemplateTypeParmPackType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<SubstTemplateTypeParmPackType> in(const Index &index);
  static gap::generator<SubstTemplateTypeParmPackType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SubstTemplateTypeParmPackType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::SUBST_TEMPLATE_TYPE_PARM_PACK;
  }

  static std::optional<SubstTemplateTypeParmPackType> from_base(const Type &parent);
  inline static std::optional<SubstTemplateTypeParmPackType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<SubstTemplateTypeParmPackType> from(const std::optional<Type> &parent);
  static std::optional<SubstTemplateTypeParmPackType> from(const Reference &r);
  static std::optional<SubstTemplateTypeParmPackType> from(const VariantEntity &e);
  static std::optional<SubstTemplateTypeParmPackType> from(const TokenContext &t);

  Decl associated_declaration(void) const;
  bool final(void) const;
  TemplateTypeParmDecl replaced_parameter(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(SubstTemplateTypeParmPackType) == sizeof(Type));

#endif
} // namespace mx
