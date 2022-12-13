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
class CXXCatchStmt;
class CXXTryStmt;
class CompoundStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXTryStmtRange = DerivedEntityRange<StmtIterator, CXXTryStmt>;
using CXXTryStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXTryStmt>;
using CXXTryStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXTryStmt>;

class CXXTryStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static CXXTryStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXTryStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXTryStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_TRY_STMT;
  }

  static CXXTryStmtContainingStmtRange containing(const Decl &decl);
  static CXXTryStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXTryStmt> from(const TokenContext &c);
  static std::optional<CXXTryStmt> from(const Stmt &parent);

  inline static std::optional<CXXTryStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXTryStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CompoundStmt try_block(void) const;
  Token try_token(void) const;
  std::vector<CXXCatchStmt> handlers(void) const;
};

static_assert(sizeof(CXXTryStmt) == sizeof(Stmt));

#endif
} // namespace mx
