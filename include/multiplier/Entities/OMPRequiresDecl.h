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
#include "OMPDeclarativeDirectiveDecl.h"

namespace mx {
class Decl;
class OMPDeclarativeDirectiveDecl;
class OMPRequiresDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPRequiresDeclRange = DerivedEntityRange<DeclIterator, OMPRequiresDecl>;
using OMPRequiresDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPRequiresDecl>;
using OMPRequiresDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, OMPRequiresDecl>;

class OMPRequiresDecl : public OMPDeclarativeDirectiveDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveDecl;
  friend class Decl;
 public:
  inline static OMPRequiresDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPRequiresDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPRequiresDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_REQUIRES;
  }

  static OMPRequiresDeclContainingDeclRange containing(const Decl &decl);
  static OMPRequiresDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPRequiresDecl> from(const TokenContext &c);
  static std::optional<OMPRequiresDecl> from(const OMPDeclarativeDirectiveDecl &parent);

  inline static std::optional<OMPRequiresDecl> from(const std::optional<OMPDeclarativeDirectiveDecl> &parent) {
    if (parent) {
      return OMPRequiresDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPRequiresDecl> from(const Decl &parent);

  inline static std::optional<OMPRequiresDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return OMPRequiresDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPRequiresDecl) == sizeof(OMPDeclarativeDirectiveDecl));

#endif
} // namespace mx
