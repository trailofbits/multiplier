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
class ContinueStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ContinueStmtRange = DerivedEntityRange<StmtIterator, ContinueStmt>;
using ContinueStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ContinueStmt>;
using ContinueStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ContinueStmt>;

class ContinueStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ContinueStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ContinueStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ContinueStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CONTINUE_STMT;
  }

  static ContinueStmtContainingStmtRange containing(const Decl &decl);
  static ContinueStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ContinueStmt> from(const TokenContext &c);
  static std::optional<ContinueStmt> from(const Stmt &parent);

  inline static std::optional<ContinueStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ContinueStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token continue_token(void) const;
};

static_assert(sizeof(ContinueStmt) == sizeof(Stmt));

#endif
} // namespace mx
