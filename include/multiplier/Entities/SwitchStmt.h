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

#include "DeclUseSelector.h"
#include "Stmt.h"
#include "StmtKind.h"
#include "StmtUseSelector.h"

namespace mx {
class DeclStmt;
class Expr;
class Stmt;
class SwitchCase;
class SwitchStmt;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using SwitchStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, SwitchStmt>;
using SwitchStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SwitchStmt>;

class SwitchStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<SwitchStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static SwitchStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : SwitchStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SWITCH_STMT;
  }

  static SwitchStmtContainingStmtRange containing(const Decl &decl);
  static SwitchStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SwitchStmt> from(const TokenContext &c);
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
