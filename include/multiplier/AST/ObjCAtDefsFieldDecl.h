// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/FieldDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class DeclaratorDecl;
class FieldDecl;
class NamedDecl;
class ObjCAtDefsFieldDecl;
class Stmt;
class Token;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCAtDefsFieldDecl : public FieldDecl {
 private:
  friend class FragmentImpl;
  friend class FieldDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCAtDefsFieldDecl> in(const Index &index);
  static gap::generator<ObjCAtDefsFieldDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCAtDefsFieldDecl> by_id(const Index &, EntityId);
  static gap::generator<ObjCAtDefsFieldDecl> in(const Fragment &frag);
  static gap::generator<ObjCAtDefsFieldDecl> in(const File &file);

  static std::optional<ObjCAtDefsFieldDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<ObjCAtDefsFieldDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_AT_DEFS_FIELD;
  }

  static gap::generator<ObjCAtDefsFieldDecl> containing(const Decl &decl);
  static gap::generator<ObjCAtDefsFieldDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCAtDefsFieldDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCAtDefsFieldDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ObjCAtDefsFieldDecl canonical_declaration(void) const;
  std::optional<ObjCAtDefsFieldDecl> definition(void) const;
  gap::generator<ObjCAtDefsFieldDecl> redeclarations(void) const &;
  static std::optional<ObjCAtDefsFieldDecl> from_base(const Decl &parent);
  inline static std::optional<ObjCAtDefsFieldDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCAtDefsFieldDecl> from(const std::optional<Decl> &parent);
  static std::optional<ObjCAtDefsFieldDecl> from(const Reference &r);
  static std::optional<ObjCAtDefsFieldDecl> from(const VariantEntity &e);
  static std::optional<ObjCAtDefsFieldDecl> from(const TokenContext &t);

};

static_assert(sizeof(ObjCAtDefsFieldDecl) == sizeof(FieldDecl));

#endif
} // namespace mx
