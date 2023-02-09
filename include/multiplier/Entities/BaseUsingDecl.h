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
class BaseUsingDecl;
class Decl;
class NamedDecl;
class UsingShadowDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class BaseUsingDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<BaseUsingDecl> in(const Fragment &frag);
  static gap::generator<BaseUsingDecl> in(const Index &index);
  static gap::generator<BaseUsingDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BaseUsingDecl> by_id(const Index &, EntityId);

  static gap::generator<BaseUsingDecl> containing(const Decl &decl);
  static gap::generator<BaseUsingDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<BaseUsingDecl> containing(const Stmt &stmt);
  static gap::generator<BaseUsingDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<BaseUsingDecl> redeclarations(void) const;
  inline static std::optional<BaseUsingDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<BaseUsingDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<BaseUsingDecl> from(const NamedDecl &parent);

  inline static std::optional<BaseUsingDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return BaseUsingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BaseUsingDecl> from(const Decl &parent);

  inline static std::optional<BaseUsingDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return BaseUsingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<UsingShadowDecl> nth_shadow(unsigned n) const;
  gap::generator<UsingShadowDecl> shadows(void) const;
};

static_assert(sizeof(BaseUsingDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
