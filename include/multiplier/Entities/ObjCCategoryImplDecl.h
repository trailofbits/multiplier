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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

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
using ObjCCategoryImplDeclRange = DerivedEntityRange<DeclIterator, ObjCCategoryImplDecl>;
using ObjCCategoryImplDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCCategoryImplDecl>;
using ObjCCategoryImplDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCCategoryImplDecl>;

class ObjCCategoryImplDecl : public ObjCImplDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCImplDecl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCCategoryImplDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCCategoryImplDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCCategoryImplDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_CATEGORY_IMPL;
  }

  static ObjCCategoryImplDeclContainingDeclRange containing(const Decl &decl);
  static ObjCCategoryImplDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCCategoryImplDecl> from(const TokenContext &c);
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
