// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/VarDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class DeclaratorDecl;
class NamedDecl;
class OMPCapturedExprDecl;
class Stmt;
class Token;
class ValueDecl;
class VarDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPCapturedExprDecl : public VarDecl {
 private:
  friend class FragmentImpl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<OMPCapturedExprDecl> in(const Index &index);
  static gap::generator<OMPCapturedExprDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPCapturedExprDecl> by_id(const Index &, EntityId);
  static gap::generator<OMPCapturedExprDecl> in(const Fragment &frag);
  static gap::generator<OMPCapturedExprDecl> in(const File &file);

  static std::optional<OMPCapturedExprDecl> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<OMPCapturedExprDecl, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_CAPTURED_EXPR;
  }

  static gap::generator<OMPCapturedExprDecl> containing(const Decl &decl);
  static gap::generator<OMPCapturedExprDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPCapturedExprDecl> containing(const Stmt &stmt);
  static gap::generator<OMPCapturedExprDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  OMPCapturedExprDecl canonical_declaration(void) const;
  std::optional<OMPCapturedExprDecl> definition(void) const;
  gap::generator<OMPCapturedExprDecl> redeclarations(void) const &;
  static std::optional<OMPCapturedExprDecl> from_base(const Decl &parent);
  inline static std::optional<OMPCapturedExprDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<OMPCapturedExprDecl> from(const std::optional<Decl> &parent);
  static std::optional<OMPCapturedExprDecl> from(const Reference &r);
  static std::optional<OMPCapturedExprDecl> from(const VariantEntity &e);
  static std::optional<OMPCapturedExprDecl> from(const TokenContext &t);

};

static_assert(sizeof(OMPCapturedExprDecl) == sizeof(VarDecl));

#endif
} // namespace mx
