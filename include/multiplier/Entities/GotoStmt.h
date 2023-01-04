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
class GotoStmt;
class LabelDecl;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using GotoStmtRange = DerivedEntityRange<StmtIterator, GotoStmt>;
using GotoStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, GotoStmt>;
using GotoStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, GotoStmt>;

class GotoStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static GotoStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static GotoStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : GotoStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::GOTO_STMT;
  }

  static GotoStmtContainingStmtRange containing(const Decl &decl);
  static GotoStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<GotoStmt> from(const TokenContext &c);
  static std::optional<GotoStmt> from(const Stmt &parent);

  inline static std::optional<GotoStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return GotoStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token goto_token(void) const;
  LabelDecl label(void) const;
  Token label_token(void) const;
};

static_assert(sizeof(GotoStmt) == sizeof(Stmt));

#endif
} // namespace mx
