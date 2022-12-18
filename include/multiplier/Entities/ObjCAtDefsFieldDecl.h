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
#include "FieldDecl.h"

namespace mx {
class Decl;
class DeclaratorDecl;
class FieldDecl;
class NamedDecl;
class ObjCAtDefsFieldDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCAtDefsFieldDeclRange = DerivedEntityRange<DeclIterator, ObjCAtDefsFieldDecl>;
using ObjCAtDefsFieldDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAtDefsFieldDecl>;
using ObjCAtDefsFieldDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCAtDefsFieldDecl>;

class ObjCAtDefsFieldDecl : public FieldDecl {
 private:
  friend class FragmentImpl;
  friend class FieldDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCAtDefsFieldDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAtDefsFieldDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCAtDefsFieldDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_AT_DEFS_FIELD;
  }

  static ObjCAtDefsFieldDeclContainingDeclRange containing(const Decl &decl);
  static ObjCAtDefsFieldDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAtDefsFieldDecl> from(const TokenContext &c);
  static std::optional<ObjCAtDefsFieldDecl> from(const FieldDecl &parent);

  inline static std::optional<ObjCAtDefsFieldDecl> from(const std::optional<FieldDecl> &parent) {
    if (parent) {
      return ObjCAtDefsFieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCAtDefsFieldDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<ObjCAtDefsFieldDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return ObjCAtDefsFieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCAtDefsFieldDecl> from(const ValueDecl &parent);

  inline static std::optional<ObjCAtDefsFieldDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return ObjCAtDefsFieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCAtDefsFieldDecl> from(const NamedDecl &parent);

  inline static std::optional<ObjCAtDefsFieldDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ObjCAtDefsFieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCAtDefsFieldDecl> from(const Decl &parent);

  inline static std::optional<ObjCAtDefsFieldDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCAtDefsFieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(ObjCAtDefsFieldDecl) == sizeof(FieldDecl));

#endif
} // namespace mx
