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
#include "TypeDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class TypeDecl;
class UnresolvedUsingTypenameDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UnresolvedUsingTypenameDeclRange = DerivedEntityRange<DeclIterator, UnresolvedUsingTypenameDecl>;
using UnresolvedUsingTypenameDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnresolvedUsingTypenameDecl>;
using UnresolvedUsingTypenameDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UnresolvedUsingTypenameDecl>;

class UnresolvedUsingTypenameDecl : public TypeDecl {
 private:
  friend class FragmentImpl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UnresolvedUsingTypenameDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UnresolvedUsingTypenameDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : UnresolvedUsingTypenameDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::UNRESOLVED_USING_TYPENAME;
  }

  static UnresolvedUsingTypenameDeclContainingDeclRange containing(const Decl &decl);
  static UnresolvedUsingTypenameDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UnresolvedUsingTypenameDecl> from(const TokenContext &c);
  static std::optional<UnresolvedUsingTypenameDecl> from(const TypeDecl &parent);

  inline static std::optional<UnresolvedUsingTypenameDecl> from(const std::optional<TypeDecl> &parent) {
    if (parent) {
      return UnresolvedUsingTypenameDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedUsingTypenameDecl> from(const NamedDecl &parent);

  inline static std::optional<UnresolvedUsingTypenameDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return UnresolvedUsingTypenameDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedUsingTypenameDecl> from(const Decl &parent);

  inline static std::optional<UnresolvedUsingTypenameDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UnresolvedUsingTypenameDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token ellipsis_token(void) const;
  Token typename_token(void) const;
  Token using_token(void) const;
  bool is_pack_expansion(void) const;
};

static_assert(sizeof(UnresolvedUsingTypenameDecl) == sizeof(TypeDecl));

#endif
} // namespace mx
