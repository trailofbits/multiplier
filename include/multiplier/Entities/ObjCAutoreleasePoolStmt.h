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
class ObjCAutoreleasePoolStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCAutoreleasePoolStmtRange = DerivedEntityRange<StmtIterator, ObjCAutoreleasePoolStmt>;
using ObjCAutoreleasePoolStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAutoreleasePoolStmt>;
using ObjCAutoreleasePoolStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAutoreleasePoolStmt>;

class ObjCAutoreleasePoolStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ObjCAutoreleasePoolStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAutoreleasePoolStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : ObjCAutoreleasePoolStmt::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AUTORELEASE_POOL_STMT;
  }

  static ObjCAutoreleasePoolStmtContainingStmtRange containing(const Decl &decl);
  static ObjCAutoreleasePoolStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAutoreleasePoolStmt> from(const TokenContext &c);
  static std::optional<ObjCAutoreleasePoolStmt> from(const Stmt &parent);

  inline static std::optional<ObjCAutoreleasePoolStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCAutoreleasePoolStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token at_token(void) const;
  Stmt sub_statement(void) const;
};

static_assert(sizeof(ObjCAutoreleasePoolStmt) == sizeof(Stmt));

#endif
} // namespace mx
