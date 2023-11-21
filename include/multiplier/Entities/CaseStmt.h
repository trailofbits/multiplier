// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "SwitchCase.h"

namespace mx {
class EntityProvider;
class Index;
class CaseStmt;
class Decl;
class Expr;
class Stmt;
class SwitchCase;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CaseStmt : public SwitchCase {
 private:
  friend class FragmentImpl;
  friend class SwitchCase;
  friend class Stmt;
 public:
  static gap::generator<CaseStmt> in(const Index &index);
  static gap::generator<CaseStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CaseStmt> by_id(const Index &, EntityId);
  static gap::generator<CaseStmt> in(const Fragment &frag);
  static gap::generator<CaseStmt> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CASE_STMT;
  }

  static gap::generator<CaseStmt> containing(const Decl &decl);
  static gap::generator<CaseStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<CaseStmt> containing(const Stmt &stmt);
  static gap::generator<CaseStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CaseStmt> from_base(const Stmt &parent);
  inline static std::optional<CaseStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CaseStmt> from(const std::optional<Stmt> &parent);
  static std::optional<CaseStmt> from(const Reference &r);
  static std::optional<CaseStmt> from(const VariantEntity &e);
  static std::optional<CaseStmt> from(const TokenContext &t);

  bool case_statement_is_gnu_range(void) const;
  Token case_token(void) const;
  Token ellipsis_token(void) const;
  Expr lhs(void) const;
  std::optional<Expr> rhs(void) const;
};

static_assert(sizeof(CaseStmt) == sizeof(SwitchCase));

#endif
} // namespace mx
