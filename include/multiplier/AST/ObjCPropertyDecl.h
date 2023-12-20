// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/ObjCPropertyDeclPropertyControl.h>
#include <multiplier/AST/ObjCPropertyDeclSetterKind.h>
#include <multiplier/AST/ObjCPropertyQueryKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class NamedDecl;
class ObjCIvarDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class Stmt;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCPropertyDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCPropertyDecl> in(const Index &index);
  static gap::generator<ObjCPropertyDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCPropertyDecl> by_id(const Index &, EntityId);
  static gap::generator<ObjCPropertyDecl> in(const Fragment &frag);
  static gap::generator<ObjCPropertyDecl> in(const File &file);

  static std::optional<ObjCPropertyDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<ObjCPropertyDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_PROPERTY;
  }

  static gap::generator<ObjCPropertyDecl> containing(const Decl &decl);
  static gap::generator<ObjCPropertyDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCPropertyDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCPropertyDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ObjCPropertyDecl canonical_declaration(void) const;
  std::optional<ObjCPropertyDecl> definition(void) const;
  gap::generator<ObjCPropertyDecl> redeclarations(void) const &;
  static std::optional<ObjCPropertyDecl> from_base(const Decl &parent);
  inline static std::optional<ObjCPropertyDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCPropertyDecl> from(const std::optional<Decl> &parent);
  static std::optional<ObjCPropertyDecl> from(const Reference &r);
  static std::optional<ObjCPropertyDecl> from(const VariantEntity &e);
  static std::optional<ObjCPropertyDecl> from(const TokenContext &t);

  Token at_token(void) const;
  ObjCMethodDecl getter_method_declaration(void) const;
  Token getter_name_token(void) const;
  Token l_paren_token(void) const;
  ObjCPropertyDeclPropertyControl property_implementation(void) const;
  ObjCIvarDecl property_instance_variable_declaration(void) const;
  ObjCPropertyQueryKind query_kind(void) const;
  ObjCPropertyDeclSetterKind setter_kind(void) const;
  ObjCMethodDecl setter_method_declaration(void) const;
  Token setter_name_token(void) const;
  Type type(void) const;
  bool is_atomic(void) const;
  bool is_class_property(void) const;
  bool is_direct_property(void) const;
  bool is_instance_property(void) const;
  bool is_optional(void) const;
  bool is_read_only(void) const;
  bool is_retaining(void) const;
};

static_assert(sizeof(ObjCPropertyDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
