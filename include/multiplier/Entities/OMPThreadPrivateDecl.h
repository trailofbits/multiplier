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

#include "OMPDeclarativeDirectiveDecl.h"

namespace mx {
class Decl;
class Expr;
class OMPDeclarativeDirectiveDecl;
class OMPThreadPrivateDecl;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPThreadPrivateDecl : public OMPDeclarativeDirectiveDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveDecl;
  friend class Decl;
 public:
  static gap::generator<OMPThreadPrivateDecl> in(const Fragment &frag);
  static gap::generator<OMPThreadPrivateDecl> in(const File &file);
  static gap::generator<OMPThreadPrivateDecl> in(const Index &index);
  static gap::generator<OMPThreadPrivateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPThreadPrivateDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_THREAD_PRIVATE;
  }

  static gap::generator<OMPThreadPrivateDecl> containing(const Decl &decl);
  static gap::generator<OMPThreadPrivateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPThreadPrivateDecl> containing(const Stmt &stmt);
  static gap::generator<OMPThreadPrivateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<OMPThreadPrivateDecl> redeclarations(void) const &;
  static std::optional<OMPThreadPrivateDecl> from(const Decl &parent);

  inline static std::optional<OMPThreadPrivateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return OMPThreadPrivateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPThreadPrivateDecl> from(const Reference &r) {
    return OMPThreadPrivateDecl::from(r.as_declaration());
  }

  inline static std::optional<OMPThreadPrivateDecl> from(const TokenContext &t) {
    return OMPThreadPrivateDecl::from(t.as_declaration());
  }

  std::optional<Expr> nth_varlist(unsigned n) const;
  gap::generator<Expr> varlists(void) const &;
};

static_assert(sizeof(OMPThreadPrivateDecl) == sizeof(OMPDeclarativeDirectiveDecl));

#endif
} // namespace mx
