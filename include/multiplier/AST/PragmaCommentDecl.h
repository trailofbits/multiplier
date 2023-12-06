// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Decl.h>
#include <multiplier/AST/PragmaMSCommentKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class PragmaCommentDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT PragmaCommentDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<PragmaCommentDecl> in(const Index &index);
  static gap::generator<PragmaCommentDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PragmaCommentDecl> by_id(const Index &, EntityId);
  static gap::generator<PragmaCommentDecl> in(const Fragment &frag);
  static gap::generator<PragmaCommentDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::PRAGMA_COMMENT;
  }

  static gap::generator<PragmaCommentDecl> containing(const Decl &decl);
  static gap::generator<PragmaCommentDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<PragmaCommentDecl> containing(const Stmt &stmt);
  static gap::generator<PragmaCommentDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  PragmaCommentDecl canonical_declaration(void) const;
  std::optional<PragmaCommentDecl> definition(void) const;
  gap::generator<PragmaCommentDecl> redeclarations(void) const &;
  static std::optional<PragmaCommentDecl> from_base(const Decl &parent);
  inline static std::optional<PragmaCommentDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<PragmaCommentDecl> from(const std::optional<Decl> &parent);
  static std::optional<PragmaCommentDecl> from(const Reference &r);
  static std::optional<PragmaCommentDecl> from(const VariantEntity &e);
  static std::optional<PragmaCommentDecl> from(const TokenContext &t);

  std::string_view argument(void) const;
  PragmaMSCommentKind comment_kind(void) const;
};

static_assert(sizeof(PragmaCommentDecl) == sizeof(Decl));

#endif
} // namespace mx
