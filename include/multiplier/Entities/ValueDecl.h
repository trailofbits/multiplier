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
class Type;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ValueDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ValueDecl> in(const Fragment &frag);
  static gap::generator<ValueDecl> in(const Index &index);
  static gap::generator<ValueDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ValueDecl> by_id(const Index &, EntityId);

  static gap::generator<ValueDecl> containing(const Decl &decl);
  static gap::generator<ValueDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ValueDecl> containing(const Stmt &stmt);
  static gap::generator<ValueDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ValueDecl> redeclarations(void) const;
  inline static std::optional<ValueDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ValueDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<ValueDecl> from(const NamedDecl &parent);

  inline static std::optional<ValueDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ValueDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ValueDecl> from(const Decl &parent);

  inline static std::optional<ValueDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ValueDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type type(void) const;
  bool is_weak(void) const;
};

static_assert(sizeof(ValueDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
