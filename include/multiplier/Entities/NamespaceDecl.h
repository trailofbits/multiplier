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
#include "NamedDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class NamespaceDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NamespaceDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<NamespaceDecl> in(const Fragment &frag);
  static gap::generator<NamespaceDecl> in(const File &file);
  static gap::generator<NamespaceDecl> in(const Index &index);
  static gap::generator<NamespaceDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NamespaceDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::NAMESPACE;
  }

  static gap::generator<NamespaceDecl> containing(const Decl &decl);
  static gap::generator<NamespaceDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<NamespaceDecl> containing(const Stmt &stmt);
  static gap::generator<NamespaceDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<NamespaceDecl> redeclarations(void) const &;
  static std::optional<NamespaceDecl> from(const Decl &parent);

  inline static std::optional<NamespaceDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return NamespaceDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<NamespaceDecl> from(const Reference &r) {
    return NamespaceDecl::from(r.as_declaration());
  }

  inline static std::optional<NamespaceDecl> from(const TokenContext &t) {
    return NamespaceDecl::from(t.as_declaration());
  }

  gap::generator<Decl> declarations_in_context(void) const &;
};

static_assert(sizeof(NamespaceDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
