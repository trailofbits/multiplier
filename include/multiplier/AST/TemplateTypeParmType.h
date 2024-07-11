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
class TemplateTypeParmDecl;
class TemplateTypeParmType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT TemplateTypeParmType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<TemplateTypeParmType> in(const Index &index);
  static gap::generator<TemplateTypeParmType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::TEMPLATE_TYPE_PARM;
  }

  static std::optional<TemplateTypeParmType> by_id(const Index &, EntityId);

  static std::optional<TemplateTypeParmType> from_base(const Type &parent);
  inline static std::optional<TemplateTypeParmType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<TemplateTypeParmType> from(const std::optional<Type> &parent);
  static std::optional<TemplateTypeParmType> from(const Reference &r);
  static std::optional<TemplateTypeParmType> from(const VariantEntity &e);
  static std::optional<TemplateTypeParmType> from(const TokenContext &t);

  std::optional<TemplateTypeParmDecl> declaration(void) const;
  uint32_t depth(void) const;
  uint32_t index(void) const;
  bool is_parameter_pack(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(TemplateTypeParmType) == sizeof(Type));

#endif
} // namespace mx
