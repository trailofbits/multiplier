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
class ObjCAtCatchStmt;
class ObjCAtFinallyStmt;
class ObjCAtTryStmt;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCAtTryStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ObjCAtTryStmt> in(const Index &index);
  static gap::generator<ObjCAtTryStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCAtTryStmt> by_id(const Index &, EntityId);
  static gap::generator<ObjCAtTryStmt> in(const Fragment &frag);
  static gap::generator<ObjCAtTryStmt> in(const File &file);

  static std::optional<ObjCAtTryStmt> from(const ir::Operation &op);
  static gap::generator<std::pair<ObjCAtTryStmt, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AT_TRY_STMT;
  }

  static gap::generator<ObjCAtTryStmt> containing(const Decl &decl);
  static gap::generator<ObjCAtTryStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCAtTryStmt> containing(const Stmt &stmt);
  static gap::generator<ObjCAtTryStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAtTryStmt> from_base(const Stmt &parent);
  inline static std::optional<ObjCAtTryStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCAtTryStmt> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCAtTryStmt> from(const Reference &r);
  static std::optional<ObjCAtTryStmt> from(const VariantEntity &e);
  static std::optional<ObjCAtTryStmt> from(const TokenContext &t);

  Token at_try_token(void) const;
  ObjCAtFinallyStmt finally_statement(void) const;
  Stmt try_body(void) const;
  std::optional<ObjCAtCatchStmt> nth_catch_statement(unsigned n) const;
  unsigned num_catch_statements(void) const;
  gap::generator<ObjCAtCatchStmt> catch_statements(void) const &;
};

static_assert(sizeof(ObjCAtTryStmt) == sizeof(Stmt));

#endif
} // namespace mx
