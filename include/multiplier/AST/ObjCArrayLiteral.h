// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class ObjCArrayLiteral;
class ObjCMethodDecl;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCArrayLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCArrayLiteral> in(const Index &index);
  static gap::generator<ObjCArrayLiteral> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCArrayLiteral> by_id(const Index &, EntityId);
  static gap::generator<ObjCArrayLiteral> in(const Fragment &frag);
  static gap::generator<ObjCArrayLiteral> in(const File &file);

  static std::optional<ObjCArrayLiteral> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<ObjCArrayLiteral, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_ARRAY_LITERAL;
  }

  static gap::generator<ObjCArrayLiteral> containing(const Decl &decl);
  static gap::generator<ObjCArrayLiteral> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCArrayLiteral> containing(const Stmt &stmt);
  static gap::generator<ObjCArrayLiteral> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCArrayLiteral> from_base(const Stmt &parent);
  inline static std::optional<ObjCArrayLiteral> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCArrayLiteral> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCArrayLiteral> from(const Reference &r);
  static std::optional<ObjCArrayLiteral> from(const VariantEntity &e);
  static std::optional<ObjCArrayLiteral> from(const TokenContext &t);

  ObjCMethodDecl array_with_objects_method(void) const;
  std::optional<Expr> nth_element(unsigned n) const;
  unsigned num_elements(void) const;
  gap::generator<Expr> elements(void) const &;
};

static_assert(sizeof(ObjCArrayLiteral) == sizeof(Expr));

#endif
} // namespace mx
