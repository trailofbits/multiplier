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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class DeclStmt;
class Expr;
class Stmt;
class SwitchCase;
class SwitchStmt;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwitchStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<SwitchStmt> in(const Fragment &frag);
  static gap::generator<SwitchStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SWITCH_STMT;
  }

  static gap::generator<SwitchStmt> containing(const Decl &decl);
  static gap::generator<SwitchStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<SwitchStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<SwitchStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<SwitchStmt> from(const Stmt &parent);

  inline static std::optional<SwitchStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SwitchStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Stmt body(void) const;
  Expr condition(void) const;
  std::optional<VarDecl> condition_variable(void) const;
  std::optional<DeclStmt> condition_variable_declaration_statement(void) const;
  std::optional<Stmt> initializer(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  std::optional<SwitchCase> first_switch_case(void) const;
  Token switch_token(void) const;
  bool has_initializer_storage(void) const;
  bool has_variable_storage(void) const;
  bool is_all_enum_cases_covered(void) const;
};

static_assert(sizeof(SwitchStmt) == sizeof(Stmt));

#endif
} // namespace mx
