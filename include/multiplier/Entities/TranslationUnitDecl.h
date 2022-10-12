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
class TranslationUnitDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TranslationUnitDeclRange = DerivedEntityRange<DeclIterator, TranslationUnitDecl>;
using TranslationUnitDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TranslationUnitDecl>;
using TranslationUnitDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TranslationUnitDecl>;

class TranslationUnitDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static TranslationUnitDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TranslationUnitDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : TranslationUnitDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TRANSLATION_UNIT;
  }

  static TranslationUnitDeclContainingDeclRange containing(const Decl &decl);
  static TranslationUnitDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TranslationUnitDecl> from(const TokenContext &c);
  static std::optional<TranslationUnitDecl> from(const Decl &parent);

  inline static std::optional<TranslationUnitDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TranslationUnitDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(TranslationUnitDecl) == sizeof(Decl));

#endif
} // namespace mx
