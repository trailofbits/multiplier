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
class NullStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NullStmtRange = DerivedEntityRange<StmtIterator, NullStmt>;
using NullStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, NullStmt>;
using NullStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, NullStmt>;

class NullStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static NullStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NullStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : NullStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::NULL_STMT;
  }

  static NullStmtContainingStmtRange containing(const Decl &decl);
  static NullStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<NullStmt> from(const TokenContext &c);
  static std::optional<NullStmt> from(const Stmt &parent);

  inline static std::optional<NullStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return NullStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token semi_token(void) const;
  bool has_leading_empty_macro(void) const;
};

static_assert(sizeof(NullStmt) == sizeof(Stmt));

#endif
} // namespace mx
