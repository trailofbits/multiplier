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

namespace mx {
class Decl;
class Expr;
class StaticAssertDecl;
class StringLiteral;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class StaticAssertDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static gap::generator<StaticAssertDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<StaticAssertDecl> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : StaticAssertDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::STATIC_ASSERT;
  }

  static gap::generator<StaticAssertDecl> containing(const Decl &decl);
  static gap::generator<StaticAssertDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<StaticAssertDecl> from(const TokenContext &c);
  static std::optional<StaticAssertDecl> from(const Decl &parent);

  inline static std::optional<StaticAssertDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return StaticAssertDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr assert_expression(void) const;
  StringLiteral message(void) const;
  Token r_paren_token(void) const;
  bool is_failed(void) const;
};

static_assert(sizeof(StaticAssertDecl) == sizeof(Decl));

#endif
} // namespace mx
