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
class ObjCAtSynchronizedStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCAtSynchronizedStmtRange = DerivedEntityRange<StmtIterator, ObjCAtSynchronizedStmt>;
using ObjCAtSynchronizedStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAtSynchronizedStmt>;
using ObjCAtSynchronizedStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAtSynchronizedStmt>;

class ObjCAtSynchronizedStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ObjCAtSynchronizedStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAtSynchronizedStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCAtSynchronizedStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_SYNCHRONIZED_STMT;
  }

  static ObjCAtSynchronizedStmtContainingStmtRange containing(const Decl &decl);
  static ObjCAtSynchronizedStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAtSynchronizedStmt> from(const TokenContext &c);
  static std::optional<ObjCAtSynchronizedStmt> from(const Stmt &parent);

  inline static std::optional<ObjCAtSynchronizedStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCAtSynchronizedStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token at_synchronized_token(void) const;
  CompoundStmt synch_body(void) const;
  Expr synch_expression(void) const;
};

static_assert(sizeof(ObjCAtSynchronizedStmt) == sizeof(Stmt));

#endif
} // namespace mx
