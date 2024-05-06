// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
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
class ExternCContextDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ExternCContextDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<ExternCContextDecl> in(const Index &index);
  static gap::generator<ExternCContextDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ExternCContextDecl> by_id(const Index &, EntityId);
  static gap::generator<ExternCContextDecl> in(const Fragment &frag);
  static gap::generator<ExternCContextDecl> in(const File &file);

  static std::optional<ExternCContextDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<ExternCContextDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::EXTERN_C_CONTEXT;
  }

  static gap::generator<ExternCContextDecl> containing(const Decl &decl);
  static gap::generator<ExternCContextDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ExternCContextDecl> containing(const Stmt &stmt);
  static gap::generator<ExternCContextDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ExternCContextDecl canonical_declaration(void) const;
  std::optional<ExternCContextDecl> definition(void) const;
  gap::generator<ExternCContextDecl> redeclarations(void) const &;
  static std::optional<ExternCContextDecl> from_base(const Decl &parent);
  inline static std::optional<ExternCContextDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ExternCContextDecl> from(const std::optional<Decl> &parent);
  static std::optional<ExternCContextDecl> from(const Reference &r);
  static std::optional<ExternCContextDecl> from(const VariantEntity &e);
  static std::optional<ExternCContextDecl> from(const TokenContext &t);

  gap::generator<Decl> contained_declarations(void) const &;
};

static_assert(sizeof(ExternCContextDecl) == sizeof(Decl));

#endif
} // namespace mx
