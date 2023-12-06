// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/FieldDecl.h>
#include <multiplier/AST/ObjCIvarDeclAccessControl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class DeclaratorDecl;
class FieldDecl;
class NamedDecl;
class ObjCInterfaceDecl;
class ObjCIvarDecl;
class Stmt;
class Token;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCIvarDecl : public FieldDecl {
 private:
  friend class FragmentImpl;
  friend class FieldDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCIvarDecl> in(const Index &index);
  static gap::generator<ObjCIvarDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCIvarDecl> by_id(const Index &, EntityId);
  static gap::generator<ObjCIvarDecl> in(const Fragment &frag);
  static gap::generator<ObjCIvarDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_IVAR;
  }

  static gap::generator<ObjCIvarDecl> containing(const Decl &decl);
  static gap::generator<ObjCIvarDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCIvarDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCIvarDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ObjCIvarDecl canonical_declaration(void) const;
  std::optional<ObjCIvarDecl> definition(void) const;
  gap::generator<ObjCIvarDecl> redeclarations(void) const &;
  static std::optional<ObjCIvarDecl> from_base(const Decl &parent);
  inline static std::optional<ObjCIvarDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCIvarDecl> from(const std::optional<Decl> &parent);
  static std::optional<ObjCIvarDecl> from(const Reference &r);
  static std::optional<ObjCIvarDecl> from(const VariantEntity &e);
  static std::optional<ObjCIvarDecl> from(const TokenContext &t);

  ObjCIvarDeclAccessControl access_control(void) const;
  ObjCIvarDeclAccessControl canonical_access_control(void) const;
  ObjCInterfaceDecl containing_interface(void) const;
  ObjCIvarDecl next_instance_variable(void) const;
  bool synthesize(void) const;
};

static_assert(sizeof(ObjCIvarDecl) == sizeof(FieldDecl));

#endif
} // namespace mx
