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

#include "NamedDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class ObjCCompatibleAliasDecl;
class ObjCInterfaceDecl;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCCompatibleAliasDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCCompatibleAliasDecl> in(const Fragment &frag);
  static gap::generator<ObjCCompatibleAliasDecl> in(const File &file);
  static gap::generator<ObjCCompatibleAliasDecl> in(const Index &index);
  static gap::generator<ObjCCompatibleAliasDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCCompatibleAliasDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_COMPATIBLE_ALIAS;
  }

  static gap::generator<ObjCCompatibleAliasDecl> containing(const Decl &decl);
  static gap::generator<ObjCCompatibleAliasDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCCompatibleAliasDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCCompatibleAliasDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ObjCCompatibleAliasDecl> redeclarations(void) const &;
  static std::optional<ObjCCompatibleAliasDecl> from(const Decl &parent);

  inline static std::optional<ObjCCompatibleAliasDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCCompatibleAliasDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCCompatibleAliasDecl> from(const Reference &r) {
    return ObjCCompatibleAliasDecl::from(r.as_declaration());
  }

  inline static std::optional<ObjCCompatibleAliasDecl> from(const TokenContext &t) {
    return ObjCCompatibleAliasDecl::from(t.as_declaration());
  }

  ObjCInterfaceDecl class_interface(void) const;
};

static_assert(sizeof(ObjCCompatibleAliasDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
