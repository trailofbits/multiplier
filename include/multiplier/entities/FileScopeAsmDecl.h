// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Decl.h"
#include "DeclKind.h"

namespace mx {
class Decl;
class FileScopeAsmDecl;
class StringLiteral;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using FileScopeAsmDeclRange = DerivedEntityRange<DeclIterator, FileScopeAsmDecl>;
using FileScopeAsmDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, FileScopeAsmDecl>;
using FileScopeAsmDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, FileScopeAsmDecl>;

class FileScopeAsmDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static FileScopeAsmDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FileScopeAsmDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : FileScopeAsmDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FILE_SCOPE_ASM;
  }

  static FileScopeAsmDeclContainingDeclRange containing(const Decl &decl);
  static FileScopeAsmDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FileScopeAsmDecl> from(const TokenContext &c);
  static std::optional<FileScopeAsmDecl> from(const Decl &parent);

  inline static std::optional<FileScopeAsmDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return FileScopeAsmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token assembly_token(void) const;
  StringLiteral assembly_string(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(FileScopeAsmDecl) == sizeof(Decl));

#endif
} // namespace mx
