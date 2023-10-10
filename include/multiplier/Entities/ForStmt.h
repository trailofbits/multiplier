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
class ForStmt;
class Stmt;
class Token;
class VarDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ForStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ForStmt> in(const Index &index);
  static gap::generator<ForStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ForStmt> by_id(const Index &, EntityId);
  static gap::generator<ForStmt> in(const Fragment &frag);
  static gap::generator<ForStmt> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::FOR_STMT;
  }

  static gap::generator<ForStmt> containing(const Decl &decl);
  static gap::generator<ForStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ForStmt> containing(const Stmt &stmt);
  static gap::generator<ForStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ForStmt> from(const Stmt &parent);

  inline static std::optional<ForStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ForStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ForStmt> from(const Reference &r);
  static std::optional<ForStmt> from(const TokenContext &t);

  Stmt body(void) const;
  std::optional<Expr> condition(void) const;
  std::optional<VarDecl> condition_variable(void) const;
  std::optional<DeclStmt> condition_variable_declaration_statement(void) const;
  Token for_token(void) const;
  std::optional<Expr> increment(void) const;
  std::optional<Stmt> initializer(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(ForStmt) == sizeof(Stmt));

#endif
} // namespace mx
