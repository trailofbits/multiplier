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
class ObjCAtFinallyStmt;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCAtFinallyStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ObjCAtFinallyStmt> in(const Index &index);
  static gap::generator<ObjCAtFinallyStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCAtFinallyStmt> by_id(const Index &, EntityId);
  static gap::generator<ObjCAtFinallyStmt> in(const Fragment &frag);
  static gap::generator<ObjCAtFinallyStmt> in(const File &file);

  static std::optional<ObjCAtFinallyStmt> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<ObjCAtFinallyStmt, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_FINALLY_STMT;
  }

  static gap::generator<ObjCAtFinallyStmt> containing(const Decl &decl);
  static gap::generator<ObjCAtFinallyStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCAtFinallyStmt> containing(const Stmt &stmt);
  static gap::generator<ObjCAtFinallyStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAtFinallyStmt> from_base(const Stmt &parent);
  inline static std::optional<ObjCAtFinallyStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCAtFinallyStmt> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCAtFinallyStmt> from(const Reference &r);
  static std::optional<ObjCAtFinallyStmt> from(const VariantEntity &e);
  static std::optional<ObjCAtFinallyStmt> from(const TokenContext &t);

  Token at_finally_token(void) const;
  Stmt finally_body(void) const;
};

static_assert(sizeof(ObjCAtFinallyStmt) == sizeof(Stmt));

#endif
} // namespace mx
