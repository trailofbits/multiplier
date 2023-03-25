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
class FileScopeAsmDecl;
class Stmt;
class StringLiteral;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FileScopeAsmDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<FileScopeAsmDecl> in(const Fragment &frag);
  static gap::generator<FileScopeAsmDecl> in(const File &file);
  static gap::generator<FileScopeAsmDecl> in(const Index &index);
  static gap::generator<FileScopeAsmDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FileScopeAsmDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FILE_SCOPE_ASM;
  }

  static gap::generator<FileScopeAsmDecl> containing(const Decl &decl);
  static gap::generator<FileScopeAsmDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<FileScopeAsmDecl> containing(const Stmt &stmt);
  static gap::generator<FileScopeAsmDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  FileScopeAsmDecl canonical_declaration(void) const;
  std::optional<FileScopeAsmDecl> definition(void) const;
  gap::generator<FileScopeAsmDecl> redeclarations(void) const &;
  static std::optional<FileScopeAsmDecl> from(const Decl &parent);

  inline static std::optional<FileScopeAsmDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return FileScopeAsmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FileScopeAsmDecl> from(const Reference &r);
  static std::optional<FileScopeAsmDecl> from(const TokenContext &t);

  Token assembly_token(void) const;
  StringLiteral assembly_string(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(FileScopeAsmDecl) == sizeof(Decl));

#endif
} // namespace mx
