// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class CoroutineBodyStmt;
class Expr;
class Stmt;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CoroutineBodyStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<CoroutineBodyStmt> in(const Fragment &frag);
  static gap::generator<CoroutineBodyStmt> in(const Index &index);
  static gap::generator<CoroutineBodyStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CoroutineBodyStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COROUTINE_BODY_STMT;
  }

  static gap::generator<CoroutineBodyStmt> containing(const Decl &decl);
  static gap::generator<CoroutineBodyStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<CoroutineBodyStmt> containing(const Stmt &stmt);
  static gap::generator<CoroutineBodyStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CoroutineBodyStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CoroutineBodyStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CoroutineBodyStmt> from(const Stmt &parent);

  inline static std::optional<CoroutineBodyStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CoroutineBodyStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr allocate(void) const;
  Stmt body(void) const;
  Expr deallocate(void) const;
  Stmt exception_handler(void) const;
  Stmt fallthrough_handler(void) const;
  Stmt final_suspend_statement(void) const;
  Stmt initializer_suspend_statement(void) const;
  std::optional<Stmt> nth_parameter_move(unsigned n) const;
  gap::generator<Stmt> parameter_moves(void) const;
  VarDecl promise_declaration(void) const;
  Stmt promise_declaration_statement(void) const;
  Stmt return_statement(void) const;
  Stmt return_statement_on_alloc_failure(void) const;
  Expr return_value(void) const;
  Expr return_value_initializer(void) const;
  bool has_dependent_promise_type(void) const;
};

static_assert(sizeof(CoroutineBodyStmt) == sizeof(Stmt));

#endif
} // namespace mx
