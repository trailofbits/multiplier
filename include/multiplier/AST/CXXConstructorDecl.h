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
class Reference;
class CXXConstructorDecl;
class CXXCtorInitializer;
class CXXMethodDecl;
class Decl;
class DeclaratorDecl;
class File;
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
class MX_EXPORT CXXConstructorDecl : public CXXMethodDecl {
 private:
  friend class FragmentImpl;
  friend class CXXMethodDecl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<CXXConstructorDecl> in(const Index &index);
  static gap::generator<CXXConstructorDecl> in(const Fragment &frag);
  static gap::generator<CXXConstructorDecl> in(const File &file);
  static gap::generator<CXXConstructorDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CXXConstructorDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXConstructorDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_CONSTRUCTOR;
  }

  static gap::generator<CXXConstructorDecl> containing(const Decl &decl);
  static gap::generator<CXXConstructorDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXConstructorDecl> containing(const Stmt &stmt);
  static gap::generator<CXXConstructorDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  CXXConstructorDecl canonical_declaration(void) const;
  std::optional<CXXConstructorDecl> definition(void) const;
  gap::generator<CXXConstructorDecl> redeclarations(void) const &;
  static std::optional<CXXConstructorDecl> by_id(const Index &, EntityId);

  static std::optional<CXXConstructorDecl> from_base(const Decl &parent);
  inline static std::optional<CXXConstructorDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<CXXConstructorDecl> from(const std::optional<Decl> &parent);
  static std::optional<CXXConstructorDecl> from(const Reference &r);
  static std::optional<CXXConstructorDecl> from(const VariantEntity &e);
  static std::optional<CXXConstructorDecl> from(const TokenContext &t);

  std::optional<CXXConstructorDecl> target_constructor(void) const;
  std::optional<CXXCtorInitializer> nth_initializer(unsigned n) const;
  unsigned num_initializers(void) const;
  gap::generator<CXXCtorInitializer> initializers(void) const &;
  bool is_default_constructor(void) const;
  bool is_delegating_constructor(void) const;
  bool is_explicit(void) const;
  bool is_inheriting_constructor(void) const;
  bool is_specialization_copying_object(void) const;
};

static_assert(sizeof(CXXConstructorDecl) == sizeof(CXXMethodDecl));

#endif
} // namespace mx
