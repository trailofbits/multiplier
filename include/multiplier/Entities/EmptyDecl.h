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
class EmptyDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class EmptyDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<EmptyDecl> in(const Fragment &frag);
  static gap::generator<EmptyDecl> in(const Index &index);
  static gap::generator<EmptyDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<EmptyDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::EMPTY;
  }

  static gap::generator<EmptyDecl> containing(const Decl &decl);
  static gap::generator<EmptyDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<EmptyDecl> containing(const Stmt &stmt);
  static gap::generator<EmptyDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<EmptyDecl> redeclarations(void) const;
  inline static std::optional<EmptyDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<EmptyDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<EmptyDecl> from(const Decl &parent);

  inline static std::optional<EmptyDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return EmptyDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(EmptyDecl) == sizeof(Decl));

#endif
} // namespace mx
