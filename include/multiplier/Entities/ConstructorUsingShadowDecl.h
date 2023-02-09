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
#include "UsingShadowDecl.h"

namespace mx {
class CXXRecordDecl;
class ConstructorUsingShadowDecl;
class Decl;
class NamedDecl;
class UsingShadowDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ConstructorUsingShadowDecl : public UsingShadowDecl {
 private:
  friend class FragmentImpl;
  friend class UsingShadowDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ConstructorUsingShadowDecl> in(const Fragment &frag);
  static gap::generator<ConstructorUsingShadowDecl> in(const Index &index);
  static gap::generator<ConstructorUsingShadowDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ConstructorUsingShadowDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CONSTRUCTOR_USING_SHADOW;
  }

  static gap::generator<ConstructorUsingShadowDecl> containing(const Decl &decl);
  static gap::generator<ConstructorUsingShadowDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ConstructorUsingShadowDecl> containing(const Stmt &stmt);
  static gap::generator<ConstructorUsingShadowDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ConstructorUsingShadowDecl> redeclarations(void) const;
  inline static std::optional<ConstructorUsingShadowDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ConstructorUsingShadowDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<ConstructorUsingShadowDecl> from(const UsingShadowDecl &parent);

  inline static std::optional<ConstructorUsingShadowDecl> from(const std::optional<UsingShadowDecl> &parent) {
    if (parent) {
      return ConstructorUsingShadowDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConstructorUsingShadowDecl> from(const NamedDecl &parent);

  inline static std::optional<ConstructorUsingShadowDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ConstructorUsingShadowDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConstructorUsingShadowDecl> from(const Decl &parent);

  inline static std::optional<ConstructorUsingShadowDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ConstructorUsingShadowDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool constructs_virtual_base(void) const;
  CXXRecordDecl constructed_base_class(void) const;
  std::optional<ConstructorUsingShadowDecl> constructed_base_class_shadow_declaration(void) const;
  CXXRecordDecl nominated_base_class(void) const;
  std::optional<ConstructorUsingShadowDecl> nominated_base_class_shadow_declaration(void) const;
};

static_assert(sizeof(ConstructorUsingShadowDecl) == sizeof(UsingShadowDecl));

#endif
} // namespace mx
