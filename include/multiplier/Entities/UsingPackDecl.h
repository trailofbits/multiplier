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
class UsingPackDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UsingPackDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<UsingPackDecl> in(const Fragment &frag);
  static gap::generator<UsingPackDecl> in(const Index &index);
  static gap::generator<UsingPackDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UsingPackDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::USING_PACK;
  }

  static gap::generator<UsingPackDecl> containing(const Decl &decl);
  static gap::generator<UsingPackDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<UsingPackDecl> containing(const Stmt &stmt);
  static gap::generator<UsingPackDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<UsingPackDecl> redeclarations(void) const;
  inline static std::optional<UsingPackDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<UsingPackDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<UsingPackDecl> from(const NamedDecl &parent);

  inline static std::optional<UsingPackDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return UsingPackDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingPackDecl> from(const Decl &parent);

  inline static std::optional<UsingPackDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UsingPackDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<NamedDecl> nth_expansion(unsigned n) const;
  gap::generator<NamedDecl> expansions(void) const;
  NamedDecl instantiated_from_using_declaration(void) const;
};

static_assert(sizeof(UsingPackDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
