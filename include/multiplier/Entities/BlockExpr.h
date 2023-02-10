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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

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
class BlockExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<BlockExpr> in(const Fragment &frag);
  static gap::generator<BlockExpr> in(const File &file);
  static gap::generator<BlockExpr> in(const Index &index);
  static gap::generator<BlockExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BlockExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::BLOCK_EXPR;
  }

  static gap::generator<BlockExpr> containing(const Decl &decl);
  static gap::generator<BlockExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<BlockExpr> containing(const Stmt &stmt);
  static gap::generator<BlockExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<BlockExpr> from(const Stmt &parent);

  inline static std::optional<BlockExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return BlockExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<BlockExpr> from(const Reference &r) {
    return BlockExpr::from(r.as_statement());
  }

  inline static std::optional<BlockExpr> from(const TokenContext &t) {
    return BlockExpr::from(t.as_statement());
  }

  BlockDecl block_declaration(void) const;
  Stmt body(void) const;
  Token caret_token(void) const;
  FunctionProtoType function_type(void) const;
};

static_assert(sizeof(BlockExpr) == sizeof(Expr));

#endif
} // namespace mx
