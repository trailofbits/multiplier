// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Decl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class Stmt;
class Token;
class TranslationUnitDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TranslationUnitDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<TranslationUnitDecl> in(const Fragment &frag);
  static gap::generator<TranslationUnitDecl> in(const File &file);
  static gap::generator<TranslationUnitDecl> in(const Index &index);
  static gap::generator<TranslationUnitDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TranslationUnitDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TRANSLATION_UNIT;
  }

  static gap::generator<TranslationUnitDecl> containing(const Decl &decl);
  static gap::generator<TranslationUnitDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TranslationUnitDecl> containing(const Stmt &stmt);
  static gap::generator<TranslationUnitDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  TranslationUnitDecl canonical_declaration(void) const;
  std::optional<TranslationUnitDecl> definition(void) const;
  gap::generator<TranslationUnitDecl> redeclarations(void) const &;
  static std::optional<TranslationUnitDecl> from(const Decl &parent);

  inline static std::optional<TranslationUnitDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TranslationUnitDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TranslationUnitDecl> from(const Reference &r);
  static std::optional<TranslationUnitDecl> from(const TokenContext &t);

  gap::generator<Decl> declarations_in_context(void) const &;
};

static_assert(sizeof(TranslationUnitDecl) == sizeof(Decl));

#endif
} // namespace mx
