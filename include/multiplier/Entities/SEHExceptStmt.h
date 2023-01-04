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
class CompoundStmt;
class Expr;
class SEHExceptStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using SEHExceptStmtRange = DerivedEntityRange<StmtIterator, SEHExceptStmt>;
using SEHExceptStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, SEHExceptStmt>;
using SEHExceptStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SEHExceptStmt>;

class SEHExceptStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static SEHExceptStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SEHExceptStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : SEHExceptStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SEH_EXCEPT_STMT;
  }

  static SEHExceptStmtContainingStmtRange containing(const Decl &decl);
  static SEHExceptStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SEHExceptStmt> from(const TokenContext &c);
  static std::optional<SEHExceptStmt> from(const Stmt &parent);

  inline static std::optional<SEHExceptStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SEHExceptStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CompoundStmt block(void) const;
  Token except_token(void) const;
  Expr filter_expression(void) const;
};

static_assert(sizeof(SEHExceptStmt) == sizeof(Stmt));

#endif
} // namespace mx
