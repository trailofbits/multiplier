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
class TypeDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TypeDecl> in(const Fragment &frag);
  static gap::generator<TypeDecl> in(const Index &index);
  static gap::generator<TypeDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<TypeDecl> by(const Index &, EntityId);

  static gap::generator<TypeDecl> containing(const Decl &decl);
  static gap::generator<TypeDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TypeDecl> containing(const Stmt &stmt);
  static gap::generator<TypeDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<TypeDecl> redeclarations(void) const;
  inline static std::optional<TypeDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<TypeDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<TypeDecl> from(const NamedDecl &parent);

  inline static std::optional<TypeDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return TypeDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeDecl> from(const Decl &parent);

  inline static std::optional<TypeDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TypeDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Type> type_for_declaration(void) const;
};

static_assert(sizeof(TypeDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
