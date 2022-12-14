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

#include "CXXMethodDecl.h"
#include "DeclKind.h"
#include "DeclUseSelector.h"
#include "StmtUseSelector.h"

namespace mx {
class CXXDestructorDecl;
class CXXMethodDecl;
class Decl;
class DeclaratorDecl;
class Expr;
class FunctionDecl;
class NamedDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXDestructorDecl : public CXXMethodDecl {
 private:
  friend class FragmentImpl;
  friend class CXXMethodDecl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<CXXDestructorDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<CXXDestructorDecl> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXDestructorDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_DESTRUCTOR;
  }

  static gap::generator<CXXDestructorDecl> containing(const Decl &decl);
  static gap::generator<CXXDestructorDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXDestructorDecl> from(const TokenContext &c);
  static std::optional<CXXDestructorDecl> from(const CXXMethodDecl &parent);

  inline static std::optional<CXXDestructorDecl> from(const std::optional<CXXMethodDecl> &parent) {
    if (parent) {
      return CXXDestructorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDestructorDecl> from(const FunctionDecl &parent);

  inline static std::optional<CXXDestructorDecl> from(const std::optional<FunctionDecl> &parent) {
    if (parent) {
      return CXXDestructorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDestructorDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<CXXDestructorDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return CXXDestructorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDestructorDecl> from(const ValueDecl &parent);

  inline static std::optional<CXXDestructorDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return CXXDestructorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDestructorDecl> from(const NamedDecl &parent);

  inline static std::optional<CXXDestructorDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return CXXDestructorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDestructorDecl> from(const Decl &parent);

  inline static std::optional<CXXDestructorDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return CXXDestructorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<FunctionDecl> operator_delete(void) const;
  std::optional<Expr> operator_delete_this_argument(void) const;
};

static_assert(sizeof(CXXDestructorDecl) == sizeof(CXXMethodDecl));

#endif
} // namespace mx
