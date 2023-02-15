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
#include "TypeDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class TagDecl;
class Type;
class TypeDecl;
class TypedefNameDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypedefNameDecl : public TypeDecl {
 private:
  friend class FragmentImpl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TypedefNameDecl> in(const Fragment &frag);
  static gap::generator<TypedefNameDecl> in(const File &file);
  static gap::generator<TypedefNameDecl> in(const Index &index);
  static gap::generator<TypedefNameDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypedefNameDecl> by_id(const Index &, EntityId);

  static gap::generator<TypedefNameDecl> containing(const Decl &decl);
  static gap::generator<TypedefNameDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TypedefNameDecl> containing(const Stmt &stmt);
  static gap::generator<TypedefNameDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<TypedefNameDecl> redeclarations(void) const &;
  static std::optional<TypedefNameDecl> from(const Decl &parent);

  inline static std::optional<TypedefNameDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TypedefNameDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<TypedefNameDecl> from(const Reference &r) {
    return TypedefNameDecl::from(r.as_declaration());
  }

  inline static std::optional<TypedefNameDecl> from(const TokenContext &t) {
    return TypedefNameDecl::from(t.as_declaration());
  }

  std::optional<TagDecl> anonymous_declaration_with_typedef_name(void) const;
  Type underlying_type(void) const;
  bool is_moded(void) const;
  bool is_transparent_tag(void) const;
};

static_assert(sizeof(TypedefNameDecl) == sizeof(TypeDecl));

#endif
} // namespace mx
