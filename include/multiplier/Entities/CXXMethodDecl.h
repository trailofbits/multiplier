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

#include "DeclKind.h"
#include "FunctionDecl.h"
#include "RefQualifierKind.h"

namespace mx {
class CXXMethodDecl;
class Decl;
class DeclaratorDecl;
class FunctionDecl;
class NamedDecl;
class Type;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXMethodDecl : public FunctionDecl {
 private:
  friend class FragmentImpl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<CXXMethodDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<CXXMethodDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CXXMethodDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_METHOD;
  }

  static gap::generator<CXXMethodDecl> containing(const Decl &decl);
  static gap::generator<CXXMethodDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXMethodDecl> from(const TokenContext &c);
  static std::optional<CXXMethodDecl> from(const FunctionDecl &parent);

  inline static std::optional<CXXMethodDecl> from(const std::optional<FunctionDecl> &parent) {
    if (parent) {
      return CXXMethodDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXMethodDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<CXXMethodDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return CXXMethodDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXMethodDecl> from(const ValueDecl &parent);

  inline static std::optional<CXXMethodDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return CXXMethodDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXMethodDecl> from(const NamedDecl &parent);

  inline static std::optional<CXXMethodDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return CXXMethodDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXMethodDecl> from(const Decl &parent);

  inline static std::optional<CXXMethodDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return CXXMethodDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  RefQualifierKind reference_qualifier(void) const;
  std::optional<Type> this_object_type(void) const;
  std::optional<Type> this_type(void) const;
  bool has_inline_body(void) const;
  bool is_const(void) const;
  bool is_copy_assignment_operator(void) const;
  bool is_instance(void) const;
  bool is_lambda_static_invoker(void) const;
  bool is_move_assignment_operator(void) const;
  bool is_virtual(void) const;
  bool is_volatile(void) const;
  std::optional<CXXMethodDecl> nth_overridden_method(unsigned n) const;
  gap::generator<CXXMethodDecl> overridden_methods(void) const;
};

static_assert(sizeof(CXXMethodDecl) == sizeof(FunctionDecl));

#endif
} // namespace mx
