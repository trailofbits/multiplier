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

namespace mx {
class Expr;
class IndirectGotoStmt;
class LabelDecl;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using IndirectGotoStmtRange = DerivedEntityRange<StmtIterator, IndirectGotoStmt>;
using IndirectGotoStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, IndirectGotoStmt>;
using IndirectGotoStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, IndirectGotoStmt>;

class IndirectGotoStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static IndirectGotoStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static IndirectGotoStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : IndirectGotoStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::INDIRECT_GOTO_STMT;
  }

  static IndirectGotoStmtContainingStmtRange containing(const Decl &decl);
  static IndirectGotoStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<IndirectGotoStmt> from(const TokenContext &c);
  static std::optional<IndirectGotoStmt> from(const Stmt &parent);

  inline static std::optional<IndirectGotoStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return IndirectGotoStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<LabelDecl> constant_target(void) const;
  Token goto_token(void) const;
  Token star_token(void) const;
  Expr target(void) const;
};

static_assert(sizeof(IndirectGotoStmt) == sizeof(Stmt));

#endif
} // namespace mx
