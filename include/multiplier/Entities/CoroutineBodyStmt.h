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
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class CoroutineBodyStmt;
class Expr;
class Stmt;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CoroutineBodyStmtRange = DerivedEntityRange<StmtIterator, CoroutineBodyStmt>;
using CoroutineBodyStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CoroutineBodyStmt>;
using CoroutineBodyStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CoroutineBodyStmt>;

class CoroutineBodyStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static CoroutineBodyStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CoroutineBodyStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CoroutineBodyStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COROUTINE_BODY_STMT;
  }

  static CoroutineBodyStmtContainingStmtRange containing(const Decl &decl);
  static CoroutineBodyStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CoroutineBodyStmt> from(const TokenContext &c);
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
  std::vector<Stmt> parameter_moves(void) const;
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
