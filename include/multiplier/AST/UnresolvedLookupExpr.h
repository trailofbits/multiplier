// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/OverloadExpr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class OverloadExpr;
class Stmt;
class Token;
class UnresolvedLookupExpr;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT UnresolvedLookupExpr : public OverloadExpr {
 private:
  friend class FragmentImpl;
  friend class OverloadExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<UnresolvedLookupExpr> in(const Index &index);
  static gap::generator<UnresolvedLookupExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnresolvedLookupExpr> by_id(const Index &, EntityId);
  static gap::generator<UnresolvedLookupExpr> in(const Fragment &frag);
  static gap::generator<UnresolvedLookupExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::UNRESOLVED_LOOKUP_EXPR;
  }

  static gap::generator<UnresolvedLookupExpr> containing(const Decl &decl);
  static gap::generator<UnresolvedLookupExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<UnresolvedLookupExpr> containing(const Stmt &stmt);
  static gap::generator<UnresolvedLookupExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UnresolvedLookupExpr> from_base(const Stmt &parent);
  inline static std::optional<UnresolvedLookupExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<UnresolvedLookupExpr> from(const std::optional<Stmt> &parent);
  static std::optional<UnresolvedLookupExpr> from(const Reference &r);
  static std::optional<UnresolvedLookupExpr> from(const VariantEntity &e);
  static std::optional<UnresolvedLookupExpr> from(const TokenContext &t);

  bool is_overloaded(void) const;
  bool requires_adl(void) const;
};

static_assert(sizeof(UnresolvedLookupExpr) == sizeof(OverloadExpr));

#endif
} // namespace mx
