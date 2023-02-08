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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

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
class BindingDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<BindingDecl> in(const Fragment &frag);
  static gap::generator<BindingDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::BINDING;
  }

  static gap::generator<DeclKind> derived_kinds(void);
  static gap::generator<BindingDecl> containing(const Decl &decl);
  static gap::generator<BindingDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<BindingDecl> redeclarations(void) const;
  inline static std::optional<BindingDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<BindingDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

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
