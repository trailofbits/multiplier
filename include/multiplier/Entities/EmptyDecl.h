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
class Decl;
class EmptyDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using EmptyDeclRange = DerivedEntityRange<DeclIterator, EmptyDecl>;
using EmptyDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, EmptyDecl>;
using EmptyDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, EmptyDecl>;

class EmptyDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static EmptyDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static EmptyDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : EmptyDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::EMPTY;
  }

  static EmptyDeclContainingDeclRange containing(const Decl &decl);
  static EmptyDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<EmptyDecl> from(const TokenContext &c);
  static std::optional<EmptyDecl> from(const Decl &parent);

  inline static std::optional<EmptyDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return EmptyDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(EmptyDecl) == sizeof(Decl));

#endif
} // namespace mx
