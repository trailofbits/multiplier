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
class ObjCCompatibleAliasDecl;
class ObjCInterfaceDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCCompatibleAliasDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCCompatibleAliasDecl> in(const Fragment &frag);
  static gap::generator<ObjCCompatibleAliasDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_COMPATIBLE_ALIAS;
  }

  static gap::generator<DeclKind> derived_kinds(void);
  static gap::generator<ObjCCompatibleAliasDecl> containing(const Decl &decl);
  static gap::generator<ObjCCompatibleAliasDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ObjCCompatibleAliasDecl> redeclarations(void) const;
  inline static std::optional<ObjCCompatibleAliasDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ObjCCompatibleAliasDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<ObjCCompatibleAliasDecl> from(const NamedDecl &parent);

  inline static std::optional<ObjCCompatibleAliasDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ObjCCompatibleAliasDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCCompatibleAliasDecl> from(const Decl &parent);

  inline static std::optional<ObjCCompatibleAliasDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCCompatibleAliasDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ObjCInterfaceDecl class_interface(void) const;
};

static_assert(sizeof(ObjCCompatibleAliasDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
