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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Decl.h"
#include "DeclKind.h"

namespace mx {
class AccessSpecDecl;
class Decl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AccessSpecDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<AccessSpecDecl> in(const Fragment &frag);
  static gap::generator<AccessSpecDecl> in(const Index &index);
  static gap::generator<AccessSpecDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<AccessSpecDecl> by(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::ACCESS_SPEC;
  }

  static gap::generator<AccessSpecDecl> containing(const Decl &decl);
  static gap::generator<AccessSpecDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<AccessSpecDecl> containing(const Stmt &stmt);
  static gap::generator<AccessSpecDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<AccessSpecDecl> redeclarations(void) const;
  inline static std::optional<AccessSpecDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<AccessSpecDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<AccessSpecDecl> from(const Decl &parent);

  inline static std::optional<AccessSpecDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return AccessSpecDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token access_specifier_token(void) const;
  Token colon_token(void) const;
};

static_assert(sizeof(AccessSpecDecl) == sizeof(Decl));

#endif
} // namespace mx
