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
#include "TypedefNameDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class TypeDecl;
class TypedefDecl;
class TypedefNameDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypedefDecl : public TypedefNameDecl {
 private:
  friend class FragmentImpl;
  friend class TypedefNameDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TypedefDecl> in(const Fragment &frag);
  static gap::generator<TypedefDecl> in(const File &file);
  static gap::generator<TypedefDecl> in(const Index &index);
  static gap::generator<TypedefDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypedefDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TYPEDEF;
  }

  static gap::generator<TypedefDecl> containing(const Decl &decl);
  static gap::generator<TypedefDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TypedefDecl> containing(const Stmt &stmt);
  static gap::generator<TypedefDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<TypedefDecl> redeclarations(void) const &;
  static std::optional<TypedefDecl> from(const Decl &parent);

  inline static std::optional<TypedefDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TypedefDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<TypedefDecl> from(const Reference &r) {
    return TypedefDecl::from(r.as_declaration());
  }

  inline static std::optional<TypedefDecl> from(const TokenContext &t) {
    return TypedefDecl::from(t.as_declaration());
  }

};

static_assert(sizeof(TypedefDecl) == sizeof(TypedefNameDecl));

#endif
} // namespace mx
