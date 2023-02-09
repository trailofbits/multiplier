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
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ValueStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ValueStmt> in(const Fragment &frag);
  static gap::generator<ValueStmt> in(const Index &index);
  static gap::generator<ValueStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ValueStmt> by_id(const Index &, EntityId);

  static gap::generator<ValueStmt> containing(const Decl &decl);
  static gap::generator<ValueStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ValueStmt> containing(const Stmt &stmt);
  static gap::generator<ValueStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<ValueStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<ValueStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<ValueStmt> from(const Stmt &parent);

  inline static std::optional<ValueStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ValueStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> expression_statement(void) const;
};

static_assert(sizeof(ValueStmt) == sizeof(Stmt));

#endif
} // namespace mx
