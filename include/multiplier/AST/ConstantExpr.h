// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ConstantResultStorageKind.h>
#include <multiplier/AST/FullExpr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class ConstantExpr;
class Decl;
class Expr;
class File;
class FullExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ConstantExpr : public FullExpr {
 private:
  friend class FragmentImpl;
  friend class FullExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ConstantExpr> in(const Index &index);
  static gap::generator<ConstantExpr> in(const Fragment &frag);
  static gap::generator<ConstantExpr> in(const File &file);
  static gap::generator<ConstantExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ConstantExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<ConstantExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CONSTANT_EXPR;
  }

  static gap::generator<ConstantExpr> containing(const Decl &decl);
  static gap::generator<ConstantExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ConstantExpr> containing(const Stmt &stmt);
  static gap::generator<ConstantExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ConstantExpr> by_id(const Index &, EntityId);

  static std::optional<ConstantExpr> from_base(const Stmt &parent);
  inline static std::optional<ConstantExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ConstantExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ConstantExpr> from(const Reference &r);
  static std::optional<ConstantExpr> from(const VariantEntity &e);
  static std::optional<ConstantExpr> from(const TokenContext &t);

  ConstantResultStorageKind result_storage_kind(void) const;
  bool has_ap_value_result(void) const;
  bool is_immediate_invocation(void) const;
};

static_assert(sizeof(ConstantExpr) == sizeof(FullExpr));

#endif
} // namespace mx
