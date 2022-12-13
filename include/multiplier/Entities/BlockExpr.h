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

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class BlockDecl;
class BlockExpr;
class Expr;
class FunctionProtoType;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using BlockExprRange = DerivedEntityRange<StmtIterator, BlockExpr>;
using BlockExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, BlockExpr>;
using BlockExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, BlockExpr>;

class BlockExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static BlockExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BlockExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : BlockExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::BLOCK_EXPR;
  }

  static BlockExprContainingStmtRange containing(const Decl &decl);
  static BlockExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<BlockExpr> from(const TokenContext &c);
  static std::optional<BlockExpr> from(const Expr &parent);

  inline static std::optional<BlockExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return BlockExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BlockExpr> from(const ValueStmt &parent);

  inline static std::optional<BlockExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return BlockExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BlockExpr> from(const Stmt &parent);

  inline static std::optional<BlockExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return BlockExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  BlockDecl block_declaration(void) const;
  Stmt body(void) const;
  Token caret_token(void) const;
  FunctionProtoType function_type(void) const;
};

static_assert(sizeof(BlockExpr) == sizeof(Expr));

#endif
} // namespace mx
