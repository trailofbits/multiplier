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
class CompoundStmt;
class Decl;
class Expr;
class ObjCAtSynchronizedStmt;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCAtSynchronizedStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ObjCAtSynchronizedStmt> in(const Index &index);
  static gap::generator<ObjCAtSynchronizedStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCAtSynchronizedStmt> by_id(const Index &, EntityId);
  static gap::generator<ObjCAtSynchronizedStmt> in(const Fragment &frag);
  static gap::generator<ObjCAtSynchronizedStmt> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<ObjCAtSynchronizedStmt> from(const ir::Operation &op);
  static gap::generator<std::pair<ObjCAtSynchronizedStmt, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_SYNCHRONIZED_STMT;
  }

  static gap::generator<ObjCAtSynchronizedStmt> containing(const Decl &decl);
  static gap::generator<ObjCAtSynchronizedStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCAtSynchronizedStmt> containing(const Stmt &stmt);
  static gap::generator<ObjCAtSynchronizedStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAtSynchronizedStmt> from_base(const Stmt &parent);
  inline static std::optional<ObjCAtSynchronizedStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCAtSynchronizedStmt> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCAtSynchronizedStmt> from(const Reference &r);
  static std::optional<ObjCAtSynchronizedStmt> from(const VariantEntity &e);
  static std::optional<ObjCAtSynchronizedStmt> from(const TokenContext &t);

  Token at_synchronized_token(void) const;
  CompoundStmt synch_body(void) const;
  Expr synch_expression(void) const;
};

static_assert(sizeof(ObjCAtSynchronizedStmt) == sizeof(Stmt));

#endif
} // namespace mx
