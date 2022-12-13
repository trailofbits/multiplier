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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class DoStmt;
class Expr;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DoStmtRange = DerivedEntityRange<StmtIterator, DoStmt>;
using DoStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, DoStmt>;
using DoStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DoStmt>;

class DoStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static DoStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DoStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : DoStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DO_STMT;
  }

  static DoStmtContainingStmtRange containing(const Decl &decl);
  static DoStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DoStmt> from(const TokenContext &c);
  static std::optional<DoStmt> from(const Stmt &parent);

  inline static std::optional<DoStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DoStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Stmt body(void) const;
  Expr condition(void) const;
  Token do_token(void) const;
  Token r_paren_token(void) const;
  Token while_token(void) const;
};

static_assert(sizeof(DoStmt) == sizeof(Stmt));

#endif
} // namespace mx
