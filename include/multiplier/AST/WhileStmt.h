// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class DeclStmt;
class Expr;
class File;
class Stmt;
class Token;
class VarDecl;
class WhileStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT WhileStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<WhileStmt> in(const Index &index);
  static gap::generator<WhileStmt> in(const Fragment &frag);
  static gap::generator<WhileStmt> in(const File &file);
  static gap::generator<WhileStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<WhileStmt> from(const ir::Operation &op);
  static gap::generator<std::pair<WhileStmt, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::WHILE_STMT;
  }

  static gap::generator<WhileStmt> containing(const Decl &decl);
  static gap::generator<WhileStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<WhileStmt> containing(const Stmt &stmt);
  static gap::generator<WhileStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<WhileStmt> by_id(const Index &, EntityId);

  static std::optional<WhileStmt> from_base(const Stmt &parent);
  inline static std::optional<WhileStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<WhileStmt> from(const std::optional<Stmt> &parent);
  static std::optional<WhileStmt> from(const Reference &r);
  static std::optional<WhileStmt> from(const VariantEntity &e);
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
