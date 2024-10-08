// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ValueDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class EnumConstantDecl;
class Expr;
class File;
class NamedDecl;
class Stmt;
class Token;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT EnumConstantDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<EnumConstantDecl> in(const Index &index);
  static gap::generator<EnumConstantDecl> in(const Fragment &frag);
  static gap::generator<EnumConstantDecl> in(const File &file);
  static gap::generator<EnumConstantDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<EnumConstantDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<EnumConstantDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::ENUM_CONSTANT;
  }

  static gap::generator<EnumConstantDecl> containing(const Decl &decl);
  static gap::generator<EnumConstantDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<EnumConstantDecl> containing(const Stmt &stmt);
  static gap::generator<EnumConstantDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  EnumConstantDecl canonical_declaration(void) const;
  std::optional<EnumConstantDecl> definition(void) const;
  gap::generator<EnumConstantDecl> redeclarations(void) const &;
  static std::optional<EnumConstantDecl> by_id(const Index &, EntityId);

  static std::optional<EnumConstantDecl> from_base(const Decl &parent);
  inline static std::optional<EnumConstantDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<EnumConstantDecl> from(const std::optional<Decl> &parent);
  static std::optional<EnumConstantDecl> from(const Reference &r);
  static std::optional<EnumConstantDecl> from(const VariantEntity &e);
  static std::optional<EnumConstantDecl> from(const TokenContext &t);

  std::optional<Expr> initializer_expression(void) const;
};

static_assert(sizeof(EnumConstantDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
