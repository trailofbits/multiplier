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

#include "DeclKind.h"
#include "NamedDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class NamespaceAliasDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NamespaceAliasDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<NamespaceAliasDecl> in(const Fragment &frag);
  static gap::generator<NamespaceAliasDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::NAMESPACE_ALIAS;
  }

  static gap::generator<DeclKind> derived_kinds(void);
  static gap::generator<NamespaceAliasDecl> containing(const Decl &decl);
  static gap::generator<NamespaceAliasDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<NamespaceAliasDecl> redeclarations(void) const;
  inline static std::optional<NamespaceAliasDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<NamespaceAliasDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<NamespaceAliasDecl> from(const NamedDecl &parent);

  inline static std::optional<NamespaceAliasDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return NamespaceAliasDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NamespaceAliasDecl> from(const Decl &parent);

  inline static std::optional<NamespaceAliasDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return NamespaceAliasDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token alias_token(void) const;
  NamedDecl aliased_namespace(void) const;
  Token namespace_token(void) const;
  Token target_name_token(void) const;
};

static_assert(sizeof(NamespaceAliasDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
