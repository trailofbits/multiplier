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

#include "BaseUsingDecl.h"
#include "DeclKind.h"

namespace mx {
class BaseUsingDecl;
class Decl;
class NamedDecl;
class UsingDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UsingDeclRange = DerivedEntityRange<DeclIterator, UsingDecl>;
using UsingDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UsingDecl>;
using UsingDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UsingDecl>;

class UsingDecl : public BaseUsingDecl {
 private:
  friend class FragmentImpl;
  friend class BaseUsingDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UsingDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UsingDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : UsingDecl::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::USING;
  }

  static UsingDeclContainingDeclRange containing(const Decl &decl);
  static UsingDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UsingDecl> from(const TokenContext &c);
  static std::optional<UsingDecl> from(const BaseUsingDecl &parent);

  inline static std::optional<UsingDecl> from(const std::optional<BaseUsingDecl> &parent) {
    if (parent) {
      return UsingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingDecl> from(const NamedDecl &parent);

  inline static std::optional<UsingDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return UsingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingDecl> from(const Decl &parent);

  inline static std::optional<UsingDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UsingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token using_token(void) const;
  bool has_typename(void) const;
  bool is_access_declaration(void) const;
};

static_assert(sizeof(UsingDecl) == sizeof(BaseUsingDecl));

#endif
} // namespace mx
