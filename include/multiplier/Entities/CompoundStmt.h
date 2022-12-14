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
class CompoundStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CompoundStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CompoundStmt>;
using CompoundStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CompoundStmt>;

class CompoundStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<CompoundStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static CompoundStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CompoundStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COMPOUND_STMT;
  }

  static CompoundStmtContainingStmtRange containing(const Decl &decl);
  static CompoundStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CompoundStmt> from(const TokenContext &c);
  static std::optional<CompoundStmt> from(const Stmt &parent);

  inline static std::optional<CompoundStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CompoundStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token left_brace_token(void) const;
  Token right_brace_token(void) const;
  std::optional<Stmt> statement_expression_result(void) const;
  bool has_stored_fp_features(void) const;
};

static_assert(sizeof(CompoundStmt) == sizeof(Stmt));

#endif
} // namespace mx
