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
class Decl;
class Expr;
class ObjCForCollectionStmt;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCForCollectionStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ObjCForCollectionStmt> in(const Index &index);
  static gap::generator<ObjCForCollectionStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCForCollectionStmt> by_id(const Index &, EntityId);
  static gap::generator<ObjCForCollectionStmt> in(const Fragment &frag);
  static gap::generator<ObjCForCollectionStmt> in(const File &file);

  static std::optional<ObjCForCollectionStmt> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<ObjCForCollectionStmt, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_FOR_COLLECTION_STMT;
  }

  static gap::generator<ObjCForCollectionStmt> containing(const Decl &decl);
  static gap::generator<ObjCForCollectionStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCForCollectionStmt> containing(const Stmt &stmt);
  static gap::generator<ObjCForCollectionStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCForCollectionStmt> from_base(const Stmt &parent);
  inline static std::optional<ObjCForCollectionStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCForCollectionStmt> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCForCollectionStmt> from(const Reference &r);
  static std::optional<ObjCForCollectionStmt> from(const VariantEntity &e);
  static std::optional<ObjCForCollectionStmt> from(const TokenContext &t);

  Stmt body(void) const;
  Expr collection(void) const;
  Stmt element(void) const;
  Token for_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(ObjCForCollectionStmt) == sizeof(Stmt));

#endif
} // namespace mx
