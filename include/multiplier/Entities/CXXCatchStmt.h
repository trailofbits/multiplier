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

#include "DeclUseSelector.h"
#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class CXXCatchStmt;
class Stmt;
class Type;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXCatchStmtRange = DerivedEntityRange<StmtIterator, CXXCatchStmt>;
using CXXCatchStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXCatchStmt>;
using CXXCatchStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXCatchStmt>;

class CXXCatchStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static CXXCatchStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXCatchStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CXXCatchStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_CATCH_STMT;
  }

  static CXXCatchStmtContainingStmtRange containing(const Decl &decl);
  static CXXCatchStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXCatchStmt> from(const TokenContext &c);
  static std::optional<CXXCatchStmt> from(const Stmt &parent);

  inline static std::optional<CXXCatchStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXCatchStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token catch_token(void) const;
  Type caught_type(void) const;
  std::optional<VarDecl> exception_declaration(void) const;
  Stmt handler_block(void) const;
};

static_assert(sizeof(CXXCatchStmt) == sizeof(Stmt));

#endif
} // namespace mx
