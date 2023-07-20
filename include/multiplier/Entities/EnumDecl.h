// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "TagDecl.h"
#include "TemplateSpecializationKind.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class EnumConstantDecl;
class EnumDecl;
class NamedDecl;
class Stmt;
class TagDecl;
class Token;
class TokenRange;
class Type;
class TypeDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class EnumDecl : public TagDecl {
 private:
  friend class FragmentImpl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<EnumDecl> in(const Index &index);
  static gap::generator<EnumDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<EnumDecl> by_id(const Index &, EntityId);
  static gap::generator<EnumDecl> in(const Fragment &frag);
  static gap::generator<EnumDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::ENUM;
  }

  static gap::generator<EnumDecl> containing(const Decl &decl);
  static gap::generator<EnumDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<EnumDecl> containing(const Stmt &stmt);
  static gap::generator<EnumDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  EnumDecl canonical_declaration(void) const;
  std::optional<EnumDecl> definition(void) const;
  gap::generator<EnumDecl> redeclarations(void) const &;
  static std::optional<EnumDecl> from(const Decl &parent);

  inline static std::optional<EnumDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return EnumDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnumDecl> from(const Reference &r);
  static std::optional<EnumDecl> from(const TokenContext &t);

  std::optional<EnumConstantDecl> nth_enumerator(unsigned n) const;
  unsigned num_enumerators(void) const;
  gap::generator<EnumConstantDecl> enumerators(void) const &;
  std::optional<EnumDecl> instantiated_from_member_enum(void) const;
  std::optional<Type> integer_type(void) const;
  TokenRange integer_type_range(void) const;
  std::optional<unsigned> odr_hash(void) const;
  std::optional<Type> promotion_type(void) const;
  std::optional<EnumDecl> template_instantiation_pattern(void) const;
  TemplateSpecializationKind template_specialization_kind(void) const;
  bool is_closed(void) const;
  bool is_closed_flag(void) const;
  bool is_closed_non_flag(void) const;
  bool is_complete(void) const;
  bool is_fixed(void) const;
  bool is_scoped(void) const;
  bool is_scoped_using_class_tag(void) const;
};

static_assert(sizeof(EnumDecl) == sizeof(TagDecl));

#endif
} // namespace mx
