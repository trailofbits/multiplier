// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "TypeDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class NamedDecl;
class ObjCTypeParamDecl;
class Stmt;
class TagDecl;
class Token;
class Type;
class TypeAliasDecl;
class TypeDecl;
class TypedefDecl;
class TypedefNameDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypedefNameDecl : public TypeDecl {
 private:
  friend class FragmentImpl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TypedefNameDecl> in(const Index &index);
  static gap::generator<TypedefNameDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypedefNameDecl> by_id(const Index &, EntityId);
  static gap::generator<TypedefNameDecl> in(const Fragment &frag);
  static gap::generator<TypedefNameDecl> in(const File &file);

  static gap::generator<TypedefNameDecl> containing(const Decl &decl);
  static gap::generator<TypedefNameDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TypedefNameDecl> containing(const Stmt &stmt);
  static gap::generator<TypedefNameDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  TypedefNameDecl canonical_declaration(void) const;
  std::optional<TypedefNameDecl> definition(void) const;
  gap::generator<TypedefNameDecl> redeclarations(void) const &;
  static std::optional<TypedefNameDecl> from_base(const Decl &parent);
  inline static std::optional<TypedefNameDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<TypedefNameDecl> from(const std::optional<Decl> &parent);
  static std::optional<TypedefNameDecl> from(const Reference &r);
  static std::optional<TypedefNameDecl> from(const VariantEntity &e);
  static std::optional<TypedefNameDecl> from(const TokenContext &t);

  std::optional<TagDecl> anonymous_declaration_with_typedef_name(void) const;
  Type underlying_type(void) const;
  bool is_moded(void) const;
  bool is_transparent_tag(void) const;
};

static_assert(sizeof(TypedefNameDecl) == sizeof(TypeDecl));

#endif
} // namespace mx
