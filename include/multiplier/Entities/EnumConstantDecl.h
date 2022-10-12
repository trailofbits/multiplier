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
#include "StmtUseSelector.h"
#include "ValueDecl.h"

namespace mx {
class Decl;
class EnumConstantDecl;
class Expr;
class NamedDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using EnumConstantDeclRange = DerivedEntityRange<DeclIterator, EnumConstantDecl>;
using EnumConstantDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, EnumConstantDecl>;
using EnumConstantDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, EnumConstantDecl>;

class EnumConstantDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static EnumConstantDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static EnumConstantDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : EnumConstantDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::ENUM_CONSTANT;
  }

  static EnumConstantDeclContainingDeclRange containing(const Decl &decl);
  static EnumConstantDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<EnumConstantDecl> from(const TokenContext &c);
  static std::optional<EnumConstantDecl> from(const ValueDecl &parent);

  inline static std::optional<EnumConstantDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return EnumConstantDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnumConstantDecl> from(const NamedDecl &parent);

  inline static std::optional<EnumConstantDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return EnumConstantDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnumConstantDecl> from(const Decl &parent);

  inline static std::optional<EnumConstantDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return EnumConstantDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> initializer_expression(void) const;
};

static_assert(sizeof(EnumConstantDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
