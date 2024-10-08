// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class File;
class ObjCDictionaryLiteral;
class ObjCMethodDecl;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCDictionaryLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCDictionaryLiteral> in(const Index &index);
  static gap::generator<ObjCDictionaryLiteral> in(const Fragment &frag);
  static gap::generator<ObjCDictionaryLiteral> in(const File &file);
  static gap::generator<ObjCDictionaryLiteral> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ObjCDictionaryLiteral> from(const ir::Operation &op);
  static gap::generator<std::pair<ObjCDictionaryLiteral, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_DICTIONARY_LITERAL;
  }

  static gap::generator<ObjCDictionaryLiteral> containing(const Decl &decl);
  static gap::generator<ObjCDictionaryLiteral> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCDictionaryLiteral> containing(const Stmt &stmt);
  static gap::generator<ObjCDictionaryLiteral> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCDictionaryLiteral> by_id(const Index &, EntityId);

  static std::optional<ObjCDictionaryLiteral> from_base(const Stmt &parent);
  inline static std::optional<ObjCDictionaryLiteral> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCDictionaryLiteral> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCDictionaryLiteral> from(const Reference &r);
  static std::optional<ObjCDictionaryLiteral> from(const VariantEntity &e);
  static std::optional<ObjCDictionaryLiteral> from(const TokenContext &t);

  ObjCMethodDecl dictionary_with_objects_method(void) const;
};

static_assert(sizeof(ObjCDictionaryLiteral) == sizeof(Expr));

#endif
} // namespace mx
