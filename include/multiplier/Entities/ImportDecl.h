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
class ImportDecl;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ImportDeclRange = DerivedEntityRange<DeclIterator, ImportDecl>;
using ImportDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ImportDecl>;
using ImportDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ImportDecl>;

class ImportDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static ImportDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ImportDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ImportDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::IMPORT;
  }

  static ImportDeclContainingDeclRange containing(const Decl &decl);
  static ImportDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ImportDecl> from(const TokenContext &c);
  static std::optional<ImportDecl> from(const Decl &parent);

  inline static std::optional<ImportDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ImportDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Token> identifier_tokens(void) const;
};

static_assert(sizeof(ImportDecl) == sizeof(Decl));

#endif
} // namespace mx
