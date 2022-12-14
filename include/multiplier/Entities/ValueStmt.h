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
#include "StmtUseSelector.h"

namespace mx {
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ValueStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ValueStmt>;
using ValueStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ValueStmt>;

class ValueStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<ValueStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static ValueStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ValueStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  static ValueStmtContainingStmtRange containing(const Decl &decl);
  static ValueStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ValueStmt> from(const TokenContext &c);
  static std::optional<ValueStmt> from(const Stmt &parent);

  inline static std::optional<ValueStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ValueStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> expression_statement(void) const;
};

static_assert(sizeof(ValueStmt) == sizeof(Stmt));

#endif
} // namespace mx
