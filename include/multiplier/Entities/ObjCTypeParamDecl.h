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
#include "ObjCTypeParamVariance.h"
#include "TypedefNameDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class ObjCTypeParamDecl;
class TypeDecl;
class TypedefNameDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCTypeParamDecl : public TypedefNameDecl {
 private:
  friend class FragmentImpl;
  friend class TypedefNameDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCTypeParamDecl> in(const Fragment &frag);
  static gap::generator<ObjCTypeParamDecl> in(const File &file);
  static gap::generator<ObjCTypeParamDecl> in(const Index &index);
  static gap::generator<ObjCTypeParamDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCTypeParamDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_TYPE_PARAM;
  }

  static gap::generator<ObjCTypeParamDecl> containing(const Decl &decl);
  static gap::generator<ObjCTypeParamDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCTypeParamDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCTypeParamDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ObjCTypeParamDecl> redeclarations(void) const;
  static std::optional<ObjCTypeParamDecl> from(const Decl &parent);

  inline static std::optional<ObjCTypeParamDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCTypeParamDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCTypeParamDecl> from(const Reference &r) {
    return ObjCTypeParamDecl::from(r.as_declaration());
  }

  inline static std::optional<ObjCTypeParamDecl> from(const TokenContext &t) {
    return ObjCTypeParamDecl::from(t.as_declaration());
  }

  Token colon_token(void) const;
  ObjCTypeParamVariance variance(void) const;
  Token variance_token(void) const;
  bool has_explicit_bound(void) const;
};

static_assert(sizeof(ObjCTypeParamDecl) == sizeof(TypedefNameDecl));

#endif
} // namespace mx
