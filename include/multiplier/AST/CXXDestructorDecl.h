// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CXXMethodDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXDestructorDecl;
class CXXMethodDecl;
class Decl;
class DeclaratorDecl;
class Expr;
class FunctionDecl;
class NamedDecl;
class Stmt;
class Token;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXDestructorDecl : public CXXMethodDecl {
 private:
  friend class FragmentImpl;
  friend class CXXMethodDecl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<CXXDestructorDecl> in(const Index &index);
  static gap::generator<CXXDestructorDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXDestructorDecl> by_id(const Index &, EntityId);
  static gap::generator<CXXDestructorDecl> in(const Fragment &frag);
  static gap::generator<CXXDestructorDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_DESTRUCTOR;
  }

  static gap::generator<CXXDestructorDecl> containing(const Decl &decl);
  static gap::generator<CXXDestructorDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXDestructorDecl> containing(const Stmt &stmt);
  static gap::generator<CXXDestructorDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  CXXDestructorDecl canonical_declaration(void) const;
  std::optional<CXXDestructorDecl> definition(void) const;
  gap::generator<CXXDestructorDecl> redeclarations(void) const &;
  static std::optional<CXXDestructorDecl> from_base(const Decl &parent);
  inline static std::optional<CXXDestructorDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<CXXDestructorDecl> from(const std::optional<Decl> &parent);
  static std::optional<CXXDestructorDecl> from(const Reference &r);
  static std::optional<CXXDestructorDecl> from(const VariantEntity &e);
  static std::optional<CXXDestructorDecl> from(const TokenContext &t);

  std::optional<FunctionDecl> operator_delete(void) const;
  std::optional<Expr> operator_delete_this_argument(void) const;
};

static_assert(sizeof(CXXDestructorDecl) == sizeof(CXXMethodDecl));

#endif
} // namespace mx
