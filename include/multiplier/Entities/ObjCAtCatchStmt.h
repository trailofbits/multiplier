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
class ObjCAtCatchStmt;
class Stmt;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCAtCatchStmtRange = DerivedEntityRange<StmtIterator, ObjCAtCatchStmt>;
using ObjCAtCatchStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAtCatchStmt>;
using ObjCAtCatchStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAtCatchStmt>;

class ObjCAtCatchStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ObjCAtCatchStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAtCatchStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : ObjCAtCatchStmt::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_CATCH_STMT;
  }

  static ObjCAtCatchStmtContainingStmtRange containing(const Decl &decl);
  static ObjCAtCatchStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAtCatchStmt> from(const TokenContext &c);
  static std::optional<ObjCAtCatchStmt> from(const Stmt &parent);

  inline static std::optional<ObjCAtCatchStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCAtCatchStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token at_catch_token(void) const;
  Stmt catch_body(void) const;
  VarDecl catch_parameter_declaration(void) const;
  Token r_paren_token(void) const;
  bool has_ellipsis(void) const;
};

static_assert(sizeof(ObjCAtCatchStmt) == sizeof(Stmt));

#endif
} // namespace mx
