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
class Type;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ValueDeclRange = DerivedEntityRange<DeclIterator, ValueDecl>;
using ValueDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ValueDecl>;
using ValueDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ValueDecl>;

class ValueDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ValueDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ValueDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ValueDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::VALUE;
  }

  static ValueDeclContainingDeclRange containing(const Decl &decl);
  static ValueDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ValueDecl> from(const TokenContext &c);
  static std::optional<ValueDecl> from(const NamedDecl &parent);

  inline static std::optional<ValueDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ValueDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ValueDecl> from(const Decl &parent);

  inline static std::optional<ValueDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ValueDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type type(void) const;
  bool is_weak(void) const;
};

static_assert(sizeof(ValueDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
