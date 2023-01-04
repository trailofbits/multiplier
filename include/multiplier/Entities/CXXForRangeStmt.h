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
#include "StmtUseSelector.h"

namespace mx {
class CXXForRangeStmt;
class DeclStmt;
class Expr;
class Stmt;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXForRangeStmtRange = DerivedEntityRange<StmtIterator, CXXForRangeStmt>;
using CXXForRangeStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXForRangeStmt>;
using CXXForRangeStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXForRangeStmt>;

class CXXForRangeStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static CXXForRangeStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXForRangeStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CXXForRangeStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_FOR_RANGE_STMT;
  }

  static CXXForRangeStmtContainingStmtRange containing(const Decl &decl);
  static CXXForRangeStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXForRangeStmt> from(const TokenContext &c);
  static std::optional<CXXForRangeStmt> from(const Stmt &parent);

  inline static std::optional<CXXForRangeStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXForRangeStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  DeclStmt begin_statement(void) const;
  Stmt body(void) const;
  Token coawait_token(void) const;
  Token colon_token(void) const;
  Expr condition(void) const;
  DeclStmt end_statement(void) const;
  Token for_token(void) const;
  Expr increment(void) const;
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
