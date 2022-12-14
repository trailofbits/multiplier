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
class Expr;
class ObjCForCollectionStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCForCollectionStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCForCollectionStmt>;
using ObjCForCollectionStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCForCollectionStmt>;

class ObjCForCollectionStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<ObjCForCollectionStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static ObjCForCollectionStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCForCollectionStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_FOR_COLLECTION_STMT;
  }

  static ObjCForCollectionStmtContainingStmtRange containing(const Decl &decl);
  static ObjCForCollectionStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCForCollectionStmt> from(const TokenContext &c);
  static std::optional<ObjCForCollectionStmt> from(const Stmt &parent);

  inline static std::optional<ObjCForCollectionStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCForCollectionStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Stmt body(void) const;
  Expr collection(void) const;
  Stmt element(void) const;
  Token for_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(ObjCForCollectionStmt) == sizeof(Stmt));

#endif
} // namespace mx
