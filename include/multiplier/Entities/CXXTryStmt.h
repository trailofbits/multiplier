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
class CXXCatchStmt;
class CXXTryStmt;
class CompoundStmt;
class Decl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXTryStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<CXXTryStmt> in(const Fragment &frag);
  static gap::generator<CXXTryStmt> in(const File &file);
  static gap::generator<CXXTryStmt> in(const Index &index);
  static gap::generator<CXXTryStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXTryStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_TRY_STMT;
  }

  static gap::generator<CXXTryStmt> containing(const Decl &decl);
  static gap::generator<CXXTryStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXTryStmt> containing(const Stmt &stmt);
  static gap::generator<CXXTryStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXTryStmt> from(const Stmt &parent);

  inline static std::optional<CXXTryStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXTryStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXTryStmt> from(const Reference &r);
  static std::optional<CXXTryStmt> from(const TokenContext &t);

  CompoundStmt try_block(void) const;
  Token try_token(void) const;
  std::optional<CXXCatchStmt> nth_handler(unsigned n) const;
  unsigned num_handlers(void) const;
  gap::generator<CXXCatchStmt> handlers(void) const &;
};

static_assert(sizeof(CXXTryStmt) == sizeof(Stmt));

#endif
} // namespace mx
