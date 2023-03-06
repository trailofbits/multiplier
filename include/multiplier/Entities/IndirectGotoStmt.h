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

namespace mx {
class Decl;
class Expr;
class IndirectGotoStmt;
class LabelDecl;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IndirectGotoStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<IndirectGotoStmt> in(const Fragment &frag);
  static gap::generator<IndirectGotoStmt> in(const File &file);
  static gap::generator<IndirectGotoStmt> in(const Index &index);
  static gap::generator<IndirectGotoStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<IndirectGotoStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::INDIRECT_GOTO_STMT;
  }

  static gap::generator<IndirectGotoStmt> containing(const Decl &decl);
  static gap::generator<IndirectGotoStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<IndirectGotoStmt> containing(const Stmt &stmt);
  static gap::generator<IndirectGotoStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<IndirectGotoStmt> from(const Stmt &parent);

  inline static std::optional<IndirectGotoStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return IndirectGotoStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<IndirectGotoStmt> from(const Reference &r) {
    return IndirectGotoStmt::from(r.as_statement());
  }

  inline static std::optional<IndirectGotoStmt> from(const TokenContext &t) {
    return IndirectGotoStmt::from(t.as_statement());
  }

  std::optional<LabelDecl> constant_target(void) const;
  Token goto_token(void) const;
  Token star_token(void) const;
  Expr target(void) const;
};

static_assert(sizeof(IndirectGotoStmt) == sizeof(Stmt));

#endif
} // namespace mx
