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
class CompoundStmt;
class CoroutineBodyStmt;
class Decl;
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
class MX_EXPORT CoroutineBodyStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<CoroutineBodyStmt> in(const Index &index);
  static gap::generator<CoroutineBodyStmt> in(const Fragment &frag);
  static gap::generator<CoroutineBodyStmt> in(const File &file);
  static gap::generator<CoroutineBodyStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CoroutineBodyStmt> from(const ir::Operation &op);
  static gap::generator<std::pair<CoroutineBodyStmt, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COROUTINE_BODY_STMT;
  }

  static gap::generator<CoroutineBodyStmt> containing(const Decl &decl);
  static gap::generator<CoroutineBodyStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<CoroutineBodyStmt> containing(const Stmt &stmt);
  static gap::generator<CoroutineBodyStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CoroutineBodyStmt> by_id(const Index &, EntityId);

  static std::optional<CoroutineBodyStmt> from_base(const Stmt &parent);
  inline static std::optional<CoroutineBodyStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CoroutineBodyStmt> from(const std::optional<Stmt> &parent);
  static std::optional<CoroutineBodyStmt> from(const Reference &r);
  static std::optional<CoroutineBodyStmt> from(const VariantEntity &e);
  static std::optional<CoroutineBodyStmt> from(const TokenContext &t);

  gap::generator<Stmt> children_excl_body(void) const &;
  Expr allocate(void) const;
  CompoundStmt body(void) const;
  Expr deallocate(void) const;
  Stmt exception_handler(void) const;
  Stmt fallthrough_handler(void) const;
  Stmt final_suspend_statement(void) const;
  Stmt initializer_suspend_statement(void) const;
  std::optional<Stmt> nth_parameter_move(unsigned n) const;
  unsigned num_parameter_moves(void) const;
  gap::generator<Stmt> parameter_moves(void) const &;
  VarDecl promise_declaration(void) const;
  Stmt promise_declaration_statement(void) const;
  std::optional<Stmt> result_declaration(void) const;
  Stmt return_statement(void) const;
  std::optional<Stmt> return_statement_on_alloc_failure(void) const;
  Expr return_value(void) const;
  Expr return_value_initializer(void) const;
  bool has_dependent_promise_type(void) const;
};

static_assert(sizeof(CoroutineBodyStmt) == sizeof(Stmt));

#endif
} // namespace mx
