// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ObjCImplDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class NamedDecl;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCContainerDecl;
class ObjCImplDecl;
class Stmt;
class Token;
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
  static gap::generator<ObjCCategoryImplDecl> in(const File &file);
  static gap::generator<ObjCCategoryImplDecl> in(const Index &index);
  static gap::generator<ObjCCategoryImplDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCCategoryImplDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_CATEGORY_IMPL;
  }

  static gap::generator<ObjCCategoryImplDecl> containing(const Decl &decl);
  static gap::generator<ObjCCategoryImplDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCCategoryImplDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCCategoryImplDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ObjCCategoryImplDecl> redeclarations(void) const &;
  static std::optional<ObjCCategoryImplDecl> from(const Decl &parent);

  inline static std::optional<ObjCCategoryImplDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCCategoryImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCCategoryImplDecl> from(const Reference &r);
  static std::optional<ObjCCategoryImplDecl> from(const TokenContext &t);

  ObjCCategoryDecl category_declaration(void) const;
  Token category_name_token(void) const;
};

static_assert(sizeof(ObjCCategoryImplDecl) == sizeof(ObjCImplDecl));

#endif
} // namespace mx
