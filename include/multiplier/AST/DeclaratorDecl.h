// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
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
class DeclaratorDecl;
class Expr;
class NamedDecl;
class Stmt;
class TemplateParameterList;
class Token;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT DeclaratorDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<DeclaratorDecl> in(const Index &index);
  static gap::generator<DeclaratorDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DeclaratorDecl> by_id(const Index &, EntityId);
  static gap::generator<DeclaratorDecl> in(const Fragment &frag);
  static gap::generator<DeclaratorDecl> in(const File &file);

  static std::optional<DeclaratorDecl> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<DeclaratorDecl, ir::hl::Operation>> in(const Compilation &tu);

  static gap::generator<DeclaratorDecl> containing(const Decl &decl);
  static gap::generator<DeclaratorDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<DeclaratorDecl> containing(const Stmt &stmt);
  static gap::generator<DeclaratorDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  DeclaratorDecl canonical_declaration(void) const;
  std::optional<DeclaratorDecl> definition(void) const;
  gap::generator<DeclaratorDecl> redeclarations(void) const &;
  static std::optional<DeclaratorDecl> from_base(const Decl &parent);
  inline static std::optional<DeclaratorDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<DeclaratorDecl> from(const std::optional<Decl> &parent);
  static std::optional<DeclaratorDecl> from(const Reference &r);
  static std::optional<DeclaratorDecl> from(const VariantEntity &e);
  static std::optional<DeclaratorDecl> from(const TokenContext &t);

  Token first_inner_token(void) const;
  Token first_outer_token(void) const;
  std::optional<Expr> trailing_requires_clause(void) const;
  Token type_spec_end_token(void) const;
  Token type_spec_start_token(void) const;
  std::optional<TemplateParameterList> nth_template_parameter_list(unsigned n) const;
  unsigned num_template_parameter_lists(void) const;
  gap::generator<TemplateParameterList> template_parameter_lists(void) const &;
};

static_assert(sizeof(DeclaratorDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
