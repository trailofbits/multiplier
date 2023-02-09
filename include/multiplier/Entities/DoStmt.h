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

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class DoStmt;
class Expr;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DoStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<DoStmt> in(const Fragment &frag);
  static gap::generator<DoStmt> in(const Index &index);
  static gap::generator<DoStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<DoStmt> by(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DO_STMT;
  }

  static gap::generator<DoStmt> containing(const Decl &decl);
  static gap::generator<DoStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<DoStmt> containing(const Stmt &stmt);
  static gap::generator<DoStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<DoStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<DoStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<DoStmt> from(const Stmt &parent);

  inline static std::optional<DoStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DoStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Stmt body(void) const;
  Expr condition(void) const;
  Token do_token(void) const;
  Token r_paren_token(void) const;
  Token while_token(void) const;
};

static_assert(sizeof(DoStmt) == sizeof(Stmt));

#endif
} // namespace mx
