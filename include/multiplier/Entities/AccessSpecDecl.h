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
class AccessSpecDecl;
class Decl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AccessSpecDeclRange = DerivedEntityRange<DeclIterator, AccessSpecDecl>;
using AccessSpecDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, AccessSpecDecl>;
using AccessSpecDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, AccessSpecDecl>;

class AccessSpecDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static AccessSpecDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AccessSpecDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : AccessSpecDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::ACCESS_SPEC;
  }

  static AccessSpecDeclContainingDeclRange containing(const Decl &decl);
  static AccessSpecDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<AccessSpecDecl> from(const TokenContext &c);
  static std::optional<AccessSpecDecl> from(const Decl &parent);

  inline static std::optional<AccessSpecDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return AccessSpecDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token access_specifier_token(void) const;
  Token colon_token(void) const;
};

static_assert(sizeof(AccessSpecDecl) == sizeof(Decl));

#endif
} // namespace mx
