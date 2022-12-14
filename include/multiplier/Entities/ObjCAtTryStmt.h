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
class ObjCAtCatchStmt;
class ObjCAtFinallyStmt;
class ObjCAtTryStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCAtTryStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAtTryStmt>;
using ObjCAtTryStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAtTryStmt>;

class ObjCAtTryStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<ObjCAtTryStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static ObjCAtTryStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCAtTryStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_TRY_STMT;
  }

  static ObjCAtTryStmtContainingStmtRange containing(const Decl &decl);
  static ObjCAtTryStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAtTryStmt> from(const TokenContext &c);
  static std::optional<ObjCAtTryStmt> from(const Stmt &parent);

  inline static std::optional<ObjCAtTryStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCAtTryStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token at_try_token(void) const;
  ObjCAtFinallyStmt finally_statement(void) const;
  Stmt try_body(void) const;
  std::vector<ObjCAtCatchStmt> catch_statements(void) const;
};

static_assert(sizeof(ObjCAtTryStmt) == sizeof(Stmt));

#endif
} // namespace mx
