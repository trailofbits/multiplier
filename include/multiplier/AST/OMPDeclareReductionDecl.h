// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/OMPDeclareReductionInitKind.h>
#include <multiplier/AST/ValueDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class NamedDecl;
class OMPDeclareReductionDecl;
class Stmt;
class Token;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPDeclareReductionDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<OMPDeclareReductionDecl> in(const Index &index);
  static gap::generator<OMPDeclareReductionDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPDeclareReductionDecl> by_id(const Index &, EntityId);
  static gap::generator<OMPDeclareReductionDecl> in(const Fragment &frag);
  static gap::generator<OMPDeclareReductionDecl> in(const File &file);

  static std::optional<OMPDeclareReductionDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPDeclareReductionDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_DECLARE_REDUCTION;
  }

  static gap::generator<OMPDeclareReductionDecl> containing(const Decl &decl);
  static gap::generator<OMPDeclareReductionDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPDeclareReductionDecl> containing(const Stmt &stmt);
  static gap::generator<OMPDeclareReductionDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  OMPDeclareReductionDecl canonical_declaration(void) const;
  std::optional<OMPDeclareReductionDecl> definition(void) const;
  gap::generator<OMPDeclareReductionDecl> redeclarations(void) const &;
  static std::optional<OMPDeclareReductionDecl> from_base(const Decl &parent);
  inline static std::optional<OMPDeclareReductionDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<OMPDeclareReductionDecl> from(const std::optional<Decl> &parent);
  static std::optional<OMPDeclareReductionDecl> from(const Reference &r);
  static std::optional<OMPDeclareReductionDecl> from(const VariantEntity &e);
  static std::optional<OMPDeclareReductionDecl> from(const TokenContext &t);

  Expr combiner(void) const;
  Expr combiner_in(void) const;
  Expr combiner_out(void) const;
  Expr initializer_original(void) const;
  Expr initializer_private(void) const;
  Expr initializer(void) const;
  OMPDeclareReductionInitKind initializer_kind(void) const;
  gap::generator<Decl> declarations_in_context(void) const &;
};

static_assert(sizeof(OMPDeclareReductionDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
