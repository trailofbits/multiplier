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
class NamespaceAliasDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NamespaceAliasDeclRange = DerivedEntityRange<DeclIterator, NamespaceAliasDecl>;
using NamespaceAliasDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, NamespaceAliasDecl>;
using NamespaceAliasDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, NamespaceAliasDecl>;

class NamespaceAliasDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static NamespaceAliasDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NamespaceAliasDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : NamespaceAliasDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::NAMESPACE_ALIAS;
  }

  static NamespaceAliasDeclContainingDeclRange containing(const Decl &decl);
  static NamespaceAliasDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<NamespaceAliasDecl> from(const TokenContext &c);
  static std::optional<NamespaceAliasDecl> from(const NamedDecl &parent);

  inline static std::optional<NamespaceAliasDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return NamespaceAliasDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NamespaceAliasDecl> from(const Decl &parent);

  inline static std::optional<NamespaceAliasDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return NamespaceAliasDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token alias_token(void) const;
  NamedDecl aliased_namespace(void) const;
  Token namespace_token(void) const;
  Token target_name_token(void) const;
};

static_assert(sizeof(NamespaceAliasDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
