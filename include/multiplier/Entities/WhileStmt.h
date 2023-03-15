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
class DeclStmt;
class Expr;
class Stmt;
class Token;
class VarDecl;
class WhileStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class WhileStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<WhileStmt> in(const Fragment &frag);
  static gap::generator<WhileStmt> in(const File &file);
  static gap::generator<WhileStmt> in(const Index &index);
  static gap::generator<WhileStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<WhileStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::WHILE_STMT;
  }

  static gap::generator<WhileStmt> containing(const Decl &decl);
  static gap::generator<WhileStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<WhileStmt> containing(const Stmt &stmt);
  static gap::generator<WhileStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<WhileStmt> from(const Stmt &parent);

  inline static std::optional<WhileStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return WhileStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<WhileStmt> from(const Reference &r);
  static std::optional<WhileStmt> from(const TokenContext &t);

  Stmt body(void) const;
  Expr condition(void) const;
  std::optional<VarDecl> condition_variable(void) const;
  std::optional<DeclStmt> condition_variable_declaration_statement(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  Token while_token(void) const;
  bool has_variable_storage(void) const;
};

static_assert(sizeof(WhileStmt) == sizeof(Stmt));

#endif
} // namespace mx
