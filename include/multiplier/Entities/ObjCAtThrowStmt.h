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
class Expr;
class ObjCAtThrowStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCAtThrowStmtRange = DerivedEntityRange<StmtIterator, ObjCAtThrowStmt>;
using ObjCAtThrowStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAtThrowStmt>;
using ObjCAtThrowStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAtThrowStmt>;

class ObjCAtThrowStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ObjCAtThrowStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAtThrowStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCAtThrowStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_THROW_STMT;
  }

  static ObjCAtThrowStmtContainingStmtRange containing(const Decl &decl);
  static ObjCAtThrowStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAtThrowStmt> from(const TokenContext &c);
  static std::optional<ObjCAtThrowStmt> from(const Stmt &parent);

  inline static std::optional<ObjCAtThrowStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCAtThrowStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr throw_expression(void) const;
  Token throw_token(void) const;
};

static_assert(sizeof(ObjCAtThrowStmt) == sizeof(Stmt));

#endif
} // namespace mx
