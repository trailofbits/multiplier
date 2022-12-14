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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclKind.h"
#include "ValueDecl.h"

namespace mx {
class BindingDecl;
class Decl;
class Expr;
class NamedDecl;
class ValueDecl;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using BindingDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, BindingDecl>;

class BindingDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<BindingDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<BindingDecl> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : BindingDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::BINDING;
  }

  static BindingDeclContainingDeclRange containing(const Decl &decl);
  static BindingDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<BindingDecl> from(const TokenContext &c);
  static std::optional<BindingDecl> from(const ValueDecl &parent);

  inline static std::optional<BindingDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return BindingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BindingDecl> from(const NamedDecl &parent);

  inline static std::optional<BindingDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return BindingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BindingDecl> from(const Decl &parent);

  inline static std::optional<BindingDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return BindingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr binding(void) const;
  ValueDecl decomposed_declaration(void) const;
  VarDecl holding_variable(void) const;
};

static_assert(sizeof(BindingDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
