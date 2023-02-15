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

#include "DeclKind.h"
#include "ValueDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class UnresolvedUsingValueDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnresolvedUsingValueDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<UnresolvedUsingValueDecl> in(const Fragment &frag);
  static gap::generator<UnresolvedUsingValueDecl> in(const File &file);
  static gap::generator<UnresolvedUsingValueDecl> in(const Index &index);
  static gap::generator<UnresolvedUsingValueDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnresolvedUsingValueDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::UNRESOLVED_USING_VALUE;
  }

  static gap::generator<UnresolvedUsingValueDecl> containing(const Decl &decl);
  static gap::generator<UnresolvedUsingValueDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<UnresolvedUsingValueDecl> containing(const Stmt &stmt);
  static gap::generator<UnresolvedUsingValueDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<UnresolvedUsingValueDecl> redeclarations(void) const &;
  static std::optional<UnresolvedUsingValueDecl> from(const Decl &parent);

  inline static std::optional<UnresolvedUsingValueDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UnresolvedUsingValueDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<UnresolvedUsingValueDecl> from(const Reference &r) {
    return UnresolvedUsingValueDecl::from(r.as_declaration());
  }

  inline static std::optional<UnresolvedUsingValueDecl> from(const TokenContext &t) {
    return UnresolvedUsingValueDecl::from(t.as_declaration());
  }

  Token ellipsis_token(void) const;
  Token using_token(void) const;
  bool is_access_declaration(void) const;
  bool is_pack_expansion(void) const;
};

static_assert(sizeof(UnresolvedUsingValueDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
