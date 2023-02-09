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

#include "StmtKind.h"
#include "SwitchCase.h"

namespace mx {
class CaseStmt;
class Expr;
class Stmt;
class SwitchCase;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CaseStmt : public SwitchCase {
 private:
  friend class FragmentImpl;
  friend class SwitchCase;
  friend class Stmt;
 public:
  static gap::generator<CaseStmt> in(const Fragment &frag);
  static gap::generator<CaseStmt> in(const Index &index);
  static gap::generator<CaseStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<CaseStmt> by(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CASE_STMT;
  }

  static gap::generator<CaseStmt> containing(const Decl &decl);
  static gap::generator<CaseStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<CaseStmt> containing(const Stmt &stmt);
  static gap::generator<CaseStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CaseStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CaseStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CaseStmt> from(const SwitchCase &parent);

  inline static std::optional<CaseStmt> from(const std::optional<SwitchCase> &parent) {
    if (parent) {
      return CaseStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CaseStmt> from(const Stmt &parent);

  inline static std::optional<CaseStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CaseStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool case_statement_is_gnu_range(void) const;
  Token case_token(void) const;
  Token ellipsis_token(void) const;
  Expr lhs(void) const;
  std::optional<Expr> rhs(void) const;
};

static_assert(sizeof(CaseStmt) == sizeof(SwitchCase));

#endif
} // namespace mx
