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

#include "DeclKind.h"
#include "ValueDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class UnresolvedUsingValueDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UnresolvedUsingValueDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnresolvedUsingValueDecl>;
using UnresolvedUsingValueDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UnresolvedUsingValueDecl>;

class UnresolvedUsingValueDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<UnresolvedUsingValueDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static UnresolvedUsingValueDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : UnresolvedUsingValueDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::UNRESOLVED_USING_VALUE;
  }

  static UnresolvedUsingValueDeclContainingDeclRange containing(const Decl &decl);
  static UnresolvedUsingValueDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UnresolvedUsingValueDecl> from(const TokenContext &c);
  static std::optional<UnresolvedUsingValueDecl> from(const ValueDecl &parent);

  inline static std::optional<UnresolvedUsingValueDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return UnresolvedUsingValueDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedUsingValueDecl> from(const NamedDecl &parent);

  inline static std::optional<UnresolvedUsingValueDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return UnresolvedUsingValueDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedUsingValueDecl> from(const Decl &parent);

  inline static std::optional<UnresolvedUsingValueDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UnresolvedUsingValueDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token ellipsis_token(void) const;
  Token using_token(void) const;
  bool is_access_declaration(void) const;
  bool is_pack_expansion(void) const;
};

static_assert(sizeof(UnresolvedUsingValueDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
