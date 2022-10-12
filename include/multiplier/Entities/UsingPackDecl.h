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
class UsingPackDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UsingPackDeclRange = DerivedEntityRange<DeclIterator, UsingPackDecl>;
using UsingPackDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UsingPackDecl>;
using UsingPackDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UsingPackDecl>;

class UsingPackDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UsingPackDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UsingPackDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : UsingPackDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::USING_PACK;
  }

  static UsingPackDeclContainingDeclRange containing(const Decl &decl);
  static UsingPackDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UsingPackDecl> from(const TokenContext &c);
  static std::optional<UsingPackDecl> from(const NamedDecl &parent);

  inline static std::optional<UsingPackDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return UsingPackDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingPackDecl> from(const Decl &parent);

  inline static std::optional<UsingPackDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UsingPackDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<NamedDecl> expansions(void) const;
  NamedDecl instantiated_from_using_declaration(void) const;
};

static_assert(sizeof(UsingPackDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
