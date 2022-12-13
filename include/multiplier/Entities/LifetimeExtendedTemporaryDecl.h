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

#include "Decl.h"
#include "DeclKind.h"
#include "StorageDuration.h"

namespace mx {
class Decl;
class Expr;
class LifetimeExtendedTemporaryDecl;
class Stmt;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using LifetimeExtendedTemporaryDeclRange = DerivedEntityRange<DeclIterator, LifetimeExtendedTemporaryDecl>;
using LifetimeExtendedTemporaryDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, LifetimeExtendedTemporaryDecl>;
using LifetimeExtendedTemporaryDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, LifetimeExtendedTemporaryDecl>;

class LifetimeExtendedTemporaryDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static LifetimeExtendedTemporaryDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static LifetimeExtendedTemporaryDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : LifetimeExtendedTemporaryDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::LIFETIME_EXTENDED_TEMPORARY;
  }

  static LifetimeExtendedTemporaryDeclContainingDeclRange containing(const Decl &decl);
  static LifetimeExtendedTemporaryDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<LifetimeExtendedTemporaryDecl> from(const TokenContext &c);
  static std::optional<LifetimeExtendedTemporaryDecl> from(const Decl &parent);

  inline static std::optional<LifetimeExtendedTemporaryDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return LifetimeExtendedTemporaryDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Stmt> children(void) const;
  ValueDecl extending_declaration(void) const;
  StorageDuration storage_duration(void) const;
  Expr temporary_expression(void) const;
};

static_assert(sizeof(LifetimeExtendedTemporaryDecl) == sizeof(Decl));

#endif
} // namespace mx
