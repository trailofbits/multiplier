// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Stmt.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class ObjCAtCatchStmt;
class Stmt;
class Token;
class VarDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCAtCatchStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ObjCAtCatchStmt> in(const Index &index);
  static gap::generator<ObjCAtCatchStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCAtCatchStmt> by_id(const Index &, EntityId);
  static gap::generator<ObjCAtCatchStmt> in(const Fragment &frag);
  static gap::generator<ObjCAtCatchStmt> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_CATCH_STMT;
  }

  static gap::generator<ObjCAtCatchStmt> containing(const Decl &decl);
  static gap::generator<ObjCAtCatchStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCAtCatchStmt> containing(const Stmt &stmt);
  static gap::generator<ObjCAtCatchStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAtCatchStmt> from_base(const Stmt &parent);
  inline static std::optional<ObjCAtCatchStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCAtCatchStmt> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCAtCatchStmt> from(const Reference &r);
  static std::optional<ObjCAtCatchStmt> from(const VariantEntity &e);
  static std::optional<ObjCAtCatchStmt> from(const TokenContext &t);

  Token at_catch_token(void) const;
  Stmt catch_body(void) const;
  VarDecl catch_parameter_declaration(void) const;
  Token r_paren_token(void) const;
  bool has_ellipsis(void) const;
};

static_assert(sizeof(ObjCAtCatchStmt) == sizeof(Stmt));

#endif
} // namespace mx
