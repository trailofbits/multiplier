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
class Decl;
class Stmt;
class Token;
class Type;
class VarDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXCatchStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<CXXCatchStmt> in(const Index &index);
  static gap::generator<CXXCatchStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXCatchStmt> by_id(const Index &, EntityId);
  static gap::generator<CXXCatchStmt> in(const Fragment &frag);
  static gap::generator<CXXCatchStmt> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_CATCH_STMT;
  }

  static gap::generator<CXXCatchStmt> containing(const Decl &decl);
  static gap::generator<CXXCatchStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXCatchStmt> containing(const Stmt &stmt);
  static gap::generator<CXXCatchStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXCatchStmt> from_base(const Stmt &parent);
  inline static std::optional<CXXCatchStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXCatchStmt> from(const std::optional<Stmt> &parent);
  static std::optional<CXXCatchStmt> from(const Reference &r);
  static std::optional<CXXCatchStmt> from(const VariantEntity &e);
  static std::optional<CXXCatchStmt> from(const TokenContext &t);

  Token catch_token(void) const;
  Type caught_type(void) const;
  std::optional<VarDecl> exception_declaration(void) const;
  Stmt handler_block(void) const;
};

static_assert(sizeof(CXXCatchStmt) == sizeof(Stmt));

#endif
} // namespace mx
