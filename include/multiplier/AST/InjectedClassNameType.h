// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class CXXRecordDecl;
class InjectedClassNameType;
class TemplateSpecializationType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT InjectedClassNameType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<InjectedClassNameType> in(const Index &index);
  static gap::generator<InjectedClassNameType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::INJECTED_CLASS_NAME;
  }

  static std::optional<InjectedClassNameType> by_id(const Index &, EntityId);

  static std::optional<InjectedClassNameType> from_base(const Type &parent);
  inline static std::optional<InjectedClassNameType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<InjectedClassNameType> from(const std::optional<Type> &parent);
  static std::optional<InjectedClassNameType> from(const Reference &r);
  static std::optional<InjectedClassNameType> from(const VariantEntity &e);
  static std::optional<InjectedClassNameType> from(const TokenContext &t);

  CXXRecordDecl declaration(void) const;
  Type injected_specialization_type(void) const;
  TemplateSpecializationType injected_tst(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(InjectedClassNameType) == sizeof(Type));

#endif
} // namespace mx
