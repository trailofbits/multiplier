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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "CXXMethodDecl.h"
#include "DeclKind.h"

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
  static gap::generator<CXXDestructorDecl> in(const Fragment &frag);
  static gap::generator<CXXDestructorDecl> in(const File &file);
  static gap::generator<CXXDestructorDecl> in(const Index &index);
  static gap::generator<CXXDestructorDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXDestructorDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_DESTRUCTOR;
  }

  static gap::generator<CXXDestructorDecl> containing(const Decl &decl);
  static gap::generator<CXXDestructorDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXDestructorDecl> containing(const Stmt &stmt);
  static gap::generator<CXXDestructorDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<CXXDestructorDecl> redeclarations(void) const;
  static std::optional<CXXDestructorDecl> from(const Decl &parent);

  inline static std::optional<CXXDestructorDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return CXXDestructorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CXXDestructorDecl> from(const Reference &r) {
    return CXXDestructorDecl::from(r.as_declaration());
  }

  inline static std::optional<CXXDestructorDecl> from(const TokenContext &t) {
    return CXXDestructorDecl::from(t.as_declaration());
  }

  std::optional<FunctionDecl> operator_delete(void) const;
  std::optional<Expr> operator_delete_this_argument(void) const;
};

static_assert(sizeof(CXXDestructorDecl) == sizeof(CXXMethodDecl));

#endif
} // namespace mx
