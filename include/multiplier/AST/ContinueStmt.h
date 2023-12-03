// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Stmt.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class ContinueStmt;
class Decl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ContinueStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ContinueStmt> in(const Index &index);
  static gap::generator<ContinueStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ContinueStmt> by_id(const Index &, EntityId);
  static gap::generator<ContinueStmt> in(const Fragment &frag);
  static gap::generator<ContinueStmt> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CONTINUE_STMT;
  }

  static gap::generator<ContinueStmt> containing(const Decl &decl);
  static gap::generator<ContinueStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ContinueStmt> containing(const Stmt &stmt);
  static gap::generator<ContinueStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ContinueStmt> from_base(const Stmt &parent);
  inline static std::optional<ContinueStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ContinueStmt> from(const std::optional<Stmt> &parent);
  static std::optional<ContinueStmt> from(const Reference &r);
  static std::optional<ContinueStmt> from(const VariantEntity &e);
  static std::optional<ContinueStmt> from(const TokenContext &t);

  Token continue_token(void) const;
};

static_assert(sizeof(ContinueStmt) == sizeof(Stmt));

#endif
} // namespace mx
