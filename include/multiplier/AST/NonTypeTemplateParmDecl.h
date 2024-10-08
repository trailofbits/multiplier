// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/DeclaratorDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class DeclaratorDecl;
class Expr;
class File;
class NamedDecl;
class NonTypeTemplateParmDecl;
class Stmt;
class Token;
class Type;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT NonTypeTemplateParmDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<NonTypeTemplateParmDecl> in(const Index &index);
  static gap::generator<NonTypeTemplateParmDecl> in(const Fragment &frag);
  static gap::generator<NonTypeTemplateParmDecl> in(const File &file);
  static gap::generator<NonTypeTemplateParmDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<NonTypeTemplateParmDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<NonTypeTemplateParmDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::NON_TYPE_TEMPLATE_PARM;
  }

  static gap::generator<NonTypeTemplateParmDecl> containing(const Decl &decl);
  static gap::generator<NonTypeTemplateParmDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<NonTypeTemplateParmDecl> containing(const Stmt &stmt);
  static gap::generator<NonTypeTemplateParmDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  NonTypeTemplateParmDecl canonical_declaration(void) const;
  std::optional<NonTypeTemplateParmDecl> definition(void) const;
  gap::generator<NonTypeTemplateParmDecl> redeclarations(void) const &;
  static std::optional<NonTypeTemplateParmDecl> by_id(const Index &, EntityId);

  static std::optional<NonTypeTemplateParmDecl> from_base(const Decl &parent);
  inline static std::optional<NonTypeTemplateParmDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<NonTypeTemplateParmDecl> from(const std::optional<Decl> &parent);
  static std::optional<NonTypeTemplateParmDecl> from(const Reference &r);
  static std::optional<NonTypeTemplateParmDecl> from(const VariantEntity &e);
  static std::optional<NonTypeTemplateParmDecl> from(const TokenContext &t);

  bool default_argument_was_inherited(void) const;
  std::optional<Expr> default_argument(void) const;
  Token default_argument_token(void) const;
  std::optional<Expr> placeholder_type_constraint(void) const;
  bool has_default_argument(void) const;
  bool has_placeholder_type_constraint(void) const;
  bool is_expanded_parameter_pack(void) const;
  bool is_pack_expansion(void) const;
  std::optional<Type> nth_expansion_type(unsigned n) const;
  unsigned num_expansion_types(void) const;
  gap::generator<Type> expansion_types(void) const &;
};

static_assert(sizeof(NonTypeTemplateParmDecl) == sizeof(DeclaratorDecl));

#endif
} // namespace mx
