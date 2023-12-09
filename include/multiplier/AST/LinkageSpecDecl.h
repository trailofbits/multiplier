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
class Decl;
class LinkageSpecDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT LinkageSpecDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<LinkageSpecDecl> in(const Index &index);
  static gap::generator<LinkageSpecDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<LinkageSpecDecl> by_id(const Index &, EntityId);
  static gap::generator<LinkageSpecDecl> in(const Fragment &frag);
  static gap::generator<LinkageSpecDecl> in(const File &file);

  static std::optional<LinkageSpecDecl> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<LinkageSpecDecl, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::LINKAGE_SPEC;
  }

  static gap::generator<LinkageSpecDecl> containing(const Decl &decl);
  static gap::generator<LinkageSpecDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<LinkageSpecDecl> containing(const Stmt &stmt);
  static gap::generator<LinkageSpecDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  LinkageSpecDecl canonical_declaration(void) const;
  std::optional<LinkageSpecDecl> definition(void) const;
  gap::generator<LinkageSpecDecl> redeclarations(void) const &;
  static std::optional<LinkageSpecDecl> from_base(const Decl &parent);
  inline static std::optional<LinkageSpecDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<LinkageSpecDecl> from(const std::optional<Decl> &parent);
  static std::optional<LinkageSpecDecl> from(const Reference &r);
  static std::optional<LinkageSpecDecl> from(const VariantEntity &e);
  static std::optional<LinkageSpecDecl> from(const TokenContext &t);

  gap::generator<Decl> declarations_in_context(void) const &;
};

static_assert(sizeof(LinkageSpecDecl) == sizeof(Decl));

#endif
} // namespace mx
