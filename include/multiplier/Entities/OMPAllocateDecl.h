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
#include "OMPDeclarativeDirectiveDecl.h"

namespace mx {
class Decl;
class Expr;
class OMPAllocateDecl;
class OMPDeclarativeDirectiveDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPAllocateDeclRange = DerivedEntityRange<DeclIterator, OMPAllocateDecl>;
using OMPAllocateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPAllocateDecl>;
using OMPAllocateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, OMPAllocateDecl>;

class OMPAllocateDecl : public OMPDeclarativeDirectiveDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveDecl;
  friend class Decl;
 public:
  inline static OMPAllocateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPAllocateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPAllocateDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_ALLOCATE;
  }

  static OMPAllocateDeclContainingDeclRange containing(const Decl &decl);
  static OMPAllocateDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPAllocateDecl> from(const TokenContext &c);
  static std::optional<OMPAllocateDecl> from(const OMPDeclarativeDirectiveDecl &parent);

  inline static std::optional<OMPAllocateDecl> from(const std::optional<OMPDeclarativeDirectiveDecl> &parent) {
    if (parent) {
      return OMPAllocateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPAllocateDecl> from(const Decl &parent);

  inline static std::optional<OMPAllocateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return OMPAllocateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Expr> varlists(void) const;
};

static_assert(sizeof(OMPAllocateDecl) == sizeof(OMPDeclarativeDirectiveDecl));

#endif
} // namespace mx
