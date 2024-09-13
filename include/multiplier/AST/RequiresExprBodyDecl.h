// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Decl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Reference;
class Decl;
class File;
class RequiresExprBodyDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT RequiresExprBodyDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<RequiresExprBodyDecl> in(const Index &index);
  static gap::generator<RequiresExprBodyDecl> in(const Fragment &frag);
  static gap::generator<RequiresExprBodyDecl> in(const File &file);
  static gap::generator<RequiresExprBodyDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<RequiresExprBodyDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<RequiresExprBodyDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::REQUIRES_EXPR_BODY;
  }

  static gap::generator<RequiresExprBodyDecl> containing(const Decl &decl);
  static gap::generator<RequiresExprBodyDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<RequiresExprBodyDecl> containing(const Stmt &stmt);
  static gap::generator<RequiresExprBodyDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  RequiresExprBodyDecl canonical_declaration(void) const;
  std::optional<RequiresExprBodyDecl> definition(void) const;
  gap::generator<RequiresExprBodyDecl> redeclarations(void) const &;
  static std::optional<RequiresExprBodyDecl> by_id(const Index &, EntityId);

  static std::optional<RequiresExprBodyDecl> from_base(const Decl &parent);
  inline static std::optional<RequiresExprBodyDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<RequiresExprBodyDecl> from(const std::optional<Decl> &parent);
  static std::optional<RequiresExprBodyDecl> from(const Reference &r);
  static std::optional<RequiresExprBodyDecl> from(const VariantEntity &e);
  static std::optional<RequiresExprBodyDecl> from(const TokenContext &t);

  gap::generator<Decl> contained_declarations(void) const &;
};

static_assert(sizeof(RequiresExprBodyDecl) == sizeof(Decl));

#endif
} // namespace mx
