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
#include "NamedDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class UnresolvedUsingIfExistsDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UnresolvedUsingIfExistsDeclRange = DerivedEntityRange<DeclIterator, UnresolvedUsingIfExistsDecl>;
using UnresolvedUsingIfExistsDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnresolvedUsingIfExistsDecl>;
using UnresolvedUsingIfExistsDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UnresolvedUsingIfExistsDecl>;

class UnresolvedUsingIfExistsDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UnresolvedUsingIfExistsDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UnresolvedUsingIfExistsDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : UnresolvedUsingIfExistsDecl::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::UNRESOLVED_USING_IF_EXISTS;
  }

  static UnresolvedUsingIfExistsDeclContainingDeclRange containing(const Decl &decl);
  static UnresolvedUsingIfExistsDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UnresolvedUsingIfExistsDecl> from(const TokenContext &c);
  static std::optional<UnresolvedUsingIfExistsDecl> from(const NamedDecl &parent);

  inline static std::optional<UnresolvedUsingIfExistsDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return UnresolvedUsingIfExistsDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedUsingIfExistsDecl> from(const Decl &parent);

  inline static std::optional<UnresolvedUsingIfExistsDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UnresolvedUsingIfExistsDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(UnresolvedUsingIfExistsDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
