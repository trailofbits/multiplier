// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Stmt.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class Expr;
class ObjCAtThrowStmt;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCAtThrowStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ObjCAtThrowStmt> in(const Index &index);
  static gap::generator<ObjCAtThrowStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCAtThrowStmt> by_id(const Index &, EntityId);
  static gap::generator<ObjCAtThrowStmt> in(const Fragment &frag);
  static gap::generator<ObjCAtThrowStmt> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_THROW_STMT;
  }

  static gap::generator<ObjCAtThrowStmt> containing(const Decl &decl);
  static gap::generator<ObjCAtThrowStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCAtThrowStmt> containing(const Stmt &stmt);
  static gap::generator<ObjCAtThrowStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAtThrowStmt> from(const Stmt &parent);

  inline static std::optional<ObjCAtThrowStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCAtThrowStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCAtThrowStmt> from(const Reference &r);
  static std::optional<ObjCAtThrowStmt> from(const TokenContext &t);

  Expr throw_expression(void) const;
  Token throw_token(void) const;
};

static_assert(sizeof(ObjCAtThrowStmt) == sizeof(Stmt));

#endif
} // namespace mx
