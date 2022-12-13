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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Decl.h"
#include "DeclKind.h"

namespace mx {
class Decl;
class RequiresExprBodyDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using RequiresExprBodyDeclRange = DerivedEntityRange<DeclIterator, RequiresExprBodyDecl>;
using RequiresExprBodyDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, RequiresExprBodyDecl>;
using RequiresExprBodyDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, RequiresExprBodyDecl>;

class RequiresExprBodyDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static RequiresExprBodyDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static RequiresExprBodyDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : RequiresExprBodyDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::REQUIRES_EXPR_BODY;
  }

  static RequiresExprBodyDeclContainingDeclRange containing(const Decl &decl);
  static RequiresExprBodyDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<RequiresExprBodyDecl> from(const TokenContext &c);
  static std::optional<RequiresExprBodyDecl> from(const Decl &parent);

  inline static std::optional<RequiresExprBodyDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return RequiresExprBodyDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(RequiresExprBodyDecl) == sizeof(Decl));

#endif
} // namespace mx
