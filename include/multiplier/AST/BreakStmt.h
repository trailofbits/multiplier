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
class BreakStmt;
class Decl;
class File;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT BreakStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<BreakStmt> in(const Index &index);
  static gap::generator<BreakStmt> in(const Fragment &frag);
  static gap::generator<BreakStmt> in(const File &file);
  static gap::generator<BreakStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<BreakStmt> from(const ir::Operation &op);
  static gap::generator<std::pair<BreakStmt, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::BREAK_STMT;
  }

  static gap::generator<BreakStmt> containing(const Decl &decl);
  static gap::generator<BreakStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<BreakStmt> containing(const Stmt &stmt);
  static gap::generator<BreakStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<BreakStmt> by_id(const Index &, EntityId);

  static std::optional<BreakStmt> from_base(const Stmt &parent);
  inline static std::optional<BreakStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<BreakStmt> from(const std::optional<Stmt> &parent);
  static std::optional<BreakStmt> from(const Reference &r);
  static std::optional<BreakStmt> from(const VariantEntity &e);
  static std::optional<BreakStmt> from(const TokenContext &t);

  Token break_token(void) const;
};

static_assert(sizeof(BreakStmt) == sizeof(Stmt));

#endif
} // namespace mx
