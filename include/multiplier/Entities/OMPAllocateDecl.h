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
class OMPAllocateDecl;
class OMPDeclarativeDirectiveDecl;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPAllocateDecl : public OMPDeclarativeDirectiveDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveDecl;
  friend class Decl;
 public:
  static gap::generator<OMPAllocateDecl> in(const Fragment &frag);
  static gap::generator<OMPAllocateDecl> in(const File &file);
  static gap::generator<OMPAllocateDecl> in(const Index &index);
  static gap::generator<OMPAllocateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPAllocateDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_ALLOCATE;
  }

  static gap::generator<OMPAllocateDecl> containing(const Decl &decl);
  static gap::generator<OMPAllocateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPAllocateDecl> containing(const Stmt &stmt);
  static gap::generator<OMPAllocateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<OMPAllocateDecl> redeclarations(void) const &;
  static std::optional<OMPAllocateDecl> from(const Decl &parent);

  inline static std::optional<OMPAllocateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return OMPAllocateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPAllocateDecl> from(const Reference &r) {
    return OMPAllocateDecl::from(r.as_declaration());
  }

  inline static std::optional<OMPAllocateDecl> from(const TokenContext &t) {
    return OMPAllocateDecl::from(t.as_declaration());
  }

  std::optional<Expr> nth_varlist(unsigned n) const;
  unsigned num_varlists(void) const;
  gap::generator<Expr> varlists(void) const &;
};

static_assert(sizeof(OMPAllocateDecl) == sizeof(OMPDeclarativeDirectiveDecl));

#endif
} // namespace mx
