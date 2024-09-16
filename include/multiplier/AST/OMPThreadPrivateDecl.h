// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/OMPDeclarativeDirectiveDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class File;
class OMPDeclarativeDirectiveDecl;
class OMPThreadPrivateDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPThreadPrivateDecl : public OMPDeclarativeDirectiveDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveDecl;
  friend class Decl;
 public:
  static gap::generator<OMPThreadPrivateDecl> in(const Index &index);
  static gap::generator<OMPThreadPrivateDecl> in(const Fragment &frag);
  static gap::generator<OMPThreadPrivateDecl> in(const File &file);
  static gap::generator<OMPThreadPrivateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<OMPThreadPrivateDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPThreadPrivateDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_THREAD_PRIVATE;
  }

  static gap::generator<OMPThreadPrivateDecl> containing(const Decl &decl);
  static gap::generator<OMPThreadPrivateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPThreadPrivateDecl> containing(const Stmt &stmt);
  static gap::generator<OMPThreadPrivateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  OMPThreadPrivateDecl canonical_declaration(void) const;
  std::optional<OMPThreadPrivateDecl> definition(void) const;
  gap::generator<OMPThreadPrivateDecl> redeclarations(void) const &;
  static std::optional<OMPThreadPrivateDecl> by_id(const Index &, EntityId);

  static std::optional<OMPThreadPrivateDecl> from_base(const Decl &parent);
  inline static std::optional<OMPThreadPrivateDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<OMPThreadPrivateDecl> from(const std::optional<Decl> &parent);
  static std::optional<OMPThreadPrivateDecl> from(const Reference &r);
  static std::optional<OMPThreadPrivateDecl> from(const VariantEntity &e);
  static std::optional<OMPThreadPrivateDecl> from(const TokenContext &t);

  std::optional<Expr> nth_varlist(unsigned n) const;
  unsigned num_varlists(void) const;
  gap::generator<Expr> varlists(void) const &;
};

static_assert(sizeof(OMPThreadPrivateDecl) == sizeof(OMPDeclarativeDirectiveDecl));

#endif
} // namespace mx
