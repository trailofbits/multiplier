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
class ObjCAtFinallyStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCAtFinallyStmtRange = DerivedEntityRange<StmtIterator, ObjCAtFinallyStmt>;
using ObjCAtFinallyStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAtFinallyStmt>;
using ObjCAtFinallyStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAtFinallyStmt>;

class ObjCAtFinallyStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ObjCAtFinallyStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAtFinallyStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCAtFinallyStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_FINALLY_STMT;
  }

  static ObjCAtFinallyStmtContainingStmtRange containing(const Decl &decl);
  static ObjCAtFinallyStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAtFinallyStmt> from(const TokenContext &c);
  static std::optional<ObjCAtFinallyStmt> from(const Stmt &parent);

  inline static std::optional<ObjCAtFinallyStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCAtFinallyStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token at_finally_token(void) const;
  Stmt finally_body(void) const;
};

static_assert(sizeof(ObjCAtFinallyStmt) == sizeof(Stmt));

#endif
} // namespace mx
