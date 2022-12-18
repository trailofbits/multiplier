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

#include "DeclKind.h"
#include "DeclUseSelector.h"
#include "NamedDecl.h"

namespace mx {
class BaseUsingDecl;
class Decl;
class NamedDecl;
class UsingShadowDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UsingShadowDeclRange = DerivedEntityRange<DeclIterator, UsingShadowDecl>;
using UsingShadowDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UsingShadowDecl>;
using UsingShadowDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UsingShadowDecl>;

class UsingShadowDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UsingShadowDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UsingShadowDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : UsingShadowDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::USING_SHADOW;
  }

  static UsingShadowDeclContainingDeclRange containing(const Decl &decl);
  static UsingShadowDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UsingShadowDecl> from(const TokenContext &c);
  static std::optional<UsingShadowDecl> from(const NamedDecl &parent);

  inline static std::optional<UsingShadowDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return UsingShadowDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingShadowDecl> from(const Decl &parent);

  inline static std::optional<UsingShadowDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UsingShadowDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  BaseUsingDecl introducer(void) const;
  std::optional<UsingShadowDecl> next_using_shadow_declaration(void) const;
  NamedDecl target_declaration(void) const;
};

static_assert(sizeof(UsingShadowDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
