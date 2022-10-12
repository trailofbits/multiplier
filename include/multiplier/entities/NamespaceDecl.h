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
class NamespaceDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NamespaceDeclRange = DerivedEntityRange<DeclIterator, NamespaceDecl>;
using NamespaceDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, NamespaceDecl>;
using NamespaceDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, NamespaceDecl>;

class NamespaceDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static NamespaceDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NamespaceDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : NamespaceDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::NAMESPACE;
  }

  static NamespaceDeclContainingDeclRange containing(const Decl &decl);
  static NamespaceDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<NamespaceDecl> from(const TokenContext &c);
  static std::optional<NamespaceDecl> from(const NamedDecl &parent);

  inline static std::optional<NamespaceDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return NamespaceDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NamespaceDecl> from(const Decl &parent);

  inline static std::optional<NamespaceDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return NamespaceDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(NamespaceDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
