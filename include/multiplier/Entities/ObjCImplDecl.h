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
#include "ObjCContainerDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class ObjCContainerDecl;
class ObjCImplDecl;
class ObjCInterfaceDecl;
class ObjCPropertyImplDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCImplDeclRange = DerivedEntityRange<DeclIterator, ObjCImplDecl>;
using ObjCImplDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCImplDecl>;
using ObjCImplDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCImplDecl>;

class ObjCImplDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCImplDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCImplDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : ObjCImplDecl::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_IMPL;
  }

  static ObjCImplDeclContainingDeclRange containing(const Decl &decl);
  static ObjCImplDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCImplDecl> from(const TokenContext &c);
  static std::optional<ObjCImplDecl> from(const ObjCContainerDecl &parent);

  inline static std::optional<ObjCImplDecl> from(const std::optional<ObjCContainerDecl> &parent) {
    if (parent) {
      return ObjCImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCImplDecl> from(const NamedDecl &parent);

  inline static std::optional<ObjCImplDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ObjCImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCImplDecl> from(const Decl &parent);

  inline static std::optional<ObjCImplDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ObjCInterfaceDecl class_interface(void) const;
  std::vector<ObjCPropertyImplDecl> property_implementations(void) const;
};

static_assert(sizeof(ObjCImplDecl) == sizeof(ObjCContainerDecl));

#endif
} // namespace mx
