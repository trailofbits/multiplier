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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

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
  static gap::generator<StaticAssertDecl> in(const Fragment &frag);
  static gap::generator<StaticAssertDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::STATIC_ASSERT;
  }

  static gap::generator<DeclKind> derived_kinds(void);
  static gap::generator<StaticAssertDecl> containing(const Decl &decl);
  static gap::generator<StaticAssertDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<StaticAssertDecl> redeclarations(void) const;
  inline static std::optional<StaticAssertDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<StaticAssertDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

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
