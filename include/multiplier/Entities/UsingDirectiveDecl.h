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
class UsingDirectiveDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UsingDirectiveDeclRange = DerivedEntityRange<DeclIterator, UsingDirectiveDecl>;
using UsingDirectiveDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UsingDirectiveDecl>;
using UsingDirectiveDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UsingDirectiveDecl>;

class UsingDirectiveDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UsingDirectiveDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UsingDirectiveDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : UsingDirectiveDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::USING_DIRECTIVE;
  }

  static UsingDirectiveDeclContainingDeclRange containing(const Decl &decl);
  static UsingDirectiveDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UsingDirectiveDecl> from(const TokenContext &c);
  static std::optional<UsingDirectiveDecl> from(const NamedDecl &parent);

  inline static std::optional<UsingDirectiveDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return UsingDirectiveDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingDirectiveDecl> from(const Decl &parent);

  inline static std::optional<UsingDirectiveDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UsingDirectiveDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token identifier_token(void) const;
  Token namespace_key_token(void) const;
  NamedDecl nominated_namespace_as_written(void) const;
  Token using_token(void) const;
};

static_assert(sizeof(UsingDirectiveDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
