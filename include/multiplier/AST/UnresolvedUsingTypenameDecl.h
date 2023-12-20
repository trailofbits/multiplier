// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/TypeDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class NamedDecl;
class Stmt;
class Token;
class TypeDecl;
class UnresolvedUsingTypenameDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT UnresolvedUsingTypenameDecl : public TypeDecl {
 private:
  friend class FragmentImpl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<UnresolvedUsingTypenameDecl> in(const Index &index);
  static gap::generator<UnresolvedUsingTypenameDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnresolvedUsingTypenameDecl> by_id(const Index &, EntityId);
  static gap::generator<UnresolvedUsingTypenameDecl> in(const Fragment &frag);
  static gap::generator<UnresolvedUsingTypenameDecl> in(const File &file);

  static std::optional<UnresolvedUsingTypenameDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<UnresolvedUsingTypenameDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::UNRESOLVED_USING_TYPENAME;
  }

  static gap::generator<UnresolvedUsingTypenameDecl> containing(const Decl &decl);
  static gap::generator<UnresolvedUsingTypenameDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<UnresolvedUsingTypenameDecl> containing(const Stmt &stmt);
  static gap::generator<UnresolvedUsingTypenameDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  UnresolvedUsingTypenameDecl canonical_declaration(void) const;
  std::optional<UnresolvedUsingTypenameDecl> definition(void) const;
  gap::generator<UnresolvedUsingTypenameDecl> redeclarations(void) const &;
  static std::optional<UnresolvedUsingTypenameDecl> from_base(const Decl &parent);
  inline static std::optional<UnresolvedUsingTypenameDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<UnresolvedUsingTypenameDecl> from(const std::optional<Decl> &parent);
  static std::optional<UnresolvedUsingTypenameDecl> from(const Reference &r);
  static std::optional<UnresolvedUsingTypenameDecl> from(const VariantEntity &e);
  static std::optional<UnresolvedUsingTypenameDecl> from(const TokenContext &t);

  Token ellipsis_token(void) const;
  Token typename_token(void) const;
  Token using_token(void) const;
  bool is_pack_expansion(void) const;
};

static_assert(sizeof(UnresolvedUsingTypenameDecl) == sizeof(TypeDecl));

#endif
} // namespace mx
