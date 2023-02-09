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
#include "ObjCImplDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCContainerDecl;
class ObjCImplDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCCategoryImplDecl : public ObjCImplDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCImplDecl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCCategoryImplDecl> in(const Fragment &frag);
  static gap::generator<ObjCCategoryImplDecl> in(const Index &index);
  static gap::generator<ObjCCategoryImplDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<ObjCCategoryImplDecl> by(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_CATEGORY_IMPL;
  }

  static gap::generator<ObjCCategoryImplDecl> containing(const Decl &decl);
  static gap::generator<ObjCCategoryImplDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCCategoryImplDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCCategoryImplDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ObjCCategoryImplDecl> redeclarations(void) const;
  inline static std::optional<ObjCCategoryImplDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ObjCCategoryImplDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<ObjCCategoryImplDecl> from(const ObjCImplDecl &parent);

  inline static std::optional<ObjCCategoryImplDecl> from(const std::optional<ObjCImplDecl> &parent) {
    if (parent) {
      return ObjCCategoryImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCCategoryImplDecl> from(const ObjCContainerDecl &parent);

  inline static std::optional<ObjCCategoryImplDecl> from(const std::optional<ObjCContainerDecl> &parent) {
    if (parent) {
      return ObjCCategoryImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCCategoryImplDecl> from(const NamedDecl &parent);

  inline static std::optional<ObjCCategoryImplDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ObjCCategoryImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCCategoryImplDecl> from(const Decl &parent);

  inline static std::optional<ObjCCategoryImplDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCCategoryImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ObjCCategoryDecl category_declaration(void) const;
  Token category_name_token(void) const;
};

static_assert(sizeof(ObjCCategoryImplDecl) == sizeof(ObjCImplDecl));

#endif
} // namespace mx
