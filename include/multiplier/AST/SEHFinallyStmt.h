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
class SEHFinallyStmt;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SEHFinallyStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<SEHFinallyStmt> in(const Index &index);
  static gap::generator<SEHFinallyStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SEHFinallyStmt> by_id(const Index &, EntityId);
  static gap::generator<SEHFinallyStmt> in(const Fragment &frag);
  static gap::generator<SEHFinallyStmt> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SEH_FINALLY_STMT;
  }

  static gap::generator<SEHFinallyStmt> containing(const Decl &decl);
  static gap::generator<SEHFinallyStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<SEHFinallyStmt> containing(const Stmt &stmt);
  static gap::generator<SEHFinallyStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SEHFinallyStmt> from_base(const Stmt &parent);
  inline static std::optional<SEHFinallyStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<SEHFinallyStmt> from(const std::optional<Stmt> &parent);
  static std::optional<SEHFinallyStmt> from(const Reference &r);
  static std::optional<SEHFinallyStmt> from(const VariantEntity &e);
  static std::optional<SEHFinallyStmt> from(const TokenContext &t);

  CompoundStmt block(void) const;
  Token finally_token(void) const;
};

static_assert(sizeof(SEHFinallyStmt) == sizeof(Stmt));

#endif
} // namespace mx
