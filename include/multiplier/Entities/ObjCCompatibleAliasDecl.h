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
#include "NamedDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class ObjCCompatibleAliasDecl;
class ObjCInterfaceDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCCompatibleAliasDeclRange = DerivedEntityRange<DeclIterator, ObjCCompatibleAliasDecl>;
using ObjCCompatibleAliasDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCCompatibleAliasDecl>;
using ObjCCompatibleAliasDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCCompatibleAliasDecl>;

class ObjCCompatibleAliasDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCCompatibleAliasDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCCompatibleAliasDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCCompatibleAliasDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_COMPATIBLE_ALIAS;
  }

  static ObjCCompatibleAliasDeclContainingDeclRange containing(const Decl &decl);
  static ObjCCompatibleAliasDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCCompatibleAliasDecl> from(const TokenContext &c);
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