// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Stmt.h"

namespace mx {
class EntityProvider;
class Index;
class CompoundStmt;
class Decl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CompoundStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<CompoundStmt> in(const Fragment &frag);
  static gap::generator<CompoundStmt> in(const File &file);
  static gap::generator<CompoundStmt> in(const Index &index);
  static gap::generator<CompoundStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CompoundStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COMPOUND_STMT;
  }

  static gap::generator<CompoundStmt> containing(const Decl &decl);
  static gap::generator<CompoundStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<CompoundStmt> containing(const Stmt &stmt);
  static gap::generator<CompoundStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CompoundStmt> from(const Stmt &parent);

  inline static std::optional<CompoundStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CompoundStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CompoundStmt> from(const Reference &r);
  static std::optional<CompoundStmt> from(const TokenContext &t);

  Token left_brace_token(void) const;
  Token right_brace_token(void) const;
  std::optional<Stmt> statement_expression_result(void) const;
  bool has_stored_fp_features(void) const;
};

static_assert(sizeof(CompoundStmt) == sizeof(Stmt));

#endif
} // namespace mx
