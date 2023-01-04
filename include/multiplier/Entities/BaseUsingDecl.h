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
class BaseUsingDecl;
class Decl;
class NamedDecl;
class UsingShadowDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using BaseUsingDeclRange = DerivedEntityRange<DeclIterator, BaseUsingDecl>;
using BaseUsingDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, BaseUsingDecl>;
using BaseUsingDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, BaseUsingDecl>;

class BaseUsingDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static BaseUsingDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BaseUsingDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : BaseUsingDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::BASE_USING;
  }

  static BaseUsingDeclContainingDeclRange containing(const Decl &decl);
  static BaseUsingDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<BaseUsingDecl> from(const TokenContext &c);
  static std::optional<BaseUsingDecl> from(const NamedDecl &parent);

  inline static std::optional<BaseUsingDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return BaseUsingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BaseUsingDecl> from(const Decl &parent);

  inline static std::optional<BaseUsingDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return BaseUsingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<UsingShadowDecl> shadows(void) const;
};

static_assert(sizeof(BaseUsingDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
