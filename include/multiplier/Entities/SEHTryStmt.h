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
class SEHExceptStmt;
class SEHFinallyStmt;
class SEHTryStmt;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SEHTryStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<SEHTryStmt> in(const Fragment &frag);
  static gap::generator<SEHTryStmt> in(const File &file);
  static gap::generator<SEHTryStmt> in(const Index &index);
  static gap::generator<SEHTryStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SEHTryStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SEH_TRY_STMT;
  }

  static gap::generator<SEHTryStmt> containing(const Decl &decl);
  static gap::generator<SEHTryStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<SEHTryStmt> containing(const Stmt &stmt);
  static gap::generator<SEHTryStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SEHTryStmt> from(const Stmt &parent);

  inline static std::optional<SEHTryStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SEHTryStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SEHTryStmt> from(const Reference &r);
  static std::optional<SEHTryStmt> from(const TokenContext &t);

  SEHExceptStmt except_handler(void) const;
  SEHFinallyStmt finally_handler(void) const;
  Stmt handler(void) const;
  bool is_cxx_try(void) const;
  CompoundStmt try_block(void) const;
  Token try_token(void) const;
};

static_assert(sizeof(SEHTryStmt) == sizeof(Stmt));

#endif
} // namespace mx
