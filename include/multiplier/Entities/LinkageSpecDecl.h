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
class Decl;
class LinkageSpecDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class LinkageSpecDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<LinkageSpecDecl> in(const Fragment &frag);
  static gap::generator<LinkageSpecDecl> in(const File &file);
  static gap::generator<LinkageSpecDecl> in(const Index &index);
  static gap::generator<LinkageSpecDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<LinkageSpecDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::LINKAGE_SPEC;
  }

  static gap::generator<LinkageSpecDecl> containing(const Decl &decl);
  static gap::generator<LinkageSpecDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<LinkageSpecDecl> containing(const Stmt &stmt);
  static gap::generator<LinkageSpecDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<LinkageSpecDecl> redeclarations(void) const &;
  static std::optional<LinkageSpecDecl> from(const Decl &parent);

  inline static std::optional<LinkageSpecDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return LinkageSpecDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<LinkageSpecDecl> from(const Reference &r) {
    return LinkageSpecDecl::from(r.as_declaration());
  }

  inline static std::optional<LinkageSpecDecl> from(const TokenContext &t) {
    return LinkageSpecDecl::from(t.as_declaration());
  }

  gap::generator<Decl> declarations_in_context(void) const &;
};

static_assert(sizeof(LinkageSpecDecl) == sizeof(Decl));

#endif
} // namespace mx
