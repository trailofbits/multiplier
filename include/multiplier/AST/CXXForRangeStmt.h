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
class CXXForRangeStmt;
class Decl;
class DeclStmt;
class Expr;
class File;
class Stmt;
class Token;
class VarDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXForRangeStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<CXXForRangeStmt> in(const Index &index);
  static gap::generator<CXXForRangeStmt> in(const Fragment &frag);
  static gap::generator<CXXForRangeStmt> in(const File &file);
  static gap::generator<CXXForRangeStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CXXForRangeStmt> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXForRangeStmt, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_FOR_RANGE_STMT;
  }

  static gap::generator<CXXForRangeStmt> containing(const Decl &decl);
  static gap::generator<CXXForRangeStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXForRangeStmt> containing(const Stmt &stmt);
  static gap::generator<CXXForRangeStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXForRangeStmt> by_id(const Index &, EntityId);

  static std::optional<CXXForRangeStmt> from_base(const Stmt &parent);
  inline static std::optional<CXXForRangeStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXForRangeStmt> from(const std::optional<Stmt> &parent);
  static std::optional<CXXForRangeStmt> from(const Reference &r);
  static std::optional<CXXForRangeStmt> from(const VariantEntity &e);
  static std::optional<CXXForRangeStmt> from(const TokenContext &t);

  std::optional<DeclStmt> begin_statement(void) const;
  Stmt body(void) const;
  Token coawait_token(void) const;
  Token colon_token(void) const;
  std::optional<Expr> condition(void) const;
  std::optional<DeclStmt> end_statement(void) const;
  Token for_token(void) const;
  std::optional<Expr> increment(void) const;
  std::optional<Stmt> initializer(void) const;
  DeclStmt loop_variable_statement(void) const;
  VarDecl loop_variable(void) const;
  Token r_paren_token(void) const;
  Expr range_initializer(void) const;
  DeclStmt range_statement(void) const;
};

static_assert(sizeof(CXXForRangeStmt) == sizeof(Stmt));

#endif
} // namespace mx
