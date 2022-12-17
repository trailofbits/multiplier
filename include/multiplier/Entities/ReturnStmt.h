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

#include "DeclUseSelector.h"
#include "Stmt.h"
#include "StmtKind.h"
#include "StmtUseSelector.h"

namespace mx {
class Expr;
class ReturnStmt;
class Stmt;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ReturnStmtRange = DerivedEntityRange<StmtIterator, ReturnStmt>;
using ReturnStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ReturnStmt>;
using ReturnStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ReturnStmt>;

class ReturnStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ReturnStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ReturnStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : ReturnStmt::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::RETURN_STMT;
  }

  static ReturnStmtContainingStmtRange containing(const Decl &decl);
  static ReturnStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ReturnStmt> from(const TokenContext &c);
  static std::optional<ReturnStmt> from(const Stmt &parent);

  inline static std::optional<ReturnStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ReturnStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<VarDecl> nrvo_candidate(void) const;
  std::optional<Expr> return_value(void) const;
  Token return_token(void) const;
};

static_assert(sizeof(ReturnStmt) == sizeof(Stmt));

#endif
} // namespace mx
