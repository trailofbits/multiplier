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
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclKind.h"
#include "FieldDecl.h"
#include "ObjCIvarDeclAccessControl.h"

namespace mx {
class Decl;
class DeclaratorDecl;
class FieldDecl;
class NamedDecl;
class ObjCInterfaceDecl;
class ObjCIvarDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCIvarDecl : public FieldDecl {
 private:
  friend class FragmentImpl;
  friend class FieldDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<ObjCIvarDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ObjCIvarDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCIvarDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_IVAR;
  }

  static gap::generator<ObjCIvarDecl> containing(const Decl &decl);
  static gap::generator<ObjCIvarDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCIvarDecl> from(const TokenContext &c);
  static std::optional<ObjCIvarDecl> from(const FieldDecl &parent);

  inline static std::optional<ObjCIvarDecl> from(const std::optional<FieldDecl> &parent) {
    if (parent) {
      return ObjCIvarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCIvarDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<ObjCIvarDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return ObjCIvarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCIvarDecl> from(const ValueDecl &parent);

  inline static std::optional<ObjCIvarDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return ObjCIvarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCIvarDecl> from(const NamedDecl &parent);

  inline static std::optional<ObjCIvarDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ObjCIvarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCIvarDecl> from(const Decl &parent);

  inline static std::optional<ObjCIvarDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCIvarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ObjCIvarDeclAccessControl access_control(void) const;
  ObjCIvarDeclAccessControl canonical_access_control(void) const;
  ObjCInterfaceDecl containing_interface(void) const;
  ObjCIvarDecl next_instance_variable(void) const;
  bool synthesize(void) const;
};

static_assert(sizeof(ObjCIvarDecl) == sizeof(FieldDecl));

#endif
} // namespace mx
