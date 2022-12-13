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
#include "OMPDeclarativeDirectiveDecl.h"

namespace mx {
class Decl;
class Expr;
class OMPDeclarativeDirectiveDecl;
class OMPThreadPrivateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPThreadPrivateDeclRange = DerivedEntityRange<DeclIterator, OMPThreadPrivateDecl>;
using OMPThreadPrivateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPThreadPrivateDecl>;
using OMPThreadPrivateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, OMPThreadPrivateDecl>;

class OMPThreadPrivateDecl : public OMPDeclarativeDirectiveDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveDecl;
  friend class Decl;
 public:
  inline static OMPThreadPrivateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPThreadPrivateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPThreadPrivateDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_THREAD_PRIVATE;
  }

  static OMPThreadPrivateDeclContainingDeclRange containing(const Decl &decl);
  static OMPThreadPrivateDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPThreadPrivateDecl> from(const TokenContext &c);
  static std::optional<OMPThreadPrivateDecl> from(const OMPDeclarativeDirectiveDecl &parent);

  inline static std::optional<OMPThreadPrivateDecl> from(const std::optional<OMPDeclarativeDirectiveDecl> &parent) {
    if (parent) {
      return OMPThreadPrivateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPThreadPrivateDecl> from(const Decl &parent);

  inline static std::optional<OMPThreadPrivateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return OMPThreadPrivateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Expr> varlists(void) const;
};

static_assert(sizeof(OMPThreadPrivateDecl) == sizeof(OMPDeclarativeDirectiveDecl));

#endif
} // namespace mx
