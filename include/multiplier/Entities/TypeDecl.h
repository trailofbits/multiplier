// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "NamedDecl.h"

namespace mx {
class EntityProvider;
class Index;
class CXXRecordDecl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class Decl;
class EnumDecl;
class NamedDecl;
class ObjCTypeParamDecl;
class RecordDecl;
class Stmt;
class TemplateTypeParmDecl;
class Token;
class Type;
class TypeAliasDecl;
class TypeDecl;
class TypedefDecl;
class UnresolvedUsingTypenameDecl;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TypeDecl> in(const Fragment &frag);
  static gap::generator<TypeDecl> in(const File &file);
  static gap::generator<TypeDecl> in(const Index &index);
  static gap::generator<TypeDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeDecl> by_id(const Index &, EntityId);

  static gap::generator<TypeDecl> containing(const Decl &decl);
  static gap::generator<TypeDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TypeDecl> containing(const Stmt &stmt);
  static gap::generator<TypeDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  TypeDecl canonical_declaration(void) const;
  std::optional<TypeDecl> definition(void) const;
  gap::generator<TypeDecl> redeclarations(void) const &;
  static std::optional<TypeDecl> from(const Decl &parent);

  inline static std::optional<TypeDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TypeDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeDecl> from(const Reference &r);
  static std::optional<TypeDecl> from(const TokenContext &t);

  std::optional<Type> type_for_declaration(void) const;
};

static_assert(sizeof(TypeDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
